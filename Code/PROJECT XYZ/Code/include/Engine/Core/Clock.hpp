#pragma once

#include <SFML/Window.hpp>

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
		
		
		
	private:
		/**
		 * \brief Tracks the time for the current clock object
		 */
		sf::Clock clock;
		
	};
}
