#ifndef RGSS_TEXTAPPEARANCE_HPP
#define RGSS_TEXTAPPEARANCE_HPP

#include "common.hpp"
#include "Color.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace RGSS
{
    class TextAppearance
    {
    private:
        int _size;
        bool _bold, _italic, _outline, _shadow;
        Color _foreColor, _outColor;
        sf::Font _font;

    public:
        TextAppearance ();
        ~TextAppearance ();

        int getSize () const;
        void setSize (int size);
        bool isBold () const;
        void setBold (bool bold);
        bool isItalic () const;
        void setItalic (bool italic);
        bool hasOutline () const;
        void setOutline (bool outline);
        bool hasShadow () const;
        void setShadow (bool shadow);
        Color getForegroundColor () const;
        void setForegroundColor (Color &color);
        Color getOutlineColor () const;
        void setOutlineColor (Color &color);

        void applyTo (sf::Text &text);
        TextAppearance *clone () const;
    };
}

#endif	/* RGSS_TEXTAPPEARANCE_HPP */
