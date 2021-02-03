#include "Managers/HighScoreManager.hpp"

namespace Sonar
{
	HighScoreManager::HighScoreManager( )
	{  }

	HighScoreManager::~HighScoreManager( ) { }

	void HighScoreManager::LoadScoresFromFile( const std::string &filepath )
	{
		_scoresList.clear( );
		_scores.clear( );

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

		nlohmann::json scoreListJSON;

		for ( int i = 0; i < _scoresList.size( ); i++ )
		{
			scoreListJSON[std::to_string( i + 1 )] =
			{
				{ "name", _scoresList.at( i )._name },
				{ "dateTime", _scoresList.at( i )._dateTime },
				{ "score", _scoresList.at( i )._score }
			};
		}

		FileManager manager;
		manager.WriteToFile( filepath, scoreListJSON.dump( ), FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE, true, true );
	}

	int HighScoreManager::CheckScore( const std::vector<long long> &scores, const long long &score )
	{
		for ( int i = 0; i < scores.size( ); i++ )
		{
			if ( score > scores.at( i ) )
			{ return i; }
		}

		return -1;
	}

	void HighScoreManager::UpdateScores( const int &position, const long long &score, const std::string &name )
	{
		std::vector<ScoreInfo> newScoreList;
		std::vector<long long> newScores;

		for ( int i = 0; i < position; i++ )
		{
			newScoreList.push_back( _scoresList.at( i ) );
			newScores.push_back( _scores.at( i ) );
		}

		ScoreInfo newScoreinfo;
		newScoreinfo._dateTime = Time::GetCurrentEpochDateTime( );
		newScoreinfo._name = name;
		newScoreinfo._score = score;

		newScoreList.push_back( newScoreinfo );
		newScores.push_back( score );

		for ( int i = position; i < _scoresList.size( ) - 1; i++ )
		{
			newScoreList.push_back( _scoresList.at( i ) );
			newScores.push_back( _scores.at( i ) );
		}

		_scoresList = newScoreList;
		_scores = newScores;
	}
}
