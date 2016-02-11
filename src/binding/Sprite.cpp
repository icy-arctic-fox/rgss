#include "common.h"

VALUE spriteClass_init (int argc, VALUE *argv, VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_dispose (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_isDisposed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_flash (VALUE self, VALUE color, VALUE duration)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_update (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getWidth (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getHeight (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getBitmap (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setBitmap (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getSrcRect (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setSrcRect (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getViewport (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setViewport (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getVisible (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setVisible (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getZ (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setZ (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getOX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setOX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getOY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setOY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getZoomX (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setZoomX (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getZoomY (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setZoomY (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getAngle (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setAngle (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getWaveAmp (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setWaveAmp (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getWaveLength (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setWaveLength (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getWaveSpeed (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setWaveSpeed (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getWavePhase (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setWavePhase (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getMirror (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setMirror (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getBushDepth (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setBushDepth (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getBushOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setBushOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getOpacity (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setOpacity (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getBlendType (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setBlendType (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getColor (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setColor (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_getTone (VALUE self)
{
    // TODO
    return Qnil;
}

VALUE spriteClass_setTone (VALUE self, VALUE value)
{
    // TODO
    return Qnil;
}

void initSpriteClass ()
{
    VALUE spriteClass = rb_define_class("Sprite", rb_cObject);

    rb_define_method(spriteClass, "initialize",    RB_FUNC(spriteClass_init),           -1);
    rb_define_method(spriteClass, "dispose",       RB_FUNC(spriteClass_dispose),         0);
    rb_define_method(spriteClass, "disposed?",     RB_FUNC(spriteClass_isDisposed),      0);
    rb_define_method(spriteClass, "flash",         RB_FUNC(spriteClass_flash),           2);
    rb_define_method(spriteClass, "update",        RB_FUNC(spriteClass_update),          0);
    rb_define_method(spriteClass, "width",         RB_FUNC(spriteClass_getWidth),        0);
    rb_define_method(spriteClass, "height",        RB_FUNC(spriteClass_getHeight),       0);
    rb_define_method(spriteClass, "bitmap",        RB_FUNC(spriteClass_getBitmap),       0);
    rb_define_method(spriteClass, "bitmap=",       RB_FUNC(spriteClass_setBitmap),       1);
    rb_define_method(spriteClass, "src_rect",      RB_FUNC(spriteClass_getSrcRect),      0);
    rb_define_method(spriteClass, "src_rect=",     RB_FUNC(spriteClass_setSrcRect),      1);
    rb_define_method(spriteClass, "viewport",      RB_FUNC(spriteClass_getViewport),     0);
    rb_define_method(spriteClass, "viewport=",     RB_FUNC(spriteClass_setViewport),     1);
    rb_define_method(spriteClass, "visible",       RB_FUNC(spriteClass_getVisible),      0);
    rb_define_method(spriteClass, "visible=",      RB_FUNC(spriteClass_setVisible),      1);
    rb_define_method(spriteClass, "x",             RB_FUNC(spriteClass_getX),            0);
    rb_define_method(spriteClass, "x=",            RB_FUNC(spriteClass_setX),            1);
    rb_define_method(spriteClass, "y",             RB_FUNC(spriteClass_getY),            0);
    rb_define_method(spriteClass, "y=",            RB_FUNC(spriteClass_setY),            1);
    rb_define_method(spriteClass, "z",             RB_FUNC(spriteClass_getZ),            0);
    rb_define_method(spriteClass, "z=",            RB_FUNC(spriteClass_setZ),            1);
    rb_define_method(spriteClass, "ox",            RB_FUNC(spriteClass_getOX),           0);
    rb_define_method(spriteClass, "ox=",           RB_FUNC(spriteClass_setOX),           1);
    rb_define_method(spriteClass, "oy",            RB_FUNC(spriteClass_getOY),           0);
    rb_define_method(spriteClass, "oy=",           RB_FUNC(spriteClass_setOY),           1);
    rb_define_method(spriteClass, "zoom_x",        RB_FUNC(spriteClass_getZoomX),        0);
    rb_define_method(spriteClass, "zoom_x=",       RB_FUNC(spriteClass_setZoomX),        1);
    rb_define_method(spriteClass, "zoom_y",        RB_FUNC(spriteClass_getZoomY),        0);
    rb_define_method(spriteClass, "zoom_y=",       RB_FUNC(spriteClass_setZoomY),        1);
    rb_define_method(spriteClass, "angle",         RB_FUNC(spriteClass_getAngle),        0);
    rb_define_method(spriteClass, "angle=",        RB_FUNC(spriteClass_setAngle),        1);
    rb_define_method(spriteClass, "wave_amp",      RB_FUNC(spriteClass_getWaveAmp),      0);
    rb_define_method(spriteClass, "wave_amp=",     RB_FUNC(spriteClass_setWaveAmp),      1);
    rb_define_method(spriteClass, "wave_length",   RB_FUNC(spriteClass_getWaveLength),   0);
    rb_define_method(spriteClass, "wave_length=",  RB_FUNC(spriteClass_setWaveLength),   1);
    rb_define_method(spriteClass, "wave_speed",    RB_FUNC(spriteClass_getWaveSpeed),    0);
    rb_define_method(spriteClass, "wave_speed=",   RB_FUNC(spriteClass_setWaveSpeed),    1);
    rb_define_method(spriteClass, "wave_phase",    RB_FUNC(spriteClass_getWavePhase),    0);
    rb_define_method(spriteClass, "wave_phase=",   RB_FUNC(spriteClass_setWavePhase),    1);
    rb_define_method(spriteClass, "mirror",        RB_FUNC(spriteClass_getMirror),       0);
    rb_define_method(spriteClass, "mirror=",       RB_FUNC(spriteClass_setMirror),       1);
    rb_define_method(spriteClass, "bush_depth",    RB_FUNC(spriteClass_getBushDepth),    0);
    rb_define_method(spriteClass, "bush_depth=",   RB_FUNC(spriteClass_setBushDepth),    1);
    rb_define_method(spriteClass, "bush_opacity",  RB_FUNC(spriteClass_getBushOpacity),  0);
    rb_define_method(spriteClass, "bush_opacity=", RB_FUNC(spriteClass_setBushOpacity),  1);
    rb_define_method(spriteClass, "opacity",       RB_FUNC(spriteClass_getOpacity),      0);
    rb_define_method(spriteClass, "opacity=",      RB_FUNC(spriteClass_setOpacity),      1);
    rb_define_method(spriteClass, "blend_type",    RB_FUNC(spriteClass_getBlendType),    0);
    rb_define_method(spriteClass, "blend_type=",   RB_FUNC(spriteClass_setBlendType),    1);
    rb_define_method(spriteClass, "color",         RB_FUNC(spriteClass_getColor),        0);
    rb_define_method(spriteClass, "color=",        RB_FUNC(spriteClass_setColor),        1);
    rb_define_method(spriteClass, "tone",          RB_FUNC(spriteClass_getTone),         0);
    rb_define_method(spriteClass, "tone=",         RB_FUNC(spriteClass_setTone),         1);
}
