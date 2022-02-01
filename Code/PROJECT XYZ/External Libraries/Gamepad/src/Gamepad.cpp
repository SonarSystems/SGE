//------------------------------------------------------------
// C++ Xbox 360 gamepad Input using XInput
// Demo code by Lawrence M
//------------------------------------------------------------
// This code is based off my tutorial but I have dropped the
// notation style used in the tutorial to make the code easier
// to read.
//
// Some function and variable names may have changed. For
// more details on the Gamepad class and its features, please
// refer to the tutorial.
//------------------------------------------------------------

#include "Gamepad.h"

// Link the 'XInput' library
// Note: For Visual Studio 2012 and above, XInput9_1_0 is the library
//       required to make XInput work.
#pragma comment(lib, "XInput9_1_0.lib")

// Define the 'XInput_ButtonIDs' struct as 'xButtons'
XInput_ButtonIDs xButtons;

// XInput_ButtonIDs struct
//------------------------------------------------------------

// Set buttton values in constructor
XInput_ButtonIDs::XInput_ButtonIDs()
{
	A = 0;
	B = 1;
	X = 2;
	Y = 3;

	DPad_Up    = 4;
	DPad_Down  = 5;
	DPad_Left  = 6;
	DPad_Right = 7;

	L_Shoulder = 8;
	R_Shoulder = 9;

	L_Thumbstick = 10;
	R_Thumbstick = 11;

	Start = 12;
	Back  = 13;
}

// Gamepad class
//------------------------------------------------------------

// Constructor
Gamepad::Gamepad()
{

}

// Constructor - set pad ID
Gamepad::Gamepad(int id)
{
	pad_id = id - 1;

	for (int i = 0; i < button_count; i++)
	{
		prev_buttonStates[i] = false;
		buttonStates[i]      = false;
	}
}

// Update gamepad state
void Gamepad::Update()
{
	// Get current gamepad state
	state = GetState();

	for (int i = 0; i < button_count; i++)
	{
		// Set button state on current frame
		buttonStates[i] = (state.Gamepad.wButtons & XINPUT_Buttons[i]) == XINPUT_Buttons[i];
	}
}

// Update gamepad state for next cycle
void Gamepad::Refresh()
{
	memcpy(prev_buttonStates, buttonStates, sizeof(prev_buttonStates));
}

// Set gamepad vibration ('rumble')
void Gamepad::SetRumble(float left, float right)
{
	// XInput vibration state
	XINPUT_VIBRATION rumble;

	// Zero memory on vibration state
	ZeroMemory(&rumble, sizeof(XINPUT_VIBRATION));

	// Calculate vibration intensity
	int left_motor  = int(left * 65535.0f);
	int right_motor = int(right * 65535.0f);

	rumble.wLeftMotorSpeed  = left_motor;
	rumble.wRightMotorSpeed = right_motor;

	// Apply vibration
	XInputSetState(pad_id, &rumble);
}

// Return gamepad number
int Gamepad::GetID()
{
	return pad_id;
}

// Check if gamepad is connected
bool Gamepad::Connected()
{
	// Zero memory
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	DWORD result = XInputGetState(pad_id, &state);

	if (result == ERROR_SUCCESS)
		return true;  // Connected
	else
		return false; // Not connected
}

// Check if specified button is pressed
bool Gamepad::GetButtonPressed(int button)
{
	if (state.Gamepad.wButtons & XINPUT_Buttons[button])
	{
		// Button is pressed
		return true;
	}

	return false; // Button is not pressed
}

// Check if specified button is pressed - CURRENT frame only!
bool Gamepad::GetButtonDown(int button)
{
	return !prev_buttonStates[button] && buttonStates[button];
}

// Check deadzone on left thumbstick
bool Gamepad::LStick_InDeadzone()
{
	short x = state.Gamepad.sThumbLX;
	short y = state.Gamepad.sThumbLY;

	if (x > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		x < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		// X axis outside of deadzone
		return false;
	}

	if (y > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		y < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		// Y axis outside of deadzone
		return false;
	}

	// One (or both) axis inside deadzone
	return true;
}

// Check deadzone on right thumbstick
bool Gamepad::RStick_InDeadzone()
{
	short x = state.Gamepad.sThumbRX;
	short y = state.Gamepad.sThumbRY;

	if (x > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
		x < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		// X axis outside of deadzone
		return false;
	}

	if (y > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
		y < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		// Y axis outside of deadzone
		return false;
	}

	// One (or both) axis inside deadzone
	return true;
}

// Return X axis of left thumbstick
float Gamepad::LeftStick_X()
{
	short x = state.Gamepad.sThumbLX;

	// Return value as a float
	return (static_cast<float>(x) / 32768.0f);
}

// Return Y axis of left thumbstick
float Gamepad::LeftStick_Y()
{
	short y = state.Gamepad.sThumbLY;

	// Return value as a float
	return (static_cast<float>(y) / 32768.0f);
}

// Return X axis of right thumbstick
float Gamepad::RightStick_X()
{
	short x = state.Gamepad.sThumbRX;

	// Return value as a float
	return (static_cast<float>(x) / 32768.0f);
}

// Return Y axis of right thumbstick
float Gamepad::RightStick_Y()
{
	short y = state.Gamepad.sThumbRY;

	// Return value as a float
	return (static_cast<float>(y) / 32768.0f);
}

// Return value of left trigger
float Gamepad::LeftTrigger()
{
	BYTE axis = state.Gamepad.bLeftTrigger;

	if (axis > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		return axis / 255.0f;

	return 0.0f; // Trigger was not pressed
}

// Return value of right trigger
float Gamepad::RightTrigger()
{
	BYTE axis = state.Gamepad.bRightTrigger;

	if (axis > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		return axis / 255.0f;

	return 0.0f; // Trigger was not pressed
}

// Return gamepad state
XINPUT_STATE Gamepad::GetState()
{
	XINPUT_STATE new_state;

	// Zero memory on state
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	// Get new state from XInput
	XInputGetState(pad_id, &new_state);

	return new_state;
}