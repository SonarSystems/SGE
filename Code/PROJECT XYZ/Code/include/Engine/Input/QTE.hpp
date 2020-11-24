#pragma once

#include "Input/Keyboard.hpp"
#include "Core/Clock.hpp"
#include <vector>
#include <iostream>

namespace Sonar
{
	class QTE
	{
	public:
		/**
		 * \brief Class constructor
		 */
		QTE( const std::vector<Keyboard::Key> &eventList, const std::vector<float> &times, const int &resetAmount = 0 );

		/**
		 * \brief Class destructor
		 */
		~QTE( );

		/**
		 * \brief Get the start status
		 *
		 * \return Output returns the started status (true or false)
		 */
		bool HasStarted( ) const;

		/**
		 * \brief Get the event position
		 *
		 * \return Output returns the position of the event in the overll QTE
		 */
		int GetEventPosition( ) const;

		/**
		 * \brief Set the event position
		 *
		 * \param position position to set the QTE event to
		 */
		void SetEventPosition( const int &position );

		/**
		 * \brief Get event count
		 *
		 * \return Output returns the total number of events in the QTE
		 */
		int GetEventCount( ) const;

		/**
		 * \brief Get event list (vector container)
		 *
		 * \return Output returns the list of events in the QTE
		 */
		std::vector<Keyboard::Key> GetEventList( ) const;

		/**
		 * \brief Checks if the QTE is complete
		 *
		 * \return Output returns the complete status of the QTE
		 */
		bool IsComplete( ) const;

		/**
		 * \brief Get the QTE clock
		 *
		 * \return Output returns the QTE clock
		 */
		Clock GetClock( ) const;

		/**
		 * \brief Process the next input
		 *
		 * \param key input key to check if it is the next input in the QTE
		 */
		void NextInput( const Keyboard::Key &key );

		/**
		 * \brief Update the QTE
		 */
		void Update( );

		/**
		 * \brief Restart the QTE (reset event position back to 0)
		 */
		void Restart( );

		/**
		* \brief Get the number of failures
		*
		* \return Output returns the QTE failure count
		*/
		int GetFailureCount( ) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// QTE ends after a single failure

		// mouse and joystick as well

	private:
		/**
		 * \brief Has the QTE begun (has the user pressed the first input)
		 */
		bool _started;

		/**
		 * \brief Where in the QTE the event has got to
		 */
		int _eventPosition;

		/**
		 * \brief List (vector container) of all the events in the QTE
		 */
		std::vector<Keyboard::Key> _eventList;

		/**
		 * \brief List (vector container) of all the individual times of the events in the QTE
		 */
		std::vector<float> _eventTimeList;

		/**
		 * \brief Clock to track the QTE countdown between events
		 */
		Clock _clock;

		/**
		* \brief Clock to track the QTE countdown between events
		*/
		int _resetAmount;

		/**
		* \brief How many times has the QTE failed
		*/
		int _failureCount;

	};
}
