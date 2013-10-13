#ifndef GAME_H
#define GAME_H

#include <gba/gba.h>

#include "globals.h"

/* Stores all game state information */
typedef struct {
   u16 score;   /* Players current score */
   u16 moves;   /* Moves remaining for current level */
   u16 bonus;   /* Accumulated bonus points/moves */
   u16 level;   /* Current level (first level = 0) */

   u16 hiScore; /* The current hi score */
} Game, *pGame;

/* An instance of the current game */
Game game;

/* Macro definitions (mostly default values and constants) */
#define SAVE_BYTE       'S'

#define DEF_MOVES       3
#define DEF_BONUS       0
#define DEF_LEVEL       -1

#define MAX_BONUS       (game.level / 3)

/* Gaming functions */
void NewGame(void);
void NewLevel(void);
void DecrementMoves(void);
u8   GameOver(void);
void CalculateBonus(void);
void UpdateScore(void);
void LoadHiScore(void);
void SaveHiScore(void);
void DisplayScore(void);
void DisplayMoves(void);
void DisplayBonus(void);
void DisplayHiScore(void);

#endif
