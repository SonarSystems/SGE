#pragma once

#include <External/glm/glm.hpp>
#include <vector>

#include "Graphics/Sprite.hpp"
#include "Sonar.hpp"

namespace Sonar
{
    class Parallax
    {
    public:
        enum DIRECTION
        {
            LEFT = 0,
            RIGHT,
            UP,
            DOWN
        };

        /**
        * \brief Default class constructor
        */
        Parallax( GameDataRef data );
        
        /**
        * \brief Class destructor
        */
        ~Parallax( );

        void SetBackgrounds( const std::vector<Sprite *> &backgrounds );

        void Update( const float &dt );

        void Draw( );

        void SetSpeed( const float &speed );

        float GetSpeed( ) const;

        // Set Direction (x and y) - LEFT/RIGHT OR UP/DOWN - ENUM BASED
        // GET direction
        // manual movement based on external trigger

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Backgrounds to scroll next to each other
        */
        std::vector<Sprite *> _backgrounds;

        /**
        * \brief Speed at which the background moves (negative moves it left/up and positive moves it right/down)
        */
        float _speed;

        /**
        * \brief The direction of the moving backgrounds
        */
        Parallax::DIRECTION _direction;
        
    };
}
