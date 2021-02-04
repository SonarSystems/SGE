#include "Managers/HighScoreManager.hpp"

namespace Sonar
{
	HighScoreManager::HighScoreManager( const unsigned int &maxNumOfHighScores ) : _maxNumOfHighScores( maxNumOfHighScores )
	{  }

	HighScoreManager::~HighScoreManager( ) { }

	void HighScoreManager::LoadScoresFromFile( const std::string &filepath )
	{
		_scoresList.clear( );
		_scores.clear( );

		FileManager manager;
		nlohmann::json scoreFileData;

		const std::string fileData = manager.GetLineFromFile( filepath, 0 );

		if ( manager.GetStatus( ) == FileManager::FILE_STATUS::OPEN )
		{ scoreFileData = nlohmann::json::parse( fileData ); }

		ScoreInfo scoreInfo;

		for ( int i = 0; i < _maxNumOfHighScores; i++ )
		{
			if ( i < scoreFileData.size( ) )
			{
				const std::string index = std::to_string( i + 1 );

				scoreInfo._name = scoreFileData[index]["name"];
				scoreInfo._dateTime = scoreFileData[index]["dateTime"];
				scoreInfo._score = scoreFileData[index]["score"];

			}
			else
			{
				scoreInfo._name = HIGH_SCORE_DEFAULT_NAME;
				scoreInfo._dateTime = HIGH_SCORE_DEFAULT_DATE_TIME;
				scoreInfo._score = HIGH_SCORE_DEFAULT_SCORE;
			}

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

		SaveFile( filepath );
	}

	int HighScoreManager::CheckScore( const std::vector<long long> &scores, const long long &score ) const
	{
		for ( int i = 0; i < scores.size( ); i++ )
		{
			if ( score > scores.at( i ) )
			{ return i; }
		}

		return -1;
	}

	void HighScoreManager::SetMaximumNumberOfHighScores( const unsigned int &maxNumOfHighScores )
	{ _maxNumOfHighScores = maxNumOfHighScores; }

	unsigned int HighScoreManager::GetMaximumNumberOfHighScores( ) const
	{ return _maxNumOfHighScores; }

	void HighScoreManager::CreateSaveFile( const std::string &filepath, const unsigned int &maxNumOfHighScores, const std::string &defaultName /*= HIGH_SCORE_DEFAULT_NAME*/, const long long &defaultDateTime /*= HIGH_SCORE_DEFAULT_DATE_TIME*/, const long long &defaultScore /*= HIGH_SCORE_DEFAULT_SCORE */ )
	{
		_scoresList.clear( );
		_scores.clear( );

		ScoreInfo scoreInfo;

		for ( int i = 0; i < maxNumOfHighScores; i++ )
		{
			scoreInfo._name = defaultName;
			scoreInfo._dateTime = defaultDateTime;
			scoreInfo._score = defaultScore;

			_scores.push_back( scoreInfo._score );
			_scoresList.push_back( scoreInfo );
		}

		SaveFile( filepath );
	}

	void HighScoreManager::UpdateScores( const int &position, const long long &score, const std::string &name )
	{
		std::vector<ScoreInfo> newScoresList;
		std::vector<long long> newScores;

		for ( int i = 0; i < position; i++ )
		{
			newScoresList.push_back( _scoresList.at( i ) );
			newScores.push_back( _scores.at( i ) );
		}

		ScoreInfo newScoreinfo;
		newScoreinfo._dateTime = Time::GetCurrentEpochDateTime( );
		newScoreinfo._name = name;
		newScoreinfo._score = score;

		newScoresList.push_back( newScoreinfo );
		newScores.push_back( score );

		for ( int i = position; i < _scoresList.size( ) - 1; i++ )
		{
			newScoresList.push_back( _scoresList.at( i ) );
			newScores.push_back( _scores.at( i ) );
		}

		_scoresList = newScoresList;
		_scores = newScores;
	}

	void HighScoreManager::SaveFile( const std::string &filepath )
	{
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

}
