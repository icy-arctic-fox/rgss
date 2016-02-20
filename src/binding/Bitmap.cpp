#include "common.h"

VALUE bitmapClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_getWidth (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_getHeight (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_getRect (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_blt (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_stretchBlt (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_fillRect (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_gradientFillRect (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_clear (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_clearRect (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_getPixel (VALUE self, VALUE x, VALUE y)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_setPixel (VALUE self, VALUE x, VALUE y, VALUE color)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_hueChange (VALUE self, VALUE hue)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_blur (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_radialBlur (VALUE self, VALUE angle, VALUE division)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_drawText (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_textSize (VALUE self, VALUE str)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_getFont (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE bitmapClass_setFont (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE initBitmapClass ()
{
    VALUE bitmapClass = rb_define_class("Bitmap", rb_cObject);

    rb_define_method(bitmapClass, "initialize",         RB_FUNC(bitmapClass_init),             -1);
    rb_define_method(bitmapClass, "dispose",            RB_FUNC(bitmapClass_dispose),           0);
    rb_define_method(bitmapClass, "disposed?",          RB_FUNC(bitmapClass_isDisposed),        0);
    rb_define_method(bitmapClass, "width",              RB_FUNC(bitmapClass_getWidth),          0);
    rb_define_method(bitmapClass, "height",             RB_FUNC(bitmapClass_getHeight),         0);
    rb_define_method(bitmapClass, "rect",               RB_FUNC(bitmapClass_getRect),           0);
    rb_define_method(bitmapClass, "blt",                RB_FUNC(bitmapClass_blt),              -1);
    rb_define_method(bitmapClass, "stretch_blt",        RB_FUNC(bitmapClass_stretchBlt),       -1);
    rb_define_method(bitmapClass, "fill_rect",          RB_FUNC(bitmapClass_fillRect),         -1);
    rb_define_method(bitmapClass, "gradient_fill_rect", RB_FUNC(bitmapClass_gradientFillRect), -1);
    rb_define_method(bitmapClass, "clear",              RB_FUNC(bitmapClass_clear),             0);
    rb_define_method(bitmapClass, "clear_rect",         RB_FUNC(bitmapClass_clearRect),        -1);
    rb_define_method(bitmapClass, "get_pixel",          RB_FUNC(bitmapClass_getPixel),          2);
    rb_define_method(bitmapClass, "set_pixel",          RB_FUNC(bitmapClass_setPixel),          3);
    rb_define_method(bitmapClass, "hue_change",         RB_FUNC(bitmapClass_hueChange),         1);
    rb_define_method(bitmapClass, "blur",               RB_FUNC(bitmapClass_blur),              0);
    rb_define_method(bitmapClass, "radial_blur",        RB_FUNC(bitmapClass_radialBlur),        2);
    rb_define_method(bitmapClass, "draw_text",          RB_FUNC(bitmapClass_drawText),         -1);
    rb_define_method(bitmapClass, "text_size",          RB_FUNC(bitmapClass_textSize),          1);
    rb_define_method(bitmapClass, "font",               RB_FUNC(bitmapClass_getFont),           0);
    rb_define_method(bitmapClass, "font=",              RB_FUNC(bitmapClass_setFont),           1);

    return bitmapClass;
}
