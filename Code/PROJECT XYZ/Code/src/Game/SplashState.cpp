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

		/*
		vendorid
		-------------------------
		1356 - Sony
		1118 - Microsoft

		productid
		-------------------------
		3290 - PS Classic
		2508 - PS4 controller new (with extra light in touch bar)
		1476 - PS4 controller old (without extra light in touch bar)
		721 - Xbox One Wireless (using Xbox One Dongle)
		736 - Xbox One Wireless (using Bluetooth)
		767 - Xbox One Wired
		2834 - Xbox Series Wireless (using Xbox One Dongle)
		2835 - Xbox Series Wireless (using Bluetooth)
		*/
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
