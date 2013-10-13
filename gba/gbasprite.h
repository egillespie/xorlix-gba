/* GBA Sprite structs and macros */

#ifndef GBA_SPRITE_H
#define GBA_SPRITE_H

#include <gba/gbatypes.h>

/** Sprite Memory Addresses **/

#define OAMmem         ((u16*)0x7000000)     /* Object Attribute Memory */
#define CharMem        ((u16*)0x6010000)     /* Character memory (where sprite data goes) */
#define OAMdata        ((u16*)0x6010000)     /* Sprite data */
#define OBJPaletteMem  ((u16*)0x5000200)     /* Sprite Palette */

/* Atribute0 stuff */
#define OBJ_ROTATION_FLAG       0x0100
#define OBJ_SIZE_DOUBLE         0x0200
#define OBJ_MODE_NORMAL         0x0000
#define OBJ_MODE_TRANSPARENT    0x0400
#define OBJ_MODE_WINDOWED       0x0800
#define OBJ_MOSAIC              0x1000
#define OBJ_COLOR_16            0x0000
#define OBJ_COLOR_256           0x2000
#define OBJ_SQUARE              0x0000
#define OBJ_TALL                0x4000
#define OBJ_WIDE                0x8000

/* Attribute1 stuff */
#define OBJ_ROTDATA(n)          (n << 9)
#define OBJ_HORIZONTAL_FLIP     0x1000
#define OBJ_VERTICAL_FLIP       0x2000
#define OBJ_SIZE_8              0x0000
#define OBJ_SIZE_16             0x4000
#define OBJ_SIZE_32             0x8000
#define OBJ_SIZE_64             0xC000

/* Attribute2 stuff */
#define OBJ_PRIORITY(n)         (n << 10)
#define OBJ_PALETTE(n)          (n << 12)

/* Sprite structures */
typedef struct tagOAMEntry {
   u16 attrib0;
   u16 attrib1;
   u16 attrib2;
   u16 attrib3;
} OAMEntry, *pOAMEntry;

typedef struct tagRotData {
   u16 filler1[3];
   u16 pa;
   u16 filler2[3];
   u16 pb;	
   u16 filler3[3];
   u16 pc;	
   u16 filler4[3];
   u16 pd;
} RotData, *pRotData;

#endif
