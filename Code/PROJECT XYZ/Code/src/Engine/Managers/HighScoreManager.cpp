#include "Managers/HighScoreManager.hpp"

namespace Sonar
{
	HighScoreManager::HighScoreManager( )
	{  }

	HighScoreManager::~HighScoreManager( ) { }

	void HighScoreManager::LoadScoresFromFile( const std::string &filepath )
	{
		FileManager manager;

		auto scoreFileData = manager.GetFileContents( filepath );

		unsigned int counter = 0;

		ScoreInfo scoreInfo;

		for ( std::string &line : scoreFileData )
		{
			if ( 0 == counter % 3 ) // NAME
			{
				scoreInfo._name = line;
			}
			else if ( 1 == counter % 3 ) // DATE
			{
				scoreInfo._dateTime = std::stoi( line );
			}
			else if ( 2 == counter % 3 ) // SCORE
			{
				scoreInfo._score = std::stoi( line );

				_scores.push_back( scoreInfo );
			}

			counter++;
		}
	}

	std::vector<Sonar::ScoreInfo> HighScoreManager::GetScores( ) const
	{ return _scores; }

}
