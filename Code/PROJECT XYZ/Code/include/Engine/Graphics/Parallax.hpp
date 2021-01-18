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

        // set speed
        // get speed
        // manual movement based on external trigger
        // Set Direction (x and y) - LEFT/RIGHT OR UP/DOWN

    private:
        std::vector<Sprite *> _backgrounds;

        /**
        * \brief Game data object
        */
        GameDataRef _data;
        
    };
}
