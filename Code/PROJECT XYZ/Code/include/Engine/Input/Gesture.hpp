#pragma once

#include "Core/Clock.hpp"
#include "Input/Joystick.hpp"
#include <iostream>

namespace Sonar
{
	struct G
	{
		int pos1[3];
		int pos2[3];
		int pos3[2];
		int pos4[2];
		
		int reset[1];
		
		float time;
	} LeftClockwiseUp, RightCounterClockwiseUp;

	//static int pos1[3] = { -50, -20, 20 };
	//static int pos2[3] = { -90, -20, 20 };
	//static int pos3[2] = { -45, -45 };
	//static int pos4[2] = { -10, -90 };

	//static int reset[1] = { -10 };

	//static float time = 0.1f;

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

	};
}