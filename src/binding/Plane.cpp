#include "common.h"

VALUE planeClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getBitmap (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setBitmap (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getViewport (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setViewport (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getZ (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setZ (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getOX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setOX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getOY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setOY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getZoomX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setZoomX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getZoomY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setZoomY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getBlendType (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setBlendType (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getColor (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setColor (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE planeClass_getTone (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE planeClass_setTone (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

void initPlaneClass ()
{
    VALUE planeClass = rb_define_class("Plane", rb_cObject);

    rb_define_method(planeClass, "initialize",  RB_FUNC(planeClass_init),         -1);
    rb_define_method(planeClass, "dispose",     RB_FUNC(planeClass_dispose),       0);
    rb_define_method(planeClass, "disposed?",   RB_FUNC(planeClass_isDisposed),    0);
    rb_define_method(planeClass, "bitmap",      RB_FUNC(planeClass_getBitmap),     0);
    rb_define_method(planeClass, "bitmap=",     RB_FUNC(planeClass_setBitmap),     1);
    rb_define_method(planeClass, "viewport",    RB_FUNC(planeClass_getViewport),   0);
    rb_define_method(planeClass, "viewport=",   RB_FUNC(planeClass_setViewport),   1);
    rb_define_method(planeClass, "visible",     RB_FUNC(planeClass_getVisible),    0);
    rb_define_method(planeClass, "visible=",    RB_FUNC(planeClass_setVisible),    1);
    rb_define_method(planeClass, "z",           RB_FUNC(planeClass_getZ),          0);
    rb_define_method(planeClass, "z=",          RB_FUNC(planeClass_setZ),          1);
    rb_define_method(planeClass, "ox",          RB_FUNC(planeClass_getOX),         0);
    rb_define_method(planeClass, "ox=",         RB_FUNC(planeClass_setOX),         1);
    rb_define_method(planeClass, "oy",          RB_FUNC(planeClass_getOY),         0);
    rb_define_method(planeClass, "oy=",         RB_FUNC(planeClass_setOY),         1);
    rb_define_method(planeClass, "zoom_x",      RB_FUNC(planeClass_getZoomX),      0);
    rb_define_method(planeClass, "zoom_x=",     RB_FUNC(planeClass_setZoomX),      1);
    rb_define_method(planeClass, "zoom_y",      RB_FUNC(planeClass_getZoomY),      0);
    rb_define_method(planeClass, "zoom_y=",     RB_FUNC(planeClass_setZoomY),      1);
    rb_define_method(planeClass, "opacity",     RB_FUNC(planeClass_getOpacity),    0);
    rb_define_method(planeClass, "opacity=",    RB_FUNC(planeClass_setOpacity),    1);
    rb_define_method(planeClass, "blend_type",  RB_FUNC(planeClass_getBlendType),  0);
    rb_define_method(planeClass, "blend_type=", RB_FUNC(planeClass_setBlendType),  1);
    rb_define_method(planeClass, "color",       RB_FUNC(planeClass_getColor),      0);
    rb_define_method(planeClass, "color=",      RB_FUNC(planeClass_setColor),      1);
    rb_define_method(planeClass, "tone",        RB_FUNC(planeClass_getTone),       0);
    rb_define_method(planeClass, "tone=",       RB_FUNC(planeClass_setTone),       1);
}
