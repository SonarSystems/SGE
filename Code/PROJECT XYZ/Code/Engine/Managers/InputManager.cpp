#include "InputManager.hpp"

namespace Sonar
{
	bool InputManager::IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window )
	{
		if ( sf::Mouse::isButtonPressed( button ) )
		{
			sf::IntRect playButtonRect( object.getPosition( ).x, object.getPosition( ).y, object.getGlobalBounds( ).width, object.getGlobalBounds( ).height );

			if ( playButtonRect.contains( sf::Mouse::getPosition( window ) ) )
			{
				return true;
			}
		}

		return false;
	}

	glm::vec2 InputManager::GetMousePosition( sf::RenderWindow &window )
	{
		return glm::vec2( sf::Mouse::getPosition( window ).x, sf::Mouse::getPosition( window ).y );
	}
}
