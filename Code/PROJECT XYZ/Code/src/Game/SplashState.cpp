#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		map = new MapManager( 2, 4 );

		map->SaveMap( "Resources/test.csv" );

		//csv::CSVFormat csvFormat;
		//csvFormat.no_header( );

		csv::CSVReader reader( "Resources/addresses.csv" );

		for ( csv::CSVRow &row : reader )
		{ // Input iterator
			//for ( csv::CSVField &field : row ) {
				// By default, get<>() produces a std::string.
				// A more efficient get<string_view>() is also available, where the resulting
				// string_view is valid as long as the parent CSVRow is alive
				std::cout << row.to_json_array() << std::endl;
			//}
			nlohmann::json fileData;
			//fileData = nlohmann::json::parse( "{\"1\":{\"dateTime\":1612368265,\"name\":\"JFK\",\"score\":101}}" );
			fileData = nlohmann::json::parse( row.to_json_array() );	

			for ( auto &value : fileData )
			{
				spdlog::info( value );
			}
		}


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
	}

	void SplashState::Draw( const float &dt )
	{
        //player->Draw( dt );
		//physicsWorld->Draw( dt );
	}
}
