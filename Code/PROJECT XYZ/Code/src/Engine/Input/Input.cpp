#include "Input.hpp"

namespace Sonar
{
    bool Input::MultiDeviceChordPressed( const std::initializer_list<Mouse::Button> &mouseButtons, const std::initializer_list<Keyboard::Key> &keyboardButtons, const std::initializer_list<std::array<int, 2>> &joystickButtons )
    { return Mouse::ChordPressed( mouseButtons ) && Keyboard::ChordPressed( keyboardButtons ) && Joystick::ChordPressed( joystickButtons ); }
}
