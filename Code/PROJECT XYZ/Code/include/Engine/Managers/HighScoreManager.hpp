#pragma once

#include "Core/Time.hpp"
#include "Managers/FileManager.hpp"
#include <spdlog/spdlog.h>

namespace Sonar
{
	/**
	* \brief Struct for each players score info
	*/
	struct ScoreInfo
	{
		std::string _name;
		unsigned long long _dateTime;
		unsigned long long _score;
	};

	class HighScoreManager
	{
	public:
		/**
		 * \brief Default class constructor
		*/
		HighScoreManager( );

		/**
		 * \brief Class destructor
		*/
		~HighScoreManager( );

		/**
		* \brief Load the scores from a local file
		*
		* \param filePath Score file location
		*/
		void LoadScoresFromFile( const std::string &filepath );

		/**
		* \brief Get the scores (name, date time & score)
		*
		* \return Output returns the scores loaded into memory
		*/
		std::vector<ScoreInfo> GetScores( ) const;

		void SaveScore( const std::string &filepath, const long long &score, const std::string &name );

		int CheckScore( const std::vector<long long> &scores, const long long &score );

	private:
		void UpdateScores( const int &position, const long long &score, const std::string &name );

		/**
		* \brief Struct of scores 
		*/
		std::vector<ScoreInfo> _scoresList;

		std::vector<long long> _scores;

	};
}
