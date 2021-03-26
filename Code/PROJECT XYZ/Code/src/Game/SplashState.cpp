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

		//menu->AddComponent( label );

		button = new Button( _data );
		//button->SetPosition( 300, 300 );
		//button->SetScale( 2.5, 2.5 );
		//button->SetPadding( 50, 50 );
		button->SetText( "BOB", true );
		button->SetFontFilePath( "Resources/arial.ttf" );
		//menu->AddComponent( button );

		textBox = new TextBox( _data );

		textBox->SetFontFilePath( "Resources/arial.ttf" );
		textBox->SetInsideColor( Color::Red );
		textBox->SetCharacterSize( 128 );
		textBox->SetText( "" );
		textBox->SetPosition( 200, 300 );
		textBox->SetClickableSize( 200, 200 );

		//menu->AddComponent( textBox );

		group = new RadioButtonGroup( _data );

		radio = new RadioButton( _data );
		radio->SetColor( Color::Blue );
		radio->SetCheckedColor( Color::Red );
		radio->SetPosition( 100, 300 );
		radio->SetBorderThickness( 5 );
		radio->SetRadius( 50 );

		radio2 = new RadioButton( _data );
		radio2->SetColor( Color::Magenta );
		radio2->SetCheckedColor( Color::Black );
		radio2->SetPosition( 300, 300 );
		radio2->SetBorderThickness( 10 );
		radio2->SetRadius( 70 );

		radio3 = new RadioButton( _data );
		radio3->SetColor( Color::Magenta );
		radio3->SetCheckedColor( Color::Black );
		radio3->SetPosition( 700, 300 );
		radio3->SetBorderThickness( 15 );
		radio3->SetRadius( 40 );
		
		group->AddRadioButton( radio );
		group->AddRadioButton( radio2 );
		group->AddRadioButton( radio3 );

		menu->AddComponent( group );
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

		textBox->PollInput( dt, event );
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
