#include "Core/Game.hpp"
#include "Core/ENGINEDEFINITIONS.hpp"
#include <iostream>
#include "External/Gamepad.h"

using namespace std;



				 // This example checks input on all gamepad buttons (Guide/logo
				 // button not supported). For example code on using the triggers
//				 // and thumbsticks, please refer to the tutorial.
//void TestGamepad( )
//{
//	// GetButtonDown only returns true on the frame it was first pressed.
//	if ( gamepad.GetButtonDown( xButtons.A ) )
//	{
//		cout << " Button [A] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.X ) )
//	{
//		cout << " Button [X] pressed" << endl;
//	}
//
//	// GetButtonPressed will keep returning true until the button is released.
//	if ( gamepad.GetButtonPressed( xButtons.Y ) )
//	{
//		cout << " Button [Y] held, see how this doesn't appear just once?" << endl;
//		gamepad.SetRumble( 1, 0 );
//	}
//
//	// Check the D-Pad buttons
//	if ( gamepad.GetButtonDown( xButtons.DPad_Up ) )
//	{
//		cout << " Button [DPad Up] pressed" << endl;
//		gamepad.SetRumble( 0, 0 );
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.DPad_Down ) )
//	{
//		cout << " Button [DPad Down] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.DPad_Left ) )
//	{
//		cout << " Button [DPad Left] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.DPad_Right ) )
//	{
//		cout << " Button [DPad Right] pressed" << endl;
//	}
//
//	// Check the Shoulder ('bumper') buttons
//	if ( gamepad.GetButtonDown( xButtons.L_Shoulder ) )
//	{
//		cout << " Button [L Bumper] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.R_Shoulder ) )
//	{
//		cout << " Button [R Bumper] pressed" << endl;
//	}
//
//	// Check the BACK and START buttons
//	if ( gamepad.GetButtonDown( xButtons.Back ) )
//	{
//		cout << " Button [BACK] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.Start ) )
//	{
//		cout << " Button [START] pressed" << endl;
//	}
//
//	// Check the Thumbstick buttons (press in the thumbstick)
//	if ( gamepad.GetButtonDown( xButtons.L_Thumbstick ) )
//	{
//		cout << " Button [L STICK] pressed" << endl;
//	}
//
//	if ( gamepad.GetButtonDown( xButtons.R_Thumbstick ) )
//	{
//		cout << " Button [R STICK] pressed" << endl;
//	}
//}

int main( )
{
	//bool running;    // Used to break the loop
	//Gamepad gamepad; // Gamepad instance


	//// Set up
	//running = true;
	//gamepad = Gamepad( 1 ); // Set gamepad ID to 1

	//cout << " --------------------------------------------" << endl;
	//cout << "          Xbox 360 Gamepad INPUT TEST        " << endl;
	//cout << " --------------------------------------------" << endl << endl;

	//cout << " Use gamepad buttons to test gamepad input." << endl;
	//cout << " To quit, press the [B] button." << endl;
	//cout << " --------------------------------------------" << endl << endl;

	//// Pretend game loop, repeat until 'B' is pressed
	//do
	//{
	//	gamepad.Update( ); // Update gamepad

	//	if ( gamepad.Connected( ) )
	//	{
	//		// Run gamepad input test
	//		//TestGamepad( );

	//		if ( gamepad.GetButtonDown( xButtons.A ) )
	//		{
	//			cout << " Button [A] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.X ) )
	//		{
	//			cout << " Button [X] pressed" << endl;
	//		}

	//		// GetButtonPressed will keep returning true until the button is released.
	//		if ( gamepad.GetButtonPressed( xButtons.Y ) )
	//		{
	//			cout << " Button [Y] held, see how this doesn't appear just once?" << endl;
	//			gamepad.SetRumble( 1, 0 );
	//		}

	//		// Check the D-Pad buttons
	//		if ( gamepad.GetButtonDown( xButtons.DPad_Up ) )
	//		{
	//			cout << " Button [DPad Up] pressed" << endl;
	//			gamepad.SetRumble( 0, 0 );
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.DPad_Down ) )
	//		{
	//			cout << " Button [DPad Down] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.DPad_Left ) )
	//		{
	//			cout << " Button [DPad Left] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.DPad_Right ) )
	//		{
	//			cout << " Button [DPad Right] pressed" << endl;
	//		}

	//		// Check the Shoulder ('bumper') buttons
	//		if ( gamepad.GetButtonDown( xButtons.L_Shoulder ) )
	//		{
	//			cout << " Button [L Bumper] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.R_Shoulder ) )
	//		{
	//			cout << " Button [R Bumper] pressed" << endl;
	//		}

	//		// Check the BACK and START buttons
	//		if ( gamepad.GetButtonDown( xButtons.Back ) )
	//		{
	//			cout << " Button [BACK] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.Start ) )
	//		{
	//			cout << " Button [START] pressed" << endl;
	//		}

	//		// Check the Thumbstick buttons (press in the thumbstick)
	//		if ( gamepad.GetButtonDown( xButtons.L_Thumbstick ) )
	//		{
	//			cout << " Button [L STICK] pressed" << endl;
	//		}

	//		if ( gamepad.GetButtonDown( xButtons.R_Thumbstick ) )
	//		{
	//			cout << " Button [R STICK] pressed" << endl;
	//		}

	//		// Pressing B quits the program
	//		if ( gamepad.GetButtonPressed( xButtons.B ) )
	//			running = false;
	//	}

	//	gamepad.Refresh( ); // Update gamepad for next cycle
	//} while ( running );

    Sonar::Game( SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE );

    return EXIT_SUCCESS;
}
