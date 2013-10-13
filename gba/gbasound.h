/* Sound flags and functions/macros */

#ifndef GBA_SOUND_H
#define GBA_SOUND_H

/** Sound Registers **/

#define REG_SG10       *(u32*)0x4000060      /* Sound 1 Sweep control */
#define REG_SG10_L     *(u16*)0x4000060      /* Sound 1 Sweep control */
#define REG_SG10_H     *(u16*)0x4000062      /* Sound 1 Length, wave duty, and envelope control */
#define REG_SG11       *(u16*)0x4000064      /* Sound 1 Frequency, reset, and loop control */
#define REG_SG20       *(u16*)0x4000068      /* Sound 2 Length, wave duty, and envelope control */
#define REG_SG21       *(u16*)0x400006C      /* Sound 2 Frequency, reset, and loop control */
#define REG_SG30       *(u32*)0x4000070      /* Sound 3 Enable and wave ram bank control */
#define REG_SG30_L     *(u16*)0x4000070      /* Sound 3 Enable and wave ram bank control */
#define REG_SG30_H     *(u16*)0x4000072      /* Sound 3 Length and output level control */
#define REG_SG31       *(u16*)0x4000074      /* Sound 3 Frequency, reset, and loop control */
#define REG_SG40       *(u16*)0x4000078      /* Sound 4 Length, output level, and envelope control */
#define REG_SG41       *(u16*)0x400007C      /* Sound 4 Noise parameters, reset, and loop control */
#define REG_SGCNT0     *(u32*)0x4000080      /* Sound 1-4 output level and stereo control */
#define REG_SGCNT0_L   *(u16*)0x4000080      /* Sound 1-4 output level and stereo control */
#define REG_SGCNT0_H   *(u16*)0x4000082      /* Direct Sound control and sound 1-4 output ratio */
#define REG_SGCNT1     *(u16*)0x4000084      /* Master sound enable and Sound 1-4 play status */
#define REG_SGBIAS     *(u16*)0x4000088      /* Sound bias and amplitude resolution control */
#define REG_SGWR0      *(u32*)0x4000090      /* Sound 3 samples 0-3 */
#define REG_SGWR0_L    *(u16*)0x4000090      /* Sound 3 samples 0-3 */
#define REG_SGWR0_H    *(u16*)0x4000092      /* Sound 3 samples 4-7 */
#define REG_SGWR1      *(u32*)0x4000094      /* Sound 3 samples 8-11 */
#define REG_SGWR1_L    *(u16*)0x4000094      /* Sound 3 samples 8-11 */
#define REG_SGWR1_H    *(u16*)0x4000096      /* Sound 3 samples 12-15 */
#define REG_SGWR2      *(u32*)0x4000098      /* Sound 3 samples 16-19 */
#define REG_SGWR2_L    *(u16*)0x4000098      /* Sound 3 samples 16-19 */
#define REG_SGWR2_H    *(u16*)0x400009A      /* Sound 3 samples 20-23 */
#define REG_SGWR3      *(u32*)0x400009C      /* Sound 3 samples 24-27 */
#define REG_SGWR3_L    *(u16*)0x400009C      /* Sound 3 samples 24-27 */
#define REG_SGWR3_H    *(u16*)0x400009E      /* Sound 3 samples 28-31 */
#define REG_SGFIF0A    *(u32*)0x40000A0      /* Direct Sound channel A samples 0-1 */
#define REG_SGFIFOA_L  *(u16*)0x40000A0      /* Direct Sound channel A samples 0-1 */
#define REG_SGFIFOA_H  *(u16*)0x40000A2      /* Direct Sound channel A samples 2-3 */
#define REG_SGFIFOB    *(u32*)0x40000A4      /* Direct Sound channel B samples 0-1 */
#define REG_SGFIFOB_L  *(u16*)0x40000A4      /* Direct Sound channel B samples 0-1 */
#define REG_SGFIFOB_H  *(u16*)0x40000A6      /* Direct Sound channel B samples 2-3 */

/** Sound Flags **/

/* Direct Sound Output Control Register Flags (REG_SGCNT0_H) */
#define CHANNEL_RATIO_25        0x00
#define CHANNEL_RATIO_50        0x01
#define CHANNEL_RATIO_100       0x02

#define DSNDA_RATIO_50          0x04
#define DSNDA_RATIO_100         0x00

#define DSNDB_RATIO_50          0x08
#define DSNDB_RATIO_100         0x00

#define DSNDA_OUTPUT_RIGHT      0x0100
#define DSNDA_OUTPUT_LEFT       0x0200
#define DSNDA_OUTPUT_BOTH       0x0300

#define DSNDA_TIMER0            0x0000
#define DSNDA_TIMER1            0x0400

#define DSNDA_FIFO_RESET        0x0800

#define DSNDB_OUTPUT_RIGHT      0x1000
#define DSNDB_OUTPUT_LEFT       0x2000
#define DSNDB_OUTPUT_BOTH       0x3000

#define DSNDB_TIMER0            0x0000
#define DSNDB_TIMER1            0x4000

#define DSNDB_FIFO_RESET        0x8000


#endif
