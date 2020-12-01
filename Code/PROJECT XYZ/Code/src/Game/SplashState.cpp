#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		
		//qte = new QTE( { Keyboard::Key::B, Keyboard::Key::C, Keyboard::Key::F, Keyboard::Key::Z, Keyboard::Key::Num2 }, { 1.0, 2.0, 3.0, 4.0, 5.0 }, 2 );
		//qte = new QTE( { { 1, 0 }, { 1, 4 }, { 1, 0 }, { 1, 1 }, { 1, 3 } }, { 1.0, 2.0, 3.0, 4.0, 5.0 }, 2 );

		qte = new QTE( { Mouse::Button::Left, Mouse::Button::Right, Mouse::Button::Left, Mouse::Button::Middle, Mouse::Button::Right }, { 1.0, 2.0, 3.0, 4.0, 5.0 }, 2 );

		rapido = new RBM( 100, 5, Time( 250000 ), 4.5 );

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

		if ( Event::JoystickButtonReleased == event.type )
		{
			//qte->NextInputJoystick( event.joystickButton.joystickId, event.joystickButton.button );
		}

		if ( Event::MouseButtonReleased == event.type )
		{
			qte->NextInputMouse( event.mouseButton.button );
		}
		
		if ( Event::KeyReleased == event.type )
		{
			if ( Keyboard::Key::Enter == event.key.code )
			{ rapido->TickUp( ); }
		}

		/*std::cout << Joystick::IsPressed( 1, 0 ) << " : " << Joystick::IsPressed( 1, 1 ) << " : " 
			<< Joystick::IsPressed( 1, 2 ) << " : " << Joystick::IsPressed( 1, 3 ) << " : " 
			<< Joystick::IsPressed( 1, 4 ) << std::endl;*/
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );
		
		qte->Update( );

		std::cout << qte->IsComplete( ) << " : " << qte->GetEventPosition( ) << " : " << qte->GetClock( ).GetElapsedTime( ).AsSeconds( ) << std::endl;
		
		//std::cout << rapido->GetCounter( ) << " : " << rapido->GetClock( ).GetElapsedTime( ).AsSeconds( ) << " : " << rapido->IsComplete( ) << std::endl;

		rapido->Update( );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
