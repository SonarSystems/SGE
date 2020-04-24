#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Sprite.hpp"

namespace Sonar
{
    class Player
    {
    public:
        Player( GameDataRef data );
        
        void HandleInput( float dt );
        void Update( float dt );
        void Draw( float dt );
        
    private:
        sf::RectangleShape player;
        Sprite _player;
        
        GameDataRef _data;
                
    };
}
