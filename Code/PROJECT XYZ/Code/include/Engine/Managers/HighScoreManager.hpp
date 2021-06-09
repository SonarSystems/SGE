#pragma once

#include <spdlog/spdlog.h>

#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Time.hpp"
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
		 *
		 * \param maxNumOfHighScores The maximum number of high scores
		*/
		HighScoreManager( const unsigned int &maxNumOfHighScores );

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

		/**
		* \brief Check and save the score if high enough
		*
		* \param filePath File path of the file
		* \param score Score to check if high enough (are you a badass or not :D)
		* \param name Name of the player
		*/
		void SaveScore( const std::string &filepath, const long long &score, const std::string &name );

		/**
		* \brief Checks if the score is greater than any scores in the list
		*
		* \param scores Scores to check the new score against
		* \param score Score to check if is a new score
		*
		* \return Output returns the position the new score will be (returns -1 if not a high score, BOOHOO)
		*/
		int CheckScore( const std::vector<long long> &scores, const long long &score ) const;

		/**
		* \brief Set the maximum number of high scores
		*
		* \param maxNumOfHighScores The maximum number of high scores
		*/
		void SetMaximumNumberOfHighScores( const unsigned int &maxNumOfHighScores );

		/**
		* \brief How many scores can be stored in this high scores
		*
		* \return Output returns the maximum number of high scores
		*/
		unsigned int GetMaximumNumberOfHighScores( ) const;

		/**
		* \brief Create a save file with default scores
		*
		* \param filePath File path of the scores file
		* \param maxNumOfHighScores The maximum number of high scores
		* \param defaultName Default name of each player in the new file
		* \param defaultDateTime Default date and time as epoch of each player in the new file
		* \param defaultScore Default score of each player in the new file
		*/
		void CreateSaveFile( const std::string &filepath, const unsigned int &maxNumOfHighScores, const std::string &defaultName = HIGH_SCORE_DEFAULT_NAME, const long long &defaultDateTime = HIGH_SCORE_DEFAULT_DATE_TIME, const long long &defaultScore = HIGH_SCORE_DEFAULT_SCORE );

	private:
		/**
		* \brief Updates the scores vectors
		*
		* \param position Position of the new high score
		* \param score Score to add
		* \param name Name of the player who has achieved greatness
		*/
		void UpdateScores( const unsigned int &position, const long long &score, const std::string &name );

		/**
		* \brief Save the file with the local scores
		*
		* \param filePath File path of the scores file
		*/
		void SaveFile( const std::string &filepath );

		/**
		* \brief Vectors of scores and user details
		*/
		std::vector<ScoreInfo> _scoresList;

		/**
		* \brief Vector of scores only
		*/
		std::vector<long long> _scores;

		/**
		* \brief Maximum number of highscores
		*/
		unsigned int _maxNumOfHighScores;

	};
}
