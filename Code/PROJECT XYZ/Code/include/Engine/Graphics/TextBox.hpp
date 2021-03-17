#pragma once

#include "Core/Clock.hpp"
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
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

        /**
        * \brief Add a character to the list of restricted characters
        *
        * \param unicodeCharacter Character to restrict (unicode)
        */
        void AddRestrictedCharacter( const unsigned int &unicodeCharacter );

        /**
        * \brief Add a character to the list of restricted characters
        *
        * \param character Character to restrict
        */
        void AddRestrictedCharacter( const char &character );

        /**
        * \brief Remove a character from the list of restricted characters
        *
        * \param character Character to remove from the list (unicode)
        */
		void RemoveRestrictedCharacter( const unsigned int &unicodeCharacter );

        /**
        * \brief Remove a character from the list of restricted characters
        *
        * \param character Character to remove from the list
        */
		void RemoveRestrictedCharacter( const char &character );

        /**
        * \brief Get a list of all the restricted characters
        *
        * \return Output returns all the restricted characters
        */
        const std::vector<unsigned int> GetRestrictedCharacterList( ) const;

        /**
        * \brief Check if a character is already restricted
        *
        * \param character Character to check (unicode)
        *
        * \return Output returns true if the character is restricted
        */
        bool IsRestrictedCharacter( const unsigned int &unicodeCharacter ) const;

        /**
        * \brief Check if a character is already restricted
        *
        * \param character Character to check
        *
        * \return Output returns true if the character is restricted
        */
        bool IsRestrictedCharacter( const char &character ) const;
        
        /**
        * \brief Update the object
        *
        * \param dt Delta time between frames
        */
        void Update( const float &dt );

        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Set how often the blinker turns off and on
        *
        * \param time Time taken to turn off/on (double to do a full cycle)
        */
        void SetBlinkerTime( const float &time );

        /**
        * \brief Get the blinkers time
        */
        const float &GetBlinkerTime( ) const;

    private:
        /**
        * \brief Maximum number of characters allowed
        */
        unsigned int _maxCharacters;

        /**
        * \brief All restricted characters
        */
        std::vector<unsigned int> _restrictedCharacters;

        /**
        * \brief Blinker for text box at the end of the string
        */
        Rectangle *_postStringBlinker;

        /**
        * \brief Is the blinker visible
        */
        bool _isPostStringBlinkerShown;

        /**
        * \brief Clock
        */
        Clock _clock;

        /**
        * \brief Blinker time between half cycle (off/on)
        */
        float _blinkerTime;

    };
}
