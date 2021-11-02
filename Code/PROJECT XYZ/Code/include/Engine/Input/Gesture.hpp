#pragma once

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
		[[nodiscard]] bool IsComplete( );

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
		[[nodiscard]] AnalogueStick GetAnalogueStick( ) const;

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
		[[nodiscard]] int GetJoystickID( ) const;

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
		[[nodiscard]] Pattern GetPattern( ) const;

		/**
		* \brief Get the status of the joystick rotation (only for Clockwise and CounterClockwise patterns)
		*
		* \return Output returns joystick rotation status
		*/
		[[nodiscard]] bool GetIsRotating( ) const;

		/**
		* \brief Get the total number of degrees turned (only for Clockwise and CounterClockwise patterns)
		*
		* \param isDegrees True (by default) returns the result in degrees and false returns it in radians
		*
		* \return Output returns total degrees turned by the joystick
		*/
		[[nodiscard]] bool GetTotalDegreesTurned( const bool &isDegrees = true ) const;

		/**
		* \brief Get the total number of circles turned by the joystick (only for Clockwise and CounterClockwise patterns)
		*
		* \return Output returns total number of joystick rotations
		*/
		[[nodiscard]] float GetTotalCirclesTurned( ) const;

		/**
		* \brief Get the gesture clock (only for Clockwise and CounterClockwise patterns)
		*
		* \return Output returns clock
		*/
		[[nodiscard]] Clock GetClock( );

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
		unsigned int _loopCounter;

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

		float _previousAngle;

		/**
		* \brief Track whether or not the joystick is turning (only for Clockwise and CounterClockwise patterns)
		*/
		bool _isRotating;

		/**
		* \brief Total number of degrees the joystick has turned (only for Clockwise and CounterClockwise patterns)
		*/
		float _totalDegreesTurned;


	};
}