#include "Rectangle.hpp"

namespace Sonar
{
    Rectangle::Rectangle( )
    {
        object = &shape;
        //shape.setSize( sf::Vector2f( 500, 500 ) );
        shape.setFillColor( sf::Color::Red );
    }

    Rectangle::Rectangle( const float &width, const float &height )
    {
        object = &shape;
        SetSize( width, height );
    }

    Rectangle::~Rectangle( )
    {
        
    }

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
}

