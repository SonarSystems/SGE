#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		
		qte = new QTE( { Keyboard::Key::B, Keyboard::Key::C, Keyboard::Key::F, Keyboard::Key::Z, Keyboard::Key::Num2 }, { 1.0, 2.0, 3.0, 4.0, 5.0 }, 2 );
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
		
		if ( Event::KeyReleased == event.type )
		{
			qte->NextInput( event.key.code );
		}
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );
		
		qte->Update( );
		
		//std::cout << " has been pressed for: " << seq.MousePressedTimer( Mouse::Button::Left ).AsSeconds( ) << " seconds" << std::endl;
		
		
		//qte->NextInput( Keyboard::Key::C );
		
		std::cout << "--------------------" << std::endl;
		
		//std::cout << "Is Completed: " << qte->IsComplete( ) << std::endl;
		
		std::cout << "Timer: " << qte->GetClock( ).GetElapsedTime( ).AsSeconds( ) << std::endl;
		
		for ( int i = 0; i < qte->GetEventCount( ); i++ )
		{
			if ( qte->GetEventPosition( ) > i )
			{
				//std::cout << 1 << std::endl;
			}
			else
			{
				//std::cout << 0 << std::endl;
			}
		}
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
