#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Texture.hpp"

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
         * \param point2 Vertex 2 of the triangle
         * \param point3 Vertex 3 of the triangle
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
        * \brief Update the object
        *
        * \param dt Delta time between frames
        */
        void Update( const float &dt );

        /**
        * \brief Set the points/vertices of the triangle
        *
        * \param point1 Vertex 1 of the triangle
        * \param point2 Vertex 2 of the triangle
        * \param point3 Vertex 3 of the triangle
        */
        void SetPoints( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 );

        /**
        * \brief Get the triangle's points/vertices
        *
        * \return Output returns the triangle's points/vertices vector of glm::vec2 (3 in total)
        */
        std::vector<glm::vec2> GetPoints( );

        /**
        * \brief Set the shape texture from a file
        *
        * \param filePath Location of image to be applied
        * \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
        void SetTexture( const std::string &filepath, const bool &resetRect = false );

        /**
        * \brief Set the shape texture from an existing Texture object
        *
        * \param texture Another texture to be copied onto the local texture
        * \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
        void SetTexture( Texture *texture, const bool &resetRect = false );

        /**
        * \brief Set the shape rectangle
        *
        * \param rectangle Vector 4 of integers (left, top, width and height)
        */
        void SetTextureRect( const glm::ivec4 &rectangle );

        /**
        * \brief Set the shape rectangle
        *
        * \param left Top left corner x value
        * \param top Top left corner y value
        * \param width Rectangles width
        * \param height Rectangles height
        */
        void SetTextureRect( const int &left, const int &top, const int &width, const int &height );

        /**
        * \brief Get the Texture object
        *
        * \return Output returns the shape's texture object
        */
        Texture *GetTexture( ) const;

        /**
        * \brief Get the Textures rectangle
        *
        * \return Output returns the shape's texture rectangle
        */
        glm::ivec4 GetTextureRect( ) const;

        /**
        * \brief Get the Textures local bounds
        *
        * \return Output returns the shape's texture local bounds
        */
        glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the Textures global bounds
        *
        * \return Output returns the shape's texture global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

    private:
        /**
        * \brief Set width and height
        *
		* \param point1 Vertex 1 of the triangle
		* \param point2 Vertex 2 of the triangle
		* \param point3 Vertex 3 of the triangle
        */
        void SetSize( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 );

        /**
         * \brief Backend SFML shape object
        */
        sf::ConvexShape _shape;

        /**
        * \brief Texture for loading an image to be assigned to the shape
        */
        Texture *_texture;

        /**
        * \brief Triangle vertice's points
        */
        std::vector<glm::vec2> _points;
        
    };
}
