#ifndef RGSS_RECT_HPP
#define	RGSS_RECT_HPP

#include "common.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace RGSS
{
    class Rect
    {
        private:
        sf::IntRect _bounds;

        public:
        Rect () {}
        Rect (int x, int y, int width, int height);
        const int getX () const;
        void setX (int x);
        const int getY () const;
        void setY (int y);
        const int getWidth () const;
        void setWidth (int width);
        const int getHeight () const;
        void setHeight (int height);
        void clear ();
        void set (int x, int y, int width, int height);
        const sf::IntRect *getBounds () const;
        Rect *clone () const;
        bool operator== (const Rect &other) const;
        bool operator!= (const Rect &other) const;
    };
}

#endif	/* RGSS_RECT_HPP */
