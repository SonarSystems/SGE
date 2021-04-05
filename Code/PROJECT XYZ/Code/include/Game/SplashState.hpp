#pragma once

#include "Sonar.hpp"
#include "Player.hpp"
#include "PhysicsWorld.hpp"
#include <ctime>

namespace Sonar
{
	class SplashState : public State
	{
	public:
		SplashState( GameDataRef data );

		~SplashState( );

		void Init( );

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void PollInput( const float &dt, const Event &event );
		void Update( const float &dt );
		void Draw( const float &dt );

	private:
		GameDataRef _data;
        
        PhysicsWorld *physicsWorld;
        
		Player *player;

		Label *label;

		Menu *menu;

		Button *button;

		TextBox *textBox;

		RadioButton *radio, *radio2, *radio3;

		RadioButtonGroup *group;

		Slider *slider;

	};
}
