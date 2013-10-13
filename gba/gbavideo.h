/* Screen mode flags and function macros */

#ifndef GBA_VIDEO_H
#define GBA_VIDEO_H

#include <gba/gbaregs.h>

/** Video Memory Addresses **/

#define FrontBuffer    ((u16*)0x6000000)     /* Front Display Memory (the screen) */
#define BackBuffer     ((u16*)0x600A000)     /* Back Display Memory (for double buffering) */

/** Video Registers **/

#define REG_DISPCNT    *(u32*)0x4000000      /* Display Control (Mode) */
#define REG_DISPCNT_L  *(u16*)0x4000000      
#define REG_DISPCNT_H  *(u16*)0x4000002      
#define REG_DISPSTAT   *(u16*)0x4000004      /* ??? */
#define REG_VCOUNT     *(u16*)0x4000006      /* Vertical Control (Sync) */
#define REG_WIN0H      *(u16*)0x4000040      /* Window 0 X coords (bits 0-7 right, bits 8-16 left) */
#define REG_WIN1H      *(u16*)0x4000042      /* Window 1 X coords (bits 0-7 right, bits 8-16 left) */
#define REG_WIN0V      *(u16*)0x4000044      /* Window 0 Y coords (bits 0-7 bottom, bits 8-16 top) */
#define REG_WIN1V      *(u16*)0x4000046      /* Window 1 Y coords (bits 0-7 bottom, bits 8-16 top) */
#define REG_WININ      *(u16*)0x4000048      /* Inside Window Settings */
#define REG_WINOUT     *(u16*)0x400004A      /* Outside Window Settings */
#define REG_MOSAIC     *(u32*)0x400004C      /* Mosaic Mode */
#define REG_MOSAIC_L   *(u32*)0x400004C      
#define REG_MOSAIC_H   *(u32*)0x400004E      
#define REG_BLDMOD     *(u16*)0x4000050      /* Blend Mode */
#define REG_COLEV      *(u16*)0x4000052      /* ??? */
#define REG_COLEY      *(u16*)0x4000054      /* ??? */

/** Video-related Flags **/
#define MODE0           0x00
#define MODE1           0x01
#define MODE2           0x02
#define MODE3           0x03
#define MODE4           0x04
#define MODE5           0x05

#define BACKBUFFER      0x10
#define H_BLANK_OAM     0x20

#define OBJ_MAP_2D      0x00
#define OBJ_MAP_1D      0x40

#define FORCE_BLANK     0x80

#define BG0_ENABLE      0x0100
#define BG1_ENABLE      0x0200 
#define BG2_ENABLE      0x0400
#define BG3_ENABLE      0x0800
#define OBJ_ENABLE      0x1000 

#define WIN1_ENABLE     0x2000 
#define WIN2_ENABLE     0x4000
#define WINOBJ_ENABLE   0x8000

#define SetVideoMode(mode) REG_DISPCNT = (mode)

#endif
