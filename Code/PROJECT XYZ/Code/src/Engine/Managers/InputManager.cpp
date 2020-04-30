#include "InputManager.hpp"

namespace Sonar
{
    InputManager::InputManager( )
    {
        
    }

    InputManager::~InputManager( )
    {
        
    }

    const glm::vec2 &InputManager::GetMousePosition( const sf::RenderWindow &window, const bool &windowOnly )
	{
        glm::vec2 position( sf::Mouse::getPosition( window ).x, sf::Mouse::getPosition( window ).y );
        
        // for mouse over window only
        if ( windowOnly )
        {
            // check if the mouse is outside of the window
            if ( sf::Mouse::getPosition( window ).x < 0 || sf::Mouse::getPosition( window ).x > window.getSize( ).x || sf::Mouse::getPosition( window ).y < 0 || sf::Mouse::getPosition( window ).y > window.getSize( ).y )
            {
                position.x = -1;
                position.y = -1;
            }
        }
        
		return position;
	}
}
