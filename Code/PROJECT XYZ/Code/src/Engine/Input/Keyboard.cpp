#include "Keyboard.hpp"

namespace Sonar
{
    bool Keyboard::IsPressed( const Key &key )
    {
        return sf::Keyboard::isKeyPressed( ( sf::Keyboard::Key )key );
    }
}
