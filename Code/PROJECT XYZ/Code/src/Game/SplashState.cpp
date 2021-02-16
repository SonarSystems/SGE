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

		menu = new Menu( _data );
		label = new Label( _data );

		label->SetFontFilePath( "Resources/arial.ttf" );
		label->SetInsideColor( Color::Red );
		//label->SetBorderColor( Color::Black );
		//label->SetBorderThickness( 23 );
		label->SetCharacterSize( 128 );
		label->SetText( "HELLO World" );
		label->SetPosition( 200, 300 );

		label->SetStyle( Label::STYLE::Italic, true );
		label->SetStyle( Label::STYLE::StrikeThrough, true );
		label->SetStyle( Label::STYLE::Bold, true );
		label->SetStyle( Label::STYLE::Underlined, true );

		menu->AddComponent( *label );

		label2 = new Label( _data );

		label2->SetFontFilePath( "Resources/arial.ttf" );
		label2->SetInsideColor( Color::Blue );
		//label->SetBorderColor( Color::Black );
		//label->SetBorderThickness( 23 );
		label2->SetCharacterSize( 64 );
		label2->SetText( "SECOND" );
		label2->SetPosition( 100, 30 );

		menu->AddComponent( *label2 );
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
			label->MoveX( 10 );
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
		//label->Draw( );
		menu->Draw( );
	}
}
