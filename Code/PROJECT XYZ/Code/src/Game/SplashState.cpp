#include "pch.hpp"
#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
		ImGui::SFML::Init( _data->window.GetSFMLWindowObject( ) );

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

		button = std::make_shared<Button>( _data );
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

		//menu->AddComponent( group );

		slider = new Slider( data );
		slider->SetJumpAmount( 15 );
		//slider->SetScale( 4 );

		//menu->AddComponent( slider );

		buttonGroup = std::make_shared<ButtonGroup>( _data );

		button = std::make_shared<Button>( _data );
		button2 = std::make_shared<Button>( _data );
		button3 = std::make_shared<Button>( _data );

		//button->SetPosition( 100, 100 );
		button->SetText( "PLAY", true );
		button->SetFontFilePath( "Resources/arial.ttf" );
		//button->Update(1);

		//button2->SetPosition( 100, 300 );
		button2->SetText( "LOAD", true );
		button2->SetFontFilePath( "Resources/arial.ttf" );
		//button2->Update(1 );

		//button3->SetPosition( 100, 500 );
		button3->SetText( "EXIT", true );
		button3->SetFontFilePath( "Resources/arial.ttf" );
		//button3->Update( 1);

		buttonGroup->AddButton( button );
		buttonGroup->AddButton( button2 );
		buttonGroup->AddButton( button3 );

		buttonGroup->AddNavigationKeyPair( Keyboard::Key::A, Keyboard::Key::D );
		buttonGroup->SetPositionToCenter( true, true );

		menu->AddComponent( buttonGroup );

		progressBar = new ProgressBar( _data, ProgressBar::Orientation::HORIZONTAL );
		progressBar->SetPosition( 200, 200 );
		progressBar->SetBackgroundSize( 400, 50 );
		progressBar->SetProgressBarSizePercentage( 1 );

		//menu->AddComponent( progressBar, true );

		progressBar->SetBackgroundBorderColor( Color::Red );
		progressBar->SetBackgroundBorderThickness( 20 );

		mm = new Minimap( _data );
		mm->SetPosition( Minimap::POSITION::BOTTOM_RIGHT );
		mm->AddObject( "Enemy", glm::vec2( 100, 0 ), 10 );
		mm->AddObject( "Friendly", glm::vec2( 100, 200 ), 10 );
		mm->AddObject( "Enemy", glm::vec2( 150, 0 ), 10 );
		mm->AddObject( "Friendly", glm::vec2( 150, 200 ), 10 );
		mm->AddObject( "Enemy", glm::vec2( 200, 0 ), 10 );
		mm->AddObject( "Friendly", glm::vec2( 200, 200 ), 10 );
	}

	SplashState::~SplashState( )
	{
		
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, Event &event )
	{
		ImGui::SFML::ProcessEvent( event.GetSFMLEventObject( ) );

        player->HandleInput( dt );

		if ( Event::MouseWheelScrolled == event.type )
		{
			progressBar->Increment( );

			//mm->RemoveObjectByType( "Test" );

			mm->HideObjectByID( 0 );

			//physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
		}
		else if ( Event::MouseButtonReleased == event.type )
		{
			mm->UpdateObjectColorByType( "Enemy", Color::Cyan );
		}

		menu->PollInput( dt, event );
	}

	void SplashState::Update( const float &dt )
	{
		
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		//button->Update( );

		menu->Update( dt );

		mm->Update( dt );

		if ( buttonGroup->GetButtonClickedIndex( ) == 0 )
		{ spdlog::info( "PLAY" ); }
		else if ( buttonGroup->GetButtonClickedIndex( ) == 1 )
		{ spdlog::info( "SETTINGS" ); }
		else if ( buttonGroup->GetButtonClickedIndex( ) == 2 )
		{ spdlog::info( "QUIT" ); }

	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		

		menu->Draw( );

		

		//mm->Draw( );

		//view->Draw( );

		//textBox->Draw( );


		//ImGui::Begin( "Sample window" ); // begin window
		ImGui::ShowDemoWindow( ); // check out simple overlay example in examples menu
	
		//// Window title text edit
		//ImGui::InputText( "Window title", windowTitle, 255 );

		//if ( ImGui::Button( "Update window title" ) ) {
		//	// this code gets if user clicks on the button
		//	// yes, you could have written if(ImGui::InputText(...))
		//	// but I do this to show how buttons work :)
		//	_data->window.SetTitle( windowTitle );
		//}

		//ImGui::End( );
		
	}
}
