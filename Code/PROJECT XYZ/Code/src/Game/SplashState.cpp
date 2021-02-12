#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		rectangle = new Rectangle( _data, 200, 75 );
		rectangle->SetInsideColor( Color::Red );

		rectangle->SetPosition( 400, 300 );

		label = new Label( _data );

		label->SetFontFilePath( "Resources/Youtube star.ttf" );
		label->SetInsideColor( Color::Red );
		label->SetBorderColor( Color::Black );
		label->SetBorderThickness( 23 );
		label->SetCharacterSize( 256 );
		label->SetText( "HELLO World" );
		label->SetPosition( 200, 300 );
	} 

	SplashState::~SplashState( )
	{
		
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );

		if ( Event::MouseWheelScrolled == event.type )
		{
			//physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
		}
	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		//rectangle->Draw( );
		label->Draw( );
	}
}
