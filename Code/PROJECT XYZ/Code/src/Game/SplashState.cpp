#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		
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

		/*std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::R ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::U ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::V  ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::Z ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::PovX ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::PovY ) << " : " << std::endl;*/


		std::cout << Joystick::IsGestureTriggered( 1, Joystick::AnalogueStick::RightStick, Joystick::Direction::Down ) << std::endl;
		
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
