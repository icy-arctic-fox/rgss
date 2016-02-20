#include "common.h"
#include "Table.hpp"

int tableClass_fixDimensionValue (VALUE value)
{
    int i = NUM2INT(value);
    if(i < 0)
        return 0;
    return i;
}

VALUE tableClass_free (RGSS::Table *table)
{
    if(table)
        delete table;
    return Qnil;
}

VALUE tableClass_allocate (VALUE klass)
{
    RGSS::Table *table;
    return Data_Make_Struct(klass, RGSS::Table, 0, tableClass_free, table);
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
    VALUE xValue, arg2, arg3, arg4;
    int x, y, z;
    sf::Int16 value;

    int count = rb_scan_args(argc, argv, "22", &xValue, &arg2, &arg3, &arg4);
    if(count >= 1 && count <= 4)
    {
        RGSS::Table *table;
        Data_Get_Struct(self, RGSS::Table, table);

        if(count - 1 != table->getDimensions())
            rb_raise(rb_eArgError, "Dimension mismatch");

        x = NUM2INT(xValue);
        switch(count)
        {
            case 2:
                value = NUM2INT(arg2);
                if(x >= 0 && x < table->getWidth())
                    table->set(value, x);
                return arg2;
            case 3:
                value = NUM2INT(arg3);
                y = NUM2INT(arg2);
                if((x >= 0 && x < table->getWidth())
                    && (y >= 0 && y < table->getHeight()))
                    table->set(value, x, y);
                return arg3;
            case 4:
                value = NUM2INT(arg4);
                y = NUM2INT(arg2);
                z = NUM2INT(arg3);
                if((x >= 0 && x < table->getWidth())
                   && (y >= 0 && y < table->getHeight())
                   && (z >= 0 && z < table->getDepth()))
                   table->set(value, x, y, z);
                return arg3;
        }
    }
    else
        return Qnil;
}

VALUE tableClass_load (VALUE tableClass, VALUE marshaled)
{
    char *data = StringValuePtr(marshaled);

    int dimensions, w, h, d, length;
    memcpy(&dimensions, &data[0], sizeof(int));
    memcpy(&w, &data[sizeof(int)], sizeof(int));
    memcpy(&h, &data[sizeof(int) * 2], sizeof(int));
    memcpy(&d, &data[sizeof(int) * 3], sizeof(int));
    memcpy(&length, &data[sizeof(int) * 4], sizeof(int));

    VALUE instance = tableClass_allocate(tableClass);
    RGSS::Table *table;
    Data_Get_Struct(instance, RGSS::Table, table);

    switch(dimensions)
    {
    case 1:
        table->resize(w);
        break;
    case 2:
        table->resize(w, h);
        break;
    case 3:
        table->resize(w, h, d);
        break;
    }

    // TODO: Optimize by copying the raw, underlying data.
    sf::Int16 *valuePtr = (sf::Int16 *)&data[sizeof(int) * 5];
    for(int z = 0; z < d; ++z)
        for(int y = 0; y < h; ++y)
            for(int x = 0; x < w && length > 0; ++x, ++valuePtr, --length)
                table->set(*valuePtr, x, y, z);

    return instance;
}

VALUE tableClass_dump (VALUE self, VALUE level)
{
    RGSS::Table *table;
    Data_Get_Struct(self, RGSS::Table, table);
    int w = table->getWidth(),
        h = table->getHeight(),
        d = table->getDepth(),
        dimensions = table->getDimensions();

    int size = w * h * d;
    int dataLength = (5 * sizeof(int)) + (size * sizeof(sf::Int16));
    char *data = new char[dataLength];

    memset(data, 0, dataLength);
    memcpy(data, &dimensions, sizeof(int));
    memcpy(&data[sizeof(int)], &w, sizeof(int));
    memcpy(&data[sizeof(int) * 2], &h, sizeof(int));
    memcpy(&data[sizeof(int) * 3], &d, sizeof(int));
    memcpy(&data[sizeof(int) * 4], &size, sizeof(int));

    // TODO: Optimize by copying the raw, underlying data.
    char *dataPtr = &data[sizeof(int) * 5];
    for(int z = 0; z < d; ++z)
        for(int y = 0; y < h; ++y)
            for(int x = 0; x < w; ++x, dataPtr += sizeof(sf::Int16))
            {
                int value = table->get(x, y, z);
                memcpy(dataPtr, &value, sizeof(sf::Int16));
            }

    VALUE str = rb_str_new(data, dataLength);
    delete[] data;
    return str;
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
