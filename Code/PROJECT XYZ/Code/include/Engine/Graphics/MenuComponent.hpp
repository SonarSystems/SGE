#pragma once

#include "Core/Game.hpp"
#include "Graphics/Drawable.hpp"

namespace Sonar
{
    class MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        MenuComponent(  );

        /**
        * \brief Class destructor
        */
        ~MenuComponent( );

        /**
        * \brief Draw method to be overridden in child classes
        */
        virtual void Draw( ) = 0;

        /**
        * \brief Update method to be overridden in child classes
        */
        virtual void Update( const float &dt ) = 0;
    
    protected:

    };
}
