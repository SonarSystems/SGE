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
        
        // DRAW
        
        // set position methods
        void SetPosition( float x, float y );
        void SetPosition( glm::vec2 pos );
        void SetPositionX( float x );
        void SetPositionY( float y );
        
        // get position methods
        float GetPositionX( );
        float GetPositionY( );
        glm::vec2 GetPosition( );
        
        // set size methods
        void SetSize( float x, float y );
        void SetSize( glm::vec2 size );
        void SetWidth( float x );
        void SetHeight( float y );
        
        // get size methods
        float GetWidth( );
        float GetHeight( );
        glm::vec2 GetSize( );
        
        // default destructor
        virtual ~Drawable( ) = 0;

        // sprite position
        glm::vec2 _position;
        
        glm::vec2 _size;
        
    };
}
