#include "common.h"

// Prototypes for initialization functions.
void initAudioModule ();
void initGraphicsModule ();
void initInputModule ();
void initBitmapClass ();
void initColorClass ();
void initFontClass ();
void initPlaneClass ();
void initRectClass ();
void initTableClass ();
void initTilemapClass ();
void initToneClass ();
void initViewportClass ();
void initSpriteClass ();
void initWindowClass ();
void initFunctions ();

extern "C" {

void initRGSSErrorClass ();
void initRGSSResetClass ();

// Entry point for Ruby.
void Init_rgss ()
{
    initAudioModule();
    initGraphicsModule();
    initInputModule();
    initBitmapClass();
    initColorClass();
    initFontClass();
    initPlaneClass();
    initRectClass();
    initSpriteClass();
    initTableClass();
    initTilemapClass();
    initToneClass();
    initViewportClass();
    initWindowClass();
    initRGSSErrorClass();
    initRGSSResetClass();
    initFunctions();
}

}
