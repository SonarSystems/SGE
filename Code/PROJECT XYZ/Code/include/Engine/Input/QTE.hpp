#pragma once

#include "Keyboard.hpp"
#include <initializer_list>
#include <iostream>

namespace Sonar
{
	class QTE
	{
	public:
		/**
		 * \brief Class constructor
		 */
		//template <class T>
		QTE( const std::initializer_list<Keyboard::Key> &eventList );

		
		
		//void Adder( std::initializer_list<T> list )
		
		/**
		 * \brief Class destructor
		 */
		~QTE( );
		
		/**
		 * \brief Get the start status
		 *
		 * \return Output returns the started status (true or false)
		 */
		const bool &HasStarted( ) const;
		
		/**
		 * \brief Get the event position
		 *
		 * \return Output returns the position of the event in the overll QTE
		 */
		const int &GetEventPosition( ) const;
		
		/**
		 * \brief Get event count
		 *
		 * \return Output returns the total number of events in the QTE
		 */
		const int &GetEventCount( ) const;
	
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		
		
		// STILL TO DOO
		void NextInput( const Keyboard::Key &key );
		
		
		// RESTART QTE
		// QTE TIMER
		// RESTART QTE
		
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
		 * \brief List of all the events in the QTE
		 */
		std::initializer_list<Keyboard::Key> _eventList;
		
	};
}
