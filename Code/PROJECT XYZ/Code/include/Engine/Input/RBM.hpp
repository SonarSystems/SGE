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
		/**
		* \brief Class constructor
		*/
		RBM( const float &threshold, const float &amountToTickUp, const Time &tickDownTime, const float &tickDownAmount );

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

		/**
		* \brief Tick up the RBM counter
		*/
		void TickUp( );

		/**
		* \brief Get the count of the RBM
		*
		* \return Output returns the RBM counter
		*/
		float GetCounter( ) const;

	private:
		/**
		* \brief Has the RBM begun (has the user pressed the first input)
		*/
		bool _started;

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
		Time _tickDownTime;
	
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
