#include <stdlib.h>
#include <gba/gba.h>

#include "globals.h"

// Current background palette index
static short curbgpal = -1;

// Current sprite palette index
static short cursprpal = -1;

// Copy first 128 sprites
void CopyOAM(void) {
   short i, j, c = 0;
   u16* oam = (u16*)OAMmem;
   
   /* Copy over the cursor */
   *oam = cursor.sprite.attrib0;
   oam++;
   *oam = cursor.sprite.attrib1;
   oam++;
   *oam = cursor.sprite.attrib2;
   oam += 2;
   c++;

   /* Copy over 127 of the pegs */
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (j = 0; j < BOARD_WIDTH; j++) {
	 *oam = board[i][j].sprite.attrib0;
	 oam++;
	 *oam = board[i][j].sprite.attrib1;
	 oam++;
	 *oam = board[i][j].sprite.attrib2;
	 oam += 2;
	 c++;
	 
	 if (c == 128)
	    return;
      }
   }
}

// Copy remaining sprites
void AdjustOAM(void) {
   short i, j, c = 0;
   u16* oam = (u16*)(OAMmem + 4);
   
   for (i = BOARD_HEIGHT - 1; i >= 0; i--) {
      for (j = BOARD_WIDTH - 1; j >= 0; j--) {
	 *oam = board[i][j].sprite.attrib0;
	 oam++;
	 *oam = board[i][j].sprite.attrib1;
	 oam++;
	 *oam = board[i][j].sprite.attrib2;
	 oam += 2;
	 
	 c++;
	 
	 if (c == 13)
	    return;
      }
   }
}

/* Stabilizes key presses by limiting when changes can
 * occur based on user input */
short CanChange(void) {
   /* Check if we're at a frame where we can change */
   if (frameWait < MIN_FRAME_WAIT && frameWait > 0)
      return FALSE;
   
   frameWait = 0;
   return TRUE;
}

/* Figure out which key is pressed and act accordingly */
void HandleKeys(void) {
   /* Increment the seed if we're supposed to */
   if (incSeed) {
      seed++;
      
      if (keyDown(KEY_ANY)) {
	 incSeed = 0;
	 srand(seed);
      }
   }
   
   /* Catch all key presses */
   if (keyDown(KEY_B) | keyDown(KEY_A)) {
      if (abDown == FALSE) {
	 ToggleBall(cursor.x, cursor.y);
	 DecrementMoves();

	 if (IsBoardClear()) {
	    UpdateScore();
	    NewLevel();
	 }
	 else if (GameOver()) {
	    SaveHiScore();
	    NewGame();
	 }

	 abDown = TRUE;
      }
   }
   else
      abDown = FALSE;
   
   if (keyDown(KEY_LEFT))
      SetCursorLocation(cursor.x - 1, cursor.y);

   if (keyDown(KEY_RIGHT))
      SetCursorLocation(cursor.x + 1, cursor.y);
   
   if (keyDown(KEY_DOWN))
      SetCursorLocation(cursor.x, cursor.y + 1);
   
   if (keyDown(KEY_UP))
      SetCursorLocation(cursor.x, cursor.y - 1);
}

// Picks a random background palette that is different from
// the previous background palette
void RandomBGPalette(void) {
   short newbgpal;
   
   do {
      newbgpal = rand() % NUM_BG_PALS;
   } while (newbgpal == curbgpal);

   SetBGPalette(newbgpal);
}

void SetBGPalette(short p) {
   short i;
   
   curbgpal = p;
   for (i = 0; i < 16; i++)
      BGPaletteMem[i] = bgpal[p][i];
}

// Picks a random palette for the sprites that is different from
// the current palette being used to draw sprites
void RandomSpritePalette(void) {
   short newspritepal;

   do {
      newspritepal = rand() % NUM_BALL_PALS;
   } while (newspritepal == cursprpal);
   
   SetSpritePalette(newspritepal);
}

void SetSpritePalette(short p) {
   short i;
   
   cursprpal = p;
   for (i = 0; i < 16; i++)
      OBJPaletteMem[i] = ballpal[p][i];
}
