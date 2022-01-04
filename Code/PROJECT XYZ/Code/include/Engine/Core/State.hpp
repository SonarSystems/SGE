#pragma once

namespace Sonar
{
    class Event;

	class State
	{
	public:
        /**
         * \brief Class destructor
        */
        virtual ~State() { }
        
        /**
         * \brief Initialize the class (overriding is essential)
        */
		virtual void Init( ) = 0;

        /**
        * \brief For any cleanup that is absolutely necessary right now

        */
        virtual void Destructor( ) = 0;

        /**
         * \brief Poll the input from the Joystick, Keyboard and Mouse (overriding is essential)
         *
         * \param dt Delta time (difference between frames)
         * \param event Event to poll
        */
		virtual void PollInput( const float &dt, Event &event ) = 0;
        /**
         * \brief Update the state (overriding is essential)
         *
         * \param dt Delta time (difference between frames)
        */
		virtual void Update( const float &dt ) = 0;
        /**
         * \brief Draw the state to the game window (overriding is essential)
         *
         * \param dt Delta time (difference between frames)
        */
		virtual void Draw( const float &dt ) = 0;

        /**
         * \brief Pause the state (overriding is optional)
        */
		virtual void Pause( ) { }
        
        /**
         * \brief Pause the state (overriding is optional)
        */
		virtual void Resume( ) { }
	};
}
