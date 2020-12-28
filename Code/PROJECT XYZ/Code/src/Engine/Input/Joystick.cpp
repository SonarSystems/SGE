#include "Input/Joystick.hpp"

namespace Sonar
{
	Joystick::Joystick( const float &joystickID )
	{
		_gamepad = Gamepad( joystickID );

		_leftRumble = _rightRumble = 0.0f;

		_joystickID = 0.0f;
	}

	Joystick::~Joystick(  ) { }

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

	float Joystick::GetAxisPosition( const unsigned int &joystick, const Axis &axis, const float &deadzone )
	{
		float position = sf::Joystick::getAxisPosition( joystick, ( sf::Joystick::Axis )axis );

		if ( position >= 0 )
		{
			if ( position < deadzone )
			{ return 0; }
		}
		else
		{
			if ( position > -deadzone )
			{ return 0; }
		}

		return position;
	}

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

	float Joystick::GetJoystickAngle( const unsigned int &joystick, const Axis &xAxis, const Axis &yAxis, const bool &isDegrees, const std::pair<float, float> &deadzone )
	{
		float xCoord = Joystick::GetAxisPosition( joystick, xAxis, deadzone.first );
		float yCoord = Joystick::GetAxisPosition( joystick, yAxis, deadzone.second );

		if ( 0 == xCoord )
		{ xCoord = 0.0001; }

		float angle = atan( yCoord / -xCoord );

		if ( xCoord > 0 )
		{ angle = 3.14159f - angle; }
		else
		{
			if ( yCoord > 0 )
			{ angle = ( 2 * 3.14159f ) - angle; }
			else
			{ angle *= -1.0f; }
		}

		if ( isDegrees )
		{ return angle * ( 180 / 3.14159f ); }
		else
		{ return angle; }
	}

	float Joystick::GetJoystickDistanceFromCenter( const unsigned int &joystick, const Axis &xAxis, const Axis &yAxis, const std::pair<float, float> &deadzone )
	{
		float xCoord = Joystick::GetAxisPosition( joystick, xAxis, deadzone.first );
		float yCoord = Joystick::GetAxisPosition( joystick, yAxis, deadzone.second );

		return sqrt( ( xCoord * xCoord ) + ( yCoord * yCoord ) );
	}

	void Joystick::Update( )
	{ _gamepad.Refresh( ); }

	void Joystick::SetVibration( const float &leftRumble, const float &rightRumble )
	{
		_gamepad.SetRumble( leftRumble, rightRumble );

		_leftRumble = leftRumble;
		_rightRumble = rightRumble;
	}

	void Joystick::SetVibrationLeft( const float &leftRumble )
	{
		_gamepad.SetRumble( leftRumble, _rightRumble );

		_leftRumble = leftRumble;
	}

	void Joystick::SetVibrationRight( const float &rightRumble )
	{
		_gamepad.SetRumble( _leftRumble, rightRumble );

		_rightRumble = rightRumble;
	}

	std::pair<float, float> Joystick::GetVibration( ) const
	{ return { _leftRumble,_rightRumble }; }

	void Joystick::DisableVibration( )
	{
		_gamepad.SetRumble( 0.0f, 0.0f );

		_leftRumble = _rightRumble = 0.0f;
	}

	void Joystick::DisableVibrationLeft( )
	{
		_gamepad.SetRumble( 0.0f, _rightRumble );

		_leftRumble = 0.0f;
	}

	void Joystick::DisableVibrationRight( )
	{
		_gamepad.SetRumble( _leftRumble, 0.0f );

		_rightRumble = 0.0f;
	}

	void Joystick::SetJoystickID( const int &joystickID )
	{
		_gamepad = Gamepad( joystickID );

		_joystickID = joystickID;
	}

	int Joystick::GetJoystickID( ) const
	{ return _joystickID; }
}
