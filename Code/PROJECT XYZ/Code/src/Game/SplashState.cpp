#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		joy = new Joystick( 0 );

		for ( int i = 0; i < Joystick::Count; i++ )
		{
			if ( Joystick::IsConnected( i ) )
			{
				Joystick::Identification id = Joystick::GetIdentification( i );

				std::cout << i << ": " << id.name << " - " << id.vendorId << " - " << id.productId << std::endl;
			}
		}

		std::cout << "-----------------" << std::endl;

		auto id = Joystick::IdentifyJoystick( 3 );

		//std::cout << std::get<0>( id ) << " : " << std::get<1>( id ) << " : " << std::get<2>( id ) 
		//	<< " : " << std::get<3>( id ) << std::endl;

		auto joysticks = Joystick::GetControllerList( );

		for ( const auto &element : joysticks )
		{
			std::cout << std::get<0>( element ) << " : " << std::get<1>( element ) << " : " << std::get<2>( element )
				<< " : " << std::get<3>( element ) << " : " << std::get<4>( element ) << std::endl;
		}
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
			joy->SetVibration( 1.0f, 0.0f );
        }
		else if ( Event::MouseButtonPressed == event.type )
		{
			joy->DisableVibration( );
		}
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );

		joy->Update( );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
		physicsWorld->Draw( dt );
	}
}
