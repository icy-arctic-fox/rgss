#include "common.h"

// Prototypes for initialization functions.
VALUE initAudioModule ();
VALUE initGraphicsModule ();
VALUE initInputModule ();
VALUE initBitmapClass ();
VALUE initColorClass ();
VALUE initFontClass ();
VALUE initPlaneClass ();
VALUE initRectClass ();
VALUE initTableClass ();
VALUE initTilemapClass ();
VALUE initToneClass ();
VALUE initViewportClass ();
VALUE initSpriteClass ();
VALUE initWindowClass ();
void initFunctions ();

extern "C" {

VALUE initRGSSErrorClass ();
VALUE initRGSSResetClass ();

VALUE audioModule, graphicsModule, inputModule,
        bitmapClass, colorClass, fontClass, planeClass,
        rectClass, tableClass, tilemapClass, toneClass,
        viewportClass, spriteClass, windowClass,
        rgssErrorClass, rgssResetClass;

// Entry point for Ruby.
void Init_rgss ()
{
    // Initialize modules.
    audioModule = initAudioModule();
    graphicsModule = initGraphicsModule();
    inputModule = initInputModule();

    // Initialize classes.
    bitmapClass   = initBitmapClass();
    colorClass    = initColorClass();
    fontClass     = initFontClass();
    planeClass    = initPlaneClass();
    rectClass     = initRectClass();
    spriteClass   = initSpriteClass();
    tableClass    = initTableClass();
    tilemapClass  = initTilemapClass();
    toneClass     = initToneClass();
    viewportClass = initViewportClass();
    windowClass   = initWindowClass();

    // Initialize exceptions.
    rgssErrorClass = initRGSSErrorClass();
    rgssResetClass = initRGSSResetClass();

    // Initialize top-level functions.
    initFunctions();
}

}
