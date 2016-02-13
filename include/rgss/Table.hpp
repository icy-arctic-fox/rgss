#ifndef RGSS_TABLE_HPP
#define	RGSS_TABLE_HPP

#include "common.hpp"

namespace RGSS
{
    class Table
    {
    private:
        int _dimensions, _w, _h, _d;
        sf::Int16 *_data; // Flat array arranged as x, y, z.

        static int _whdToSize (int w, int h, int d);
        int _xyzToIndex (int x, int y, int z) const;
        void _resize (int w, int h, int d);

    public:
        Table ();
        Table (int w);
        Table (int w, int h);
        Table (int w, int h, int d);
        ~Table ();
        int getWidth () const;
        int getHeight () const;
        int getDepth () const;
        int getDimensions () const;
        sf::Int16 get (int x, int y = 0, int z = 0) const;
        void set (sf::Int16 value, int x, int y = 0, int z = 0);
        void resize (int w);
        void resize (int w, int h);
        void resize (int w, int h, int d);
        Table *clone () const;
    };
}

#endif	/* RGSS_TABLE_HPP */
