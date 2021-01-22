#include "SplashState.hpp"

#define SPEED 100

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		rectangle = new Rectangle( _data );
		rectangle->SetSize( 200, 150 );
		rectangle->SetInsideColor( Color::Red );
		rectangle->SetScale( 2, 2 );

		circle1 = new Circle( _data, 50 );
		circle1->SetInsideColor( Color::Blue );

		circle2 = new Circle( _data, 100 );
		circle2->SetInsideColor( Color::Green );
		circle2->SetPosition( 200, 300 );

		spr = new Sprite( _data, "Resources/Background.jpg" );
		spr2 = new Sprite( _data, "Resources/Background.jpg" );

		parallax = new Parallax( _data );
		parallax2 = new Parallax( _data );

		parallax->SetBackgrounds( {
			new Sprite( _data, "Resources/1.png" ),
			new Sprite( _data, "Resources/2.png" ),
			new Sprite( _data, "Resources/3.png" )
		} );

		parallax2->SetBackgrounds( {
			new Sprite( _data, "Resources/Cloud.png" ),
			new Sprite( _data, "Resources/Cloud.png" ),
			new Sprite( _data, "Resources/Cloud.png" ),
			new Sprite( _data, "Resources/Cloud.png" ),
			new Sprite( _data, "Resources/Cloud.png" )
		} );

		parallax2->SetSpeed( 500 );
		parallax2->SetDirection( Parallax::DIRECTION::UP );
		parallax2->SetOffset( 350, 250 );

		parallax->SetSpeed( 500 );
		//parallax->SetDirection( Parallax::DIRECTION::RIGHT );
		parallax->SetScrollToManual( Parallax::ORIENTATION::VERTICAL );
		//parallax->SetSpeed( 0 );
		//parallax->SetDirection( Parallax::DIRECTION::DOWN );
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

			std::cout << (float)event.mouseWheelScroll.delta << std::endl;
			

			if ( event.mouseWheelScroll.delta < 0 )
			{
				parallax->Move( Parallax::DIRECTION::UP, -event.mouseWheelScroll.delta * 600 );
			}
			else
			{
				parallax->Move( Parallax::DIRECTION::DOWN, event.mouseWheelScroll.delta * 600 );
			}
		}
	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		if ( Keyboard::IsPressed( Keyboard::Key::Left ) )
		{
			parallax->Reset( );
		}

		parallax->Update( dt );
		parallax2->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		//rectangle->Draw( );
		//circle1->Draw( );
		//circle2->Draw( );

		parallax->Draw( );
		parallax2->Draw( );

		//spr->Draw( );
	}
}
