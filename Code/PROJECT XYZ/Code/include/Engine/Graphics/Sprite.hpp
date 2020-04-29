#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Drawable.hpp"

namespace Sonar
{
    class Sprite// : public Drawable
    {
    public:
        // default constructor
        Sprite( );
        // constructor with image filepath to create a texture
        Sprite( std::string filepath );
        
        // DRAW
        
        // default destructor
        ~Sprite( );

    private:
        // sprite for the class
        sf::Sprite mySprite;
        // texture for loading an image to be assigned to the sprite
        sf::Texture myTexture;
        

        
    };
}
