#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Circle.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Input/Mouse.hpp"

namespace Sonar
{
    class Slider : public MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Slider( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Slider( );
        
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
        * \brief Set the background size
        *
        * \param size Width and height of the background
        */
		void SetBackgroundSize( const glm::vec2 &size );

        /**
        * \brief Set the background size
        *
		* \param width Width of the background
		* \param height Height of the background
        */
		void SetBackgroundSize( const float &width, const float &height );

        /**
        * \brief Set the background width
        *
        * \param width Width of the background
        */
		void SetBackgroundWidth( const float &width );

        /**
        * \brief Set the background height
        *
        * \param height Height of the background
        */
		void SetBackgroundHeight( const float &height );

        /**
        * \brief Get the background size
        *
        * \return Output returns the background size
        */
        glm::vec2 GetBackgroundSize( ) const;

        /**
        * \brief Get the background width
        *
        * \return Output returns the background width
        */
        float GetBackgroundWidth( ) const;

        /**
        * \brief Get the background height
        *
        * \return Output returns the background height
        */
        float GetBackgroundHeight( ) const;

        /**
        * \brief Set the knob size/radius
        *
        * \param radius Radius of the knob
        */
		void SetKnobRadius( const float &radius );

        /**
        * \brief Get the knob size/radius
        *
        * \return Output returns the knob size/radius
        */
        float GetKnobRadius( ) const;

        /**
        * \brief Set the color of the border
        *
        * \param color Color object
        */
        void SetColor( const Color &color );

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
        * \brief Get the inside color (fill color)
        *
        * \return Output returns the inside color
        */
        Color GetColor( ) const;

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
        * \brief Get the local bounds (for the background)
        *
        * \return Output returns the shape's local bounds
        */
        glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the global bounds (for the background)
        *
        * \return Output returns the shape's global bounds
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
        * \brief Slider background
        */
        Rectangle *_background;

        /**
        * \brief Slider knob
        */
        Circle *_knob;

        /**
        * \brief Is the mouse currently down
        */
        bool _isMouseDown;

    };
}
