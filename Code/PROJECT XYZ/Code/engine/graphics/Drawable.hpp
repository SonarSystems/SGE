#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>

namespace Sonar
{
    class Drawable
    {
    protected:
        // default constructor
        Drawable( );
        
        // default destructor
        virtual ~Drawable( ) = 0;
        
    public:
        // draw object
        void Draw( sf::RenderWindow &window );
        
        // set position methods
        void SetPosition( const float &x, const float &y );
        void SetPositionX( const float &x );
        void SetPositionY( const float &y );
        
        // get position methods
        const float GetPositionX( ) const;
        const float GetPositionY( ) const;
        const glm::vec2 GetPosition( ) const;
        
        // set size methods
        void SetSize( const float &width, const float &height );
        void SetWidth( const float &width );
        void SetHeight( const float &height );
        
        // get size methods
        const float GetWidth( ) const;
        const float GetHeight( ) const;
        const glm::vec2 GetSize( ) const;
        
        // set colors
        void SetFillColor( );
        void Set
        
        sf::Drawable *object;

    private:
        // object position (x and y)
        glm::vec2 _position;
        
        // object size (width and heigh(
        glm::vec2 _size;
        
    };
}
