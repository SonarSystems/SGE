#include "pch.hpp"

namespace Sonar
{
	Gesture::Gesture( const int &joystickID, const AnalogueStick &analogueStick, const Pattern &pattern ) : _joystickID( joystickID )
	{
		_loopCounter = 0;

		_isComplete = false;
		_isMoving = false;

		SetAnalogueStick( analogueStick );

		SetPattern( pattern );

		_previousAngle = 0.0f;
		_isRotating = false;
		_totalDegreesTurned = 0;
	}

	Gesture::~Gesture( ) { }

	void Gesture::Update( )
	{		
		if ( Pattern::Clockwise != _gesturePattern.pattern && Pattern::CounterClockwise != _gesturePattern.pattern )
		{ 
			if ( !_isMoving )
			{
				_clock.Reset( );
				_isMoving = true;
				_loopCounter = 0;
			}

			if ( _loopCounter < _gesturePattern.steps.size( ) )
			{
				auto step = _gesturePattern.steps.at( _loopCounter );

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

					if ( _loopCounter >= _gesturePattern.steps.size( ) )
					{ _isComplete = true; }
				}
				else
				{
					if ( ComparisonDirection::LessThan == _comparisonDirection )
					{
						if ( Joystick::GetAxisPosition( _joystickID, _resetAxis ) < _gesturePattern.resetPos )
						{ _isMoving = false; }
					}
					else if ( ComparisonDirection::GreaterThan == _comparisonDirection )
					{
						if ( Joystick::GetAxisPosition( _joystickID, _resetAxis ) > _gesturePattern.resetPos )
						{ _isMoving = false; }
					}
				}
			}
			else
			{ _loopCounter = 0; }
		}
		else if ( Pattern::Clockwise == _gesturePattern.pattern )
		{
			float distanceFromCenter = Joystick::GetJoystickDistanceFromCenter( _joystickID, _xAxis, _yAxis );

			if ( distanceFromCenter > 70 )
			{
				float angle = Joystick::GetJoystickAngle( _joystickID, _xAxis, _yAxis );

				if ( !_isRotating )
				{
					_clock.Reset( );
					_previousAngle = angle;
					_isRotating = true;
					_totalDegreesTurned = 0;
				}
				else
				{
					if ( angle > _previousAngle )
					{
						_totalDegreesTurned += angle - _previousAngle;
						_previousAngle = angle;
					}
					else if ( _previousAngle > 300 && angle < 60 )
					{ _previousAngle = angle; }
					else if ( angle < _previousAngle )
					{
						_isRotating = false;
					}
				}
			}
			else
			{
				_isRotating = false;
				_totalDegreesTurned = 0;
			}
		}
		else if ( Pattern::CounterClockwise == _gesturePattern.pattern )
		{
			float distanceFromCenter = Joystick::GetJoystickDistanceFromCenter( _joystickID, _xAxis, _yAxis );

			if ( distanceFromCenter > 70 )
			{
				float angle = Joystick::GetJoystickAngle( _joystickID, _xAxis, _yAxis );

				if ( !_isRotating )
				{
					_clock.Reset( );
					_previousAngle = angle;
					_isRotating = true;
					_totalDegreesTurned = 0;
				}
				else
				{
					if ( angle < _previousAngle )
					{
						_totalDegreesTurned += _previousAngle - angle;
						_previousAngle = angle;
					}
					else if ( _previousAngle < 300 && angle > 60 )
					{ _previousAngle = angle; }
					else if ( angle > _previousAngle )
					{
						_isRotating = false;
					}
				}
			}
			else
			{
				_isRotating = false;
				_totalDegreesTurned = 0;
			}
		}
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

	void Gesture::SetPattern( const Pattern &pattern )
	{
		_gesturePattern.pattern = pattern;

		if ( Pattern::LeftClockwiseUp == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -50.0f, -50.0f },
				{ -30.0f, 30.0f },
				Direction::Left,
				Direction::NONE,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -90.0f, -90.0f },
				{ -30.0f, 30.0f },
				Direction::Left,
				Direction::NONE,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -45.0f, -45.0f },
				{ -45.0f, -45.0f },
				Direction::Right,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -20.0f, -20.0f },
				{ -90.0f, -90.0f },
				Direction::Right,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = -15.0f;
		}
		else if ( Pattern::LeftCounterClockwiseDown == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -50.0f, -50.0f },
				{ -30.0f, 30.0f },
				Direction::Left,
				Direction::NONE,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -90.0f, -90.0f },
				{ -30.0f, 30.0f },
				Direction::Left,
				Direction::NONE,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -45.0f, -45.0f },
				{ 45.0f, 45.0f },
				Direction::Right,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -20.0f, -20.0f },
				{ 90.0f, 90.0f },
				Direction::Right,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = -15.0f;
		}
		else if ( Pattern::RightCounterClockwiseUp == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ 50.0f, 50.0f },
				{ -30.0f, 30.0f },
				Direction::Right,
				Direction::NONE,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ 90.0f, 90.0f },
				{ -30.0f, 30.0f },
				Direction::Right,
				Direction::NONE,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 45.0f, 45.0f },
				{ -45.0f, -45.0f },
				Direction::Left,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 20.0f, 20.0f },
				{ -90.0f, -90.0f },
				Direction::Left,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = 15.0f;
		}
		else if ( Pattern::RightClockwiseDown == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ 50.0f, 50.0f },
				{ -30.0f, 30.0f },
				Direction::Right,
				Direction::NONE,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ 90.0f, 90.0f },
				{ -30.0f, 30.0f },
				Direction::Right,
				Direction::NONE,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 45.0f, 45.0f },
				{ 45.0f, 45.0f },
				Direction::Left,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 20.0f, 20.0f },
				{ 90.0f, 90.0f },
				Direction::Left,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = 15.0f;
		}
		else if ( Pattern::UpCounterClockwiseLeft == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ -50.0f, -50.0f },
				Direction::NONE,
				Direction::Up,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ -90.0f, -90.0f },
				Direction::NONE,
				Direction::Up,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -45.0f, -45.0f },
				{ -45.0f, -45.0f },
				Direction::Left,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -90.0f, -90.0f },
				{ -20.0f, -20.0f },
				Direction::Left,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = -15.0f;
		}
		else if ( Pattern::UpClockwiseRight == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ -50.0f, -50.0f },
				Direction::NONE,
				Direction::Up,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ -90.0f, -90.0f },
				Direction::NONE,
				Direction::Up,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 45.0f, 45.0f },
				{ -45.0f, -45.0f },
				Direction::Right,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 90.0f, 90.0f },
				{ -20.0f, -20.0f },
				Direction::Right,
				Direction::Down,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = -15.0f;
		}
		else if ( Pattern::DownClockwiseLeft == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ 50.0f, 50.0f },
				Direction::NONE,
				Direction::Down,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ 90.0f, 90.0f },
				Direction::NONE,
				Direction::Down,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -45.0f, -45.0f },
				{ 45.0f, 45.0f },
				Direction::Left,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ -90.0f, -90.0f },
				{ 20.0f, 20.0f },
				Direction::Left,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = 15.0f;
		}
		else if ( Pattern::DownCounterClockwiseRight == _gesturePattern.pattern )
		{
			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ 50.0f, 50.0f },
				Direction::NONE,
				Direction::Down,
				{ 0.2f },
			} );

			_gesturePattern.steps.push_back(
			{
				{ -30.0f, 30.0f },
				{ 90.0f, 90.0f },
				Direction::NONE,
				Direction::Down,
				{ 0.2f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 45.0f, 45.0f },
				{ 45.0f, 45.0f },
				Direction::Right,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.steps.push_back(
			{
				{ 90.0f, 90.0f },
				{ 20.0f, 20.0f },
				Direction::Right,
				Direction::Up,
				{ 0.45f }
			} );

			_gesturePattern.resetPos = 15.0f;
		}

		SetResetAxis( );
	}

	Pattern Gesture::GetPattern( ) const
	{ return _gesturePattern.pattern; }


	bool Gesture::GetIsRotating( ) const
	{ return _isRotating; }

	bool Gesture::GetTotalDegreesTurned( const bool &isDegrees /*= true */ ) const
	{
		if ( !isDegrees )
		{ return _totalDegreesTurned * ( 3.14159f / 180.0f ); }
		else
		{ return _totalDegreesTurned; }
	}

	float Gesture::GetTotalCirclesTurned( ) const
	{ return _totalDegreesTurned / 360.0f; }

	Sonar::Clock Gesture::GetClock( )
	{ return _clock; }

	void Gesture::SetResetAxis( )
	{
		if ( Pattern::Clockwise != _gesturePattern.pattern && Pattern::CounterClockwise != _gesturePattern.pattern )
		{
			if ( Direction::NONE != _gesturePattern.steps.at( 0 ).xDirection )
			{
				if ( Direction::Left == _gesturePattern.steps.at( 0 ).xDirection )
				{
					// > is original for Left
					_comparisonDirection = ComparisonDirection::GreaterThan;
				}
				else if ( Direction::Right == _gesturePattern.steps.at( 0 ).xDirection )
				{
					// < should be for Right
					_comparisonDirection = ComparisonDirection::LessThan;
				}

				_resetAxis = _xAxis;
			}
			else if ( Direction::NONE != _gesturePattern.steps.at( 0 ).yDirection )
			{
				if ( Direction::Up == _gesturePattern.steps.at( 0 ).yDirection )
				{
					// > is original for Up
					_comparisonDirection = ComparisonDirection::GreaterThan;
				}
				else if ( Direction::Down == _gesturePattern.steps.at( 0 ).yDirection )
				{
					// < should be for Down
					_comparisonDirection = ComparisonDirection::LessThan;
				}

				_resetAxis = _yAxis;
			}
		}
	}


}