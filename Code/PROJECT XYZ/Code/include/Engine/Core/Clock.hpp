#pragma once

#include <SFML/Window.hpp>
#include "Time.hpp"

namespace Sonar
{
	class Clock
	{
	public:
		/**
		 * \brief Class constructor
		 */
		Clock( ) { }
		
		/**
		 * \brief Class destructor
		 */
		~Clock( ) { }
		
		/**
		 * \brief Resets the clocks
		 */
		void Reset( );
		
		/**
		 * \brief Get elapsed time
		 *
		 * \return Output returns the time that elapsed since the last reset or start
		 */
		 const Time GetElapsedTime( ) const;
		
		
	private:
		/**
		 * \brief Tracks the time for the current clock object
		 */
		sf::Clock _clock;
		
	};
}
