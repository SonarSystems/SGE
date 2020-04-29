#include "Drawable.hpp"

namespace Sonar
{
    Drawable::Drawable( GameDataRef data ) : _data( data ) { }

    Drawable::~Drawable( ) { }

    void Drawable::Draw( )
    { _data->window.draw( *object ); }

    void Drawable::SetPosition( const float &x, const float &y )
    {
        _position.x = x;
        _position.y = y;
    }

    void Drawable::SetPositionX( const float &x )
    { _position.x = x; }

    void Drawable::SetPositionY( const float &y )
    { _position.y = y; }

    const float &Drawable::GetPositionX( ) const
    { return _position.x; }

    const float &Drawable::GetPositionY( ) const
    { return _position.y; }

    const glm::vec2 &Drawable::GetPosition( ) const
    { return _position; }

    void Drawable::SetSize( const float &width, const float &height )
    {
        _size.x = width;
        _size.y = height;
    }

    void Drawable::SetWidth( const float &width )
    { _size.x = width; }

    void Drawable::SetHeight( const float &height )
    { _size.y = height; }
    
    const float &Drawable::GetWidth( ) const
    { return _size.x; }

    const float &Drawable::GetHeight( ) const
    { return _size.y; }

    const glm::vec2 &Drawable::GetSize( ) const
    { return _size; }

    void Drawable::SetInsideColor( const Color &color )
    { _color = color; }

    void Drawable::SetBorderColor( const Color &color )
    { _borderColor = color; }

    void Drawable::SetBorderThickness( const float &thickness )
    { _borderThickness = thickness; }

    const Color &Drawable::GetInsideColor( ) const
    { return _color; }

    const Color &Drawable::GetBorderColor( ) const
    { return _borderColor; }

    const float &Drawable::GetBorderThickness( ) const
    { return _borderThickness; }

    void Drawable::Move( const float &x, const float &y )
    {
        _position.x += x;
        _position.y += y;
    }

    void Drawable::MoveX( const float &x )
    { _position.x += x; }

    void Drawable::MoveY( const float &y )
    { _position.y += y; }
}

