#include "common.h"
#include "Table.hpp"

int tableClass_fixDimensionValue (VALUE value)
{
    int i = NUM2INT(value);
    if(i < 0)
        return 0;
    return i;
}

VALUE tableClass_allocate (VALUE klass)
{
    RGSS::Table *table;
    return Data_Make_Struct(klass, RGSS::Table, 0, -1, table);
}

VALUE tableClass_resize (int argc, VALUE *argv, VALUE self)
{
    VALUE xValue, yValue, zValue;
    int w, h, d;

    int count = rb_scan_args(argc, argv, "12", &xValue, &yValue, &zValue);
    if(count >= 1 && count <= 3)
    {
        RGSS::Table *table;
        Data_Get_Struct(self, RGSS::Table, table);

        w = tableClass_fixDimensionValue(xValue);
        switch(count)
        {
            case 1:
                table->resize(w);
                break;
            case 2:
                h = tableClass_fixDimensionValue(yValue);
                table->resize(w, h);
                break;
            case 3:
                h = tableClass_fixDimensionValue(yValue);
                d = tableClass_fixDimensionValue(zValue);
                table->resize(w, h, d);
                break;
        }
    }

    return self;
}

VALUE tableClass_init (int argc, VALUE *argv, VALUE self)
{
    return tableClass_resize(argc, argv, self);
}

VALUE tableClass_getXSize (VALUE self)
{
    RGSS::Table *table;
    Data_Get_Struct(self, RGSS::Table, table);
    int width = table->getWidth();
    return INT2FIX(width);
}

VALUE tableClass_getYSize (VALUE self)
{
    RGSS::Table *table;
    Data_Get_Struct(self, RGSS::Table, table);
    int height = table->getHeight();
    return INT2FIX(height);
}

VALUE tableClass_getZSize (VALUE self)
{
    RGSS::Table *table;
    Data_Get_Struct(self, RGSS::Table, table);
    int depth = table->getDepth();
    return INT2FIX(depth);
}

VALUE tableClass_getElement (int argc, VALUE *argv, VALUE self)
{
    VALUE xValue, yValue, zValue;
    int x, y, z;

    int count = rb_scan_args(argc, argv, "12", &xValue, &yValue, &zValue);
    if(count >= 1 && count <= 3)
    {
        RGSS::Table *table;
        sf::Int16 value;
        Data_Get_Struct(self, RGSS::Table, table);

        if(count != table->getDimensions())
            rb_raise(rb_eArgError, "Dimension mismatch");

        x = NUM2INT(xValue);
        if(x < 0 || x >= table->getWidth())
            return Qnil;

        switch(count)
        {
            case 1:
                value = table->get(x);
                break;
            case 2:
                y = NUM2INT(yValue);
                if(y < 0 || y >= table->getHeight())
                    return Qnil;
                value = table->get(x, y);
                break;
            case 3:
                y = NUM2INT(yValue);
                if(y < 0 || y >= table->getHeight())
                    return Qnil;
                z = NUM2INT(zValue);
                if(z < 0 || z >= table->getDepth())
                    return Qnil;
                value = table->get(x, y, z);
                break;
        }

        return INT2FIX(value);
    }
    else
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
    rb_define_alloc_func(tableClass, tableClass_allocate);

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
