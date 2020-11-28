#pragma once

#include "Input/Keyboard.hpp"
#include "Core/Clock.hpp"
#include <vector>
#include <iostream>

namespace Sonar
{
	class RBM // Rapid Button Masher
	{
	public:

		// SONAR: REMOVE KEY, MAKE IT SIMPLE AND ABSTRACT, WHICH EVENT TRIGGERS THE COUNT TO GO UP IS DEPENDENT ON AN EXTERNAL CLASS

		/**
		* \brief Class constructor
		*/
		RBM( const Keyboard::Key &key, const float &threshold, const float &amountToTickUp, const float &tickDownTime, const float &tickDownAmount );

		/**
		* \brief Class destructor
		*/
		~RBM( );

		/**
		* \brief Get the start status
		*
		* \return Output returns the started status (true or false)
		*/
		bool HasStarted( ) const;

		/**
		* \brief Checks if the RBM is complete
		*
		* \return Output returns the complete status of the RBM
		*/
		bool IsComplete( ) const;

		/**
		* \brief Get the RBM clock
		*
		* \return Output returns the RBM clock
		*/
		Clock GetClock( ) const;

		/**
		* \brief Update the RBM
		*/
		void Update( );

		/**
		* \brief Restart the RBM (reset event position back to 0)
		*/
		void Restart( );

		/**
		* \brief Get the number of failures
		*
		* \return Output returns the RBM failure count
		*/
		int GetFailureCount( ) const;

	private:
		/**
		* \brief Has the RBM begun (has the user pressed the first input)
		*/
		bool _started;

		/**
		* \brief Which key is to be pressed in the RBM
		*/
		Keyboard::Key _key;

		/**
		* \brief Amount to get to in the RBM
		*/
		float _thresholdGoal;

		/**
		* \brief Per press amount to add to counter
		*/
		float _amountToTickUp;

		/**
		* \brief Period after which the counter goes down
		*/
		float _tickDownTime;
	
		/**
		* \brief Amount for counter to go down
		*/
		float _tickDownAmount;

		/**
		* \brief Progress of the RBM
		*/
		float _counter;

		/**
		* \brief Clock to track the RBM countdown between events
		*/
		Clock _clock;

		/**
		* \brief How many times has the RBM failed
		*/
		int _failureCount;

	};
}
