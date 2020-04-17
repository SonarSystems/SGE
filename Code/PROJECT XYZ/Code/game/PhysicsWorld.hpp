#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "b2GLDraw.h"
#include "Game.hpp"
#include <iostream>

namespace Sonar
{
    class PhysicsWorld
    {
    public:
        PhysicsWorld( GameDataRef data );
        
        void Update( float dt );
        void Draw( float dt );
        
        
        void CreateStaticBody( float posX, float posY, float width, float height, float density = 0 );

        /** Create the boxes */
        void CreateDynamicBody( float posX, float posY, float width, float height, float density = 0, float friction = 0 );
        
    private:
        GameDataRef _data;
        
        b2Vec2 Gravity;
        b2World *World;
        
        b2GLDraw fooDrawInstance;
        
        sf::Texture GroundTexture;
        sf::Texture BoxTexture;
        
        
    };
}
