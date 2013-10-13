#include "game.h"

#include "text.h"

void NewGame(void) {
   register short i, j;

   game.score = 0;
   game.moves = 0;
   game.bonus = DEF_BONUS;
   game.level = DEF_LEVEL;

   /* Load the hi score */
   LoadHiScore();

   /* Turn off all pegs */
   for (i = 0; i < BOARD_HEIGHT; i++)
      for (j = 0; j < BOARD_WIDTH; j++)
	 board[i][j].on = FALSE;

   /* Create a new level */
   NewLevel();
}

void NewLevel(void) {
   CalculateBonus();

   game.level++;
   game.moves = DEF_MOVES + game.level;

   /* Randomize the appearance/layout of the new level */
   RandomBoard(game.moves);
   RandomBGPalette();
   RandomSpritePalette();

   /* Update text displays */
   DisplayScore();
   DisplayMoves();
   DisplayBonus();
   DisplayHiScore();
}

void DecrementMoves(void) {
   /* First try to decrement moves, if no moves left then decrement bonus */
   if (game.moves > 0) {
      game.moves--;
      DisplayMoves();
   }
   else if (game.bonus > 0) {
      game.bonus--;
      DisplayBonus();
   }
}

u8 GameOver(void) {
   if (game.moves <= 0 && game.bonus <= 0)
      return TRUE;
   return FALSE;
}

void CalculateBonus(void) {
   // Award a bonus point if they clear all pegs with moves remaining
   if (game.moves > MAX_BONUS)
      game.bonus++;

   // Don't give them too much of an advantage
   if (game.bonus > MAX_BONUS)
      game.bonus = MAX_BONUS;
}

void UpdateScore(void) {
   game.score += game.moves + 1;
   DisplayScore();

   /* See if it's a new high score */
   if (game.score > game.hiScore) {
      game.hiScore = game.score;
      DisplayHiScore();
      SaveHiScore();
   }
}

void LoadHiScore(void) {
   u8* pSaveMem = GAMEPAK_RAM;

   /* Check the save header to see if a save exists */
   if (pSaveMem[0] == SAVE_BYTE) {
      game.hiScore = (pSaveMem[1] << 8) | pSaveMem[2];
   }
   else {
      /* No saved game, so no high score */
      game.hiScore = 0;
   }
}

void SaveHiScore(void) {
   u8* pSaveMem = GAMEPAK_RAM;
   u16 hiScore = game.hiScore;
   u8 save;
   
   /* Write the save header */
   pSaveMem[0] = SAVE_BYTE;

   /* Write the high score data */
   save = hiScore & 255;
   pSaveMem[2] = save;
   save = (hiScore >> 8) & 255;
   pSaveMem[1] = save;
}

void DisplayScore(void) {
   short len = txtLenN(game.score);
   short x;

   txtPrintS(8, 1, "             ", 13);
   
   switch (len) {
   case 1:
   case 2:
      x = 10;
      break;
   case 3:
   case 4:
      x = 9;
      break;
   default:
      x = 8;
      break;
   }
   
   txtPrintS(x, 1, "Score:", 6);
   txtPrintN(x + 7, 1, game.score);
}

void DisplayMoves(void) {
   short len = txtLenN(game.moves);
   short x;

   txtPrintS(0, 10, "     ", 5);

   switch (len) {
   case 1:
      x = 2;
      break;
   case 2:
   case 3:
      x = 1;
      break;
   default:
      x = 0;
      break;
   }

   txtPrintN(x, 10, game.moves);
}

void DisplayBonus(void) {
   short len = txtLenN(game.moves);
   short x;

   txtPrintS(25, 10, "     ", 5);

   switch (len) {
   case 1:
   case 2:
      x = 27;
      break;
   case 3:
   case 4:
      x = 26;
      break;
   default:
      x = 25;
      break;
   }

   txtPrintN(x, 10, game.bonus);
}

void DisplayHiScore(void) {
   short len = txtLenN(game.hiScore);
   short x;

   txtPrintS(7, 19, "                ", 16);
   
   switch (len) {
   case 1:
   case 2:
      x = 9;
      break;
   case 3:
   case 4:
      x = 8;
      break;
   default:
      x = 7;
      break;
   }
   
   txtPrintS(x, 19, "Hi Score:", 9);
   txtPrintN(x + 10, 19, game.hiScore);
}
