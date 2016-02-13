#include "Table.hpp"
#include "string.h"

namespace RGSS
{
    int Table::_whdToSize (int w, int h, int d)
    {
        // TODO: Throw exception for invalid dimensions.
        int size = w * h * d;
        return size < 0 ? 1 : size;
    }

    int Table::_xyzToIndex (int x, int y, int z) const
    {
        // TODO: Throw exception for invalid indices.
        return x + (y * _w + (z * _w * _h));
    }

    void Table::_resize (int w, int h, int d)
    {
        int newSize = _whdToSize(w, h, d);

        if(newSize > 0)
        {
            int minW = w < _w ? w : _w;
            int minH = h < _h ? h : _h;
            int minD = d < _d ? d : _d;
            sf::Int16 *newData = new sf::Int16[newSize];
            memset(newData, 0, newSize * sizeof(sf::Int16));

            sf::Int16 *source = _data, *dest = newData;
            for(int z = 0; z < minD; ++z)
                for(int y = 0; y < minH; ++y, source += _w, dest += w)
                    memcpy(source, dest, minW);

            if(_data)
                delete _data;
            _data = newData;
        }
        else if(_data)
            delete _data;

        _w = w;
        _h = h;
        _d = d;
    }

    Table::Table ()
    {
        _dimensions = 0;
        _w = 0;
        _h = 0;
        _d = 0;
        _data = NULL;
    }

    Table::Table (int w)
    {
        _dimensions = 1;
        _w = w;
        _h = 1;
        _d = 1;

        int size = _whdToSize(_w, _h, _d);
        _data = new sf::Int16[size];
        memset(_data, 0, size * sizeof(sf::Int16));
    }

    Table::Table (int w, int h)
    {
        _dimensions = 2;
        _w = w;
        _h = h;
        _d = 1;

        int size = _whdToSize(_w, _h, _d);
        _data = new sf::Int16[size];
        memset(_data, 0, size * sizeof(sf::Int16));
    }

    Table::Table (int w, int h, int d)
    {
        _dimensions = 3;
        _w = w;
        _h = h;
        _d = d;

        int size = _whdToSize(_w, _h, _d);
        _data = new sf::Int16[size];
        memset(_data, 0, size * sizeof(sf::Int16));
    }

    Table::~Table ()
    {
        if(_data)
            delete _data;
    }

    int Table::getWidth () const
    {
        return _w;
    }

    int Table::getHeight () const
    {
        return _h;
    }

    int Table::getDepth () const
    {
        return _d;
    }

    int Table::getDimensions () const
    {
        return _dimensions;
    }

    sf::Int16 Table::get (int x, int y, int z) const
    {
        int index = _xyzToIndex(x, y, z);
        return _data[index];
    }

    void Table::set (sf::Int16 value, int x, int y, int z)
    {
        int index = _xyzToIndex(x, y, z);
        _data[index] = value;
    }

    void Table::resize (int w)
    {
        _dimensions = 1;
        if(w < 0)
            w = 0;
        _resize(w, 1, 1);
    }

    void Table::resize (int w, int h)
    {
        _dimensions = 2;
        if(w < 0)
            w = 0;
        if(h < 0)
            h = 0;
        _resize(w, h, 1);
    }

    void Table::resize (int w, int h, int d)
    {
        _dimensions = 3;
        if(w < 0)
            w = 0;
        if(h < 0)
            h = 0;
        if(d < 0)
            d = 0;
        _resize(w, h, d);
    }

    Table *Table::clone () const
    {
        int size = _whdToSize(_w, _h, _d);
        Table *copy = new Table(_w, _h, _d);
        if(_data)
            memcpy(copy->_data, _data, size * sizeof(sf::Int16));
        return copy;
    }
}
