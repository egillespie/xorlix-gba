/* All external declarations for sprites, palettes, tiles go here */

#ifndef GFX_H
#define GFX_H

/* Tiles */
extern const unsigned char bg16_Tiles[19200];
extern unsigned short bg16_Map[1024];

extern const unsigned char board16_Tiles[2400];
extern unsigned short board16_Map[1024];

/* Sprites */
extern const unsigned char ball16_Bitmap[352];
extern const unsigned char cursor16_Bitmap[640];

/* Palettes */
#define NUM_BG_PALS   13
#define NUM_BALL_PALS 13

extern unsigned short bgpal[NUM_BG_PALS][16];
extern unsigned short ballpal[NUM_BALL_PALS][16];
extern unsigned short cursorpal[16];
extern unsigned short boardpal[16];

#endif
