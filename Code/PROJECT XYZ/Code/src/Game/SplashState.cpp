#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

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

		menu->AddComponent( label );

		button = new Button( _data );
		//button->SetPosition( 300, 300 );
		//button->SetScale( 2.5, 2.5 );
		//button->SetPadding( 50, 50 );
		button->SetText( "BOB", true );
		menu->AddComponent( button );

		textBox = new TextBox( _data );

		textBox->SetFontFilePath( "Resources/arial.ttf" );
		textBox->SetInsideColor( Color::Red );
		//label->SetBorderColor( Color::Black );
		//label->SetBorderThickness( 23 );
		textBox->SetCharacterSize( 128 );
		textBox->SetText( "HELLO World" );
		textBox->SetPosition( 200, 300 );

		menu->AddComponent( textBox );
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

		//button->Update( );

		menu->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		menu->Draw( );

		//textBox->Draw( );
	}
}
