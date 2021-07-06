#include "Input/Mouse.hpp"
#include "Core/Window.hpp"

namespace Sonar
{
    Mouse::Cursor Mouse::_CURSOR_ = Mouse::Cursor::Arrow;
    bool Mouse::_IS_MOUSE_CURSOR_VISIBLE_ = true;

	bool Mouse::IsPressed( const Button &button )
    { return sf::Mouse::isButtonPressed( ( sf::Mouse::Button )button ); }

    glm::vec2 Mouse::GetPosition( Window &window, const bool &windowOnly )
	{
        glm::vec2 position( sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).x, sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).y );
        
        // for mouse over window only
        if ( windowOnly )
        {
            // check if the mouse is outside of the window
            if ( sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).x < 0 || sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).x > ( int )window.GetSize( ).x || sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).y < 0 || sf::Mouse::getPosition( window.GetSFMLWindowObject( ) ).y > ( int )window.GetSize( ).y )
            {
                position.x = -1;
                position.y = -1;
            }
        }
        
		return position;
	}

    glm::vec2 Mouse::GetScreenPosition( )
    { return glm::vec2( sf::Mouse::getPosition( ).x, sf::Mouse::getPosition( ).y ); }

    void Mouse::SetPosition( const int &x, const int &y )
    { sf::Mouse::setPosition( sf::Vector2i( x, y ) ); }

    void Mouse::SetPosition( const int &x, const int &y, Window &window )
    { sf::Mouse::setPosition( sf::Vector2i( x, y ), window.GetSFMLWindowObject( ) ); }

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

	void Mouse::ChangeCursor( const Cursor &cursor, Window &window )
	{
		sf::Cursor cursorLoader;

		if ( cursorLoader.loadFromSystem( ( sf::Cursor::Type )cursor ) )
        {
            window.SetMouseCursor( cursor );
            _CURSOR_ = cursor;
        }
	}

    const Mouse::Cursor &Mouse::GetCurrentCursor( )
	{ return _CURSOR_; }

	void Mouse::ShowCursor( Window &window )
	{
		_IS_MOUSE_CURSOR_VISIBLE_ = true;

		window.SetMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	void Mouse::HideCursor( Window &window )
	{
		_IS_MOUSE_CURSOR_VISIBLE_ = false;

		window.SetMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	void Mouse::ToggleCursor( Window &window )
	{
        _IS_MOUSE_CURSOR_VISIBLE_ = !_IS_MOUSE_CURSOR_VISIBLE_;

        window.SetMouseCursorVisible( _IS_MOUSE_CURSOR_VISIBLE_ );
	}

	bool Mouse::GetCursorStatus( Window &window )
	{ return _IS_MOUSE_CURSOR_VISIBLE_; }
}
