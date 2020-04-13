#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace Sonar
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void HandleInput(float dt);
		void Update(float dt);
		void Draw(float dt);
        
        /** Create the base for the boxes to land */
        void CreateGround(b2World& World, float X, float Y);

        /** Create the boxes */
        void CreateBox(b2World& World, int MouseX, int MouseY);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::RectangleShape player;
        
        b2Vec2 Gravity;
        b2World *World;
        
        b2GLDraw fooDrawInstance;
        
        sf::Texture GroundTexture;
        sf::Texture BoxTexture;
	};
}
