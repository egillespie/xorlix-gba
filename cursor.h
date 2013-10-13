#ifndef CURSOR_H
#define CURSOR_H

#include <gba/gba.h>

/* Cursor structure (track data easier) */
typedef struct {
   /* Whether or not the cursor should be displayed */
   u8 enabled;

   /* The cursor's current board coordinates */
   short x;
   short y;

   /* Which animation frame the cursor is on */
   u8 frame;

   /* GBA Info about the cursor's sprite */
   OAMEntry sprite;
} Cursor, *pCursor;

/* Declare that the cursor exists */
Cursor cursor;

/* Function declarations */
void InitCursor(void);
void SetCursorLocation(short, short);
void SetCursorFrame(u8);
void EnableCursor(u8);

#endif
