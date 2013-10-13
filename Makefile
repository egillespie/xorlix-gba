# ------------------------------------------
# Generic Makefile for a GBA project
# -------------------------------------------

PROJNAME = Xorlix

# -------------------------------------------
# Define some directories
# -------------------------------------------
DEVKIT  = C:/Development/GBA/devkitadv
SRCDIR  = .

CMPDIR  = $(DEVKIT)/bin

LIBDIR1 = $(DEVKIT)/lib/gcc-lib/arm-agb-elf/3.0.2/interwork
LIBDIR2 = $(DEVKIT)/arm-agb-elf/lib/interwork
LIBDIRS = -L$(LIBDIR1) -L$(LIBDIR2)

INCDIR1 = $(DEVKIT)/lib/gcc-lib/arm-agb-elf/3.0.2/include
INCDIR2 = $(DEVKIT)/arm-agb-elf/include
INCDIRS = -I$(SRCDIR) -I$(INCDIR1) -I$(INCDIR2)

GFXDIR = $(SRCDIR)/graphics
SPRDIR = $(GFXDIR)/sprites
TILEDIR = $(GFXDIR)/tiles
PALDIR = $(GFXDIR)/palettes

# -------------------------------------------
# Define some of the tools we may use
# -------------------------------------------

LD      = $(CMPDIR)/ld
CC      = $(CMPDIR)/gcc
AS      = $(CMPDIR)/as
RM      = $(CMPDIR)/rm -f

OBJCOPY = $(CMPDIR)/objcopy
GBAFIX  = $(CMPDIR)/gbafix

GFX2GBA = $(CMPDIR)/gfx2gba
PAL2SRC = $(CMPDIR)/pal2src

EMULATE = C:/Development/GBA/Mappy/mappy.exe

# -------------------------------------------
# Define the flags for the compilers
# -------------------------------------------
CFLAGS  = $(INCDIRS) -c -O3 -Wall
SFLAGS  = $(INCDIRS)
LDFLAGS = $(LIBDIRS) -T lnkscript -lc

# -------------------------------------------
# Define the list(s) of all files needed
# -------------------------------------------
O_FILES_RM =	crt0.o			\
		vidfuncs.o		\
		init.o			\
		main.o			\
		globals.o		\
		bg16.map.o		\
		bg16.raw.o		\
		bgpal.o			\
		ball16.raw.o		\
		ballpal.o		\
		board.o			\
		cursor16.raw.o		\
		cursorpal.o		\
		cursor.o		\
		game.o			\
		boardpal.o		\
		board16.map.o		\
		board16.raw.o		\
		text.o

O_FILES =	$(O_FILES_RM)	\
		crtbegin.o	\
		crtend.o

# -------------------------------------------
# Object targets/dependencies
# -------------------------------------------
all : $(PROJNAME).gba

%.gba : %.elf
	$(OBJCOPY) -v -O binary $< $@
	$(GBAFIX) -t$(PROJNAME) $@

$(PROJNAME).elf : lnkscript $(O_FILES)
	$(LD) -o$@ $(O_FILES) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $< 

%.o : %.s
	$(AS) $(SFLAGS) -o$@ $<

%.o : %.S
	$(AS) $(SFLAGS) -o$@ $<

# -------------------------------------------
# Miscellaneous targets
# -------------------------------------------

clean :
	$(RM) $(SPR_FILES) $(PAL_FILES) $(TILE_FILES)
	$(RM) $(PROJNAME).gba $(PROJNAME).elf
	$(RM) $(O_FILES_RM)

test : $(PROJNAME).gba
	$(EMULATE) $(PROJNAME).gba

#graphics :
