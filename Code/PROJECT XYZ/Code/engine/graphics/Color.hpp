#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Sonar
{
    class Color
    {
    public:
        // default constructor (0, 0, 0, 255) - opaque black
        Color( );
        
        // custom constructor for red, green and blue value
        Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue );
                
        // custom constructor for red, green, blue and alpha values
        Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha );
        
        // custom constructor for Color object
        Color( const Color &color );
        
        // default destructor
        ~Color( );
        
        // set colors
        void SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue );
        void SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha );
        void SetColor( const Color &color );
        void SetRed( const uint8_t &red );
        void SetGreen( const uint8_t &green );
        void SetBlue( const uint8_t &blue );
        void SetAlpha( const uint8_t &alpha );
        
        // get colors
        const sf::Color &GetColor( ) const;
        const uint8_t &GetRed( ) const;
        const uint8_t &GetGreen( ) const;
        const uint8_t &GetBlue( ) const;
        const uint8_t &GetAlpha( ) const;

        // static colors
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        static const Color Transparent;
        
    private:
        sf::Color _color;
        
        uint8_t _red;
        uint8_t _green;
        uint8_t _blue;
        uint8_t _alpha;
        
    };
}
