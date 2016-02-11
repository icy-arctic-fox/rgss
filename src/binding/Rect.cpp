#include "common.h"

VALUE rectClass_allocate (VALUE klass)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setValues (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setFromRect (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE rectClass_initDefault (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_set (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_empty (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_getX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE rectClass_getY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE rectClass_getWidth (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setWidth (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE rectClass_getHeight (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_setHeight (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE rectClass_toString (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE rectClass_eq (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE rectClass_dump (VALUE self, VALUE depth)
{
    // TODO
    return Qnil;
}

VALUE rectClass_load (VALUE klass, VALUE marshaled)
{
    // TODO
    return Qnil;
}

void initRectClass ()
{
    VALUE rectClass = rb_define_class("Rect", rb_cObject);
    rb_define_alloc_func(rectClass, rectClass_allocate);

    rb_define_method(rectClass, "initialize", RB_FUNC(rectClass_init),      -1);
    rb_define_method(rectClass, "set",        RB_FUNC(rectClass_set),       -1);
    rb_define_method(rectClass, "empty",      RB_FUNC(rectClass_empty),      0);
    rb_define_method(rectClass, "x",          RB_FUNC(rectClass_getX),       0);
    rb_define_method(rectClass, "x=",         RB_FUNC(rectClass_setX),       1);
    rb_define_method(rectClass, "y",          RB_FUNC(rectClass_getY),       0);
    rb_define_method(rectClass, "y=",         RB_FUNC(rectClass_setY),       1);
    rb_define_method(rectClass, "width",      RB_FUNC(rectClass_getWidth),   0);
    rb_define_method(rectClass, "width=",     RB_FUNC(rectClass_setWidth),   1);
    rb_define_method(rectClass, "height",     RB_FUNC(rectClass_getHeight),  0);
    rb_define_method(rectClass, "height=",    RB_FUNC(rectClass_setHeight),  1);
    rb_define_method(rectClass, "to_s",       RB_FUNC(rectClass_toString),   0);
    rb_define_method(rectClass, "==",         RB_FUNC(rectClass_eq),         1);

    rb_define_method(rectClass, "_dump", RB_FUNC(rectClass_dump), 1);
    rb_define_singleton_method(rectClass, "_load", RB_FUNC(rectClass_load), 1);
}
