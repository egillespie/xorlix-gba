/* Global function declarations and macros go here */

#ifndef GLOBALS_H
#define GLOBALS_H

/* Palettes, sprites, tiles, you know, graphics */
#include "gfx.h"
#include "board.h"
#include "cursor.h"
#include "game.h"

/* Macro definitions */
#define TRUE    1
#define FALSE   0

#define MIN_FRAME_WAIT   10
#define CURSOR_STEP      10
#define BOARD_STEP       3
#define MAX_FRAMES       (CURSOR_STEP * BOARD_STEP)

/* Global variables */

/* Used for seeding the random number generator */
unsigned int seed;
short incSeed;

/* Frame counters */
short curFrame;
short frameWait;

/* Is the A or B button down? */
u8 abDown;

/* External functions */
extern void WaitForSync(unsigned short);

/* Functions implemented in globals.c */
void CopyOAM(void);
void AdjustOAM(void);

short CanChange(void);
void  HandleKeys(void);

void RandomBGPalette(void);
void SetBGPalette(short);

void RandomSpritePalette(void);
void SetSpritePalette(short);

#endif
