#pragma once

namespace Sonar
{
	class QTE
	{
	public:
		/**
		* \brief Class constructor for Keyboard QTE
		*/
		QTE( const std::vector<Keyboard::Key> &eventList, const std::vector<float> &times, const int &resetAmount = 0 );
		
		/**
		* \brief Class constructor for Joystick QTE
		*/
		QTE( const std::vector<std::array<int, 2>> &eventList, const std::vector<float> &times, const int &resetAmount = 0 );

		/**
		* \brief Class constructor for Joystick QTE
		*/
		QTE( const std::vector<Mouse::Button> &eventList, const std::vector<float> &times, const int &resetAmount = 0 );

		/**
		 * \brief Class destructor
		 */
		~QTE( );

		/**
		 * \brief Get the start status
		 *
		 * \return Output returns the started status (true or false)
		 */
		[[nodiscard]] bool HasStarted( ) const;

		/**
		 * \brief Get the event position
		 *
		 * \return Output returns the position of the event in the overll QTE
		 */
		[[nodiscard]] int GetEventPosition( ) const;

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
		[[nodiscard]] int GetEventCount( ) const;

		/**
		* \brief Get event list for the keyboard (vector container)
		*
		* \return Output returns the list of events in the keyboard QTE
		*/
		[[nodiscard]] std::vector<Keyboard::Key> GetEventListKeyboard( ) const;

		/**
		* \brief Get event list for the joystick (vector container)
		*
		* \return Output returns the list of events in the joystick QTE
		*/
		[[nodiscard]] std::vector<std::array<int, 2>> GetEventListJoystick( ) const;

		/**
		 * \brief Checks if the QTE is complete
		 *
		 * \return Output returns the complete status of the QTE
		 */
		[[nodiscard]] bool IsComplete( ) const;

		/**
		 * \brief Get the QTE clock
		 *
		 * \return Output returns the QTE clock
		 */
		[[nodiscard]] Clock GetClock( ) const;

		/**
		* \brief Process the next keyboard input
		*
		* \param key input key to check if it is the next input in the QTE
		*/
		void NextInputKeyboard( const Keyboard::Key &key );

		/**
		* \brief Process the next joystick input
		*
		* \param key input key to check if it is the next input in the QTE
		*/
		void NextInputJoystick( const unsigned int &joystickID, const unsigned int &joystickButton );

		/**
		* \brief Process the next mouse input
		*
		* \param key input key to check if it is the next input in the QTE
		*/
		void NextInputMouse( const Mouse::Button &button );

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
		[[nodiscard]] unsigned int GetFailureCount( ) const;

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
		* \brief List (vector container) of all the events in the keyboard QTE
		*/
		std::vector<Keyboard::Key> _eventListKeyboard;

		/**
		* \brief List (vector container) of all the events in the joystick QTE
		*/
		std::vector<std::array<int, 2>> _eventListJoystick;

		/**
		* \brief List (vector container) of all the events in the mouse QTE
		*/
		std::vector<Mouse::Button> _eventListMouse;

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

		/**
		* \brief Number of events
		*/
		int _eventCount;

	};
}
