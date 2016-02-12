#include "common.h"
#include "Rect.hpp"

VALUE rectClass_allocate (VALUE klass)
{
    RGSS::Rect *rect;
    return Data_Make_Struct(klass, RGSS::Rect, 0, -1, rect);
}

VALUE rectClass_setValues (int argc, VALUE *argv, VALUE self)
{
    VALUE xValue, yValue, widthValue, heightValue;
    int x, y, width, height;

    if(4 == rb_scan_args(argc, argv, "4", &xValue, &yValue, &widthValue, &heightValue))
    {
        x      = NUM2INT(xValue);
        y      = NUM2INT(yValue);
        width  = NUM2INT(widthValue);
        height = NUM2INT(heightValue);

        RGSS::Rect *rect;
        Data_Get_Struct(self, RGSS::Rect, rect);
        rect->set(x, y, width, height);
    }

    return self;
}

VALUE rectClass_setFromRect (VALUE self, VALUE other)
{
    RGSS::Rect *rect, *otherRect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    Data_Get_Struct(other, RGSS::Rect, otherRect);

    int x      = otherRect->getX();
    int y      = otherRect->getY();
    int width  = otherRect->getWidth();
    int height = otherRect->getHeight();

    rect->set(x, y, width, height);

    return self;
}

VALUE rectClass_initDefault (VALUE self)
{
    return self;
}

VALUE rectClass_init (int argc, VALUE *argv, VALUE self)
{
    return (argc == 0)
           ? rectClass_initDefault(self)
           : rectClass_setValues(argc, argv, self);
}

VALUE rectClass_set (int argc, VALUE *argv, VALUE self)
{
    return (1 == argc)
           ? rectClass_setFromRect(self, argv[0])
           : rectClass_setValues(argc, argv, self);
}

VALUE rectClass_empty (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    rect->clear();
    return self;
}

VALUE rectClass_getX (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int x = rect->getX();
    return INT2FIX(x);
}

VALUE rectClass_setX (VALUE self, VALUE value)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int x = NUM2INT(value);
    rect->setX(x);
    return value;
}

VALUE rectClass_getY (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int y = rect->getY();
    return INT2FIX(y);
}

VALUE rectClass_setY (VALUE self, VALUE value)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int y = NUM2INT(value);
    rect->setY(y);
    return value;
}

VALUE rectClass_getWidth (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int width = rect->getWidth();
    return INT2FIX(width);
}

VALUE rectClass_setWidth (VALUE self, VALUE value)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int width = NUM2INT(value);
    rect->setWidth(width);
    return value;
}

VALUE rectClass_getHeight (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int height = rect->getHeight();
    return INT2FIX(height);
}

VALUE rectClass_setHeight (VALUE self, VALUE value)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);
    int height = NUM2INT(value);
    rect->setHeight(height);
    return value;
}

VALUE rectClass_toString (VALUE self)
{
    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);

    int x      = rect->getX();
    int y      = rect->getY();
    int width  = rect->getWidth();
    int height = rect->getHeight();

    return rb_sprintf("(%i, %i, %i, %i)", x, y, width, height);
}

VALUE rectClass_eq (VALUE self, VALUE other)
{
    if(CLASS_OF(other) != CLASS_OF(self))
        return Qfalse;

    RGSS::Rect *left, *right;
    Data_Get_Struct(self, RGSS::Rect, left);
    Data_Get_Struct(other, RGSS::Rect, right);

    return VALUE2BOOL(*left == *right);
}

VALUE rectClass_dump (VALUE self, VALUE depth)
{
    const int dataLength = sizeof(int) * 4;
    char *data = new char[dataLength];

    RGSS::Rect *rect;
    Data_Get_Struct(self, RGSS::Rect, rect);

    int x      = rect->getX();
    int y      = rect->getY();
    int width  = rect->getWidth();
    int height = rect->getHeight();

    memcpy(&data[0], &x, sizeof(int));
    memcpy(&data[sizeof(int)], &y, sizeof(int));
    memcpy(&data[sizeof(int) * 2], &width, sizeof(int));
    memcpy(&data[sizeof(int) * 3], &height, sizeof(int));

    return rb_str_new(data, dataLength);
}

VALUE rectClass_load (VALUE klass, VALUE marshaled)
{
    char *data = StringValuePtr(marshaled);

    int x, y, width, height;
    memcpy(&x, &data[0], sizeof(int));
    memcpy(&y, &data[sizeof(int)], sizeof(int));
    memcpy(&width, &data[sizeof(int) * 2], sizeof(int));
    memcpy(&height, &data[sizeof(int) * 3], sizeof(int));

    VALUE instance = rectClass_allocate(klass);

    RGSS::Rect *rect;
    Data_Get_Struct(instance, RGSS::Rect, rect);
    rect->set(x, y, width, height);

    return instance;
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
