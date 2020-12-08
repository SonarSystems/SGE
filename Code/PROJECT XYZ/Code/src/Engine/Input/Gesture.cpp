#include "Input/Gesture.hpp"

namespace Sonar
{
	Gesture::Gesture( const int &joystickID, const AnalogueStick &analogueStick ) : _joystickID( joystickID )
	{
		_loopCounter = 0;

		_isComplete = false;
		_isMoving = false;

		SetAnalogueStick( analogueStick );

		LeftClockwiseUp.steps.push_back(
		{
			{ -50, -50 },
			{ -20, 20 },
			Direction::Left,
			Direction::NONE,
			{ 0.2 },
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -90, -90 },
			{ -20, 20 },
			Direction::Left,
			Direction::NONE,
			{ 0.2 }
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -45, -45 },
			{ -45, -45 },
			Direction::Right,
			Direction::Up,
			{ 0.45 }
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -10, -10 },
			{ -90, -90 },
			Direction::Right,
			Direction::Up,
			{ 0.45 }
		} );

		LeftClockwiseUp.resetXY = { -5, -5 };
	}

	Gesture::~Gesture( ) { }

	void Gesture::Update( )
	{
		if ( !_isMoving )
		{
			_clock.Reset( );
			_isMoving = true;
			_loopCounter = 0;
		}

		if ( _loopCounter < LeftClockwiseUp.steps.size( ) )
		{
			auto step = LeftClockwiseUp.steps.at( _loopCounter );

			bool xValid = false;
			bool yValid = false;
			bool timeValid = false;

			if ( Direction::NONE != step.xDirection )
			{
				float xLeftValue = 0;
				float xRightValue = 0;

				if ( Direction::Left == step.xDirection )
				{
					xLeftValue = Joystick::GetAxisPosition( _joystickID, _xAxis );
					xRightValue = step.xMinMax.first;
				}
				else if ( Direction::Right == step.xDirection )
				{
					xLeftValue = step.xMinMax.first;
					xRightValue = Joystick::GetAxisPosition( _joystickID, _xAxis );
				}

				if ( xLeftValue < xRightValue )
				{ xValid = true; }
			}
			else
			{
				if ( Joystick::GetAxisPosition( _joystickID, _xAxis ) > step.xMinMax.first
					&& Joystick::GetAxisPosition( _joystickID, _xAxis ) < step.xMinMax.second )
				{
					xValid = true;
				}
			}

			if ( Direction::NONE != step.yDirection )
			{
				float yLeftValue = 0;
				float yRightValue = 0;

				if ( Direction::Up == step.yDirection )
				{
					yLeftValue = Joystick::GetAxisPosition( _joystickID, _yAxis );
					yRightValue = step.yMinMax.first;
				}
				else if ( Direction::Down == step.yDirection )
				{
					yLeftValue = step.yMinMax.first;
					yRightValue = Joystick::GetAxisPosition( _joystickID, _yAxis );
				}

				if ( yLeftValue < yRightValue )
				{ yValid = true; }
			}
			else
			{
				if ( Joystick::GetAxisPosition( _joystickID, _yAxis ) > step.yMinMax.first
					&& Joystick::GetAxisPosition( _joystickID, _yAxis ) < step.yMinMax.second )
				{
					yValid = true;
				}
			}

			if ( _clock.GetElapsedTime( ).AsSeconds( ) < step.timeToFinish )
			{ timeValid = true; }

			if ( xValid && yValid && timeValid )
			{
				std::cout << _loopCounter << std::endl;

				_clock.Reset( );

				_loopCounter++;

				if ( _loopCounter >= LeftClockwiseUp.steps.size( ) )
				{ _isComplete = true; }
			}
			else if ( Joystick::GetAxisPosition( _joystickID, _xAxis ) > LeftClockwiseUp.resetXY.first )
			{ _isMoving = false; }
		}
		else
		{ _loopCounter = 0; }
	}

	bool Gesture::IsComplete( )
	{ return _isComplete; }

	void Gesture::Reset( )
	{
		_loopCounter = 0;

		_isComplete = false;
		_isMoving = false;
	}

	void Gesture::SetAnalogueStick( const AnalogueStick &analogueStick )
	{
		_analogueStick = analogueStick;

		if ( AnalogueStick::LeftStick == _analogueStick )
		{
			_xAxis = Joystick::Axis::X;
			_yAxis = Joystick::Axis::Y;
		}
		else if ( AnalogueStick::RightStick == _analogueStick )
		{
			_xAxis = Joystick::Axis::U;
			_yAxis = Joystick::Axis::R;
		}
	}

	AnalogueStick Gesture::GetAnalogueStick( ) const
	{ return _analogueStick; }

	void Gesture::SetJoystickID( const int &joystickID )
	{ _joystickID = joystickID; }

	int Gesture::GetJoystickID( ) const
	{ return _joystickID; }
}