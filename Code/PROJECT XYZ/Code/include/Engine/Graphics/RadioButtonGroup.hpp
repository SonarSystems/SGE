#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include <External/glm/glm.hpp>
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Game.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/RadioButton.hpp"

namespace Sonar
{
    class RadioButtonGroup : public MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        RadioButtonGroup( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~RadioButtonGroup( );
        
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
        * \brief Add a radio button
        *
        * \param radioButton Radio button to add
        */
        void AddRadioButton( RadioButton *radioButton );

        /**
        * \brief Get the number of radio buttons
        *
        * \return Output returns the size of the radio button vector
        */
        unsigned int GetSize( ) const;

        /**
        * \brief Set the components theme
        *
        * \param theme Theme to set
        */
        void SetTheme( const MenuComponent::Theme &theme );

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Vector of radio buttons
        */
        std::vector<RadioButton *> _radioButtons;

    };
}
