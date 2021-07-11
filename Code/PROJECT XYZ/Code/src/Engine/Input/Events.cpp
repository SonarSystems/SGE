#include "pch.hpp"

namespace Sonar
{
	Event::Event( )
	{
		sf::Event event = sf::Event( );
		_event = event;

		Update( );
	}

    /*
     Constructor
     Assign all the properties of the SFML event to this event
     */
    Event::Event( const sf::Event &event )
    {
        _event = event;

        Update( );
    }

	sf::Event &Event::GetSFMLEventObject( )
	{ return _event; }

	void Event::Update( )
	{
		this->type = ( EventType )_event.type;

		this->size.width = _event.size.width;
		this->size.height = _event.size.height;

		this->key.code = ( Keyboard::Key )_event.key.code;
		this->key.alt = _event.key.alt;
		this->key.control = _event.key.control;
		this->key.shift = _event.key.shift;
		this->key.system = _event.key.system;

		this->text.unicode = _event.text.unicode;

		this->mouseMove.x = _event.mouseMove.x;
		this->mouseMove.y = _event.mouseMove.y;

		this->mouseButton.button = ( Mouse::Button )_event.mouseButton.button;
		this->mouseButton.x = _event.mouseButton.x;
		this->mouseButton.y = _event.mouseButton.y;

		this->mouseWheel.delta = _event.mouseWheel.delta;
		this->mouseWheel.x = _event.mouseWheel.x;
		this->mouseWheel.y = _event.mouseWheel.y;

		this->mouseWheelScroll.wheel = ( Mouse::Wheel )_event.mouseWheelScroll.wheel;
		this->mouseWheelScroll.delta = _event.mouseWheelScroll.delta;
		this->mouseWheelScroll.x = _event.mouseWheelScroll.x;
		this->mouseWheelScroll.y = _event.mouseWheelScroll.y;

		this->joystickConnect.joystickId = _event.joystickConnect.joystickId;

		this->joystickMove.joystickId = _event.joystickMove.joystickId;
		this->joystickMove.axis = ( Joystick::Axis )_event.joystickMove.axis;
		this->joystickMove.position = _event.joystickMove.position;

		this->joystickButton.joystickId = _event.joystickButton.joystickId;
		this->joystickButton.button = _event.joystickButton.button;

		this->touch.finger = _event.touch.finger;
		this->touch.x = _event.touch.x;
		this->touch.y = _event.touch.y;

		this->sensor.type = ( Sensor::Type )_event.sensor.type;
		this->sensor.x = _event.sensor.x;
		this->sensor.y = _event.sensor.y;
		this->sensor.z = _event.sensor.z;
	}

}
