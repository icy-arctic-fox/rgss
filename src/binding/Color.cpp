#include "common.h"
#include <Color.hpp>

VALUE colorClass_allocate (VALUE klass)
{
    RGSS::Color *color;
    return Data_Make_Struct(klass, RGSS::Color, 0, -1, color);
}

VALUE colorClass_setValues (int argc, VALUE *argv, VALUE self)
{
    VALUE redValue, greenValue, blueValue, alphaValue;
    double red, green, blue, alpha;

    int count = rb_scan_args(argc, argv, "31", &redValue, &greenValue, &blueValue, &alphaValue);
    if(3 == count || 4 == count)
    {
        red   = NUM2DBL(redValue);
        green = NUM2DBL(greenValue);
        blue  = NUM2DBL(blueValue);

        if(3 == count)
            alpha = 255;
        else
            alpha = NUM2DBL(alphaValue);

        RGSS::Color *color;
        Data_Get_Struct(self, RGSS::Color, color);
        color->set(red, green, blue, alpha);
    }

    return self;
}

VALUE colorClass_setFromColor (VALUE self, VALUE other)
{
    RGSS::Color *color, *otherColor;
    Data_Get_Struct(self, RGSS::Color, color);
    Data_Get_Struct(other, RGSS::Color, otherColor);

    double red   = otherColor->getRed();
    double green = otherColor->getGreen();
    double blue  = otherColor->getBlue();
    double alpha = otherColor->getAlpha();

    color->set(red, green, blue, alpha);

    return self;
}

VALUE colorClass_initDefault (VALUE self)
{
    return self;
}

VALUE colorClass_init (int argc, VALUE *argv, VALUE self)
{
    return (argc == 0)
           ? colorClass_initDefault(self)
           : colorClass_setValues(argc, argv, self);
}

VALUE colorClass_set (int argc, VALUE *argv, VALUE self)
{
    return (1 == argc)
           ? colorClass_setFromColor(self, argv[0])
           : colorClass_setValues(argc, argv, self);
}

VALUE colorClass_getRed (VALUE self)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double red = color->getRed();
    return rb_float_new(red);
}

VALUE colorClass_setRed (VALUE self, VALUE value)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double red = NUM2DBL(value);
    color->setRed(red);
    return value;
}

VALUE colorClass_getGreen (VALUE self)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double green = color->getGreen();
    return rb_float_new(green);
}

VALUE colorClass_setGreen (VALUE self, VALUE value)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double green = NUM2DBL(value);
    color->setGreen(green);
    return value;
}

VALUE colorClass_getBlue (VALUE self)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double blue = color->getBlue();
    return rb_float_new(blue);
}

VALUE colorClass_setBlue (VALUE self, VALUE value)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double blue = NUM2DBL(value);
    color->setBlue(blue);
    return value;
}

VALUE colorClass_getAlpha (VALUE self)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double alpha = color->getAlpha();
    return rb_float_new(alpha);
}

VALUE colorClass_setAlpha (VALUE self, VALUE value)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);
    double alpha = NUM2DBL(value);
    color->setAlpha(alpha);
    return value;
}

VALUE colorClass_toString (VALUE self)
{
    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);

    double red   = color->getRed();
    double green = color->getGreen();
    double blue  = color->getBlue();
    double alpha = color->getAlpha();

    return rb_sprintf("(%f, %f, %f, %f)", red, green, blue, alpha);
}

VALUE colorClass_eq (VALUE self, VALUE other)
{
    if(CLASS_OF(other) != CLASS_OF(self))
        return Qfalse;

    RGSS::Color *left, *right;
    Data_Get_Struct(self, RGSS::Color, left);
    Data_Get_Struct(other, RGSS::Color, right);

    return VALUE2BOOL(*left == *right);
}

VALUE colorClass_load (VALUE klass, VALUE marshaled)
{
    char *data = StringValuePtr(marshaled);

    double red, green, blue, alpha;
    memcpy(&red, &data[0], sizeof(double));
    memcpy(&green, &data[sizeof(double)], sizeof(double));
    memcpy(&blue, &data[sizeof(double) * 2], sizeof(double));
    memcpy(&alpha, &data[sizeof(double) * 3], sizeof(double));

    VALUE instance = colorClass_allocate(klass);

    RGSS::Color *color;
    Data_Get_Struct(instance, RGSS::Color, color);
    color->set(red, green, blue, alpha);

    return instance;
}

VALUE colorClass_dump (VALUE self, VALUE level)
{
    const int dataLength = sizeof(double) * 4;
    char *data = new char[dataLength];

    RGSS::Color *color;
    Data_Get_Struct(self, RGSS::Color, color);

    double red   = color->getRed();
    double green = color->getGreen();
    double blue  = color->getBlue();
    double alpha = color->getAlpha();

    memcpy(&data[0], &red, sizeof(double));
    memcpy(&data[sizeof(double)], &green, sizeof(double));
    memcpy(&data[sizeof(double) * 2], &blue, sizeof(double));
    memcpy(&data[sizeof(double) * 3], &alpha, sizeof(double));

    return rb_str_new(data, dataLength);
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
