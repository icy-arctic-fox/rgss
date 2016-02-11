#include "common.h"

VALUE fontClass_allocate (VALUE klass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getName (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setName (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getSize (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setSize (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getBold (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setBold (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getItalic (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setItalic (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getOutline (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setOutline (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getShadow (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setShadow (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getColor (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setColor (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getOutColor (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setOutColor (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultName (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultName (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultSize (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultSize (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultBold (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultBold (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultItalic (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultItalic (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultShadow (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultShadow (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultOutline (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultOutline (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultColor (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultColor (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_getDefaultOutColor (VALUE fontClass)
{
    // TODO
    return Qnil;
}

VALUE fontClass_setDefaultOutColor (VALUE fontClass, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE fontClass_exist (VALUE fontClass, VALUE name)
{
    // TODO
    return Qnil;
}

void initFontClass ()
{
    VALUE fontClass = rb_define_class("Font", rb_cObject);
    rb_define_alloc_func(fontClass, fontClass_allocate);

    rb_define_method(fontClass, "initialize", RB_FUNC(fontClass_init),        -1);
    rb_define_method(fontClass, "name",       RB_FUNC(fontClass_getName),      0);
    rb_define_method(fontClass, "name=",      RB_FUNC(fontClass_setName),      1);
    rb_define_method(fontClass, "size",       RB_FUNC(fontClass_getSize),      0);
    rb_define_method(fontClass, "size=",      RB_FUNC(fontClass_setSize),      1);
    rb_define_method(fontClass, "bold",       RB_FUNC(fontClass_getBold),      0);
    rb_define_method(fontClass, "bold=",      RB_FUNC(fontClass_setBold),      1);
    rb_define_method(fontClass, "italic",     RB_FUNC(fontClass_getItalic),    0);
    rb_define_method(fontClass, "italic=",    RB_FUNC(fontClass_setItalic),    1);
    rb_define_method(fontClass, "outline",    RB_FUNC(fontClass_getOutline),   0);
    rb_define_method(fontClass, "outline=",   RB_FUNC(fontClass_setOutline),   1);
    rb_define_method(fontClass, "shadow",     RB_FUNC(fontClass_getShadow),    0);
    rb_define_method(fontClass, "shadow=",    RB_FUNC(fontClass_setShadow),    1);
    rb_define_method(fontClass, "color",      RB_FUNC(fontClass_getColor),     0);
    rb_define_method(fontClass, "color=",     RB_FUNC(fontClass_setColor),     1);
    rb_define_method(fontClass, "out_color",  RB_FUNC(fontClass_getOutColor),  0);
    rb_define_method(fontClass, "out_color=", RB_FUNC(fontClass_setOutColor),  1);

    rb_define_singleton_method(fontClass, "default_name",       RB_FUNC(fontClass_getDefaultName),     0);
    rb_define_singleton_method(fontClass, "default_name=",      RB_FUNC(fontClass_setDefaultName),     1);
    rb_define_singleton_method(fontClass, "default_size",       RB_FUNC(fontClass_getDefaultSize),     0);
    rb_define_singleton_method(fontClass, "default_size=",      RB_FUNC(fontClass_setDefaultSize),     1);
    rb_define_singleton_method(fontClass, "default_bold",       RB_FUNC(fontClass_getDefaultBold),     0);
    rb_define_singleton_method(fontClass, "default_bold=",      RB_FUNC(fontClass_setDefaultBold),     1);
    rb_define_singleton_method(fontClass, "default_italic",     RB_FUNC(fontClass_getDefaultItalic),   0);
    rb_define_singleton_method(fontClass, "default_italic=",    RB_FUNC(fontClass_setDefaultItalic),   1);
    rb_define_singleton_method(fontClass, "default_outline",    RB_FUNC(fontClass_getDefaultOutline),  0);
    rb_define_singleton_method(fontClass, "default_outline=",   RB_FUNC(fontClass_setDefaultOutline),  1);
    rb_define_singleton_method(fontClass, "default_shadow",     RB_FUNC(fontClass_getDefaultShadow),   0);
    rb_define_singleton_method(fontClass, "default_shadow=",    RB_FUNC(fontClass_setDefaultShadow),   1);
    rb_define_singleton_method(fontClass, "default_color",      RB_FUNC(fontClass_getDefaultColor),    0);
    rb_define_singleton_method(fontClass, "default_color=",     RB_FUNC(fontClass_setDefaultColor),    1);
    rb_define_singleton_method(fontClass, "default_out_color",  RB_FUNC(fontClass_getDefaultOutColor), 0);
    rb_define_singleton_method(fontClass, "default_out_color=", RB_FUNC(fontClass_setDefaultOutColor), 1);
    rb_define_singleton_method(fontClass, "exist?",             RB_FUNC(fontClass_exist),              1);
}
