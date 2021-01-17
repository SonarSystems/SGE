#include "SplashState.hpp"

#define SPEED 100

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		rectangle = new Rectangle( _data );
		rectangle->SetSize( 200, 150 );
		rectangle->SetInsideColor( Color::Red );
		rectangle->SetScale( 2, 2 );

		circle1 = new Circle( _data, 50 );
		circle1->SetInsideColor( Color::Blue );

		circle2 = new Circle( _data, 100 );
		circle2->SetInsideColor( Color::Green );
		circle2->SetPosition( 200, 300 );
	} 

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );

		if ( Event::MouseWheelMoved == event.type )
		{
			physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
		}
	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		if ( Keyboard::IsPressed( Keyboard::Key::Left ) )
		{
			circle1->MoveX( dt * -SPEED );
		}

		if ( Keyboard::IsPressed( Keyboard::Key::Right ) )
		{
			circle1->MoveX( dt * SPEED );
		}

		if ( Keyboard::IsPressed( Keyboard::Key::Up ) )
		{
			circle1->MoveY( dt * -SPEED );
		}

		if ( Keyboard::IsPressed( Keyboard::Key::Down ) )
		{
			circle1->MoveY( dt * SPEED );
		}

		if ( circle1->CircleCollision( *circle2 ) )
		{
			spdlog::info( "Collision detected" );
		}
		else
		{
			spdlog::info( "NO COLLISION" );
		}
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		//rectangle->Draw( );
		circle1->Draw( );
		circle2->Draw( );
	}
}
