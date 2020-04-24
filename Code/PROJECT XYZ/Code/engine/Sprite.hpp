#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Sonar
{
    class Sprite
    {
    public:
        // default constructor
        Sprite( );
        // constructor with image filepath to create a texture
        Sprite( std::string filepath );
        
        // DRAW
        
        void SetPosition( float x, float y );
        void SetPositionX( float x );
        void SetPositionY( float y );
        void SetPosition( std::vector<float> pos );
        
        // default destructor
        ~Sprite( );

    private:
        // sprite for the class
        sf::Sprite mySprite;
        // texture for loading an image to be assigned to the sprite
        sf::Texture myTexture;
        
        // sprite position
        std::vector<float> position;
        
    };
}
