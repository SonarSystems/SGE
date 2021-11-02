#pragma once

namespace Sonar
{
	class Time;

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
		* \brief Resets the clocks
		* 
		* \return Output return the SFML time after a restart
		*/
		[[nodiscard]] sf::Time SFMLRestart( );
		
		/**
		 * \brief Get elapsed time
		 *
		 * \return Output returns the time that elapsed since the last reset or start
		 */
		[[nodiscard]] const Time GetElapsedTime( ) const;
		
	private:
		/**
		 * \brief Tracks the time for the current clock object
		 */
		sf::Clock _clock;
		
	};
}
