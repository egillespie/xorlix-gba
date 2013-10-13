# Xorlix for the Gameboy Advance
*By Erik Gillespie*

## Overview
This game is a basic toggle game (like Lights Out).  When you activate the peg at the location of the cursor, that peg and the pegs above, below, and to the left and right of it will all toggle.  The goal of each level is to turn all of the pegs off in the number of toggles permitted for that level.

Later in the game it's possible to clear a board without using all of the required toggles.  If you do this with enough leftover toggles then you will get bonus toggles for the next level.

That's it!  There's no end to this game, you just try to beat the high score.

## Features
If you are learning GBA development, you'll be able to learn the following from picking apart the source code provided for this game:

* Moving a cursor
* Animation
* Drawing sprites
* Using hackery to draw more sprites than is normally allowed
* Drawing backgrounds
* Changing color palettes for sprites and backgrounds
* Drawing fix-width text
* Saving game state (high score)

## Developer Goodies
The following commands might be useful to understand how graphics are being transformed from bitmaps and palettes to code.

To convert 16 color tile background

    gfx2gba -fsrc -t8 -c16 -b0 -m -mm -P -x graphics/tiles/bg16.bmp

To convert 16 color background palettes

    pal2src -f bgpal.c graphics/palettes/16/bgpal00.pal \
                       graphics/palettes/16/bgpal01.pal \
                       graphics/palettes/16/bgpal02.pal \
                       graphics/palettes/16/bgpal03.pal \
                       graphics/palettes/16/bgpal04.pal \
                       graphics/palettes/16/bgpal05.pal \
                       graphics/palettes/16/bgpal06.pal \
                       graphics/palettes/16/bgpal07.pal \
                       graphics/palettes/16/bgpal08.pal \
                       graphics/palettes/16/bgpal09.pal \
                       graphics/palettes/16/bgpal10.pal \
                       graphics/palettes/16/bgpal11.pal \
                       graphics/palettes/16/bgpal12.pal

To convert 16 color title and board and text backgrounds (also saves palette)

    gfx2gba -fsrc -F -t8 -c16 -b1 -m -mm -pboardpal \
            graphics/tiles/board16.bmp \
            graphics/tiles/txt16.bmp   \
            graphics/tiles/title16.bmp

To convert 16 color ball sprites

    gfx2gba -fsrc -t8 -c16 -b0 -P graphics/sprites/ball16.bmp

To convert 16 color ball palettes

    pal2src -f ballpal.c graphics/palettes/16/ballpal00.pal \
                         graphics/palettes/16/ballpal01.pal \
                         graphics/palettes/16/ballpal02.pal \
                         graphics/palettes/16/ballpal03.pal \
                         graphics/palettes/16/ballpal04.pal \
                         graphics/palettes/16/ballpal05.pal \
                         graphics/palettes/16/ballpal06.pal \
                         graphics/palettes/16/ballpal07.pal \
                         graphics/palettes/16/ballpal08.pal \
                         graphics/palettes/16/ballpal09.pal \
                         graphics/palettes/16/ballpal10.pal \
                         graphics/palettes/16/ballpal11.pal \
                         graphics/palettes/16/ballpal12.pal

To convert 16 color cursor sprites

    gfx2gba -fsrc -t8 -T16 -c16 -b0 -P graphics/sprites/cursor16.bmp

To convert 16 color cursor palette

    pal2src -f cursorpal.c graphics/palettes/16/cursorpal.pal
