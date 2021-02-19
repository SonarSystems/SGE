#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Rectangle.hpp"

namespace Sonar
{
    class Button : public MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Button( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Button( );

        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Set the button's background rectangle (most of the time leave as is)
        *
        * \param rectangle Pointer to the rectangle
        */
        void SetRectangleBackground( Rectangle *rectangle );

        /**
        * \brief Set the button's label (most of the time leave as is)
        *
        * \param label Pointer to the label
        */
        void SetLabelBackground( Label *label );

        /**
        * \brief Get the buttons background rectangle
        *
        * \return Output returns the buttons background rectangle
        */
		Rectangle *GetRectangleBackground( ) const;

        /**
        * \brief Get the buttons label
        *
        * \return Output returns the buttons label
        */
		Label *GetRectangleLabel( ) const;

    private:
        /**
        * \brief Button background
        */
        Rectangle *_buttonBackground;

        /**
        * \brief Button label
        */
        Label *_buttonLabel;

    };
}
