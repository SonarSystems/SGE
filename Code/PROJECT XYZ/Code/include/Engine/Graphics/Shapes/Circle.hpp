#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <External/glm/glm.hpp>
#include "Graphics/Drawable.hpp"
#include "Graphics/Color.hpp"

namespace Sonar
{
    class Circle : public Drawable
    {
    public:
        /**
         * \brief Class constructor
         *
         * \param data Game data object
        */
        Circle( GameDataRef data );
        
        /**
         * \brief Class constructor with radius of the circl
         *
         * \param data Game data object
         * \param width Width of the rectangle
         * \param height Height of the rectangle
        */
        Circle( GameDataRef data, const float &radius );
        
        /**
         * \brief Class destructor
        */
        ~Circle( );

        /**
        * \brief Set the circle's radius
        *
        * \param radius Radius of the circle
        */
		void SetRadius( const float &radius );

        /**
        * \brief Get the radius
        *
        * \return Output returns the radius
        */
		float GetRadius( ) const;

        /**
        * \brief Set the point/side count
        *
        * \param count Number of points/sides
        */
		void SetPointCount( const unsigned int &count );

        /**
        * \brief Get the point/side count
        *
        * \return Output returns the point/side count
        */
		int GetPointCount( ) const;

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
        * \brief Set width and height
        *
        * \param radius Radius of the circle object
        */
        void SetSize( const float &radius );

        /**
         * \brief Backend SFML shape object
        */
        sf::CircleShape _shape;
        
    };
}
