#include "Table.hpp"
#include "string.h"

namespace RGSS
{
    int Table::_xyzToIndex (int x, int y, int z) const
    {
        // TODO: Throw exception for invalid indices.
        return x + (y * _w + (z * _w * _h));
    }

    static int _whdToSize (int w, int h, int d)
    {
        // TODO: Throw exception for invalid dimensions.
        int size = w * h * d;
        return size < 0 ? 1 : size;
    }

    Table::Table (int w, int h, int d)
    {
        int size = _whdToSize(w, h, d);
        _w = w;
        _h = h;
        _d = d;
        _data = new sf::Int16[size];
    }

    sf::Int16 Table::get (int x, int y, int z) const
    {
        int index = _xyzToIndex(x, y, z);
        return _data[index];
    }

    void Table::set (int x, int y, int z, sf::Int16 value)
    {
        int index = _xyzToIndex(x, y, z);
        _data[index] = value;
    }

    void Table::resize (int w, int h, int d)
    {
        // TODO
    }

    Table *Table::clone () const
    {
        int size = _whdToSize(_w, _h, _d);
        Table *copy = new Table(_w, _h, _d);
        memcpy(copy->_data, _data, size * sizeof(sf::Int16));
        return copy;
    }
}