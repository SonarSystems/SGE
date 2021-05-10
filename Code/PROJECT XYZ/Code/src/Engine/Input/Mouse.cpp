#include "Input/Mouse.hpp"

namespace Sonar
{
    Mouse::Cursor Mouse::_CURSOR_ = Mouse::Cursor::Arrow;
    bool Mouse::_IS_MOUSE_CURSOR_VISIBLE_ = true;

	bool Mouse::IsPressed( const Button &button )
    { return ( Mouse::Button )sf::Mouse::isButtonPressed( ( sf::Mouse::Button )button ); }

    glm::vec2 Mouse::GetPosition( const sf::RenderWindow &window, const bool &windowOnly )
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

    glm::vec2 Mouse::GetScreenPosition( )
    { return glm::vec2( sf::Mouse::getPosition( ).x, sf::Mouse::getPosition( ).y ); }

    void Mouse::SetPosition( const float &x, const float &y )
    { sf::Mouse::setPosition( sf::Vector2i( x, y ) ); }

    void Mouse::SetPosition( const float &x, const float &y, const sf::RenderWindow &window )
    { sf::Mouse::setPosition( sf::Vector2i( x, y ), window ); }

    bool Mouse::ChordPressed( const std::initializer_list<Button> &buttons )
    {
        bool allButtonsPressed = true;
        
        // Iterate over all the buttons
        for ( Button button : buttons )
        {
            // Check if a key hasn't been pressed
            if ( !sf::Mouse::isButtonPressed( ( sf::Mouse::Button )button ) )
            { allButtonsPressed = false; }
        }
        
        return allButtonsPressed;
    }

	void Mouse::ChangeCursor( const Cursor &cursor, sf::RenderWindow &window )
	{
		sf::Cursor cursorLoader;

		if ( cursorLoader.loadFromSystem( ( sf::Cursor::Type )cursor ) )
        {
            window.setMouseCursor( cursorLoader );
            _CURSOR_ = cursor;
        }
	}

    const Mouse::Cursor &Mouse::GetCurrentCursor( )
	{ return _CURSOR_; }

	void Mouse::ShowCursor( sf::RenderWindow &window )
	{
		_IS_MOUSE_CURSOR_VISIBLE_ = true;

		window.setMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	void Mouse::HideCursor( sf::RenderWindow &window )
	{
		_IS_MOUSE_CURSOR_VISIBLE_ = false;

		window.setMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	void Mouse::ToggleCursor( sf::RenderWindow &window )
	{
        _IS_MOUSE_CURSOR_VISIBLE_ = !_IS_MOUSE_CURSOR_VISIBLE_;

        window.setMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	bool Mouse::GetCursorStatus( sf::RenderWindow &window )
	{ return _IS_MOUSE_CURSOR_VISIBLE_; }
}
