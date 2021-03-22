#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Input/Mouse.hpp"

namespace Sonar
{
    class Checkbox : public MenuComponent
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Checkbox( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Checkbox( );
        
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
        * \brief Set width and height
        *
        * \param size Size of the rectangle object
        */
        void SetSize( const glm::vec2 &size );

        /**
        * \brief Set width and height
        *
        * \param width Width of the rectangle object
        * \param height Height of the rectangle object
        */
        void SetSize( const float &width, const float &height );

        /**
        * \brief Set width
        *
        * \param width Width of the rectangle object
        */
        void SetWidth( const float &width );

        /**
        * \brief Set height
        *
        * \param height Height of the rectangle object
        */
        void SetHeight( const float &height );

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
        * \brief Set the rotation angle
        *
        * \param angle Angle of the rotation
        */
        void SetRotation( const float &angle );

        /**
        * \brief Rotate the object relative to it's current angle
        *
        * \param angle Angle of the rotation
        */
        void Rotate( const float &angle );

        /**
        * \brief Get the rotation angle
        *
        * \return Output returns the rotation angle
        */
        float GetRotation( ) const;

        /**
        * \brief Set the scale factor
        *
        * \param xScale Scale in x axis
        * \param yScale Scale in y axis
        */
        void SetScale( const float &xScale, const float &yScale );

        /**
        * \brief Set the scale factor
        *
        * \param scale Scale in x and y axes
        */
        void SetScale( const glm::vec2 &scale );

        /**
        * \brief Set the x axis scale factor
        *
        * \param xScale Scale in x axis
        */
        void SetScaleX( const float &xScale );

        /**
        * \brief Set the y axis scale factor
        *
        * \param yScale Scale in y axis
        */
        void SetScaleY( const float &yScale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param scale Scale in the x and y axis
        */
        void Scale( const glm::vec2 &scale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param xScale Scale in x axis
        * \param yScale Scale in y axis
        */
        void Scale( const float &xScale, const float &yScale );

        /**
        * \brief Scale the object relative to it's current x scale
        *
        * \param xScale Scale in x axis
        */
        void ScaleX( const float &xScale );

        /**
        * \brief Scale the object relative to it's current y scale
        *
        * \param yScale Scale in y axis
        */
        void ScaleY( const float &yScale );

        /**
        * \brief Set the pivot point
        *
        * \param xPoint X pivot point
        * \param yPoint Y pivot point
        */
        void SetPivot( const float &xPoint, const float &yPoint );

        /**
        * \brief Set the pivot point
        *
        * \param pivot X and y pivot point
        */
        void SetPivot( const glm::vec2 &pivot );

        /**
        * \brief Set the pivot point based on predefined points (center, top left, top right, bottom left, bottom right)
        *
        * \param pivot Predefined pivot location
        */
        void SetPivot( const OBJECT_POINTS &pivot );

        /**
        * \brief Set the x pivot point
        *
        * \param xPoint X pivot point
        */
        void SetPivotX( const float &xPoint );

        /**
        * \brief Set the y pivot point
        *
        * \param yPoint Y pivot point
        */
        void SetPivotY( const float &yPoint );

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
        Rectangle *_outerLayer, *_insideLayer;

    };
}
