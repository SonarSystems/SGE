#include "Input/Joystick.hpp"

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

	bool Joystick::IsPressed( const unsigned int &joystick, const unsigned int &button )
	{ return sf::Joystick::isButtonPressed( joystick, button ); }

	float Joystick::GetAxisPosition( const unsigned int &joystick, const Axis &axis )
	{ return sf::Joystick::getAxisPosition( joystick, ( sf::Joystick::Axis )axis ); }

	bool Joystick::ChordPressed( const std::initializer_list<std::array<int, 2>> &joystickButtons )
	{
		bool allKeysPressed = true;

		// Iterate over all the keys
		for ( std::array<int, 2> joystick : joystickButtons )
		{
			// Check if a key hasn't been pressed
			if ( !sf::Joystick::isButtonPressed( joystick[0], joystick[1] ) )
			{ allKeysPressed = false; }
		}

		return allKeysPressed;
	}

	bool Joystick::IsGestureTriggered( const unsigned int &joystickID, const Joystick::AnalogueStick &analogueStick, const Direction &direction )
	{
		Axis axisX, axisY;

		if ( AnalogueStick::LeftStick == analogueStick )
		{
			axisX = Axis::X;
			axisY = Axis::Y;
		}
		else if ( AnalogueStick::RightStick == analogueStick )
		{
			axisX = Axis::U;
			axisY = Axis::R;
		}

		if ( Direction::Left == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) < -90 )
			{ return true; }
			else
			{ return false; }
		}
		else if ( Direction::Right == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) > 90 )
			{ return true; }
			else
			{ return false; }
		}
		else if ( Direction::Up == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisY ) < -90 )
			{ return true; }
			else
			{ return false; }
		}
		else if ( Direction::Down == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisY ) > 90 )
			{ return true; }
			else
			{ return false; }
		}
		else if ( Direction::LeftUp == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) < -45
				&& Joystick::GetAxisPosition( joystickID, axisY ) < -45 )
			{
				return true;
			}
			else
			{ return false; }
		}
		else if ( Direction::RightUp == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) > 45
				&& Joystick::GetAxisPosition( joystickID, axisY ) < -45 )
			{
				return true;
			}
			else
			{ return false; }
		}
		else if ( Direction::LeftDown == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) < -45
				&& Joystick::GetAxisPosition( joystickID, axisY ) > 45 )
			{
				return true;
			}
			else
			{ return false; }
		}
		else if ( Direction::RightDown == direction )
		{
			if ( Joystick::GetAxisPosition( joystickID, axisX ) > 45
				&& Joystick::GetAxisPosition( joystickID, axisY ) > 45 )
			{
				return true;
			}
			else
			{ return false; }
		}
		else
		{
			if ( IsGestureTriggered( joystickID, analogueStick, Direction::Left ) )
			{

			}
		}
	}

	float Joystick::GetJoystickAngle( const unsigned int &joystick, const Axis &xAxis, const Axis &yAxis, const bool &isDegrees )
	{
		float xCoord = Joystick::GetAxisPosition( joystick, xAxis );
		float yCoord = Joystick::GetAxisPosition( joystick, yAxis );

		float multiplyFactor = 1.0f;
		float initialAngle = 3.14159f;

		if ( 0 == xCoord )
		{ xCoord = 0.0001; }

		float angle = atan( yCoord / -xCoord );

		if ( xCoord > 0 )
		{ angle = initialAngle - angle; }
		else
		{
			if ( yCoord > 0 )
			{ angle = ( 2 * initialAngle ) - angle; }
			else
			{ angle *= -1.0f; }
		}

		if ( isDegrees )
		{ return angle * ( 180 / 3.14159 ); }
		else
		{ return angle; }
	}

}
