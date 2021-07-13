#pragma once

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
        * \brief Poll the input from the Joystick, Keyboard and Mouse
        *
        * \param dt Delta time (difference between frames)
        * \param event Event to poll
        */
        void PollInput( const float &dt, const Event &event );

        /**
        * \brief Add a radio button
        *
        * \param radioButton Radio button to add
		* \param overrideStyle Should the radio button's style be overriden using the group's style
        */
        void AddRadioButton( RadioButton *radioButton, const bool &overrideStyle = true );

        /**
        * \brief Remove radio button
        *
        * \param radioButton Radio button to remove
        */
        void RemoveRadioButton( RadioButton *radioButton );

        /**
        * \brief Remove radio button at a specific index
        *
        * \param index Index of radio button to remove
        */
        void RemoveRadioButton( const unsigned int &index );

        /**
        * \brief Remove the first radio button
        */
        void RemoveFirstRadioButton( );

        /**
        * \brief Remove the last radio button from the menu
        */
        void RemoveLastRadioButton( );

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

        /**
        * \brief Style of the menu
        */
        MenuComponent::Theme _theme;

    };
}
