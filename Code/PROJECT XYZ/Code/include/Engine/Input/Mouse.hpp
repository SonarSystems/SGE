#pragma once

#include <SFML/Graphics.hpp>
#include <External/glm/glm.hpp>

namespace Sonar
{
	class Mouse
	{
	public:
        /**
         * \brief Buttons supported by the mouse
        */
        enum Button
        {
            Left,       // The left mouse button
            Right,      // The right mouse button
            Middle,     // The middle (wheel) mouse button
            XButton1,   // The first extra mouse button
            XButton2,   // The second extra mouse button

            ButtonCount // Keep last -- the total number of mouse buttons
        };
        
        /**
         * \brief Wheels supported by the mouse
        */
        enum Wheel
        {
            VerticalWheel,  // The vertical mouse wheel
            HorizontalWheel // The horizontal mouse wheel
        };

        /**
        * \brief Different mouse cursors
        */
        /*enum Cursor
        {
            sf::Cu
        };*/

        /**
         * \brief Check if a mouse button is pressed
         *
         * \param button Button to check if it is pressed
         *
         * \return Output returns true if the button is pressed abd false otherwise
        */
        static bool IsPressed( const Button &button );
        
        /**
         * \brief Get the mouse position relative to the game window
         *
         * \param window Game window
         * \param windowOnly Should the position go beyond the game window
         *
         * \return Output returns the mouse position relative to the game window
         */
        static glm::vec2 GetPosition( const sf::RenderWindow &window, const bool &windowOnly = true );
        /**
         * \brief Get the mouse position relative to the screen
         *
         * \return Output returns the mouse position relative to the screen
        */
        static glm::vec2 GetScreenPosition( );
        
        /**
         * \brief Set the mouse position relative to the screen
         *
         * \param x Screen's x coordinate
         * \param y Screen's y coordinate
        */
        static void SetPosition( const float &x, const float &y );
        /**
         * \brief Set the mouse position relative to the game window
         *
         * \param x Screen's x coordinate
         * \param y Screen's y coordinate
         * \param window Game window
        */
        static void SetPosition( const float &x, const float &y, const sf::RenderWindow &window );
        
        /**
         * \brief Check if multiple buttons have been pressed
         *
         * \param buttons Buttons to be checked
         *
         * \return Output returns true if key is pressed and false otherwise
        */
        static bool ChordPressed( const std::initializer_list<Button> &buttons );

	};
}
