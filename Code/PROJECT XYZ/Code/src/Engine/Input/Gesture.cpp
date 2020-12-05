#include "Input/Gesture.hpp"

namespace Sonar
{
	Gesture::Gesture( )
	{
		canCheckRotation = false;

		
	}

	Gesture::~Gesture( ) { }

	void Gesture::Update( )
	{
		if ( !isMoving )
		{
			clock.Reset( );
			isMoving = true;
		}

		if ( !canCheckRotation )
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
		else if ( canCheckRotation )
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
		}
	}
}

/* RECOMMENDATION BY MR HERR DINGENZ
that can be done by setting up a bool when a gestures is triggered 
and checking which gesture was triggered at the end of the gesture
*/