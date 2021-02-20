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

		//menu->AddComponent( label );

		label2 = new Label( _data );

		label2->SetFontFilePath( "Resources/arial.ttf" );
		label2->SetInsideColor( Color::Blue );
		//label->SetBorderColor( Color::Black );
		//label->SetBorderThickness( 23 );
		label2->SetCharacterSize( 64 );
		label2->SetText( "SECOND" );
		label2->SetPosition( 100, 30 );

		//menu->AddComponent( label2 );

		button = new Button( _data );
		button->SetPadding( 200, 200 );

		menu->AddComponent( button );
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
			button->SetPadding( button->GetPadding( ) + glm::vec2( 0.5, 0.5 ) );
			//physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
		}

		//spdlog::info( rectangle->IsMouseOver( ) );

		if ( rectangle->IsMouseOver( ) )
		{
			rectangle->SetInsideColor( Color::Green );
		}
		else
		{
			rectangle->SetInsideColor( Color::Red );
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

		//button->Draw( );
	}
}
