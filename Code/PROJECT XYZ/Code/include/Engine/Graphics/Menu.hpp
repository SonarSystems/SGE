#pragma once

#include <vector>

#include "Core/ENGINEDEFINITIONS.hpp"
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
        * \brief Poll the input from the Joystick, Keyboard and Mouse
        *
        * \param dt Delta time (difference between frames)
        * \param event Event to poll
        */
        void PollInput( const float &dt, const Event &event );

        /**
        * \brief Add component to the menu
        *
		* \param component Component to add
		* \param overrideStyle Should the component's style be overriden using the Menu's style
        */
        void AddComponent( MenuComponent *component, const bool &overrideStyle = true );

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

        /**
        * \brief Set all the components theme
        *
        * \param theme Theme to apply to all components
        */
        void SetTheme( const MenuComponent::Theme &theme );

        /**
        * \brief Reset all components theme to the menu's current theme
        */
        void ResetThemeForAllComponents( );

        /**
        * \brief Get the menu's current theme
        *
        * \return Output returns the menu's theme
        */
        const MenuComponent::Theme &GetTheme( ) const;

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief All the components of the menu
        */
        std::vector<MenuComponent *> _menuComponents;

        /**
        * \brief Style of the menu
        */
        MenuComponent::Theme _theme;

    };
}
