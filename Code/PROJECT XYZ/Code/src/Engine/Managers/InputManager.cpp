#include "InputManager.hpp"

namespace Sonar
{
    InputManager::InputManager( )
    {
        
    }

    InputManager::~InputManager( )
    {
        
    }

	bool InputManager::IsObjectClicked( const Drawable &object, const sf::Mouse::Button &button, const sf::RenderWindow &window )
	{
        //sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
        
		if (sf::Mouse::isButtonPressed(button))
		{
            
            sf::IntRect playButtonRect( object.GetPositionX( ), object.GetPositionY( ), object.GetWidth( ), object.GetHeight( ) );

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
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
