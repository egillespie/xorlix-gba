#ifndef BOARD_H
#define BOARD_H

#include <gba/gba.h>

/* Macro definitions */
#define BOARD_WIDTH    14
#define BOARD_HEIGHT   10

/* Structure for a single game piece in the board */
typedef struct {
   /* Whether the peg is on or off */
   char on;

   /* Which animation frame the peg is on */
   char frame;

   /* GBA Information about the peg's sprite */
   OAMEntry sprite;
} Peg, *pPeg;

/* All pegs in the board */
Peg board[BOARD_HEIGHT][BOARD_WIDTH];

/* Function declarations */
void InitBoard(void);
u8 IsBoardClear(void);
void RandomBoard(short);
void RandomToggle(void);
void UpdateBoard(void);
void SetBallFrame(short, short, short);
void ToggleBall(short, short);

#endif
