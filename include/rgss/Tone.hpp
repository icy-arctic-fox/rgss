#ifndef RGSS_TONE_HPP
#define	RGSS_TONE_HPP

#include "common.hpp"

namespace RGSS
{
    class Tone
    {
    private:
        double _red, _green, _blue, _gray;

    public:
        Tone ();
        Tone (double red, double green, double blue, double gray);
        const double getRed () const;
        void setRed (double red);
        const double getGreen () const;
        void setGreen (double green);
        const double getBlue () const;
        void setBlue (double blue);
        const double getGray () const;
        void setGray (double gray);
        void set (double red, double green, double blue, double gray);
        Tone *clone () const;
        bool operator== (const Tone &other) const;
        bool operator!= (const Tone &other) const;
    };
}

#endif	/* RGSS_TONE_HPP */
