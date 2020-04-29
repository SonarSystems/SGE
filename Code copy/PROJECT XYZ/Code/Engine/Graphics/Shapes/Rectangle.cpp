#include "Rectangle.hpp"

namespace Sonar
{
    Rectangle::Rectangle( GameDataRef data ) : Drawable( data )
    {
        object = &shape;
    }

    Rectangle::Rectangle( GameDataRef data, const float &width, const float &height ) : Drawable( data )
    {
        object = &shape;
        SetSize( width, height );
    }

    Rectangle::~Rectangle( ) { }

    void Rectangle::SetPosition( const float &x, const float &y )
    {
        Drawable::SetPosition( x, y );
        shape.setPosition( x, y );
    }

    void Rectangle::SetPositionX( const float &x )
    {
        Drawable::SetPositionX( x );
        shape.setPosition( x, shape.getPosition( ).y );
    }

    void Rectangle::SetPositionY( const float &y )
    {
        Drawable::SetPositionY( y );
        shape.setPosition( shape.getPosition( ).x, y );
    }

    void Rectangle::SetSize( const float &width, const float &height )
    {
        Drawable::SetSize( width, height );
        shape.setSize( sf::Vector2f( width, height ) );
    }

    void Rectangle::SetWidth( const float &width )
    {
        Drawable::SetWidth( width );
        shape.setSize( sf::Vector2f( width, shape.getSize( ).y ) );
    }

    void Rectangle::SetHeight( const float &height )
    {
        Drawable::SetHeight( height );
        shape.setSize( sf::Vector2f( shape.getSize( ).x, height ) );
    }

    void Rectangle::SetInsideColor( const Color &color )
    {
        Drawable::SetInsideColor( color );
        shape.setFillColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderColor( const Color &color )
    {
        Drawable::SetBorderColor( color );
        shape.setOutlineColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderThickness( const float &thickness )
    {
        Drawable::SetBorderThickness( thickness );
        shape.setOutlineThickness( thickness );
    }

    void Rectangle::Move( const float &x, const float &y )
    {
        Drawable::Move( x, y );
        shape.move( x, y );
    }

    void Rectangle::MoveX( const float &x )
    {
        Drawable::MoveX( x );
        shape.move( x, 0 );
    }

    void Rectangle::MoveY( const float &y )
    {
        Drawable::MoveY( y );
        shape.move( 0, y );
    }
}

