#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace Sonar
{
	class Mouse
	{
	public:
        enum Button
        {
            Left,       // The left mouse button
            Right,      // The right mouse button
            Middle,     // The middle (wheel) mouse button
            XButton1,   // The first extra mouse button
            XButton2,   // The second extra mouse button

            ButtonCount // Keep last -- the total number of mouse buttons
        };
        
        enum Wheel
        {
            VerticalWheel,  // The vertical mouse wheel
            HorizontalWheel // The horizontal mouse wheel
        };
        
        Mouse( ) { }
        ~Mouse( ) { }
        
        // check if a mouse button is pressed
        static const bool &IsPressed( const Button &button );
        
        // get the mouse position relative to the game window
        static const glm::vec2 &GetPosition( const sf::RenderWindow &window, const bool &windowOnly = true );
        // get the mouse position relative to the screen
        static const glm::vec2 &GetScreenPosition( );
        
        // set the mouse position
        static void SetPosition( const float &x, const float &y );
        static void SetPosition( const float &x, const float &y, const sf::RenderWindow &window );

	};
}
