#include "PhysicsWorld.hpp"

namespace Sonar
{
    /** We need this to easily convert between pixel and real-world coordinates*/
    static const float SCALE = 30.f;

    PhysicsWorld::PhysicsWorld( GameDataRef data ): _data( data )
    {        
        _data->assets.LoadTexture("Ground Texture", "Resources/ground.png");
        //_data->assets.LoadTexture("Box Texture", "Resources/box.png");

        /** Prepare the world */
        //Gravity = b2Vec2( 0.f, 9.8f );
        //World = new b2World( Gravity );
        //CreateStaticBody( 0, 952, 1920, 128 );
        //
        //World->SetDebugDraw(&fooDrawInstance);
        //uint32 flags = 0;
        //flags += b2Draw::e_shapeBit;
        //flags += b2Draw::e_jointBit;
        //flags += b2Draw::e_aabbBit;
        //flags += b2Draw::e_pairBit;
        //flags += b2Draw::e_centerOfMassBit;
        //fooDrawInstance.SetFlags(flags);
    }

    void PhysicsWorld::Update( float dt )
    {
        World->Step( dt, 8, 3 );
    }

    void PhysicsWorld::Draw( float dt )
    {
        /*int BodyCount = 0;
        for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                sf::Sprite Sprite;
                Sprite.setTexture(_data->assets.GetTexture("Box Texture"));
                Sprite.setOrigin(16.f, 16.f);
                Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
                Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
                _data->window.draw(Sprite);
                ++BodyCount;
            }
            else
            {
                sf::Sprite GroundSprite;
                GroundSprite.setTexture(_data->assets.GetTexture("Ground Texture"));
                
                float relativeX = ( BodyIterator->GetPosition().x * SCALE ) - ( GroundSprite.getLocalBounds().width / 2 );
                float relativeY = ( BodyIterator->GetPosition().y * SCALE ) - ( GroundSprite.getLocalBounds().height / 2 );
                
                GroundSprite.setPosition(relativeX, relativeY);
                GroundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
                //GroundSprite.scale(0, 0);
                
                _data->window.draw(GroundSprite);
            }
        }
        
        if ( _data->debug->IsPhysicsEnabled( ) )
        { World->DrawDebugData(); }*/
    }

    void PhysicsWorld::CreateDynamicBody( float posX, float posY, float width, float height, float density, float friction )
    {
        float relativeX = posX + ( width / 2 );
        float relativeY = posY + ( height / 2 );
        
        
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2( relativeX / SCALE, relativeY / SCALE );
        BodyDef.type = b2_dynamicBody;
        b2Body *Body = World->CreateBody( &BodyDef );
        
        b2PolygonShape Shape;
        Shape.SetAsBox( ( width / 2 ) / SCALE, ( height / 2 ) / SCALE );
        b2FixtureDef FixtureDef;
        FixtureDef.density = 1.f;
        FixtureDef.friction = 1.f;
        FixtureDef.shape = &Shape;
        Body->CreateFixture( &FixtureDef );
    }

    void PhysicsWorld::CreateStaticBody( float posX, float posY, float width, float height, float density )
    {
        float relativeX = posX + ( width / 2 );
        float relativeY = posY + ( height / 2 );
        
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2( relativeX / SCALE, relativeY / SCALE );
        BodyDef.type = b2_staticBody;
        b2Body *Body = World->CreateBody( &BodyDef );
        
        b2PolygonShape Shape;
        Shape.SetAsBox( ( width / 2 ) / SCALE, ( height / 2 ) / SCALE );
        b2FixtureDef FixtureDef;
        FixtureDef.density = density;
        FixtureDef.shape = &Shape;
        Body->CreateFixture( &FixtureDef );
    }
}
