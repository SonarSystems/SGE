#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		parallax = new Parallax( _data );

		parallax->AddLayer( {
			"Resources/1.png",
			"Resources/2.png",
			"Resources/3.png"
		} );

		parallax->AddLayer( {
			"Resources/Cloud.png",
			"Resources/Cloud.png",
			"Resources/Cloud.png",
			"Resources/Cloud.png",
			"Resources/Cloud.png"
		} );

		parallax->AddLayer( {
			"Resources/Heart.png",
			"Resources/Heart.png",
			"Resources/Heart.png",
			"Resources/Heart.png",
			"Resources/Heart.png"
		} );

		parallax->SetSpeed( 0, 200 );
		parallax->SetSpeed( 1, 400 );
		parallax->SetSpeed( 2, 600 );

		parallax->SetOffset( 1, 350, 150 );
		parallax->SetOffset( 2, 600, 500 );
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
		}
	}

	void SplashState::Update( const float &dt )
	{
        //player->Update( dt );
        
        //physicsWorld->Update( dt );

		parallax->Update( dt );
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );

		parallax->Draw( );
	}
}
