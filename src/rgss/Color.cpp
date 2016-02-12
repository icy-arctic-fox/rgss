#include "Color.hpp"

namespace RGSS
{
    Color::Color ()
    {
        _red   = 0;
        _green = 0;
        _blue  = 0;
        _alpha = 0;
    }

    Color::Color (double red, double green, double blue, double alpha)
    {
        setRed(red);
        setGreen(green);
        setBlue(blue);
        setAlpha(alpha);
    }

    const double Color::getRed () const
    {
        return _red;
    }

    void Color::setRed (double red)
    {
        if(red < 0)
            red = 0;
        else if(red > 255)
            red = 255;
        _red = red;
        _internal.r = (sf::Uint8)red;
    }

    const double Color::getGreen () const
    {
        return _green;
    }

    void Color::setGreen (double green)
    {
        if(green < 0)
            green = 0;
        else if(green > 255)
            green = 255;
        _green = green;
        _internal.g = (sf::Uint8)green;
    }

    const double Color::getBlue () const
    {
        return _blue;
    }

    void Color::setBlue (double blue)
    {
        if(blue < 0)
            blue = 0;
        else if(blue > 255)
            blue = 255;
        _blue = blue;
        _internal.b = (sf::Uint8)blue;
    }

    const double Color::getAlpha () const
    {
        return _alpha;
    }

    void Color::setAlpha (double alpha)
    {
        if(alpha < 0)
            alpha = 0;
        else if(alpha > 255)
            alpha = 255;
        _alpha = alpha;
        _internal.a = (sf::Uint8)alpha;
    }

    void Color::set (double red, double green, double blue, double alpha)
    {
        setRed(red);
        setGreen(green);
        setBlue(blue);
        setAlpha(alpha);
    }

    const sf::Color *Color::getResolvedColor () const
    {
        return &_internal;
    }

    Color *Color::clone () const
    {
        return new Color(_red, _green, _blue, _alpha);
    }

    bool Color::operator== (const Color &other) const
    {
        return (_red   == other._red)
               && (_green == other._green)
               && (_blue  == other._blue)
               && (_alpha == other._alpha);
    }

    bool Color::operator!= (const Color &other) const
    {
        return !(*this == other);
    }
}
