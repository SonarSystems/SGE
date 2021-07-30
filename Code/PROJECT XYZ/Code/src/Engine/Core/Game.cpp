#include "pch.hpp"
#include "SplashState.hpp"

namespace Sonar
{
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
			frames++;

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
                    { _data->window.CloseWindow( ); }
                                        
                    _data->machine.GetActiveState( )->PollInput( dt, event );
                }
                
				_data->machine.GetActiveState( )->Update( dt );

				accumulator -= dt;
			}

			interpolation = accumulator / dt;



			spdlog::info( "FPS: {}", 1.0f / frameTime );
			spdlog::info( "Frame Time: {}ms", frameTime * 1000 );
			spdlog::info( "Total Number Of Frames: {}", frames );

			Sonar::SysInfo s;

				//Timestamp + Memory Info, and eventually CPU Load percentage

				//Sonar::SystemInformation info = s.GetSystemInformation( );


				/*			std::cout
								<< info._timestamp._hour << ":"
								<< info._timestamp._minutes << ":"
								<< info._timestamp._seconds << ":"
								<< info._timestamp._milliseconds << " - "
								<< info._gpus.front( )._name << " - "
								<< info._gpus.front( )._manufacturer << " - "
								<< info._gpus.front( )._caption << " - "
								<< info._gpus.front( )._ram << " - "
								<< info._gpus.front( )._refreshRate << " - "
								<< info._gpus.front( )._driverVersion << " - "
								<< info._gpus.front( )._videoArchitecture << " - "
								<< info._gpus.front( )._videoModeDescription << " - "
								<< info._gpus.front( )._videoProcessor << " - "
								<< std::endl;*/
            
			_data->window.Clear( _data->backgroundColor );

			ImGui::SFML::Update( _data->window.GetSFMLWindowObject( ), _imGUIClock.SFMLRestart( ) );

			_data->machine.GetActiveState( )->Draw( interpolation );

			ImGui::SFML::Render( _data->window.GetSFMLWindowObject( ) );
            
            _data->window.Display( );
		}
	}
}
