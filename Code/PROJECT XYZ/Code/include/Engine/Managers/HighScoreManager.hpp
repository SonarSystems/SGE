#pragma once

#include "Managers/FileManager.hpp"

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

	private:
		/**
		* \brief Struct of scores 
		*/
		std::vector<ScoreInfo> _scores;

	};
}
