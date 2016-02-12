#include "Rect.hpp"

namespace RGSS
{
    Rect::Rect (int x, int y, int width, int height)
    {
        _bounds.left   = x;
        _bounds.top    = y;
        _bounds.width  = width;
        _bounds.height = height;
    }

    const int Rect::getX () const
    {
        return _bounds.left;
    }

    void Rect::setX (int x)
    {
        _bounds.left = x;
    }

    const int Rect::getY () const
    {
        return _bounds.top;
    }

    void Rect::setY (int y)
    {
        _bounds.top = y;
    }

    const int Rect::getWidth () const
    {
        return _bounds.width;
    }

    void Rect::setWidth (int width)
    {
        _bounds.width = width;
    }

    const int Rect::getHeight () const
    {
        return _bounds.height;
    }

    void Rect::setHeight (int height)
    {
        _bounds.height = height;
    }

    void Rect::clear ()
    {
        _bounds.left   = 0;
        _bounds.top    = 0;
        _bounds.width  = 0;
        _bounds.height = 0;
    }

    void Rect::set (int x, int y, int width, int height)
    {
        _bounds.left   = x;
        _bounds.top    = y;
        _bounds.width  = width;
        _bounds.height = height;
    }

    const sf::IntRect *Rect::getBounds () const
    {
        return &_bounds;
    }

    Rect *Rect::clone () const
    {
        return new Rect(_bounds.left, _bounds.top, _bounds.width, _bounds.height);
    }

    bool Rect::operator== (const Rect &other) const
    {
        return _bounds == other._bounds;
    }

    bool Rect::operator!= (const Rect &other) const
    {
        return !(*this == other);
    }
}
