#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include "Drawable.hpp"

namespace Sonar
{
	class InputManager
	{
	public:
        InputManager( );
        ~InputManager( );

		bool IsObjectClicked( const Drawable &object, const sf::Mouse::Button &button, const sf::RenderWindow &window );

        static const glm::vec2 &GetMousePosition( const sf::RenderWindow &window, const bool &windowOnly = true );
        
	};
}
