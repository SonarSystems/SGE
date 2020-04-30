#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Color.hpp"
#include "Game.hpp"

namespace Sonar
{
    class Drawable
    {
    public:
        // draw object to application window
        void Draw( );
        
        // set position methods
        void SetPosition( const float &x, const float &y );
        void SetPositionX( const float &x );
        void SetPositionY( const float &y );
        
        // get position methods
        const float &GetPositionX( ) const;
        const float &GetPositionY( ) const;
        const glm::vec2 &GetPosition( ) const;
        
        // set size methods
        void SetSize( const float &width, const float &height );
        void SetWidth( const float &width );
        void SetHeight( const float &height );
        
        // get size methods
        const float &GetWidth( ) const;
        const float &GetHeight( ) const;
        const glm::vec2 &GetSize( ) const;
        
        // set color properties
        void SetInsideColor( const Color &color );
        void SetBorderColor( const Color &color );
        void SetBorderThickness( const float &thickness );
        
        // get color properties
        const Color &GetInsideColor( ) const;
        const Color &GetBorderColor( ) const;
        const float &GetBorderThickness( ) const;
        
        // move the object
        void Move( const float &x, const float &y );
        void MoveX( const float &x );
        void MoveY( const float &y );
    
    protected:
        // default constructor
        Drawable( GameDataRef data );
        
        // default destructor
         ~Drawable( ) ;
        
        // object to be drawn to the screen, assigned the address of the object from a child class
        sf::Drawable *object;
        
        GameDataRef _data;

    private:
        // object position (x and y)
        glm::vec2 _position;
        
        // object size (width and heigh(
        glm::vec2 _size;
        
        // colors
        Color _color;
        Color _borderColor;
        float _borderThickness;
        
    };
}
