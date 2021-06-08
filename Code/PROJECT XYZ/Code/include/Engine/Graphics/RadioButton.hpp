#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Input/Mouse.hpp"

namespace Sonar
{
    class RadioButton : public MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        RadioButton( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~RadioButton( );
        
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
        * \brief Set the components theme
        *
        * \param theme Theme to set
        */
        void SetTheme( const MenuComponent::Theme &theme );

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

        /**
        * \brief Set the position (x and y)
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set the x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set the y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
        * \brief Get the x position
        *
        * \return Output returns the x position
        */
        float GetPositionX( ) const;

        /**
        * \brief Get the y position
        *
        * \return Output returns the y position
        */
        float GetPositionY( ) const;

        /**
        * \brief Get the position vector
        *
        * \return Output returns the position vector
        */
        glm::vec2 GetPosition( ) const;

        /**
        * \brief Set radius of the object
        *
        * \param radius Radius of the object
        */
        void SetRadius( const float &radius );

        /**
        * \brief Get the radius of the object
        *
        * \return Output returns the radius
        */
        float GetRadius( ) const;

        /**
        * \brief Set the color of the border
        *
        * \param color Color object
        */
        void SetColor( const Color &color );

        /**
        * \brief Set the inside color of the outer circle (border circle)
        *
        * \param color Color object
        */
        void SetInsideColor( const Color &color );

        /**
        * \brief Set the checked status color
        *
        * \param color Color object
        *
        * SetBorderThickness method required aswell
        */
        void SetCheckedColor( const Color &color );

        /**
        * \brief Set the border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBorderThickness( const float &thickness );

        /**
        * \brief Get the border color
        *
        * \return Output returns the border color
        */
        Color GetColor( ) const;

        /**
        * \brief Get the inside color (fill color)
        *
        * \return Output returns the inside color
        */
        Color GetInsideColor( ) const;

        /**
        * \brief Get the checked color
        *
        * \return Output returns the checked color
        */
        Color GetCheckedColor( ) const;

        /**
        * \brief Get the border thickness
        *
        * \return Output returns the border thickness
        */
        float GetBorderThickness( ) const;

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param offset Offset in x and y axis
        */
        void Move( const glm::vec2 &offset );

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param x Offset in x axis
        * \param y Offset in y axis
        */
        void Move( const float &x, const float &y );

        /**
        * \brief Move the object relative to it's current position in the x axis
        *
        * \param x Offset in x axis
        */
        void MoveX( const float &x );

        /**
        * \brief Move the object relative to it's current position in the y axis
        *
        * \param y Offset in y axis
        */
        void MoveY( const float &y );

        /**
        * \brief Set the scale factor
        *
        * \param scale Scale factor
        */
        void SetScale( const float &scale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param scale Scale factor
        */
        void Scale( const float &scale );

        /**
        * \brief Get the scale factor
        *
        * \return Output returns the scale factor
        */
        float GetScale( ) const;

        /**
        * \brief Get the local bounds
        *
        * \return Output returns the shape's texture local bounds
        */
        glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the global bounds
        *
        * \return Output returns the shape's texture global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

        /**
        * \brief Set the mousee button which would trigger the click function
        *
        * \param button Mouse button
        */
        void SetMouseButtonToClick( const Mouse::Button &button );

        /**
        * \brief Get the current mouse button which would trigger the click function
        *
        * \return Output returns the mouse button
        */
        const Mouse::Button &GetMouseButtonToClick( ) const;

        /**
        * \brief Is the checkbox selected
        *
        * \return Output returns the selected status
        */
        const bool &IsSelected( ) const;

        /**
        * \brief Enable the radio button
        */
        void EnableSelection( );

        /**
        * \brief Disable the radio button
        */
        void DisableSelection( );

        /**
        * \brief Toggle the radio button
        */
        void ToggleSelection( );

        /**
        * \brief Get the last time this radio button was selected
        *
        * \return Output returns the selected time
        */
        const long long GetSelectedTime( ) const;

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Which button triggers the clicked function
        */
        Mouse::Button _buttonToClick;

        /**
        * \brief Button background
        */
        Circle *_outerLayer, *_insideLayer;

        /**
        * \brief Color of the inside layer
        */
        Color _checkedColor;

        /**
        * \brief Tracks the selected status
        */
        bool _isSelected;

        /**
        * \brief Is the mouse currently down
        */
        bool _isMouseDown;

        /**
        * \brief The time the radio button was selected
        */
        long long _timeSelected;
        
    };
}
