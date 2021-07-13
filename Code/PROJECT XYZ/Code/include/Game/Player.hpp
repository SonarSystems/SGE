#pragma once

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
		Rectangle *_player;
		Rectangle *object2;

        GameDataRef _data;
                
    };
}
