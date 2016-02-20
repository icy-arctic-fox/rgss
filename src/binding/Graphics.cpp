#include "common.h"

VALUE graphicsModule_update (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_wait (VALUE graphicsModule, VALUE duration)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_fadeout (VALUE graphicsModule, VALUE duration)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_fadein (VALUE graphicsModule, VALUE duration)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_freeze (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_transition (int argc, VALUE *argv, VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_snapToBitmap (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_frameReset (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_getWidth (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_getHeight (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_resizeScreen (VALUE graphicsModule, VALUE width, VALUE height)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_playMovie (VALUE graphicsModule, VALUE filename)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_getFrameRate (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_setFrameRate (VALUE graphicsModule, VALUE value)
{
    // TODO
    return value;
}

VALUE graphicsModule_getFrameCount (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_setFrameCount (VALUE graphicsModule, VALUE value)
{
    // TODO
    return value;
}

VALUE graphicsModule_getBrightness (VALUE graphicsModule)
{
    // TODO
    return Qnil;
}

VALUE graphicsModule_setBrightness (VALUE graphicsModule, VALUE value)
{
    // TODO
    return value;
}

VALUE initGraphicsModule ()
{
    VALUE graphicsModule = rb_define_module("Graphics");

    rb_define_singleton_method(graphicsModule, "update",         RB_FUNC(graphicsModule_update),         0);
    rb_define_singleton_method(graphicsModule, "wait",           RB_FUNC(graphicsModule_wait),           1);
    rb_define_singleton_method(graphicsModule, "fadeout",        RB_FUNC(graphicsModule_fadeout),        1);
    rb_define_singleton_method(graphicsModule, "fadein",         RB_FUNC(graphicsModule_fadein),         1);
    rb_define_singleton_method(graphicsModule, "freeze",         RB_FUNC(graphicsModule_freeze),         0);
    rb_define_singleton_method(graphicsModule, "transition",     RB_FUNC(graphicsModule_transition),    -1);
    rb_define_singleton_method(graphicsModule, "snap_to_bitmap", RB_FUNC(graphicsModule_snapToBitmap),   0);
    rb_define_singleton_method(graphicsModule, "frame_reset",    RB_FUNC(graphicsModule_frameReset),     0);
    rb_define_singleton_method(graphicsModule, "width",          RB_FUNC(graphicsModule_getWidth),       0);
    rb_define_singleton_method(graphicsModule, "height",         RB_FUNC(graphicsModule_getHeight),      0);
    rb_define_singleton_method(graphicsModule, "resize_screen",  RB_FUNC(graphicsModule_resizeScreen),   2);
    rb_define_singleton_method(graphicsModule, "play_movie",     RB_FUNC(graphicsModule_playMovie),      1);
    rb_define_singleton_method(graphicsModule, "frame_rate",     RB_FUNC(graphicsModule_getFrameRate),   0);
    rb_define_singleton_method(graphicsModule, "frame_rate=",    RB_FUNC(graphicsModule_setFrameRate),   1);
    rb_define_singleton_method(graphicsModule, "frame_count",    RB_FUNC(graphicsModule_getFrameCount),  0);
    rb_define_singleton_method(graphicsModule, "frame_count=",   RB_FUNC(graphicsModule_setFrameCount),  1);
    rb_define_singleton_method(graphicsModule, "brightness",     RB_FUNC(graphicsModule_getBrightness),  0);
    rb_define_singleton_method(graphicsModule, "brightness=",    RB_FUNC(graphicsModule_setBrightness),  1);

    return graphicsModule;
}
