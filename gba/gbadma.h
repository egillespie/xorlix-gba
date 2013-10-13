/* GBA DMA access values */

#ifndef GBA_DMA_H
#define GBA_DMA_H

#include <gba/gbatypes.h>

/** DMA Registers **/

#define REG_DMA0SAD    *(u32*)0x40000B0      /* DMA0 Source Address */
#define REG_DMA0SAD_L  *(u16*)0x40000B0      /* DMA0 Source Address Low Value */
#define REG_DMA0SAD_H  *(u16*)0x40000B2      /* DMA0 Source Address High Value */
#define REG_DMA0DAD    *(u32*)0x40000B4      /* DMA0 Destination Address */
#define REG_DMA0DAD_L  *(u16*)0x40000B4      /* DMA0 Destination Address Low Value */
#define REG_DMA0DAD_H  *(u16*)0x40000B6      /* DMA0 Destination Address High Value */
#define REG_DMA0CNT    *(u32*)0x40000B8      /* DMA0 Control (Amount) */
#define REG_DMA0CNT_L  *(u16*)0x40000B8      /* DMA0 Control Low Value */
#define REG_DMA0CNT_H  *(u16*)0x40000BA      /* DMA0 Control High Value */
#define REG_DMA1SAD    *(u32*)0x40000BC      /* DMA1 Source Address */
#define REG_DMA1SAD_L  *(u16*)0x40000BC      /* DMA1 Source Address Low Value */
#define REG_DMA1SAD_H  *(u16*)0x40000BE      /* DMA1 Source Address High Value */
#define REG_DMA1DAD    *(u32*)0x40000C0      /* DMA1 Desination Address */
#define REG_DMA1DAD_L  *(u16*)0x40000C0      /* DMA1 Destination Address Low Value */
#define REG_DMA1DAD_H  *(u16*)0x40000C2      /* DMA1 Destination Address High Value */
#define REG_DMA1CNT    *(u32*)0x40000C4      /* DMA1 Control (Amount) */
#define REG_DMA1CNT_L  *(u16*)0x40000C4      /* DMA1 Control Low Value */
#define REG_DMA1CNT_H  *(u16*)0x40000C6      /* DMA1 Control High Value */
#define REG_DMA2SAD    *(u32*)0x40000C8      /* DMA2 Source Address */
#define REG_DMA2SAD_L  *(u16*)0x40000C8      /* DMA2 Source Address Low Value */
#define REG_DMA2SAD_H  *(u16*)0x40000CA      /* DMA2 Source Address High Value */
#define REG_DMA2DAD    *(u32*)0x40000CC      /* DMA2 Destination Address */
#define REG_DMA2DAD_L  *(u16*)0x40000CC      /* DMA2 Destination Address Low Value */
#define REG_DMA2DAD_H  *(u16*)0x40000CE      /* DMA2 Destination Address High Value */
#define REG_DMA2CNT    *(u32*)0x40000D0      /* DMA2 Control (Amount) */
#define REG_DMA2CNT_L  *(u16*)0x40000D0      /* DMA2 Control Low Value */
#define REG_DMA2CNT_H  *(u16*)0x40000D2      /* DMA2 Control High Value */
#define REG_DMA3SAD    *(u32*)0x40000D4      /* DMA3 Source Address */
#define REG_DMA3SAD_L  *(u16*)0x40000D4      /* DMA3 Source Address Low Value */
#define REG_DMA3SAD_H  *(u16*)0x40000D6      /* DMA3 Source Address High Value */
#define REG_DMA3DAD    *(u32*)0x40000D8      /* DMA3 Destination Address */
#define REG_DMA3DAD_L  *(u16*)0x40000D8      /* DMA3 Destination Address Low Value */
#define REG_DMA3DAD_H  *(u16*)0x40000DA      /* DMA3 Destination Address High Value */
#define REG_DMA3CNT    *(u32*)0x40000DC      /* DMA3 Control (Amount) */
#define REG_DMA3CNT_L  *(u16*)0x40000DC      /* DMA3 Control Low Value */
#define REG_DMA3CNT_H  *(u16*)0x40000DE      /* DMA3 Control High Value */

/** DMA Flags **/

#define DMA_ENABLE                  0x80000000
#define DMA_INTERUPT_ENABLE         0x40000000
#define DMA_TIMING_IMMEDIATE        0x00000000
#define DMA_TIMING_VBLANK           0x10000000
#define DMA_TIMING_HBLANK           0x20000000
#define DMA_TIMING_SYNC_TO_DISPLAY  0x30000000
#define DMA_16                      0x00000000
#define DMA_32                      0x04000000
#define DMA_REPEAT                  0x02000000
#define DMA_SOURCE_INCREMENT        0x00000000
#define DMA_SOURCE_DECREMENT        0x00800000
#define DMA_SOURCE_FIXED            0x01000000
#define DMA_DEST_INCREMENT          0x00000000
#define DMA_DEST_DECREMENT          0x00200000
#define DMA_DEST_FIXED              0x00400000
#define DMA_DEST_RELOAD             0x00600000

#define DMA_32NOW                   DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_32 
#define DMA_16NOW                   DMA_ENABLE | DMA_TIMING_IMMEDIATE | DMA_16 

#define DMA_32VBLANK                DMA_ENABLE | DMA_TIMING_VBLANK | DMA_32 
#define DMA_16VBLANK                DMA_ENABLE | DMA_TIMING_VBLANK | DMA_16 

#endif
