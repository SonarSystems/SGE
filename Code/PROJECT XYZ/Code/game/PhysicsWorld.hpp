#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "b2GLDraw.h"
#include "Game.hpp"

namespace Sonar
{
    class PhysicsWorld
    {
    public:
        PhysicsWorld( GameDataRef data );
        
        void Update( float dt );
        void Draw( float dt );
        
        /** Create the base for the boxes to land */
        void CreateGround( b2World &World, float X, float Y );

        /** Create the boxes */
        void CreateBox( b2World &World, int MouseX, int MouseY );
        
    private:
        GameDataRef _data;
        
        b2Vec2 Gravity;
        b2World *World;
        
        b2GLDraw fooDrawInstance;
        
        sf::Texture GroundTexture;
        sf::Texture BoxTexture;
        
        
    };
}
