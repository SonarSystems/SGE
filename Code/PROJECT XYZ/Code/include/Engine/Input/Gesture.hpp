#pragma once

#include "Core/Clock.hpp"
#include "Input/Joystick.hpp"
#include <iostream>

namespace Sonar
{
	/*struct GesturePattern
	{
		int pos1[3];
		int pos2[3];
		int pos3[2];
		int pos4[2];
		
		int reset[1];
		
		float time;
	};*/

	enum Direction
	{
		 Left,
		 Right,
		 Up,
		 Down,
		 NONE
	};

	struct GestureStep
	{
		std::pair<float, float> xMinMax;
		std::pair<float, float> yMinMax;

		Direction xDirection;
		Direction yDirection;

		float timeToFinish = 0;
	};

	struct GesturePattern
	{
		std::vector<GestureStep> steps;

		std::pair<float, float> resetXY;
	};

	class Gesture
	{
	public:
		/**
		* \brief Class constructor
		*/
		Gesture( );

		/**
		* \brief Class destructor
		*/
		~Gesture( );

		void Update( );

	private:
		Clock clock;

		bool isMoving;

		bool canCheckRotation;

		GesturePattern LeftClockwiseUp;

		

	};
}