#ifndef RGSS_COLOR_HPP
#define	RGSS_COLOR_HPP

#include "common.hpp"
#include <SFML/Graphics/Color.hpp>

namespace RGSS
{
    class Color
    {
    private:
        sf::Color _internal;
        double _red, _green, _blue, _alpha;

    public:
        Color ();
        Color (double red, double green, double blue, double alpha);
        const double getRed () const;
        void setRed (double red);
        const double getGreen () const;
        void setGreen (double green);
        const double getBlue () const;
        void setBlue (double blue);
        const double getAlpha () const;
        void setAlpha (double alpha);
        void set (double red, double green, double blue, double alpha);
        const sf::Color *getResolvedColor () const;
        Color *clone () const;
        bool operator== (const Color &other) const;
        bool operator!= (const Color &other) const;
    };
}

#endif	/* RGSS_COLOR_HPP */
