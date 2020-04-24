#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Drawable.hpp"

namespace Sonar
{
    class Rectangle : public Drawable
    {
    public:
        // default constructor
        Rectangle( );
        // constructor with image filepath to create a texture
        Rectangle( float width, float height );
        
        // default destructor
        ~Rectangle( );
        
        // DRAW

    private:
        // sprite for the class
        sf::RectangleShape shape;
        
    };
}
