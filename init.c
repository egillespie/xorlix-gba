/* Application initialization implementations go here */

#include <gba/gba.h>

#include "init.h"
#include "globals.h"

#include "text.h"

void Init(void) {
   /* Initialize random number generation */
   seed = 0;
   incSeed = 1;

   /* Initialize the frame info */
   curFrame = 0;
   frameWait = -1;

   /* Initialize button press status */
   abDown = FALSE;

   /* Initialize the video mode */
   SetVideoMode(OBJ_MAP_1D | MODE0 | OBJ_ENABLE | BG0_ENABLE | BG1_ENABLE);
   
   /* Initialize graphic objects */
   InitPalettes();
   InitSprites();
   InitTiles();

   /* Initialize workspace */
   InitBoard();
   InitCursor();

   /* Start a new game */
   NewGame();
}

void InitPalettes(void) {
   short i;

   /* The cursor palette is the 2nd sprite palette */
   /* The board palette is the 2nd tile palette */
   for (i = 0; i < 16; i++) {
      BGPaletteMem[i+16] = boardpal[i];
      OBJPaletteMem[i+16] = cursorpal[i];
   }

   /* Set default palettes */
   SetBGPalette(2);
   SetSpritePalette(8);
}

void InitSprites(void) {
   register u16 i;
   register u16* OBJdata;
   register u16* CharData = CharMem;

   /* Copy ball data */
   OBJdata = (u16*)ball16_Bitmap;
   for (i = 0; i < 176; i++, CharData++)
      *CharData = OBJdata[i];

   /* Copy cursor data */
   OBJdata = (u16*)cursor16_Bitmap;
   for (i = 0; i < 320; i++, CharData++)
      *CharData = OBJdata[i];
}

void InitTiles(void) {
   register u16 i;
   register u16 *tileMem, *tileData, *endBlock;

   // Set Background 1 properties (background)
   REG_BG1CNT = CHAR_BASE_BLOCK(0) | SCREEN_BASE_BLOCK(16) | BG_COLOR_16 |
      BG_TEXT_SIZE_256x256;
   
   // Copy tile data
   tileMem = CharBaseBlockAddr(0);
   tileData = (u16*)bg16_Tiles;
   for (i = 0; i < 9600; i++)
      tileMem[i] = tileData[i];

   // Copy the tile map
   tileData = bg16_Map;
   endBlock = ScreenBaseBlockAddr(16) + 2048;
   for (tileMem = ScreenBaseBlockAddr(16); tileMem < endBlock; tileMem++)
      *tileMem = *(tileData++);

   // Set Background 0 properties (game board)
   REG_BG0CNT = CHAR_BASE_BLOCK(3) | SCREEN_BASE_BLOCK(17) | BG_COLOR_16 |
      BG_TEXT_SIZE_256x256;

   // Copy tile data
   tileMem = CharBaseBlockAddr(3);
   tileData = (u16*)board16_Tiles;
   for (i = 0; i < 2864/*1248*/; i++)
      tileMem[i] = tileData[i];

   // Copy the tile map
   tileData = board16_Map;
   endBlock = ScreenBaseBlockAddr(17) + 2048;
   for (tileMem = ScreenBaseBlockAddr(17); tileMem < endBlock; tileMem++)
      *tileMem = *(tileData++);

   // Output some text
   txtSetPalette(1);
   txtPrintS(0, 8, "Moves", 5);
   txtPrintS(25, 8, "Bonus", 5);
}
