
#----------------------------------------------------------------------------------------
# To build scanner:
#
# dos2unix reformat_scanner.l
# flex -f -oReformatScanner.cpp reformat_scanner.l   // creates ReformatScanner.cpp
#   (ReformatScanner.h already exists)
#
# search for "FlexLexer.h" in ReformatScanner.cpp - replace:
#   #include <FlexLexer.h>
# with
#   #include "../base/platform/FlexLexer.h"
#----------------------------------------------------------------------------------------

include ../makedefs

LIB = $(OPENEAAGLES_LIB_DIR)/liboegraphics.a

OBJS =  \
	BmpTexture.o \
	BitmapFont.o \
	Clip3D.o \
	ColorGradient.o \
	ColorRotary.o \
	Display.o \
	factory.o \
	Field.o \
	Font.o \
	FtglFonts.o \
	Graphic.o \
	Image.o \
	Material.o \
	Page.o \
	Polygon.o \
	Readouts.o \
	ReformatScanner.o \
	Rotators.o \
	Scanline.o \
	Shapes.o \
	StrokeFont.o \
	Texture.o \
	MfdPage.o \
	MapPage.o \
	SymbolLoader.o \
	Translator.o

CPPFLAGS += -I$(FREETYPE2_INC_DIR)

.PHONY: all clean

all: $(LIB)

$(LIB) : $(OBJS)
	ar rs $@ $(OBJS)

clean:
	-rm -f *.o
	-rm -f $(LIB)
