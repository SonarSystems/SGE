#include "Sprite.hpp"

namespace Sonar
{
    Sprite::Sprite( )
    {
        
    }

    Sprite::Sprite( std::string filepath )
    {
        myTexture.loadFromFile( filepath );
        mySprite.setTexture( myTexture );
    }

    Sprite::~Sprite( )
    {
        
    }
}

