#pragma once

#include <SFML/Graphics.hpp>
#include "Sonar.h"
#include "Player.hpp"
#include "PhysicsWorld.hpp"

namespace Sonar
{
	class SplashState : public State
	{
	public:
		SplashState( GameDataRef data );

		void Init( );

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void HandleInput( float dt );
		void Update( float dt );
		void Draw( float dt );

	private:
		GameDataRef _data;

		sf::Clock _clock;
        
        PhysicsWorld *physicsWorld;
        
        Player *player;
                
	};
}
