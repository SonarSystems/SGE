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

        /**
        * \brief Add component to the menu
        *
        * \param component Component to add
        */
        void AddComponent( MenuComponent *component );

        /**
        * \brief Remove component from the menu
        *
        * \param component Component to remove
        */
        void RemoveComponent( MenuComponent *component );

        /**
        * \brief Remove component at a specific index from the menu
        *
        * \param index Index of component to remove
        */
        void RemoveComponent( const int &index );

        /**
        * \brief Remove the first component from the menu
        */
        void RemoveFirstComponent( );

        /**
        * \brief Remove the last component from the menu
        */
        void RemoveLastComponent( );

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
