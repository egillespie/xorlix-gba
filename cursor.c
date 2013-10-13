#include <gba/gba.h>

#include "globals.h"
#include "cursor.h"
#include "board.h"

void InitCursor(void) {
   EnableCursor(TRUE);
   SetCursorLocation((BOARD_WIDTH >> 1) - 1, (BOARD_HEIGHT >> 1) - 1);
}

void SetCursorLocation(short nx, short ny) {
   /* Check if we're at a frame where we can change */
   if (!CanChange())
      return;

   /* Make sure the cursor's enabled */
   if (!cursor.enabled)
      return;

   /* Clamp/wrap-around the cursor coordinates */
   if (nx < 0)
      nx = BOARD_WIDTH - 1;
   if (nx >= BOARD_WIDTH)
      nx = 0;
   if (ny < 0)
      ny = BOARD_HEIGHT - 1;
   if (ny >= BOARD_HEIGHT)
      ny = 0;

   /* Set cursor's new board coordinates */
   cursor.x = nx;
   cursor.y = ny;

   /* Compute the actual screen coordinates */
   cursor.sprite.attrib0 = OBJ_COLOR_16 | OBJ_SQUARE | (11 * ny + 26);
   cursor.sprite.attrib1 = OBJ_SIZE_16 | (11 * nx + 40);
}

void SetCursorFrame(u8 f) {
   if (f >= 5)
      f = 1;
   if (!cursor.enabled)
      f = 0;

   cursor.frame = f;
   cursor.sprite.attrib2 = OBJ_PALETTE(1) | ((f << 2) + 11);
}

void EnableCursor(u8 enable) {
   if (CanChange()) {
      SetCursorFrame(enable);
      cursor.enabled = enable;
   }
}
