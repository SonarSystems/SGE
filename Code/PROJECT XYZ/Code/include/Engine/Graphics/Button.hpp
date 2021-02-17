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
        * \brief Class constructor
        *
        * \param filePath Font file path
        */
        Button( GameDataRef data, const std::string &filepath );

        /**
        * \brief Class destructor
        */
        ~Button( );

        void Draw( );

    private:
        Rectangle *_buttonBackground;

        Label *_buttonLabel;

    };
}
