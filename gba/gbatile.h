/* GBA Tile structs and macros */

#ifndef GBA_TILE_H
#define GBA_TILE_H

/** Tile Memory Addresses **/

#define BGMem          ((u16*)0x6004000)     /* Background memory (where backgrounds go) */
#define BGPaletteMem   ((u16*)0x5000000)     /* Background Palette */

/** Tile Registers **/

#define REG_BG0CNT     *(u16*)0x4000008      /* Background 0 */
#define REG_BG1CNT     *(u16*)0x400000A      /* Background 1 */
#define REG_BG2CNT     *(u16*)0x400000C      /* Background 2 */
#define REG_BG3CNT     *(u16*)0x400000E      /* Background 3 */
#define REG_BG0HOFS    *(u16*)0x4000010      /* Background 0 Horizontal Offset */
#define REG_BG0VOFS    *(u16*)0x4000012      /* Background 0 Vertical Offset */
#define REG_BG1HOFS    *(u16*)0x4000014      /* Background 1 Horizontal Offset */
#define REG_BG1VOFS    *(u16*)0x4000016      /* Background 1 Vertical Offset */
#define REG_BG2HOFS    *(u16*)0x4000018      /* Background 2 Horizontal Offset */
#define REG_BG2VOFS    *(u16*)0x400001A      /* Background 2 Vertical Offset */
#define REG_BG3HOFS    *(u16*)0x400001C      /* Background 3 Horizontal Offset */
#define REG_BG3VOFS    *(u16*)0x400001E      /* Background 3 Vertical Offset */
#define REG_BG2PA      *(u16*)0x4000020      /* Background 2 PA Rotation (pa = x_scale * cos(angle);) */
#define REG_BG2PB      *(u16*)0x4000022      /* Background 2 PB Rotation (pb = y_scale * sin(angle);) */
#define REG_BG2PC      *(u16*)0x4000024      /* Background 2 PC Rotation (pc = x_scale * -sin(angle);) */
#define REG_BG2PD      *(u16*)0x4000026      /* Background 2 PD Rotation (pd = y_scale * cos(angle);) */
#define REG_BG2X       *(u32*)0x4000028      /* Background 2 X Location */
#define REG_BG2X_L     *(u16*)0x4000028      
#define REG_BG2X_H     *(u16*)0x400002A      
#define REG_BG2Y       *(u32*)0x400002C      /* Background 2 Y Location */
#define REG_BG2Y_L     *(u16*)0x400002C      
#define REG_BG2Y_H     *(u16*)0x400002E      
#define REG_BG3PA      *(u16*)0x4000030      /* Background 3 PA Rotation (pa = x_scale * cos(angle);) */
#define REG_BG3PB      *(u16*)0x4000032      /* Background 3 PB Rotation (pb = y_scale * sin(angle);) */
#define REG_BG3PC      *(u16*)0x4000034      /* Background 3 PC Rotation (pc = x_scale * -sin(angle);) */
#define REG_BG3PD      *(u16*)0x4000036      /* Background 3 PD Rotation (pd = y_scale * cos(angle);) */
#define REG_BG3X       *(u32*)0x4000038      /* Background 3 X Location */
#define REG_BG3X_L     *(u16*)0x4000038      
#define REG_BG3X_H     *(u16*)0x400003A      
#define REG_BG3Y       *(u32*)0x400003C      /* Background 3 Y Location */
#define REG_BG3Y_L     *(u16*)0x400003C      
#define REG_BG3Y_H     *(u16*)0x400003E      

/* Used for tile map entries */
#define TILE_PALETTE(n)         (n<<12)
#define TILE_VERTICAL_FLIP      0x0800
#define TILE_HORIZONTAL_FLIP    0x0400

/* REG_BGxCNT Options */
#define BG_COLOR_16             0x00
#define BG_COLOR_256            0x80
#define BG_MOSAIC               0x40
#define BG_WRAPAROUND           0x2000

#define BG_TEXT_SIZE_256x256    0x0000
#define BG_TEXT_SIZE_512x256    0x4000
#define BG_TEXT_SIZE_256x512    0x8000
#define BG_TEXT_SIZE_512x512    0xC000

#define BG_ROT_SIZE_128x128     0x0000
#define BG_ROT_SIZE_256x256     0x4000
#define BG_ROT_SIZE_512x512     0x8000
#define BG_ROT_SIZE_1024x1024   0xC000

#define CHAR_BASE_BLOCK(n)      (n<<2)
#define SCREEN_BASE_BLOCK(n)    (n<<8)

/* For determining tile and map memory locations */
#define CharBaseBlockAddr(n)    (void*)((n<<14)+0x6000000)
#define ScreenBaseBlockAddr(n)  (void*)((n<<11)+0x6000000)

#endif
