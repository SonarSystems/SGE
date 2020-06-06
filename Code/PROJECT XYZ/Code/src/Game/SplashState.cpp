#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
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
        
        if ( Input::AnyMouseButtonPressed( event ) )
        {
            Debug::Print( "YAS QUEEN2" );
        }
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
		this->_data->window.clear( sf::Color::White );

        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
