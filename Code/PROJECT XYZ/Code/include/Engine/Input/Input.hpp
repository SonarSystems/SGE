#pragma once

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
        [[nodiscard]] static bool MultiDeviceChordPressed( const std::initializer_list<Mouse::Button> &mouseButtons, const std::initializer_list<Keyboard::Key> &keyboardButtons, const std::initializer_list<std::array<int, 2>> &joystickButtons );
        
        /**
         * \brief Check if any joystick button has been pressed
         *
         * \param event Event to poll
         *
         * \return Output returns true if any button has been pressed, false otherwise
        */
        [[nodiscard]] static bool AnyJoystickButtonPressed( const Event &event );
        
        /**
         * \brief Check if any mouse button has been pressed
         *
         * \param event Event to poll
         *
         * \return Output returns true if any button has been pressed, false otherwise
        */
        [[nodiscard]] static bool AnyMouseButtonPressed( const Event &event );
        
        /**
         * \brief Check if any keyboard button has been pressed
         *
         * \param event Event to poll
         *
         * \return Output returns true if any button has been pressed, false otherwise
        */
        [[nodiscard]] static bool AnyKeyboardButtonPressed( const Event &event );
        
    };
}
