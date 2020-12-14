#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		gesture = new Gesture( 1, AnalogueStick::LeftStick, Pattern::Clockwise );
		
		std::cout << Joystick::IsConnected( 1 ) << std::endl;
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
        player->Update( dt );
        
        physicsWorld->Update( dt );

		gesture->Update( );

		//std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " :: " << Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << std::endl;

		//std::cout << gesture->IsComplete( ) << std::endl;
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}
}
