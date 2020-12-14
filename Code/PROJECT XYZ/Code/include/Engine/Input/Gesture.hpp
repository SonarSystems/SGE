#pragma once

#include "Core/Clock.hpp"
#include "Input/Joystick.hpp"

#include <iostream>
#include <cmath>

namespace Sonar
{
	/**
	* \brief Analogue Sticks
	*/
	enum AnalogueStick
	{
		LeftStick,
		RightStick
	};

	/**
	* \brief Analogue Stick Direction
	*/
	enum Direction
	{
		Left,
		Right,
		Up,
		Down,
		NONE
	};

	/**
	* \brief Logical Comparison Direction
	*/
	enum ComparisonDirection
	{
		LessThan,
		GreaterThan
	};

	/**
	* \brief Patterns for the Gesture
	*/
	enum Pattern
	{
		LeftClockwiseUp,
		LeftCounterClockwiseDown,
		RightCounterClockwiseUp,
		RightClockwiseDown,

		UpCounterClockwiseLeft,
		UpClockwiseRight,
		DownClockwiseLeft,
		DownCounterClockwiseRight,

		Clockwise,
		CounterClockwise
	};

	/**
	* \brief Individual gesture step
	*/
	struct GestureStep
	{
		std::pair<float, float> xMinMax;
		std::pair<float, float> yMinMax;

		Direction xDirection;
		Direction yDirection;

		float timeToFinish = 0;
	};

	/**
	* \brief Gesture sequence with all steps and reset
	*/
	struct GesturePattern
	{
		std::vector<GestureStep> steps;

		float resetPos;

		Pattern pattern;
	};

	class Gesture
	{
	public:
		/**
		* \brief Class constructor
		*/
		Gesture( const int &joystickID, const AnalogueStick &analogueStick, const Pattern &pattern );

		/**
		* \brief Class destructor
		*/
		~Gesture( );

		/**
		* \brief Update the gesture
		*/
		void Update( );

		/**
		* \brief Checks if the gesture is complete
		*
		* \return Output returns the status of the gesture
		*/
		bool IsComplete( );

		/**
		* \brief Reset the Gesture
		*/
		void Reset( );

		/**
		* \brief Set the analogue stick
		*
		* \param analogueStick Analogue stick for gesture
		*/
		void SetAnalogueStick( const AnalogueStick &analogueStick );

		/**
		* \brief Get the current analogue stick
		*
		* \return Output returns the gesture's analogue stick
		*/
		AnalogueStick GetAnalogueStick( ) const;

		/**
		* \brief Set the joysticks ID
		*
		* \param analogueStick Analogue stick for gesture
		*/
		void SetJoystickID( const int &joystickID );

		/**
		* \brief Get the ID of the current joystick
		*
		* \return Output returns the joystick ID
		*/
		int GetJoystickID( ) const;

		/**
		* \brief Set the gesture pattern
		*
		* \param pattern Gesture pattern to be used
		*/
		void SetPattern( const Pattern &pattern );

		/**
		* \brief Get the gesture pattern
		*
		* \return Output returns the gesture pattern
		*/
		Pattern GetPattern( ) const;

	private:
		void SetResetAxis( );

		/**
		* \brief Keeps track of the time between steps
		*/
		Clock _clock;

		/**
		* \brief Is the device moving or not
		*/
		bool _isMoving;

		/**
		* \brief Is the gesture complete
		*/
		bool _isComplete;

		/**
		* \brief What stage of the gesture is currently active
		*/
		int _loopCounter;

		/**
		* \brief ID of the joystick to be checked
		*/
		int _joystickID;

		/**
		* \brief X axis of the joystick
		*/
		Joystick::Axis _xAxis;

		/**
		* \brief Y axis of the joystick
		*/
		Joystick::Axis _yAxis;

		/**
		* \brief Analogue stick to check gesture with
		*/
		AnalogueStick _analogueStick;

		/**
		* \brief Gesture pattern to be checked
		*/
		GesturePattern _gesturePattern;

		/**
		* \brief Reset axis to check
		*/
		Joystick::Axis _resetAxis;

		/**
		* \brief Comparison direction for the reset axis
		*/
		ComparisonDirection _comparisonDirection;

	};
}