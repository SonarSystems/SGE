#include "Core/Game.hpp"
#include "SplashState.hpp"

namespace Sonar
{
	Game::Game( const int &width, const int &height, const std::string &title )
	{
        _data->debug = Debug::getInstance( );
        
		_data->window.Setup( width, height, title );
		_data->machine.AddState( StateRef( new SplashState( _data ) ) );

		Run( );
	}

	void Game::Run( )
	{
		float newTime, frameTime, interpolation;

		float currentTime = _clock.GetElapsedTime( ).AsSeconds( );
		float accumulator = 0.0f;

		while ( _data->window.IsOpen( ) )
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
                sf::Event sfEvent;
				Sonar::Event event( sfEvent );
                
                while ( _data->window.PollEvent( event ) )
                {
                    if ( Sonar::Event::EventType::Closed == event.type )
                    { _data->window.CloseWindow( ); }
                                        
                    _data->machine.GetActiveState( )->PollInput( dt, event );
                }
                
				_data->machine.GetActiveState( )->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
            
			_data->window.Clear( _data->backgroundColor );
			
			_data->machine.GetActiveState( )->Draw( interpolation );
            
            _data->window.Display( );
		}
	}
}
