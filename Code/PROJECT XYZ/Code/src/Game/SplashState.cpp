#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		rectangle = new Rectangle( _data );
		rectangle->SetSize( 200, 75 );
		rectangle->SetPivot( OBJECT_POINTS::CENTER );
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
		//button->SetPosition( 300, 300 );
		//button->SetScale( 2.5, 2.5 );
		//button->SetPadding( 50, 50 );
		button->SetText( "BOB", true );
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
			//physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
			
		}


	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		/*spdlog::info( "Clicked: {0}", button->IsClicked( Mouse::Button::Left ) );
		spdlog::info( "Hover: {0}", button->IsMouseOver( ) );
		spdlog::info( "------------------------------------------------" );*/

		button->Update( );
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
