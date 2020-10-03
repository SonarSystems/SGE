#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		
		qte = new QTE( { Keyboard::Key::B, Keyboard::Key::C, Keyboard::Key::F, Keyboard::Key::Z, Keyboard::Key::Num2,  } );
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
		
		//std::cout << " has been pressed for: " << seq.MousePressedTimer( Mouse::Button::Left ).AsSeconds( ) << " seconds" << std::endl;
		
		
		qte->NextInput( Keyboard::Key::B );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
