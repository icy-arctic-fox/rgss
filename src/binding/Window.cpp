#include "common.h"

VALUE windowClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_update (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_move (VALUE self, VALUE x, VALUE y, VALUE width, VALUE height)
{
    // TODO
    return Qnil;
}

VALUE windowClass_isOpen (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_isClosed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getWindowSkin (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setWindowSkin (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getContents (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setContents (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getCursorRect (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setCursorRect (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getViewport (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setViewport (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getActive (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setActive (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getArrowsVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setArrowsVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getPause (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setPause (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getWidth (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setWidth (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getHeight (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setHeight (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getZ (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setZ (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getOX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setOX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getOY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setOY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getPadding (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setPadding (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getPaddingBottom (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setPaddingBottom (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getBackOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setBackOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getContentsOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setContentsOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getOpenness (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setOpenness (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE windowClass_getTone (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE windowClass_setTone (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE initWindowClass ()
{
    VALUE windowClass = rb_define_class("Window", rb_cObject);

    rb_define_method(windowClass, "initialize",        RB_FUNC(windowClass_init),               -1);
    rb_define_method(windowClass, "dispose",           RB_FUNC(windowClass_dispose),             0);
    rb_define_method(windowClass, "disposed?",         RB_FUNC(windowClass_isDisposed),          0);
    rb_define_method(windowClass, "update",            RB_FUNC(windowClass_update),              0);
    rb_define_method(windowClass, "move",              RB_FUNC(windowClass_move),                4);
    rb_define_method(windowClass, "open?",             RB_FUNC(windowClass_isOpen),              0);
    rb_define_method(windowClass, "close?",            RB_FUNC(windowClass_isClosed),            0);
    rb_define_method(windowClass, "windowskin",        RB_FUNC(windowClass_getWindowSkin),       0);
    rb_define_method(windowClass, "windowskin=",       RB_FUNC(windowClass_setWindowSkin),       1);
    rb_define_method(windowClass, "contents",          RB_FUNC(windowClass_getContents),         0);
    rb_define_method(windowClass, "contents=",         RB_FUNC(windowClass_setContents),         1);
    rb_define_method(windowClass, "cursor_rect",       RB_FUNC(windowClass_getCursorRect),       0);
    rb_define_method(windowClass, "cursor_rect=",      RB_FUNC(windowClass_setCursorRect),       1);
    rb_define_method(windowClass, "viewport",          RB_FUNC(windowClass_getViewport),         0);
    rb_define_method(windowClass, "viewport=",         RB_FUNC(windowClass_setViewport),         1);
    rb_define_method(windowClass, "active",            RB_FUNC(windowClass_getActive),           0);
    rb_define_method(windowClass, "active=",           RB_FUNC(windowClass_setActive),           1);
    rb_define_method(windowClass, "visible",           RB_FUNC(windowClass_getVisible),          0);
    rb_define_method(windowClass, "visible=",          RB_FUNC(windowClass_setVisible),          1);
    rb_define_method(windowClass, "arrows_visible",    RB_FUNC(windowClass_getArrowsVisible),    0);
    rb_define_method(windowClass, "arrows_visible=",   RB_FUNC(windowClass_setArrowsVisible),    1);
    rb_define_method(windowClass, "pause",             RB_FUNC(windowClass_getPause),            0);
    rb_define_method(windowClass, "pause=",            RB_FUNC(windowClass_setPause),            1);
    rb_define_method(windowClass, "x",                 RB_FUNC(windowClass_getX),                0);
    rb_define_method(windowClass, "x=",                RB_FUNC(windowClass_setX),                1);
    rb_define_method(windowClass, "y",                 RB_FUNC(windowClass_getY),                0);
    rb_define_method(windowClass, "y=",                RB_FUNC(windowClass_setY),                1);
    rb_define_method(windowClass, "width",             RB_FUNC(windowClass_getWidth),            0);
    rb_define_method(windowClass, "width=",            RB_FUNC(windowClass_setWidth),            1);
    rb_define_method(windowClass, "height",            RB_FUNC(windowClass_getHeight),           0);
    rb_define_method(windowClass, "height=",           RB_FUNC(windowClass_setHeight),           1);
    rb_define_method(windowClass, "z",                 RB_FUNC(windowClass_getZ),                0);
    rb_define_method(windowClass, "z=",                RB_FUNC(windowClass_setZ),                1);
    rb_define_method(windowClass, "ox",                RB_FUNC(windowClass_getOX),               0);
    rb_define_method(windowClass, "ox=",               RB_FUNC(windowClass_setOX),               1);
    rb_define_method(windowClass, "oy",                RB_FUNC(windowClass_getOY),               0);
    rb_define_method(windowClass, "oy=",               RB_FUNC(windowClass_setOY),               1);
    rb_define_method(windowClass, "padding",           RB_FUNC(windowClass_getPadding),          0);
    rb_define_method(windowClass, "padding=",          RB_FUNC(windowClass_setPadding),          1);
    rb_define_method(windowClass, "padding_bottom",    RB_FUNC(windowClass_getPaddingBottom),    0);
    rb_define_method(windowClass, "padding_bottom=",   RB_FUNC(windowClass_setPaddingBottom),    1);
    rb_define_method(windowClass, "opacity",           RB_FUNC(windowClass_getOpacity),          0);
    rb_define_method(windowClass, "opacity=",          RB_FUNC(windowClass_setOpacity),          1);
    rb_define_method(windowClass, "back_opacity",      RB_FUNC(windowClass_getBackOpacity),      0);
    rb_define_method(windowClass, "back_opacity=",     RB_FUNC(windowClass_setBackOpacity),      1);
    rb_define_method(windowClass, "contents_opacity",  RB_FUNC(windowClass_getContentsOpacity),  0);
    rb_define_method(windowClass, "contents_opacity=", RB_FUNC(windowClass_setContentsOpacity),  1);
    rb_define_method(windowClass, "openness",          RB_FUNC(windowClass_getOpenness),         0);
    rb_define_method(windowClass, "openness=",         RB_FUNC(windowClass_setOpenness),         1);
    rb_define_method(windowClass, "tone",              RB_FUNC(windowClass_getTone),             0);
    rb_define_method(windowClass, "tone=",             RB_FUNC(windowClass_setTone),             1);

    return windowClass;
}
