#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		circle = new Circle( _data, 100 );
		circle->SetInsideColor( Color::Red );

		circle->SetScale(0.1f, 0.1f);
		circle->SetPulse( 0.5, 0.5, Seconds( 1 ) );
		circle->SetPivot( OBJECT_POINTS::CENTER );
		circle->SetPosition( 200, 200 );

		circle2 = new Circle( _data, 100 );
		circle2->SetInsideColor( Color::Blue );
		circle2->SetPivot( OBJECT_POINTS::CENTER );
		circle2->SetPosition( 200, 500 );

		circle3 = new Circle( _data, 150 );
		circle3->SetInsideColor( Color::Green );
		circle3->SetPivot( OBJECT_POINTS::CENTER );
		circle3->SetPosition( 500, 200 );

		triangle = new Triangle( _data, {0, 0}, {100, 200}, {50, 200} );
		triangle->SetInsideColor( Color::Red );
		triangle->SetRotation( 20 );
	} 

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );

		if ( Event::MouseWheelMoved == event.type )
		{
			circle->StopPulse( );
			//circle->SetPulse( 0.9, 0.9, Seconds( 2 ) );
			physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
		}
	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		circle->Update( dt );
		circle2->Update( dt );
		circle3->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
        //sprite->Draw( );
		circle->Draw( );
		circle2->Draw( );
		circle3->Draw( );
		//physicsWorld->Draw( dt );

		//triangle->Draw( );
	}
}
