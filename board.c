#include <stdlib.h>
#include <gba/gba.h>

#include "board.h"
#include "globals.h"

void InitBoard(void) {
   register short i, j;
   
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (j = 0; j < BOARD_WIDTH; j++) {
	 /* Set peg properties */
	 board[i][j].on = TRUE;
	 board[i][j].frame = 0;
	 
	 /* Set peg sprite properties */
	 board[i][j].sprite.attrib0 = OBJ_COLOR_16 | OBJ_SQUARE | (11 * i + 30);
	 board[i][j].sprite.attrib1 = OBJ_SIZE_8 | (11 * j + 44);
	 board[i][j].sprite.attrib2 = OBJ_PALETTE(0) | 0;
      }
   }
}

u8 IsBoardClear(void) {
   register short i, j;

   for (i = 0; i < BOARD_HEIGHT; i++)
      for (j = 0; j < BOARD_WIDTH; j++)
	 if (board[i][j].on)
	    return FALSE;

   return TRUE;
}

void RandomBoard(short n) {
   while (n > 0) {
      RandomToggle();
      n--;
   }
}

void RandomToggle(void) {
   short i, x, y;

   for (i = 0; i <= game.level; i++) {
      x = rand() % BOARD_WIDTH;
      y = rand() % BOARD_HEIGHT;

      // If it's not on, toggle and return
      if (!board[x][y].on) {
	 ToggleBall(x, y);
	 return;
      }
   }

   // We tried a bunch of times and failed, so let's just give up
   ToggleBall(rand() % BOARD_WIDTH, rand() % BOARD_HEIGHT);
}

void UpdateBoard(void) {
   register short i, j;
   
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (j = 0; j < BOARD_WIDTH; j++) {
	 if ((board[i][j].on == TRUE) && (board[i][j].frame > 0))
	    SetBallFrame(i, j, board[i][j].frame - 1);
	 else if ((board[i][j].on == FALSE) && (board[i][j].frame < 10))
	    SetBallFrame(i, j, board[i][j].frame + 1);
      }
   }
}

void SetBallFrame(short x, short y, short f) {
   if (f > 10)
      f = 10;
   if (f < 0)
      f = 0;
   
   board[x][y].frame = f;
   board[x][y].sprite.attrib2 = OBJ_PALETTE(0) | f;
}

void ToggleBall(short x, short y) {
   board[y][x].on = !board[y][x].on;
   
   if (x != 0)
      board[y][x-1].on = !board[y][x-1].on;
   
   if (x != BOARD_WIDTH - 1)
      board[y][x+1].on = !board[y][x+1].on;
   
   if (y != 0)
      board[y-1][x].on = !board[y-1][x].on;
   
   if (y != BOARD_HEIGHT - 1)
      board[y+1][x].on = !board[y+1][x].on;
}
