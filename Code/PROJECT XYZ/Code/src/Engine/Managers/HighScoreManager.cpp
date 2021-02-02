#include "Managers/HighScoreManager.hpp"

namespace Sonar
{
	HighScoreManager::HighScoreManager( )
	{  }

	HighScoreManager::~HighScoreManager( ) { }

	void HighScoreManager::LoadScoresFromFile( const std::string &filepath )
	{
		FileManager manager;

		nlohmann::json scoreFileData = nlohmann::json::parse( manager.GetLineFromFile( filepath, 0 ) );

		ScoreInfo scoreInfo;

		for ( auto &score : scoreFileData )
		{
			scoreInfo._name = score["name"];
			scoreInfo._dateTime = score["dateTime"];
			scoreInfo._score = score["score"];

			_scores.push_back( scoreInfo._score );
			_scoresList.push_back( scoreInfo );
		}

		//for ( auto &line : scoreFileData )
		//{
		//	if ( 0 == counter % 3 ) // NAME
		//	{
		//		auto trimmed = line;
		//		trimmed.erase( std::remove( trimmed.begin( ), trimmed.end( ), '\r' ), trimmed.end( ) );

		//		scoreInfo._name = trimmed;
		//	}
		//	else if ( 1 == counter % 3 ) // DATE
		//	{
		//		scoreInfo._dateTime = std::stoll( line );
		//	}
		//	else if ( 2 == counter % 3 ) // SCORE
		//	{
		//		scoreInfo._score = std::stoll( line );
		//		
		//		_scoresList.push_back( scoreInfo );
		//		_scores.push_back( std::stoll( line ) );
		//	}

		//	counter++;
		//}
	}

	std::vector<Sonar::ScoreInfo> HighScoreManager::GetScores( ) const
	{ return _scoresList; }

	void HighScoreManager::SaveScore( const std::string &filepath, const long long &score, const std::string &name )
	{
		LoadScoresFromFile( filepath );

		int position = CheckScore( _scores, score );

		if ( -1 == position )
		{ return; }

		UpdateScores( position, score, name );

		std::vector<std::string> fileList;
		
		for ( auto &score : _scoresList )
		{
			fileList.push_back( score._name );
			fileList.push_back( std::to_string( score._dateTime ) );
			fileList.push_back( std::to_string( score._score ) );
		}

		FileManager manager;
		manager.WriteToFile( filepath, fileList, FileManager::WRITE_PROPERTY::ADD_TO_NEW_LINE, true, true );
	}

	int HighScoreManager::CheckScore( const std::vector<long long> &scores, const long long &score )
	{
		spdlog::info( "uihiuh" );
		for ( int i = 0; i < scores.size( ); i++ )
		{
			spdlog::info( "1" );
			if ( score > scores.at( i ) )
			{
				spdlog::info( "2" );
				return i;
			}
		}

		return -1;
	}
	/*
	
	NEW - 95

	0 - 100
	1 - 90
	2 - 80
	3 - 70
	4 - 60
	
	*/

	void HighScoreManager::UpdateScores( const int &position, const long long &score, const std::string &name )
	{
		std::vector<ScoreInfo> scoreBackup;
		std::vector<ScoreInfo> newScoreList;

		for ( int i = 0; i < position; i++ )
		{
			newScoreList.push_back( _scoresList.at( i ) );
		}

		ScoreInfo newScoreinfo;
		newScoreinfo._dateTime = Time::GetCurrentEpochDateTime( );
		newScoreinfo._name = name;
		newScoreinfo._score = score;

		newScoreList.push_back( newScoreinfo );

		for ( int i = position; i < _scores.size( ) - 2; i++ )
		{
			newScoreList.push_back( _scoresList.at( i ) );
		}

		_scoresList = newScoreList;

		/*for ( int i = _scores.size( ) - 1; i >= position; i-- )
		{
			scoreBackup.push_back( _scoresList.at( i ) );
		}*/
	}
}
