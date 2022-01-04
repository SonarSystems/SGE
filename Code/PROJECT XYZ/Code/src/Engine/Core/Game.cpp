#include "pch.hpp"
#include "SplashState.hpp"

namespace Sonar
{
	static bool SHOW_SYSTEM_STATS_OVERLAY = SHOW_SYSTEM_STATS_OVERLAY_ON_LAUNCH;

	Game::Game( const int &width, const int &height, const std::string &title )
	{
        _data->debug = Debug::getInstance( );
        
		Window::Style style;

		_data->window.Setup( width, height, title, style );
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
				Sonar::Event event;
                
                while ( _data->window.PollEvent( event ) )
                {
                    if ( Sonar::Event::EventType::Closed == event.type )
                    {
						_data->machine.GetActiveState( )->Destructor( );
						_data->window.CloseWindow( );
					}
                                        
                    _data->machine.GetActiveState( )->PollInput( dt, event );
                }
                
				_data->machine.GetActiveState( )->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;

			_data->debug->UpdateFrameData( frameTime );
            
			_data->window.Clear( _data->backgroundColor );

			ImGui::SFML::Update( _data->window.GetSFMLWindowObject( ), _imGUIClock.SFMLRestart( ) );

			_data->machine.GetActiveState( )->Draw( interpolation );

			_data->debug->DrawComputerStats( &SHOW_SYSTEM_STATS_OVERLAY, _data->window.GetSize( ) );

			ImGui::SFML::Render( _data->window.GetSFMLWindowObject( ) );
            
            _data->window.Display( );
		}
	}
}
