#pragma once

#include "Input/Events.hpp"

/* All MenuComponent Children
* 
* Button
* ButtonGroup
* Checkbox
* Label
* RadioButton
* RadioButtonGroup
* Slider
* TextBox
*/

namespace Sonar
{
    class MenuComponent
    {
    public:
        enum Theme
        {
            DARK = 0,
            LIGHT,
        };

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        MenuComponent( );

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

        /**
        * \brief Poll input method to be overridden in child classes
        */
        virtual void PollInput( const float &dt, const Event &event ) = 0;

        /**
        * \brief Set theme method to be overriden in child classes
        */
        virtual void SetTheme( const MenuComponent::Theme &theme ) = 0;
    
    protected:

    };
}
