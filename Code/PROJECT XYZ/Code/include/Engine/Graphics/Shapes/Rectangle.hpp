#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Drawable.hpp"
#include "Color.hpp"

namespace Sonar
{
    class Rectangle : public Drawable
    {
    public:
        /**
         * \brief Class constructor
         *
         * \param data Game data object
        */
        Rectangle( GameDataRef data );
        
        /**
         * \brief Class constructor with width and height of rectangle
         *
         * \param data Game data object
         * \param width Width of the rectangle
         * \param height Height of the rectangle
        */
        Rectangle( GameDataRef data, const float &width, const float &height );
        
        /**
         * \brief Class destructor
        */
        ~Rectangle( );
        
        /**
         * \brief Set the rectangles position (x and y)
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
        const Color &GetInsideColor( ) const;
        
        /**
         * \brief Get the border color
         *
         * \return Output returns the border color
        */
        const Color &GetBorderColor( ) const;
        
        /**
         * \brief Get the border thickness
         *
         * \return Output returns the border thickness
        */
        const float &GetBorderThickness( ) const;
        
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

    private:
        /**
         * \brief Backend SFML shape object
        */
        sf::RectangleShape _shape;
        
    };
}
