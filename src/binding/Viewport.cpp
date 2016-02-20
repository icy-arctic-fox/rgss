#include "common.h"

VALUE viewportClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_flash (VALUE self, VALUE color, VALUE duration)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_update (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getRect (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setRect (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getZ (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setZ (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getOX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setOX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getOY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setOY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getColor (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setColor (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_getTone (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE viewportClass_setTone (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE initViewportClass ()
{
    VALUE viewportClass = rb_define_class("Viewport", rb_cObject);

    rb_define_method(viewportClass, "initialize", RB_FUNC(viewportClass_init),       -1);
    rb_define_method(viewportClass, "dispose",    RB_FUNC(viewportClass_dispose),     0);
    rb_define_method(viewportClass, "disposed?",  RB_FUNC(viewportClass_isDisposed),  0);
    rb_define_method(viewportClass, "flash",      RB_FUNC(viewportClass_flash),       2);
    rb_define_method(viewportClass, "update",     RB_FUNC(viewportClass_update),      0);
    rb_define_method(viewportClass, "rect",       RB_FUNC(viewportClass_getRect),     0);
    rb_define_method(viewportClass, "rect=",      RB_FUNC(viewportClass_setRect),     1);
    rb_define_method(viewportClass, "visible",    RB_FUNC(viewportClass_getVisible),  0);
    rb_define_method(viewportClass, "visible=",   RB_FUNC(viewportClass_setVisible),  1);
    rb_define_method(viewportClass, "z",          RB_FUNC(viewportClass_getZ),        0);
    rb_define_method(viewportClass, "z=",         RB_FUNC(viewportClass_setZ),        1);
    rb_define_method(viewportClass, "ox",         RB_FUNC(viewportClass_getOX),       0);
    rb_define_method(viewportClass, "ox=",        RB_FUNC(viewportClass_setOX),       1);
    rb_define_method(viewportClass, "oy",         RB_FUNC(viewportClass_getOY),       0);
    rb_define_method(viewportClass, "oy=",        RB_FUNC(viewportClass_setOY),       1);
    rb_define_method(viewportClass, "color",      RB_FUNC(viewportClass_getColor),    0);
    rb_define_method(viewportClass, "color=",     RB_FUNC(viewportClass_setColor),    1);
    rb_define_method(viewportClass, "tone",       RB_FUNC(viewportClass_getTone),     0);
    rb_define_method(viewportClass, "tone=",      RB_FUNC(viewportClass_setTone),     1);

    return viewportClass;
}
