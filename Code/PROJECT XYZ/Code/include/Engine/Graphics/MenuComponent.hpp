#pragma once

#include "Core/Game.hpp"
#include "Graphics/Drawable.hpp"

namespace Sonar
{
    class MenuComponent : public Drawable
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        MenuComponent( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~MenuComponent( );
    
    protected:

    };
}
