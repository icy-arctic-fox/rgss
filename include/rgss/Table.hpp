#ifndef RGSS_TABLE_HPP
#define	RGSS_TABLE_HPP

#include "common.hpp"

namespace RGSS
{
    class Table
    {
    private:
        int _w, _h, _d;
        sf::Int16 *_data; // Flat array arranged as x, y, z.

        int _xyzToIndex (int x, int y, int z) const;
        static int _whdToSize (int w, int h, int d);

    public:
        Table (int w, int h, int d);
        int getWidth () const;
        int getHeight () const;
        int getDepth () const;
        sf::Int16 get (int x, int y, int z) const;
        void set (int x, int y, int z, sf::Int16 value);
        void resize (int w, int h, int d);
        Table *clone () const;
    };
}

#endif	/* RGSS_TABLE_HPP */
