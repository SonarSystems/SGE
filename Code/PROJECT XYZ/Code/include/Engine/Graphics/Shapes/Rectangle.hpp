#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Drawable.hpp"
#include "Color.hpp"

namespace Sonar
{
    class Rectangle : public Drawable
    {
    public:
        // default constructor
        Rectangle( GameDataRef data );
        // constructor with image filepath to create a texture
        Rectangle( GameDataRef data, const float &width, const float &height );
        
        // default destructor
        ~Rectangle( );
        
        // set position methods
        void SetPosition( const float &x, const float &y );
        void SetPositionX( const float &x );
        void SetPositionY( const float &y );
        
        // set size methods
        void SetSize( const float &width, const float &height );
        void SetWidth( const float &width );
        void SetHeight( const float &height );
        
        // set color properties
        void SetInsideColor( const Color &color );
        void SetBorderColor( const Color &color );
        void SetBorderThickness( const float &thickness );
        
        // get color properties
        const Color &GetInsideColor( ) const;
        const Color &GetBorderColor( ) const;
        const float &GetBorderThickness( ) const;
        
        // move the shape
        void Move( const float &x, const float &y );
        void MoveX( const float &x );
        void MoveY( const float &y );

    private:
        // sprite for the class
        sf::RectangleShape shape;
        
    };
}
