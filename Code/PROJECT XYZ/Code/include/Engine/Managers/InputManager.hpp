#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include "Game.hpp"

namespace Sonar
{
	class InputManager
	{
	public:
		InputManager( ) {}
		~InputManager( ) {}

		bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window );

		glm::vec2 GetMousePosition( sf::RenderWindow &window );
        
	};
}
