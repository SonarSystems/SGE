#include "Input/Gesture.hpp"

namespace Sonar
{
	Gesture::Gesture( )
	{
		canCheckRotation = false;

		LeftClockwiseUp.steps.push_back(
		{
			{ -50, -50 },
			{ -20, 20 },
			Direction::Left,
			Direction::NONE,
			{ 0.1 },
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -90, -90 },
			{ -20, 20 },
			Direction::Left,
			Direction::NONE,
			{ 0.1 }
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -45, -45 },
			{ -45, -45 },
			Direction::Right,
			Direction::Up,
			{ 0.1 }
		} );

		LeftClockwiseUp.steps.push_back(
		{
			{ -10, -10 },
			{ -90, -90 },
			Direction::Right,
			Direction::Up,
			{ 0.1 }
		} );

		LeftClockwiseUp.resetXY = { -10, -10 };

		/*LeftClockwiseUp.pos1[0] = -50;
		LeftClockwiseUp.pos1[1] = -20;
		LeftClockwiseUp.pos1[2] = 20;

		LeftClockwiseUp.pos2[0] = -90;
		LeftClockwiseUp.pos2[1] = -20;
		LeftClockwiseUp.pos2[2] = 20;

		LeftClockwiseUp.pos3[0] = -45;
		LeftClockwiseUp.pos3[1] = -45;

		LeftClockwiseUp.pos4[0] = -10;
		LeftClockwiseUp.pos4[1] = -90;

		LeftClockwiseUp.reset[0] = -10;

		LeftClockwiseUp.time = 0.1f;*/
	}

	Gesture::~Gesture( ) { }

	void Gesture::Update( )
	{
		if ( !isMoving )
		{
			clock.Reset( );
			isMoving = true;
		}

		int counter = 0;

		for ( auto step : LeftClockwiseUp.steps )
		{
			//std::cout << step.xMinMax.first << " : " << step.xMinMax.second << std::endl;

			bool xValid = false;
			bool yValid = false;
			bool timeValid = false;

			if ( Direction::NONE != step.xDirection )
			{
				float xLeftValue = 0;
				float xRightValue = 0;

				if ( Direction::Left == step.xDirection )
				{
					xLeftValue = Joystick::GetAxisPosition( 1, Joystick::Axis::X );
					xRightValue = step.xMinMax.first;
				}
				else if ( Direction::Right == step.xDirection )
				{
					xLeftValue = step.xMinMax.first;
					xRightValue = Joystick::GetAxisPosition( 1, Joystick::Axis::X );
				}

				if ( xLeftValue < xRightValue )
				{ xValid = true; }
			}
			else
			{
				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > step.xMinMax.first
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < step.xMinMax.second )
				{ xValid = true; }
			}

			if ( Direction::NONE != step.yDirection )
			{
				float yLeftValue = 0;
				float yRightValue = 0;

				if ( Direction::Up == step.yDirection )
				{
					yLeftValue = Joystick::GetAxisPosition( 1, Joystick::Axis::Y );
					yRightValue = step.yMinMax.first;
				}
				else if ( Direction::Down == step.yDirection )
				{
					yLeftValue = step.yMinMax.first;
					yRightValue = Joystick::GetAxisPosition( 1, Joystick::Axis::Y );
				}

				if ( yLeftValue < yRightValue )
				{ yValid = true; }
			}
			else
			{
				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) > step.yMinMax.first
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < step.yMinMax.second )
				{ yValid = true; }
			}

			if ( clock.GetElapsedTime( ).AsSeconds( ) < step.timeToFinish )
			{ timeValid = true;  }

			if ( xValid && yValid && timeValid )
			{
				clock.Reset( );

				counter++;

				if ( counter >= LeftClockwiseUp.steps.size( ) )
				{
					std::cout << "Gesture DONE" << std::endl;
				}
				continue;
			}
			else if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > LeftClockwiseUp.resetXY.first )
			{
				isMoving = false;
			}

			break;
		}







		/*if ( !canCheckRotation )
		{
			if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < LeftClockwiseUp.pos1[0]
				&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) > LeftClockwiseUp.pos1[1]
				&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < LeftClockwiseUp.pos1[2]
				&& clock.GetElapsedTime( ).AsSeconds( ) < LeftClockwiseUp.time )
			{
				clock.Reset( );

				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < LeftClockwiseUp.pos2[0]
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) > LeftClockwiseUp.pos2[1]
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < LeftClockwiseUp.pos2[2]
					&& clock.GetElapsedTime( ).AsSeconds( ) < LeftClockwiseUp.time )
				{
					clock.Reset( );
					canCheckRotation = true;
				}
			}
			else if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > LeftClockwiseUp.reset[0] )
			{
				isMoving = false;
			}
		}
		else
		{
			if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > LeftClockwiseUp.pos3[0]
				&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < LeftClockwiseUp.pos3[1]
				&& clock.GetElapsedTime( ).AsSeconds( ) < LeftClockwiseUp.time )
			{
				clock.Reset( );

				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > LeftClockwiseUp.pos4[0]
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < LeftClockwiseUp.pos4[1]
					&& clock.GetElapsedTime( ).AsSeconds( ) < LeftClockwiseUp.time )
				{
					std::cout << "Gesture Successful" << std::endl;
					clock.Reset( );
					canCheckRotation = false;
				}
			}
			else if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > LeftClockwiseUp.reset[0] )
			{
				isMoving = false;
			}
		}*/
	}
}

/* RECOMMENDATION BY MR HERR DINGENZ
that can be done by setting up a bool when a gestures is triggered 
and checking which gesture was triggered at the end of the gesture
*/