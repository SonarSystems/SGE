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

        void AddComponent( const MenuComponent &component );

        void Draw( );

    private:
        GameDataRef _data;

        std::vector<MenuComponent> _menuComponents;

    };
}
