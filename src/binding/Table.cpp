#include "common.h"

VALUE tableClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_resize (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_getXSize (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_getYSize (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_getZSize (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_getElement (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_setElement (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE tableClass_load (VALUE tableClass, VALUE marshaled)
{
    // TODO
    return Qnil;
}

VALUE tableClass_dump (VALUE self, VALUE level)
{
    // TODO
    return Qnil;
}

void initTableClass ()
{
    VALUE tableClass = rb_define_class("Table", rb_cObject);

    rb_define_method(tableClass, "initialize", RB_FUNC(tableClass_init),       -1);
    rb_define_method(tableClass, "resize",     RB_FUNC(tableClass_resize),     -1);
    rb_define_method(tableClass, "xsize",      RB_FUNC(tableClass_getXSize),    0);
    rb_define_method(tableClass, "ysize",      RB_FUNC(tableClass_getYSize),    0);
    rb_define_method(tableClass, "zsize",      RB_FUNC(tableClass_getZSize),    0);
    rb_define_method(tableClass, "[]",         RB_FUNC(tableClass_getElement), -1);
    rb_define_method(tableClass, "[]=",        RB_FUNC(tableClass_setElement), -1);

    rb_define_singleton_method(tableClass, "_load", RB_FUNC(tableClass_load), 1);
    rb_define_method(tableClass, "_dump", RB_FUNC(tableClass_dump), 1);
}
