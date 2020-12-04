#include <sstream>
#include "SplashState.hpp"
#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );
		
		std::cout << Joystick::IsConnected( 1 ) << std::endl;

		canCheckRotation = false;

		check1 = check2 = check3 = false;
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );
        
        if ( Event::MouseWheelMoved == event.type )
        {
            physicsWorld->CreateDynamicBody( event.mouseButton.x, event.mouseButton.y, 32, 32 );
        }

		/*std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::R ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::U ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::V  ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::Z ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::PovX ) << " : "
			<< Joystick::GetAxisPosition( 1, Joystick::Axis::PovY ) << " : " << std::endl;*/

		if ( Event::JoystickMoved == event.type )
		{
			//std::cout << "The joystick has moved" << std::endl;

			if ( Joystick::Axis::X == event.joystickMove.axis )
			{
				//started = true;
				//std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " : " << Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << std::endl;

				////std::cout << "X movement" << std::endl;

				//if ( !isMoving )
				//{
				//	clock.Reset( );
				//	isMoving = true;
				//}



				//if ( event.joystickMove.position < -50 && clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				//{
				//	//std::cout << "YO" << std::endl;
				//	clock.Reset( );

				//	if ( event.joystickMove.position < -90 && clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				//	{
				//		//std::cout << "YO2" << std::endl;
				//		clock.Reset( );

				//		if ( ( event.joystickMove.position < -45 && Joystick::Axis::X == event.joystickMove.axis ) 
				//			&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < -45
				//			&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				//		{
				//			//std::cout << "YO3" << std::endl;
				//			clock.Reset( );

				//			

				//			if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < -90
				//				&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < -50
				//				&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				//			{
				//				//std::cout << "Gesture Successful" << std::endl;
				//				clock.Reset( );
				//			}
				//		}
				//	}
				//}
				//else if ( event.joystickMove.position > -10 )
				//{
				//	isMoving = false;
				//}
			}
		}

		//std::cout << Joystick::IsGestureTriggered( 1, Joystick::AnalogueStick::RightStick, Joystick::Direction::LeftDown ) << std::endl;
		
		
	}

	void SplashState::Update( const float &dt )
	{
		//std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " : " << Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << std::endl;
        player->Update( dt );
        
        physicsWorld->Update( dt );

		/*std::cout << ( Joystick::IsGestureTriggered( 1, Joystick::AnalogueStick::LeftStick, Joystick::Direction::Up ) 
			&& Joystick::IsGestureTriggered( 1, Joystick::AnalogueStick::LeftStick, Joystick::Direction::Left ) ) 
			<< std::endl;*/

		//if ( started )
		{
			if ( !isMoving )
			{
				clock.Reset( );
				isMoving = true;
			}



			if ( !canCheckRotation )
			{
				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < -50
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) > -20
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < 20
					&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				{
					check1 = true;
					std::cout << "YO" << std::endl;
					clock.Reset( );

					if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) < -90
						&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) > -20
						&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < 20
						&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
					{
						check2 = true;
						std::cout << "YO2" << std::endl;
						clock.Reset( );

						canCheckRotation = true;
					}
					else
					{ check1 = check2 = check3 = false; }
				}
				else if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > -10 )
				{
					isMoving = false;
					check1 = check2 = check3 = false;
				}
				else
				{ check1 = check2 = check3 = false; }
			}
			else if ( canCheckRotation )
			{
				//std::cout << Joystick::GetAxisPosition( 1, Joystick::Axis::X ) << " : " << Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) << std::endl;
				if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > -45
					&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < -45
					&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5 )
				{
					check3 = true;
					std::cout << "YO3" << std::endl;
					clock.Reset( );



					if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > -10
						&& Joystick::GetAxisPosition( 1, Joystick::Axis::Y ) < -90
						&& clock.GetElapsedTime( ).AsSeconds( ) < 0.5
						&& true == check1 && true == check2 && true == check3)
					{
						std::cout << "Gesture Successful" << std::endl;
						clock.Reset( );
						canCheckRotation = false;
					}
					else
					{ check3 = false; }
				}
				else if ( Joystick::GetAxisPosition( 1, Joystick::Axis::X ) > -10 )
				{
					isMoving = false;
					check3 = false;
				}
				else
				{ check3 = false; }
			}
		}
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
        physicsWorld->Draw( dt );
	}

    
}
