#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <External/glm/glm.hpp>
#include "Graphics/Drawable.hpp"
#include "Graphics/Color.hpp"

namespace Sonar
{
    class Triangle : public Drawable
    {
    public:
        /**
         * \brief Class constructor
         *
         * \param data Game data object
        */
        Triangle( GameDataRef data );
        
        /**
         * \brief Class constructor with the 3 points (clockwise or counterclockwise order)
         *
         * \param data Game data object
		 * \param point1 Vertex 1 of the triangle
         * \param point1 Vertex 2 of the triangle
         * \param point1 Vertex 3 of the triangle
		 */
        Triangle( GameDataRef data, const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 );
        
        /**
         * \brief Class destructor
        */
        ~Triangle( );

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

        // METHODS FOR THE FOLLOWING
        // SET POINTS (call the the setsize method)
        // GET POINTS

    private:
        /**
        * \brief Set width and height
        *
		* \param point1 Vertex 1 of the triangle
		* \param point1 Vertex 2 of the triangle
		* \param point1 Vertex 3 of the triangle
        */
        void SetSize( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 );

        /**
         * \brief Backend SFML shape object
        */
        sf::ConvexShape _shape;
        
    };
}
