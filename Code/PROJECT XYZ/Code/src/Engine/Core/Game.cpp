#include "Core/Game.hpp"
#include "SplashState.hpp"

namespace Sonar
{
	Game::Game( const int &width, const int &height, const std::string &title )
	{
        _data->debug = Debug::getInstance( );
        
		_data->window.create( sf::VideoMode( width, height ), title, sf::Style::Close | sf::Style::Titlebar );
		_data->machine.AddState( StateRef( new SplashState( _data ) ) );

		Run( );
	}

	void Game::Run( )
	{
		float newTime, frameTime, interpolation;

		float currentTime = _clock.GetElapsedTime( ).AsSeconds( );
		float accumulator = 0.0f;

		while ( _data->window.isOpen( ) )
		{
			_data->machine.ProcessStateChanges( );

			newTime = _clock.GetElapsedTime( ).AsSeconds( );
			frameTime = newTime - currentTime;

			if ( frameTime > 0.25f )
			{ frameTime = 0.25f; }

			currentTime = newTime;
			accumulator += frameTime;

			while ( accumulator >= dt )
			{
                sf::Event event;
                
                while ( _data->window.pollEvent( event ) )
                {
                    if ( sf::Event::Closed == event.type )
                    { _data->window.close( ); }
                                        
                    _data->machine.GetActiveState( )->PollInput( dt, Event( event ) );
                }
                
				_data->machine.GetActiveState( )->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
            
			_data->window.clear( sf::Color( _data->backgroundColor.GetRed( ), _data->backgroundColor.GetGreen( ), _data->backgroundColor.GetBlue( ), _data->backgroundColor.GetAlpha( ) ) );
			
			_data->machine.GetActiveState( )->Draw( interpolation );
            
            _data->window.display( );
		}
	}
}
