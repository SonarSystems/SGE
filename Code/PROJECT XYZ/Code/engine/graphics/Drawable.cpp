#include "Drawable.hpp"

namespace Sonar
{
    Drawable::Drawable( )
    {
        
    }

    Drawable::~Drawable( )
    {
        
    }

    void Drawable::SetPosition( float x, float y )
    {
        position.x = x;
        position.y = y;
    }

    void Drawable::SetPositionX( float x )
    {
        position.x = x;
    }

    void Drawable::SetPositionY( float y )
    {
        position.y = y;
    }

    void Drawable::SetPosition( glm::vec2 pos )
    {
        position = pos;
    }

    float Drawable::GetPositionX( )
    {
        return position.x;
    }

    float Drawable::GetPositionY( )
    {
        return position.y;
    }

    glm::vec2 Drawable::GetPosition( )
    {
        return position;
    }
}

