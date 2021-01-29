#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		fileManager.OpenFile( "Resources/Hello.txt", FileManager::ACCESS_METHOD::READING );
		/*fileManager.WriteToFile( "Hello World", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );
		fileManager.WriteToFile( "Hello iuh", FileManager::WRITE_PROPERTY::ADD_TO_NEW_LINE );
		fileManager.WriteToFile( "Heliuhiuhd", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );
		fileManager.WriteToFile( "Hehiuhrld", FileManager::WRITE_PROPERTY::ADD_TO_NEW_LINE );
		fileManager.WriteToFile( "Hello World", FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE );*/

		std::vector<std::string> daya2 = fileManager.GetFileContents( );

		for ( auto &line : daya2 )
		{
			spdlog::info( line );
		}

		spdlog::info( "------------------------" );
		fileManager.WriteToFile( { "87777", "2", "3", "4" } );

		std::vector<std::string> daya = fileManager.GetFileContents( );

		for ( auto &line : daya )
		{
			spdlog::info( line );
		}

		//spdlog::info( "------------------------" );

		//std::vector<std::string> daya2 = fileManager.GetFileContents( );

		//for ( auto &line : daya2 )
		//{
		//	spdlog::info( line );
		//}

		////std::string line = fileManager.GetLineFromFile( 0 );

		//spdlog::info( fileManager.GetLineFromFile( 4 ) );
		//spdlog::info( fileManager.GetLineFromFile( 2 ) );
		//spdlog::info( fileManager.GetLineFromFile( 3 ) );
		//spdlog::info( fileManager.GetLineFromFile( 1 ) );
		//spdlog::info( fileManager.GetLineFromFile( 4 ) );
		//spdlog::info( fileManager.GetLineFromFile( 5 ) );
		//spdlog::info( fileManager.GetLineFromFile( 6 ) );
		//spdlog::info( fileManager.GetLineFromFile( 600 ) );
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
