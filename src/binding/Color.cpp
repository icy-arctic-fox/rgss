#include "common.h"

VALUE colorClass_allocate (VALUE klass)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setValues (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setFromColor (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE colorClass_initDefault (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_set (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_getRed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setRed (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE colorClass_getGreen (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setGreen (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE colorClass_getBlue (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setBlue (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE colorClass_getAlpha (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_setAlpha (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE colorClass_toString (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE colorClass_eq (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE colorClass_load (VALUE klass, VALUE marshaled)
{
    // TODO
    return Qnil;
}

VALUE colorClass_dump (VALUE self, VALUE level)
{
    // TODO
    return Qnil;
}

void initColorClass ()
{
    VALUE colorClass = rb_define_class("Color", rb_cObject);
    rb_define_alloc_func(colorClass, colorClass_allocate);

    rb_define_method(colorClass, "initialize", RB_FUNC(colorClass_init),     -1);
    rb_define_method(colorClass, "set",        RB_FUNC(colorClass_set),      -1);
    rb_define_method(colorClass, "red",        RB_FUNC(colorClass_getRed),    0);
    rb_define_method(colorClass, "red=",       RB_FUNC(colorClass_setRed),    1);
    rb_define_method(colorClass, "green",      RB_FUNC(colorClass_getGreen),  0);
    rb_define_method(colorClass, "green=",     RB_FUNC(colorClass_setGreen),  1);
    rb_define_method(colorClass, "blue",       RB_FUNC(colorClass_getBlue),   0);
    rb_define_method(colorClass, "blue=",      RB_FUNC(colorClass_setBlue),   1);
    rb_define_method(colorClass, "alpha",      RB_FUNC(colorClass_getAlpha),  0);
    rb_define_method(colorClass, "alpha=",     RB_FUNC(colorClass_setAlpha),  1);
    rb_define_method(colorClass, "to_s",       RB_FUNC(colorClass_toString),  0);
    rb_define_method(colorClass, "==",         RB_FUNC(colorClass_eq),        1);

    rb_define_singleton_method(colorClass, "_load", RB_FUNC(colorClass_load), 1);
    rb_define_method(colorClass, "_dump", RB_FUNC(colorClass_dump), 1);
}
