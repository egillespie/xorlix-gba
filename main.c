#include <gba/gba.h>

/* Include all of our sprites/palettes */
#include "globals.h"
#include "init.h"

int AgbMain(void) {
   Init();

   while (1) {
      /* Do any events caused by key presses */
      HandleKeys();

      /* Draw the pegs and cursor */
      WaitForSync(160);
      CopyOAM();
      WaitForSync(80);
      AdjustOAM();

      /* Increment the frame counters */
      curFrame++;
      frameWait++;

      /* Animate the cursor */
      if (curFrame % CURSOR_STEP == 0)
	 SetCursorFrame(cursor.frame + 1);

      /* Animate the board (fade in/out effects) */
      if (curFrame % BOARD_STEP == 0)
	 UpdateBoard();

      /* Reset the frame counter if necessary */
      if (curFrame >= MAX_FRAMES)
	 curFrame = 0;
   }

   return 0;
}
