#include "common.h"
#include "Tone.hpp"

VALUE toneClass_allocate (VALUE klass)
{
    RGSS::Tone *tone;
    return Data_Make_Struct(klass, RGSS::Tone, 0, -1, tone);
}

VALUE toneClass_setValues (int argc, VALUE *argv, VALUE self)
{
    VALUE redValue, greenValue, blueValue, grayValue;
    double red, green, blue, gray;

    int count = rb_scan_args(argc, argv, "31", &redValue, &greenValue, &blueValue, &grayValue);
    if(3 == count || 4 == count)
    {
        red   = NUM2DBL(redValue);
        green = NUM2DBL(greenValue);
        blue  = NUM2DBL(blueValue);

        if(3 == count)
            gray = 0;
        else
            gray = NUM2DBL(grayValue);

        RGSS::Tone *tone;
        Data_Get_Struct(self, RGSS::Tone, tone);
        tone->set(red, green, blue, gray);
    }

    return self;
}

VALUE toneClass_setFromTone (VALUE self, VALUE other)
{
    RGSS::Tone *tone, *otherTone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    Data_Get_Struct(other, RGSS::Tone, otherTone);

    double red   = otherTone->getRed();
    double green = otherTone->getGreen();
    double blue  = otherTone->getBlue();
    double gray  = otherTone->getGray();

    tone->set(red, green, blue, gray);

    return self;
}

VALUE toneClass_initDefault (VALUE self)
{
    return self;
}

VALUE toneClass_init (int argc, VALUE *argv, VALUE self)
{
    return (argc == 0)
           ? toneClass_initDefault(self)
           : toneClass_setValues(argc, argv, self);
}

VALUE toneClass_set (int argc, VALUE *argv, VALUE self)
{
    return (1 == argc)
           ? toneClass_setFromTone(self, argv[0])
           : toneClass_setValues(argc, argv, self);
}

VALUE toneClass_getRed (VALUE self)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double red = tone->getRed();
    return rb_float_new(red);
}

VALUE toneClass_setRed (VALUE self, VALUE value)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double red = NUM2DBL(value);
    tone->setRed(red);
    return value;
}

VALUE toneClass_getGreen (VALUE self)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double green = tone->getGreen();
    return rb_float_new(green);
}

VALUE toneClass_setGreen (VALUE self, VALUE value)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double green = NUM2DBL(value);
    tone->setGreen(green);
    return value;
}

VALUE toneClass_getBlue (VALUE self)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double blue = tone->getBlue();
    return rb_float_new(blue);
}

VALUE toneClass_setBlue (VALUE self, VALUE value)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double blue = NUM2DBL(value);
    tone->setBlue(blue);
    return value;
}

VALUE toneClass_getGray (VALUE self)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double gray = tone->getGray();
    return rb_float_new(gray);
}

VALUE toneClass_setGray (VALUE self, VALUE value)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);
    double gray = NUM2DBL(value);
    tone->setGray(gray);
    return value;
}

VALUE toneClass_toString (VALUE self)
{
    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);

    double red   = tone->getRed();
    double green = tone->getGreen();
    double blue  = tone->getBlue();
    double gray  = tone->getGray();

    return rb_sprintf("(%f, %f, %f, %f)", red, green, blue, gray);
}

VALUE toneClass_eq (VALUE self, VALUE other)
{
    if(CLASS_OF(other) != CLASS_OF(self))
        return Qfalse;

    RGSS::Tone *left, *right;
    Data_Get_Struct(self, RGSS::Tone, left);
    Data_Get_Struct(other, RGSS::Tone, right);

    return VALUE2BOOL(*left == *right);
}

VALUE toneClass_load (VALUE klass, VALUE marshaled)
{
    char *data = StringValuePtr(marshaled);

    double red, green, blue, gray;
    memcpy(&red, &data[0], sizeof(double));
    memcpy(&green, &data[sizeof(double)], sizeof(double));
    memcpy(&blue, &data[sizeof(double) * 2], sizeof(double));
    memcpy(&gray, &data[sizeof(double) * 3], sizeof(double));

    VALUE instance = toneClass_allocate(klass);

    RGSS::Tone *tone;
    Data_Get_Struct(instance, RGSS::Tone, tone);
    tone->set(red, green, blue, gray);

    return instance;
}

VALUE toneClass_dump (VALUE self, VALUE level)
{
    const int dataLength = sizeof(double) * 4;
    char *data = new char[dataLength];

    RGSS::Tone *tone;
    Data_Get_Struct(self, RGSS::Tone, tone);

    double red   = tone->getRed();
    double green = tone->getGreen();
    double blue  = tone->getBlue();
    double gray = tone->getGray();

    memcpy(&data[0], &red, sizeof(double));
    memcpy(&data[sizeof(double)], &green, sizeof(double));
    memcpy(&data[sizeof(double) * 2], &blue, sizeof(double));
    memcpy(&data[sizeof(double) * 3], &gray, sizeof(double));

    return rb_str_new(data, dataLength);
}

VALUE initToneClass ()
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

    return toneClass;
}
