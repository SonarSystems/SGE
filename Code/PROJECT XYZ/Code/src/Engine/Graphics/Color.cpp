#include "Color.hpp"

namespace Sonar
{
    const Color Color::Black( 0, 0, 0 );
    const Color Color::White( 255, 255, 255 );
    const Color Color::Red( 255, 0, 0 );
    const Color Color::Green( 0, 255, 0 );
    const Color Color::Blue( 0, 0, 255 );
    const Color Color::Yellow( 255, 255, 0 );
    const Color Color::Magenta( 255, 0, 255 );
    const Color Color::Cyan( 0, 255, 255 );
    const Color Color::Transparent( 0, 0, 0, 0 );
    
    Color::Color( ) : _red( 0 ), _green( 0 ), _blue( 0 ), _alpha( 255 )
    {
        _color.r = _red;
        _color.g = _green;
        _color.b = _blue;
        _color.a = _alpha;
    }
    
    Color::Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue ) : _red( red ), _green( green ), _blue( blue )
    {
        _color.r = red;
        _color.g = green;
        _color.b = blue;
        _color.a = 255;
    }
    
    Color::Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha ) : _red( red ), _green( green ), _blue( blue ), _alpha( alpha )
    {
        _color.r = red;
        _color.g = green;
        _color.b = blue;
        _color.a = alpha;
    }

    Color::Color( const Color &color ) : _red( color._red ), _green( color._green ), _blue( color._blue ), _alpha( color._alpha )
    {
        _color.r = color.GetRed( );
        _color.g = color.GetGreen( );
        _color.b = color.GetBlue( );
        _color.a = color.GetAlpha( );
    }
    
    Color::~Color( ) { }

    void Color::SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue )
    {
        _red = red;
        _green = green;
        _blue = blue;
        
        _color.r = red;
        _color.g = green;
        _color.b = blue;
    }

    void Color::SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha )
    {
        _red = red;
        _green = green;
        _blue = blue;
        _alpha = alpha;
        
        _color.r = red;
        _color.g = green;
        _color.b = blue;
        _color.a = alpha;
    }

    void Color::SetColor( const Color &color )
    {
        _red = color.GetRed( );
        _green = color.GetGreen( );
        _blue = color.GetBlue( );
        _alpha = color.GetAlpha( );
        
        _color.r = _red;
        _color.g = _green;
        _color.b = _blue;
        _color.a = _alpha;
    }
    
    void Color::SetRed( const uint8_t &red )
    {
        _red = red;
        
        _color.r = red;
    }

    void Color::SetGreen( const uint8_t &green )
    {
        _green = green;
        
        _color.g = green;
    }

    void Color::SetBlue( const uint8_t &blue )
    {
        _blue = blue;
        
        _color.b = blue;
    }

    void Color::SetAlpha( const uint8_t &alpha )
    {
        _alpha = alpha;
        
        _color.a = alpha;
    }

    const sf::Color &Color::GetColor( ) const
    { return _color; }
    
    const uint8_t &Color::GetRed( ) const
    { return _red; }
    
    const uint8_t &Color::GetGreen( ) const
    { return _green; }
    
    const uint8_t &Color::GetBlue( ) const
    { return _blue; }
    
    const uint8_t &Color::GetAlpha( ) const
    { return _alpha; }
}
