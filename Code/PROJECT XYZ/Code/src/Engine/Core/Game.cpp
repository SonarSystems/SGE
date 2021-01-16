#include "Core/Game.hpp"
#include "SplashState.hpp"

namespace Sonar
{
	Game::Game( const int &width, const int &height, const std::string &title )
	{
        _data->debug = Debug::getInstance( );
        
		_data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );
		_data->machine.AddState( StateRef( new SplashState( this->_data ) ) );

		this->Run( );
	}

	void Game::Run( )
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime( ).asSeconds( );
		float accumulator = 0.0f;

		while ( this->_data->window.isOpen( ) )
		{
			this->_data->machine.ProcessStateChanges( );

			newTime = this->_clock.getElapsedTime( ).asSeconds( );
			frameTime = newTime - currentTime;

			if ( frameTime > 0.25f )
			{ frameTime = 0.25f; }

			currentTime = newTime;
			accumulator += frameTime;

			while ( accumulator >= dt )
			{
                sf::Event event;
                
                while ( this->_data->window.pollEvent( event ) )
                {
                    if ( sf::Event::Closed == event.type )
                    { this->_data->window.close( ); }
                                        
                    this->_data->machine.GetActiveState( )->PollInput( dt, Event( event ) );
                }
                
				this->_data->machine.GetActiveState( )->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
            
            this->_data->window.clear( sf::Color( _data->backgroundColor.GetRed( ), _data->backgroundColor.GetGreen( ), _data->backgroundColor.GetBlue( ), _data->backgroundColor.GetAlpha( ) ) );
            
			this->_data->machine.GetActiveState( )->Draw( interpolation );
            
            this->_data->window.display( );
		}
	}
}
