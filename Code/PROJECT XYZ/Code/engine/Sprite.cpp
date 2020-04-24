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

    void Sprite::SetPosition( float x, float y )
    {
        position.
    }

    void Sprite::SetPositionX( float x )
    {
        
    }

    void Sprite::SetPositionY( float y )
    {
        
    }

    void Sprite::SetPosition( std::vector<float> pos )
    {
        
    }
}

