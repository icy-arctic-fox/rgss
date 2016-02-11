#include "common.h"

VALUE tilemapClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_update (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getBitmaps (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getMapData (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getFlashData (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getFlags (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getViewport (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_setViewport (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_setVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getOX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_setOX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_getOY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tilemapClass_setOY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

void initTilemapClass ()
{
    VALUE tilemapClass = rb_define_class("Tilemap", rb_cObject);

    rb_define_method(tilemapClass, "initialize", RB_FUNC(tilemapClass_init),         -1);
    rb_define_method(tilemapClass, "dispose",    RB_FUNC(tilemapClass_dispose),       0);
    rb_define_method(tilemapClass, "disposed?",  RB_FUNC(tilemapClass_isDisposed),    0);
    rb_define_method(tilemapClass, "update",     RB_FUNC(tilemapClass_update),        0);
    rb_define_method(tilemapClass, "bitmaps",    RB_FUNC(tilemapClass_getBitmaps),    0);
    rb_define_method(tilemapClass, "map_data",   RB_FUNC(tilemapClass_getMapData),    0);
    rb_define_method(tilemapClass, "flash_data", RB_FUNC(tilemapClass_getFlashData),  0);
    rb_define_method(tilemapClass, "flags",      RB_FUNC(tilemapClass_getFlags),      0);
    rb_define_method(tilemapClass, "viewport",   RB_FUNC(tilemapClass_getViewport),   0);
    rb_define_method(tilemapClass, "viewport=",  RB_FUNC(tilemapClass_setViewport),   1);
    rb_define_method(tilemapClass, "visible",    RB_FUNC(tilemapClass_getVisible),    0);
    rb_define_method(tilemapClass, "visible=",   RB_FUNC(tilemapClass_setVisible),    1);
    rb_define_method(tilemapClass, "ox",         RB_FUNC(tilemapClass_getOX),         0);
    rb_define_method(tilemapClass, "ox=",        RB_FUNC(tilemapClass_setOX),         1);
    rb_define_method(tilemapClass, "oy",         RB_FUNC(tilemapClass_getOY),         0);
    rb_define_method(tilemapClass, "oy=",        RB_FUNC(tilemapClass_setOY),         1);
}
