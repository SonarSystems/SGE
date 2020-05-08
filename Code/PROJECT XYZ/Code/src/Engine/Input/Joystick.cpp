#include "Joystick.hpp"

namespace Sonar
{
    Joystick::Identification Joystick::GetIdentification( const unsigned int &joystick )
    {
        Identification id;
        sf::Joystick::Identification sfmlID = sf::Joystick::getIdentification( joystick );
        
        id.name = sfmlID.name;
        id.vendorId = sfmlID.vendorId;
        id.productId = sfmlID.productId;
        
        return id;
    }
    bool Joystick::IsConnected( const unsigned int &joystick )
    { return sf::Joystick::isConnected( joystick ); }

    unsigned int Joystick::GetButtonCount( const unsigned int &joystick )
    { return sf::Joystick::getButtonCount( joystick ); }

    bool Joystick::HasAxis( const unsigned int &joystick, const Axis &axis )
    { return sf::Joystick::hasAxis( joystick, ( sf::Joystick::Axis )axis ); }

    bool Joystick::IsPressed( const unsigned int &joystick, const unsigned int &button)
    { return sf::Joystick::isButtonPressed( joystick, button ); }

    float Joystick::GetAxisPosition( const unsigned int &joystick, const Axis &axis)
    { return sf::Joystick::getAxisPosition( joystick, ( sf::Joystick::Axis )axis ); }
}
