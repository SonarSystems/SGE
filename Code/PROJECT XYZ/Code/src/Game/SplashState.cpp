#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		fileManager.OpenFile( "Hello.txt" );
		fileManager.WriteToFile( "Hello World", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );
		fileManager.WriteToFile( "Hello iuh", FileManager::WRITE_PROPERTY::ADD_TO_NEW_LINE );
		fileManager.WriteToFile( "Heliuhiuhd", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );
		fileManager.WriteToFile( "Hehiuhrld", FileManager::WRITE_PROPERTY::ADD_TO_NEW_LINE );
		fileManager.WriteToFile( "Hello World", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );
	} 

	SplashState::~SplashState( )
	{
		fileManager.CloseFile( );
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
	}
}
