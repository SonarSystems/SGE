#pragma once

#include <vector>

#include "Core/Game.hpp"
#include "Graphics/MenuComponent.hpp"

namespace Sonar
{
    class Menu
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Menu( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Menu( );

        void AddComponent(  MenuComponent *component );

        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Update the classes objects
        *
        * \param dt Delta time (difference between frames)
        */
        void Update( const float &dt );

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief All the components of the menu
        */
        std::vector<MenuComponent *> _menuComponents;

    };
}
