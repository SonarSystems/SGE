#pragma once

namespace Sonar
{
	/**
	 * \brief enum for tick direction
	 */
	enum DIRECTION { UP, DOWN };
	
    class Sequence
    {
    public:
		/**
		 * \brief Class constructor
		 */
        Sequence( );
		
		/**
		 * \brief Class destructor
		 */
        ~Sequence( ) { };
        
		/**
		 * \brief Tick up the sequence counter
		 *
		 * \param amount Interval jump for the counter
		 * \param canGoOver Can the counter go above its max
		 */
        void TickUp( const float &amount = 1, const bool &canGoOver = false );
        
		/**
		 * \brief Tick down the sequence counter
		 *
		 * \param amount Interval jump for the counter
		 * \param canGoUnder Can the counter go below its max
		 */
        void TickDown( const float &amount = 1, const bool &canGoUnder = false );

		/**
		* \brief Tick up/down based on a keyboard press event
		*
		* \param key Which key triggers the keyboard press event
		* \param amount Interval jump for the counter
		* \param direction Tick up or down
		* \param canGoBeyond Can the counter go above/below its max/min
		*/
		void KeyboardPress( const Keyboard::Key &key, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP, const bool &canGoBeyond = false );
        
		/**
		 * \brief Tick up/down based on a mouse press event
		 *
		 * \param button Which button triggers the mouse press event
		 * \param amount Interval jump for the counter
		 * \param direction Tick up or down
		 * \param canGoBeyond Can the counter go above/below its max/min
		 */
        void MousePress( const Mouse::Button &button, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP, const bool &canGoBeyond = false );
        
		/**
		 * \brief Tick up/down based on a joystick press event
		 *
		 * \param joystickID Joystick to check
		 * \param button Which button triggers the joystick press event
		 * \param amount Interval jump for the counter
		 * \param direction Tick up or down
		 * \param canGoBeyond Can the counter go above/below its max/min
		 */
        void JoystickPress( const unsigned int joystickID, const unsigned int &button, const float &amount = 1, const DIRECTION &direction = DIRECTION::UP, const bool &canGoBeyond = false );
        
		/**
		 * \brief Set the counter
		 *
		 * \param count Specific value to set the counter to
		 */
        void SetCount( const float &count );
        
		/**
		 * \brief Set the min value
		 *
		 * \param min Specific value to set the min boundary to
		 */
        void SetMin( const float &min );
        
		/**
		 * \brief Set the max value
		 *
		 * \param max Specific value to set the max boundary to
		 */
        void SetMax( const float &max );
        
		/**
		 * \brief Get the counter value
		 *
		 * \return Output returns the counter
		 */
        float GetCount( ) const;
        
		/**
		 * \brief Get the min boundary value
		 *
		 * \return Output returns the min boundary value
		 */
        float GetMin( ) const;
        
		/**
		 * \brief Get the max boundary value
		 *
		 * \return Output returns the max boundary value
		 */
        float GetMax( ) const;
        
		/**
		 * \brief Keyboard pressed event timer
		 *
		 * \param key Key to check if it's pressed
		 *
		 * \return Output returns the timer total since last reset
		 */
		Time KeyboardPressedTimer( const Keyboard::Key &key );
		
		/**
		 * \brief Mouse pressed event timer
		 *
		 * \param button Button to check if it's pressed
		 *
		 * \return Output returns the timer total since last reset
		 */
		Time MousePressedTimer( const Mouse::Button &button );
		
		/**
		 * \brief Joystick pressed event timer
		 *
		 * \param joystick Joystick to check
		 * \param button Button to check if it's pressed
		 *
		 * \return Output returns the timer total since last reset
		 */
		Time JoystickPressedTimer( const unsigned int &joystick, const unsigned int &button );
		
    private:
		/**
		 * \brief Counter to track the number of ticks
		 */
        float _count;
        
		/**
		 * \brief Minimun boundary for the counter
		 */
        float _min;
        
		/**
		 * \brief Maximum boundary for the counter
		 */
        float _max;
		
		/**
		 * \brief Clock to track the time
		 */
		Clock _clock;
        
    };
}
