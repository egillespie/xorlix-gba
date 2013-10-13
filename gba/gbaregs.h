/* Important GBA registers */

#ifndef GBA_REGS_H
#define GBA_REGS_H

#include <gba/gbatypes.h>

#define GAMEPAK_RAM    ((u8*)0x0E000000)     /* Beginning of battery-saved memory */

#define REG_INTERRUPT  *(u32*)0x3007FFC      /* Interrupt Register */
#define REG_TM0D       *(u16*)0x4000100      /* Timer 1? */
#define REG_TM0CNT     *(u16*)0x4000102      /* Timer 1 Control */
#define REG_TM1D       *(u16*)0x4000104      /* Timer 2? */
#define REG_TM1CNT     *(u16*)0x4000106      /* Timer 2 Control */
#define REG_TM2D       *(u16*)0x4000108      /* Timer 3? */
#define REG_TM2CNT     *(u16*)0x400010A      /* Timer 3 Control */
#define REG_TM3D       *(u16*)0x400010C      /* Timer 4? */
#define REG_TM3CNT     *(u16*)0x400010E      /* Timer 4 Control */
#define REG_SCD0       *(u16*)0x4000120      /* 32-bit Normal Serial Communication Data 0 / Multi-play */
#define REG_SCD1       *(u16*)0x4000122      /* 32-bit Normal Serial Communication Data 1 / Multi-play */
#define REG_SCD2       *(u16*)0x4000124      /* Multi-play Communication Data 2 */
#define REG_SCD3       *(u16*)0x4000126      /* Multi-play Communication Data 3 */
#define REG_SCCNT      *(u32*)0x4000128      /* ??? */
#define REG_SCCNT_L    *(u16*)0x4000128      /* ??? */
#define REG_SCCNT_H    *(u16*)0x400012A      /* ??? */
#define REG_P1         *(u16*)0x4000130      /* Player 1 Input */
#define REG_P1CNT      *(u16*)0x4000132      /* Player 1 Input Interrupt Status */
#define REG_R          *(u16*)0x4000134      /* ??? */
#define REG_HS_CTRL    *(u16*)0x4000140      /* ??? */
#define REG_JOYRE      *(u32*)0x4000150      /* ??? */
#define REG_JOYRE_L    *(u16*)0x4000150      /* ??? */
#define REG_JOYRE_H    *(u16*)0x4000152      /* ??? */
#define REG_JOYTR      *(u32*)0x4000154      /* ??? */
#define REG_JOYTR_L    *(u16*)0x4000154      /* ??? */
#define REG_JOYTR_H    *(u16*)0x4000156      /* ??? */
#define REG_JSTAT      *(u32*)0x4000158      /* ??? */
#define REG_JSTAT_L    *(u16*)0x4000158      /* ??? */
#define REG_JSTAT_H    *(u16*)0x400015A      /* ??? */
#define REG_IE         *(u16*)0x4000200      /* Master Interrupt Enable */
#define REG_IF         *(u16*)0x4000202      /* Interrupt Flags */
#define REG_WSCNT      *(u16*)0x4000204      /* ??? */
#define REG_IME        *(u16*)0x4000208      /* Interrupt Master Enable */
#define REG_PAUSE      *(u16*)0x4000300      /* Pause */

#endif
