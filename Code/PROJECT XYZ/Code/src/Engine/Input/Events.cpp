#include "Input/Events.hpp"

namespace Sonar
{
    /*
     Constructor
     Assign all the properties of the SFML event to this event
     */
    Event::Event( const sf::Event &event )
    {
        this->type = ( EventType )event.type;
        
        this->size.width = event.size.width;
        this->size.height = event.size.height;
        
        this->key.code = ( Keyboard::Key )event.key.code;
        this->key.alt = event.key.alt;
        this->key.control = event.key.control;
        this->key.shift = event.key.shift;
        this->key.system = event.key.system;
        
        this->text.unicode = event.text.unicode;
        
        this->mouseMove.x = event.mouseMove.x;
        this->mouseMove.y = event.mouseMove.y;
        
        this->mouseButton.button = ( Mouse::Button )event.mouseButton.button;
        this->mouseButton.x = event.mouseButton.x;
        this->mouseButton.y = event.mouseButton.y;
        
        this->mouseWheel.delta = event.mouseWheel.delta;
        this->mouseWheel.x = event.mouseWheel.x;
        this->mouseWheel.y = event.mouseWheel.y;
        
        this->mouseWheelScroll.wheel = ( Mouse::Wheel )event.mouseWheelScroll.wheel;
        this->mouseWheelScroll.delta = event.mouseWheelScroll.delta;
        this->mouseWheelScroll.x = event.mouseWheelScroll.x;
        this->mouseWheelScroll.y = event.mouseWheelScroll.y;
        
        this->joystickConnect.joystickId = event.joystickConnect.joystickId;
        
        this->joystickMove.joystickId = event.joystickMove.joystickId;
        this->joystickMove.axis = ( Joystick::Axis )event.joystickMove.axis;
        this->joystickMove.position = event.joystickMove.position;
        
        this->joystickButton.joystickId = event.joystickButton.joystickId;
        this->joystickButton.button = event.joystickButton.button;
        
        this->touch.finger = event.touch.finger;
        this->touch.x = event.touch.x;
        this->touch.y = event.touch.y;
        
        this->sensor.type = ( Sensor::Type )event.sensor.type;
        this->sensor.x = event.sensor.x;
        this->sensor.y = event.sensor.y;
        this->sensor.z = event.sensor.z;
    }
}
