#pragma once

#include "Managers/AssetManager.hpp"

namespace Sonar
{
    /**
     * \brief Game data 
    */
	struct GameData
	{
		StateMachine machine; // State machine to handle the states
		Window window; // Game window
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
		Clock _clock;

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
