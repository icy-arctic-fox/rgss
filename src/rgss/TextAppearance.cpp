#include "TextAppearance.hpp"
#include <string.h>

namespace RGSS
{
    TextAppearance::TextAppearance ()
    {
        // TODO
    }

    TextAppearance::~TextAppearance ()
    {
        // TODO
    }

    int TextAppearance::getSize () const
    {
        return _size;
    }

    void TextAppearance::setSize (int size)
    {
        _size = size;
    }

    bool TextAppearance::isBold () const
    {
        return _bold;
    }

    void TextAppearance::setBold (bool bold)
    {
        _bold = bold;
    }

    bool TextAppearance::isItalic () const
    {
        return _italic;
    }

    void TextAppearance::setItalic (bool italic)
    {
        _italic = italic;
    }

    bool TextAppearance::hasOutline () const
    {
        return _outline;
    }

    void TextAppearance::setOutline (bool outline)
    {
        _outline = outline;
    }

    bool TextAppearance::hasShadow () const
    {
        return _shadow;
    }

    void TextAppearance::setShadow (bool shadow)
    {
        _shadow = shadow;
    }

    Color &TextAppearance::getForegroundColor ()
    {
        return _foreColor;
    }

    void TextAppearance::setForegroundColor (Color &color)
    {
        _foreColor = color;
    }

    Color &TextAppearance::getOutlineColor ()
    {
        return _outColor;
    }

    void TextAppearance::setOutlineColor (Color &color)
    {
        _outColor = color;
    }

    void TextAppearance::applyTo (sf::Text &text)
    {
        // TODO
    }

    TextAppearance *TextAppearance::clone () const
    {
        // TODO
        return NULL;
    }
}
