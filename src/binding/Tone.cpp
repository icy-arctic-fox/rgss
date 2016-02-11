#include "common.h"

VALUE toneClass_allocate (VALUE klass)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setValues (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setFromTone (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE toneClass_initDefault (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_set (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_getRed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setRed (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE toneClass_getGreen (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setGreen (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE toneClass_getBlue (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setBlue (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE toneClass_getGray (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_setGray (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE toneClass_toString (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE toneClass_eq (VALUE self, VALUE other)
{
    // TODO
    return Qnil;
}

VALUE toneClass_load (VALUE klass, VALUE marshaled)
{
    // TODO
    return Qnil;
}

VALUE toneClass_dump (VALUE self, VALUE level)
{
    // TODO
    return Qnil;
}

void initToneClass ()
{
    VALUE toneClass = rb_define_class("Tone", rb_cObject);
    rb_define_alloc_func(toneClass, toneClass_allocate);

    rb_define_method(toneClass, "initialize", RB_FUNC(toneClass_init),     -1);
    rb_define_method(toneClass, "set",        RB_FUNC(toneClass_set),      -1);
    rb_define_method(toneClass, "red",        RB_FUNC(toneClass_getRed),    0);
    rb_define_method(toneClass, "red=",       RB_FUNC(toneClass_setRed),    1);
    rb_define_method(toneClass, "green",      RB_FUNC(toneClass_getGreen),  0);
    rb_define_method(toneClass, "green=",     RB_FUNC(toneClass_setGreen),  1);
    rb_define_method(toneClass, "blue",       RB_FUNC(toneClass_getBlue),   0);
    rb_define_method(toneClass, "blue=",      RB_FUNC(toneClass_setBlue),   1);
    rb_define_method(toneClass, "gray",       RB_FUNC(toneClass_getGray),   0);
    rb_define_method(toneClass, "gray=",      RB_FUNC(toneClass_setGray),   1);
    rb_define_method(toneClass, "to_s",       RB_FUNC(toneClass_toString),  0);
    rb_define_method(toneClass, "==",         RB_FUNC(toneClass_eq),        1);

    rb_define_singleton_method(toneClass, "_load", RB_FUNC(toneClass_load), 1);
    rb_define_method(toneClass, "_dump", RB_FUNC(toneClass_dump), 1);
}
