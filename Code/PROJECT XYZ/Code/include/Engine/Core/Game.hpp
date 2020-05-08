#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include <Box2D/Box2D.h>
#include "b2GLDraw.h"
#include "Debug.hpp"
#include "Events.hpp"

namespace Sonar
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
        Debug *debug;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game( const int &width, const int &height, const std::string &title );
                
	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>( );

		void Run( );
        
	};
}
