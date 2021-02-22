#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <External/glm/glm.hpp>

#include "Color.hpp"
#include "Core/Clock.hpp"
#include "Core/Game.hpp"
#include "Core/Time.hpp"
#include "Input/Mouse.hpp"

namespace Sonar
{
    /**
    * \brief Points on the object
    */
    enum OBJECT_POINTS
    {
        CENTER,
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT
    };

    class Drawable
    {
    public:
        /**
        * \brief Draw object to application window
        */
        void Draw( );

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

        /**
        * \brief Set x and y position
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set y position
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
        * \brief Set width and height
        *
        * \param size Size of the drawable object
        */
        void SetSize( const glm::vec2 &size );

        /**
        * \brief Set width and height
        *
        * \param width Width of the drawable object
        * \param height Height of the drawable object
        */
        void SetSize( const float &width, const float &height );

        /**
        * \brief Set width
        *
        * \param width Width of the drawable object
        */
        void SetWidth( const float &width );

        /**
        * \brief Set height
        *
        * \param height Height of the drawable object
        */
        void SetHeight( const float &height );

        /**
        * \brief Get the width
        *
        * \return Output returns the width
        */
        float GetWidth( ) const;

        /**
        * \brief Get the height
        *
        * \return Output returns the height
        */
        float GetHeight( ) const;

        /**
        * \brief Get the size vector
        *
        * \return Output returns the size vector
        */
        glm::vec2 GetSize( ) const;

        /**
        * \brief Set the inside color (fill color)
        *
        * \param color Color object
        */
        void SetInsideColor( const Color &color );

        /**
        * \brief Set the border color
        *
        * \param color Color object
        *
        * SetBorderThickness method required aswell
        */
        void SetBorderColor( const Color &color );

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
        Color GetInsideColor( ) const;

        /**
        * \brief Get the border color
        *
        * \return Output returns the border color
        */
        Color GetBorderColor( ) const;

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
        * \brief Get the scale factor for both axes
        *
        * \return Output returns scale factor for both axes
        */
        glm::vec2 GetScale( ) const;

        /**
        * \brief Get the scale factor for x axis
        *
        * \return Output returns scale factor for the x axis
        */
        float GetScaleX( ) const;

        /**
        * \brief Get the scale factor for y axis
        *
        * \return Output returns scale factor for the y axis
        */
        float GetScaleY( ) const;

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
        * \brief Get the pivot points for both axes
        *
        * \return Output returns pivot points for both axes
        */
        glm::vec2 GetPivot( ) const;

        /**
        * \brief Get the x pivot point
        *
        * \return Output returns x pivot point
        */
        float GetPivotX( ) const;

        /**
        * \brief Get the y pivot point
        *
        * \return Output returns y pivot point
        */
        float GetPivotY( ) const;

        /**
        * \brief Set the pulse properties and activate it
        *
        * \param endScaleX The scale goal x axis
        * \param endScaleY The scale goal y axis
        * \param timeBetweenPulses How long each scale takes (half to get to the end scale size and half to get back)
        * \param pulseAmount How many times to pulse (default of 0 is infinite pulse)
        */
        void SetPulse( const float &endScaleX, const float &endScaleY, const Time &timeBetweenPulses, const int &pulseAmount = 0 );

        /**
        * \brief Get the end pulse scale
        *
        * \return Output returns the end pulse scale vector
        */
        glm::vec2 GetPulse( ) const;

        /**
        * \brief Gets the total number of pulses to be performed
        *
        * \return Output returns the pulse amount
        */
        int GetPulseAmount( ) const;

        /**
        * \brief Gets the amount of successful pulses
        *
        * \return Output returns the pulse counter
        */
        int GetPulseCounter( ) const;

        /**
        * \brief Stop the pulse
        */
        void StopPulse( );

        /**
        * \brief Update the object
        *
        * \param dt Delta time between frames
        */
        void Update( const float &dt );

        /**
        * \brief Check if the object is clicked by the mouse
        *
        * \param button The mouse button to check
        *
        * \return Output returns true if the mouse is being clicked over the object and false otherwise
        */
        bool IsClicked( const Mouse::Button &button ) const;

        /**
        * \brief Is the mouse hovering
        *
        * \return Output returns the mouse hover status, true if the mouse is in the item and false if it isn't
        */
        bool IsMouseOver( ) const;

        /**
        * \brief Check if the object has collided with another using bounding box
        *
        * \param object The other object to check collision with
        *
        * \return Output returns true if the objects have collided, false otherwise
        */
        bool BoundingBoxCollision( const Drawable &object ) const;

        /**
        * \brief Check if the object has collided with another using circle collision detection
        *
        * \param object The other object to check collision with
        *
        * \return Output returns true if the objects have collided, false otherwise
        */
        bool CircleCollision( const Drawable &object ) const;

        /**
        * \brief Get the global bounds
        *
        * \return Output returns the shape's texture global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

    protected:
        /**
        * \brief Class constructor
        *
        * \param data game engine object
        */
        Drawable( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Drawable( ) ;

        /**
        * \brief Object to be drawn to the screen, assigned the address of the object from a child class
        */
        sf::Drawable *_object;

        /**
        * \brief Bounding box relative to the window
        */
        sf::FloatRect _globalBounds;

        /**
        * \brief Game data object
        */
        GameDataRef _data;

    private:
        /**
        * \brief Object position vector (x and y)
        */
        glm::vec2 _position;

        /**
        * \brief Object size vector (width and height)
        */
        glm::vec2 _size;

        /**
        * \brief Inside color object
        */
        Color _color;

        /**
        * \brief Border color object
        */
        Color _borderColor;

        /**
        * \brief Border thickness
        */
        float _borderThickness;

        /**
        * \brief Rotation of the object
        */
        float _rotation;

        /**
        * \brief Scale of the object
        */
        glm::vec2 _scale;

        /**
        * \brief Pivot point of the object
        */
        glm::vec2 _pivot;

        /**
        * \brief The current scale when the pulse is set
        */
        glm::vec2 _initialPulseScale;

        /**
        * \brief The end scale for the each pulse to get to before resetting to the initial pulse scale
        */
        glm::vec2 _endPulseScale;

        /**
        * \brief How many times to pulse (0 is infinite)
        */
        int _pulseAmount;

        /**
        * \brief The amount of times the object has pulse
        */
        int _pulseCounter;

        /**
        * \brief How long each pulse takes (half to get to end pulse scale and half to reset back to initial pulse scale)
        */
        Time _timeBetweenPulses;

        /**
        * \brief Clock to keep track of the time
        */
        Clock _clock;

    };
}
