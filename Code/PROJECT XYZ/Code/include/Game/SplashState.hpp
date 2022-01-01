#pragma once

#include "Sonar.hpp"
#include "Player.hpp"
#include "PhysicsWorld.hpp"

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

		void PollInput( const float &dt, Event &event );
		void Update( const float &dt );
		void Draw( const float &dt );

	private:
		GameDataRef _data;
        
        PhysicsWorld *physicsWorld;
        
		Player *player;

		Label *label;

		Menu *menu;

		std::shared_ptr<Button> button, button2, button3;

		std::shared_ptr<ButtonGroup> buttonGroup;

		TextBox *textBox;

		RadioButton *radio, *radio2, *radio3;

		RadioButtonGroup *group;

		Slider *slider;

		ProgressBar *progressBar;

		Minimap *mm;

		View *view;

		std::shared_ptr<Music> music;

		
		char windowTitle[255] = "ImGui + SFML = <3";


	};
}
