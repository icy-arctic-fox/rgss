#include "Tone.hpp"

namespace RGSS
{
    Tone::Tone ()
    {
        _red   = 0;
        _green = 0;
        _blue  = 0;
        _gray  = 0;
    }

    Tone::Tone (double red, double green, double blue, double gray)
    {
        setRed(red);
        setGreen(green);
        setBlue(blue);
        setGray(gray);
    }

    const double Tone::getRed () const
    {
        return _red;
    }

    void Tone::setRed (double red)
    {
        if(red < -255)
            red = -255;
        else if(red > 255)
            red = 255;
        _red = red;
    }

    const double Tone::getGreen () const
    {
        return _green;
    }

    void Tone::setGreen (double green)
    {
        if(green < -255)
            green = -255;
        else if(green > 255)
            green = 255;
        _green = green;
    }

    const double Tone::getBlue () const
    {
        return _blue;
    }

    void Tone::setBlue (double blue)
    {
        if(blue < -255)
            blue = -255;
        else if(blue > 255)
            blue = 255;
        _blue = blue;
    }

    const double Tone::getGray () const
    {
        return _gray;
    }

    void Tone::setGray (double gray)
    {
        if(gray < 0)
            gray = 0;
        else if(gray > 255)
            gray = 255;
        _gray = gray;
    }

    void Tone::set (double red, double green, double blue, double gray)
    {
        setRed(red);
        setGreen(green);
        setBlue(blue);
        setGray(gray);
    }

    Tone *Tone::clone () const
    {
        return new Tone(_red, _green, _blue, _gray);
    }

    bool Tone::operator== (const Tone &other) const
    {
        return (_red   == other._red)
               && (_green == other._green)
               && (_blue  == other._blue)
               && (_gray  == other._gray);
    }

    bool Tone::operator!= (const Tone &other) const
    {
        return !(*this == other);
    }
}
