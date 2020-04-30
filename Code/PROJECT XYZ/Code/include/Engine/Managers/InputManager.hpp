#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

namespace Sonar
{
	class InputManager
	{
	public:
        InputManager( );
        ~InputManager( );

        static const glm::vec2 &GetMousePosition( const sf::RenderWindow &window, const bool &windowOnly = true );
        
	};
}
