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

		rapido = new RBM( 100, 5, Time( 250000 ), 4.5 );
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
			//qte->NextInput( event.key.code );
			
			if ( Keyboard::Key::Enter == event.key.code )
			{ rapido->TickUp( ); }
		}
		
		seq.KeyboardPress( Keyboard::Key::A, 5, DIRECTION::UP, false );
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );
		
		qte->Update( );
		
		//std::cout << rapido->GetCounter( ) << " : " << rapido->GetClock( ).GetElapsedTime( ).AsSeconds( ) << " : " << rapido->IsComplete( ) << std::endl;

		rapido->Update( );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
