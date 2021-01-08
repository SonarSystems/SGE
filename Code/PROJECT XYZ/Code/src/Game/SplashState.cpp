#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		circle = new Circle( _data, 100 );
		circle->SetInsideColor( Color::Red );
		circle->SetBorderColor( Color::Cyan );
		circle->SetBorderThickness( 10 );

		triangle = new Triangle( _data, {0, 0}, {100, 200}, {50, 200} );
		triangle->SetInsideColor( Color::Red );
		//triangle->
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
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
        //sprite->Draw( );
		//circle->Draw( );
		//physicsWorld->Draw( dt );

		triangle->Draw( );
	}
}
