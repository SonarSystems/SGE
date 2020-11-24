#include "Graphics/Shapes/Rectangle.hpp"

namespace Sonar
{
    Rectangle::Rectangle( GameDataRef data ) : Drawable( data )
    {
        object = &_shape;
    }

    Rectangle::Rectangle( GameDataRef data, const float &width, const float &height ) : Drawable( data )
    {
        object = &_shape;
        SetSize( width, height );
    }

    Rectangle::~Rectangle( ) { }

    void Rectangle::SetPosition( const float &x, const float &y )
    {
        Drawable::SetPosition( x, y );
        _shape.setPosition( x, y );
    }

    void Rectangle::SetPositionX( const float &x )
    {
        Drawable::SetPositionX( x );
        _shape.setPosition( x, _shape.getPosition( ).y );
    }

    void Rectangle::SetPositionY( const float &y )
    {
        Drawable::SetPositionY( y );
        _shape.setPosition( _shape.getPosition( ).x, y );
    }

    void Rectangle::SetSize( const float &width, const float &height )
    {
        Drawable::SetSize( width, height );
        _shape.setSize( sf::Vector2f( width, height ) );
    }

    void Rectangle::SetWidth( const float &width )
    {
        Drawable::SetWidth( width );
        _shape.setSize( sf::Vector2f( width, _shape.getSize( ).y ) );
    }

    void Rectangle::SetHeight( const float &height )
    {
        Drawable::SetHeight( height );
        _shape.setSize( sf::Vector2f( _shape.getSize( ).x, height ) );
    }

    void Rectangle::SetInsideColor( const Color &color )
    {
        Drawable::SetInsideColor( color );
        _shape.setFillColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderColor( const Color &color )
    {
        Drawable::SetBorderColor( color );
        _shape.setOutlineColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderThickness( const float &thickness )
    {
        Drawable::SetBorderThickness( thickness );
        _shape.setOutlineThickness( thickness );
    }

    void Rectangle::Move( const float &x, const float &y )
    {
        Drawable::Move( x, y );
        _shape.move( x, y );
    }

    void Rectangle::MoveX( const float &x )
    {
        Drawable::MoveX( x );
        _shape.move( x, 0 );
    }

    void Rectangle::MoveY( const float &y )
    {
        Drawable::MoveY( y );
        _shape.move( 0, y );
    }
}

