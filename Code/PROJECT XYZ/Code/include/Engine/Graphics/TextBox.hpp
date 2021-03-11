#pragma once

#include "Core/ENGINEDEFINITIONS.hpp"
#include "Graphics/Label.hpp"
#include "Input/Events.hpp"

namespace Sonar
{
    class TextBox : public Label
    {
    public:

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        TextBox( GameDataRef data );

        /**
        * \brief Class constructor
        *
        * \param filePath Font file path
        */
        TextBox( GameDataRef data, const std::string &filepath );

        /**
        * \brief Class destructor
        */
        ~TextBox( );

        /**
        * \brief Poll the input from the Joystick, Keyboard and Mouse
        *
        * \param dt Delta time (difference between frames)
        * \param event Event to poll
        */
        void PollInput( const float &dt, const Event &event );

        /**
        * \brief Set the maximum number of characters
        *
		* \param maxCharacters Maximum number of characters allowed
		* \param removeExtraCharacters Whether or not to remove any extra characters if the length is too long
        */
        void SetMaximumCharacters( const unsigned int &maxCharacters, const bool &removeExtraCharacters = true );

        /**
        * \brief Get the maximum number of characters
        *
        * \return Output returns the maximum number of characters allowed
        */
        const unsigned int &GetMaximumCharacters( ) const;

    private:
        /**
        * \brief Maximum number of characters allowed
        */
        unsigned int _maxCharacters;

    };
}
