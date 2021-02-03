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

		/**
		* \brief Check and save the score if high enough
		*
		* \param filePath File path of the scores file
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
		* \return Output returns the position the new score will be (returns -1 if not a highscore, BOOHOO)
		*/
		int CheckScore( const std::vector<long long> &scores, const long long &score );

	private:
		/**
		* \brief Updates the scores vectors
		*
		* \param position Position of the new highscore
		* \param score Score to add
		* \param name Name of the player who has achieved greatness
		*/
		void UpdateScores( const int &position, const long long &score, const std::string &name );

		/**
		* \brief Vectors of scores and user details
		*/
		std::vector<ScoreInfo> _scoresList;

		/**
		* \brief Vector of scores only
		*/
		std::vector<long long> _scores;

	};
}
