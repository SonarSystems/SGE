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
		float newTime, frameTime;

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

			while ( accumulator >= _fixedFrameRate )
			{
				Sonar::Event event;
                
                while ( _data->window.PollEvent( event ) )
                {
                    if ( Sonar::Event::EventType::Closed == event.type )
                    {
						_data->machine.GetActiveState( )->Destructor( );
						_data->window.CloseWindow( );
					}
                                        
                    _data->machine.GetActiveState( )->PollInput( _fixedFrameRate, event );
                }
                
				_data->machine.GetActiveState( )->Update( _fixedFrameRate );

				accumulator -= _fixedFrameRate;
			}

			_data->dt = accumulator / _fixedFrameRate;

			_data->debug->UpdateFrameData( frameTime );
            
			_data->window.Clear( _data->backgroundColor );

			ImGui::SFML::Update( _data->window.GetSFMLWindowObject( ), _imGUIClock.SFMLRestart( ) );

			_data->machine.GetActiveState( )->Draw( _data->dt );

			_data->debug->DrawComputerStats( &SHOW_SYSTEM_STATS_OVERLAY, _data->window.GetSize( ) );

			ImGui::SFML::Render( _data->window.GetSFMLWindowObject( ) );

			if ( _data->debug->IsGridEnabled( ) )
			{
				int x = 20, y = 20;

				for ( int i = 1; i <= x; i++ )
				{
					std::shared_ptr<Rectangle> line = std::make_shared<Rectangle>( _data, 3, 720 );

					line->SetInsideColor( Color::Black );
					line->SetPosition( ( ( _data->window.GetSize( ).x / ( x + 1.0f ) ) * i ) - ( line->GetWidth( ) * 0.5f ), 0 );

					line->Draw( );
				}

				for ( int j = 1; j <= y; j++ )
				{
					std::shared_ptr<Rectangle> line = std::make_shared<Rectangle>( _data, 1280, 3 );

					line->SetInsideColor( Color::Black );
					line->SetPosition( 0, ( ( _data->window.GetSize( ).y / ( y + 1.0f ) ) * j ) - ( line->GetHeight( ) * 0.5f ) );

					line->Draw( );
				}
			}
            
            _data->window.Display( );
		}
	}
}
