#pragma once

#include <SFML/Window.hpp>
#include <string>
#include <array>

#include "Joystick.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace Sonar
{
    class Input
    {
    public:
        
        /**
         * \brief Check if multiple buttons have been pressed across multiple devices
         *
         * \param mouseButtons List of all the mouse buttons to be checked
         * \param keyboardButtons List of all the keyboard keys to check
         * \param joystickButtons List of all the joysticks and buttons to check, first array parameter is the joystick id and second array parameter is the button id
         *
         * \return Output returns true if all buttons on all devices are pressed, false if not
        */
        static bool MultiDeviceChordPressed( const std::initializer_list<Mouse::Button> &mouseButtons, const std::initializer_list<Keyboard::Key> &keyboardButtons, const std::initializer_list<std::array<int, 2>> &joystickButtons );
    };
}
