#include "Input/Keyboard.hpp"

namespace Sonar
{
    bool Keyboard::IsPressed( const Key &key )
    { return sf::Keyboard::isKeyPressed( ( sf::Keyboard::Key )key ); }

    bool Keyboard::ChordPressed( const std::initializer_list<Key> &keys )
    {
        bool allKeysPressed = true;
        
        // Iterate over all the keys
        for ( Key key : keys )
        {
            // Check if a key hasn't been pressed
            if ( !sf::Keyboard::isKeyPressed( ( sf::Keyboard::Key )key ) )
            { allKeysPressed = false; }
        }
        
        return allKeysPressed;
    }
}
