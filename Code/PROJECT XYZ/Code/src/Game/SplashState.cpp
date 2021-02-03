#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		HighScoreManager high;

		high.LoadScoresFromFile( "Resources/Scores.json" );
		auto scoresOG = high.GetScores( );

		for ( auto score : scoresOG )
		{
			//std::cout << score._name << " (" << score._dateTime << "): " << score._score << std::endl;
		}

		high.SaveScore( "Resources/Scores.json", 99, "LONDON" );

		/*

		high.SaveScore( "Resources/Scores.txt", 95, "BOB" );*/

		nlohmann::json score;

		score["1"] =
		{
			{ "name", "Frahaan" },
			{ "dateTime", 1111 },
			{ "score", 100 }
		};

		// instead, you could also write (which looks very similar to the JSON above)
		nlohmann::json j2 = {
			{
				"1",
				{
					{ "name", "Frahaan" },
					{ "dateTime", 1111 },
					{ "score", 100 }
				}
			},
			{
				"2",
				{
					{ "name", "Batman" },
					{ "dateTime", 999 },
					{ "score", 90 }
				}
			},
			{
				"3",
				{
					{ "name", "Yoda" },
					{ "dateTime", 888},
					{ "score", 70 }
				}
			},
			{
				"4",
				{
					{ "name", "Darth Vader" },
					{ "dateTime", 777 },
					{ "score", 60 }
				}
			},
			{
				"5",
				{
					{ "name", "Sodam Yat" },
					{ "dateTime", 666 },
					{ "score", 40 }
				}
			},
		};

		//fileManager.WriteToFile( "Resources/Scores.json", j2.dump( ), FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE, true, true );

		nlohmann::json scores = nlohmann::json::parse( fileManager.GetLineFromFile( "Resources/Scores.json", 0 ) );

		for ( auto &score : scores )
		{
			//std::cout << score["name"] << " (" << score["dateTime"] << ") " << " : " << score["score"] << std::endl;
			//std::cout << score["score"] << std::endl;
		}

			//nlohmann::json jsonData = nlohmann::json::parse( your_json );
		//std::cout << scores["2"]["dateTime"] << std::endl;    // returns boolea
		//std::cout << scores["2"]["score"] << std::endl;    // returns boolea
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
