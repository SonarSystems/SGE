#pragma once

#include <sstream>
#include "SplashState.hpp"

#include <iostream>

namespace Sonar
{
    /** We need this to easily convert between pixel and real-world coordinates*/
    static const float SCALE = 30.f;

    

	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        
        /** Prepare the world */
        Gravity = b2Vec2(0.f, 9.8f);
        World = new b2World(Gravity);
        CreateGround(*World, 400.f, 500.f);
        
        fooDrawInstance;
        World->SetDebugDraw(&fooDrawInstance);
        uint32 flags = 0;
        flags += b2Draw::e_shapeBit;
        flags += b2Draw::e_jointBit;
        flags += b2Draw::e_aabbBit;
        flags += b2Draw::e_pairBit;
        flags += b2Draw::e_centerOfMassBit;
        fooDrawInstance.SetFlags(flags);
        
        
        GroundTexture.loadFromFile("Resources/ground.png");
        BoxTexture.loadFromFile("Resources/box.png");
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::HandleInput( float dt )
	{
		sf::Event event;
        
        player->HandleInput( dt );

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update( float dt )
	{
        player->Update( dt );
        
        World->Step(1 / 60.f, 8, 3);
	}

	void SplashState::Draw( float dt )
	{
		this->_data->window.clear(sf::Color::White);

        player->Draw( dt );
        
        int BodyCount = 0;
        for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                sf::Sprite Sprite;
                Sprite.setTexture(BoxTexture);
                Sprite.setOrigin(16.f, 16.f);
                Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
                Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
                _data->window.draw(Sprite);
                ++BodyCount;
            }
            else
            {
                sf::Sprite GroundSprite;
                GroundSprite.setTexture(GroundTexture);
                GroundSprite.setOrigin(400.f, 8.f);
                GroundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
                GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
                _data->window.draw(GroundSprite);
            }
        }
        
        World->DrawDebugData();

		this->_data->window.display();
	}

    void SplashState::CreateBox(b2World& World, int MouseX, int MouseY)
    {
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2(MouseX / SCALE, MouseY / SCALE);
        BodyDef.type = b2_dynamicBody;
        b2Body* Body = World.CreateBody(&BodyDef);
        
        b2PolygonShape Shape;
        Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
        b2FixtureDef FixtureDef;
        FixtureDef.density = 1.f;
        FixtureDef.friction = 0.7f;
        FixtureDef.shape = &Shape;
        Body->CreateFixture(&FixtureDef);
    }

    void SplashState::CreateGround(b2World& World, float X, float Y)
    {
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2(X / SCALE, Y / SCALE);
        BodyDef.type = b2_staticBody;
        b2Body* Body = World.CreateBody(&BodyDef);
        
        b2PolygonShape Shape;
        Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE);
        b2FixtureDef FixtureDef;
        FixtureDef.density = 0.f;
        FixtureDef.shape = &Shape;
        Body->CreateFixture(&FixtureDef);
    }
}
