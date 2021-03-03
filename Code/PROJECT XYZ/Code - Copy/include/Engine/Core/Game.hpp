#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "StateMachine.hpp"
#include "Managers/AssetManager.hpp"
#include "External/b2GLDraw.h"
#include "Core/Debug.hpp"
#include "Input/Events.hpp"
#include "Graphics/Color.hpp"

namespace Sonar
{
    /**
     * \brief Game data 
    */
	struct GameData
	{
		StateMachine machine; // State machine to handle the states
		sf::RenderWindow window; // Game window
		AssetManager assets; // Asset manager
        Debug *debug; // Debugger
        Color backgroundColor = Color::White;
	};
    
    /**
     * \brief Shared pointer for the Game data struct
    */
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
        /**
         * \brief Class constructor
         *
         * \param width Game window width
         * \param height Game window height
         * \param title Game window title
        */
		Game( const int &width, const int &height, const std::string &title );
                        
	private:
        /**
         * \brief Updates run at 60 per second.
        */
		const float dt = 1.0f / 60.0f;
        
        /**
         * \brief Game clock
        */
		sf::Clock _clock;

        /**
         * \brief Game data variable for use within the game code
        */
		GameDataRef _data = std::make_shared<GameData>( );

        /**
         * \brief Run the game
        */
		void Run( );
        
	};
}
