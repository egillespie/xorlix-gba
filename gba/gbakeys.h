/* Game Boy button flags and addresses */

#ifndef GBA_KEYS_H
#define GBA_KEYS_H

#include <gba/gbatypes.h>

#define KEY_A        0x001
#define KEY_B        0x002
#define KEY_SELECT   0x004
#define KEY_START    0x008
#define KEY_RIGHT    0x010
#define KEY_LEFT     0x020
#define KEY_UP       0x040
#define KEY_DOWN     0x080
#define KEY_R        0x100
#define KEY_L        0x200
#define KEY_ANY      0x3ff

#define KEYS         *(volatile u16*)0x04000130

#define readKeys()   (~KEYS)
#define keyDown(k)   (~KEYS & (k))

#endif
