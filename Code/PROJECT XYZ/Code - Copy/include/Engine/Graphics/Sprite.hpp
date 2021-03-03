#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "External/Collision.hpp"
#include <External/glm/glm.hpp>
#include "Graphics/Drawable.hpp"
#include "Graphics/Texture.hpp"


namespace Sonar
{
    class Sprite : public Drawable
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Sprite( GameDataRef data );

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        * \param filePath Texture file path
        */
        Sprite( GameDataRef data, const std::string &filepath );

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        * \param texture Another texture to be copied onto the local texture
        */
        Sprite( GameDataRef data, Texture *texture );

        /**
        * \brief Class destructor
        */
        ~Sprite( );

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
        * \brief Set the color
        *
        * \param color Color object
        */
        void SetColor( const Color &color );

        /**
        * \brief Get the color
        *
        * \return Output returns the color
        */
        Color GetColor( ) const;

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
        * \brief Set the sprite texture from a file
        *
		* \param filePath Location of image to be applied
		* \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
		void SetTexture( const std::string &filepath, const bool &resetRect = false );

        /**
        * \brief Set the sprite texture from an existing Texture object
        *
        * \param texture Another texture to be copied onto the local texture
        * \param resetRect Whether or not the texture rect should be reset (default set to false)
        */
		void SetTexture( Texture *texture, const bool &resetRect = false );

        /**
        * \brief Set the sprite rectangle
        *
        * \param rectangle Vector 4 of integers (left, top, width and height)
        */
        void SetTextureRect( const glm::ivec4 &rectangle );

        /**
        * \brief Set the sprite rectangle
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
        * \return Output returns the sprite's texture object
        */
        Texture *GetTexture( ) const;

        /**
        * \brief Get the Textures rectangle
        *
        * \return Output returns the sprite's texture rectangle
        */
		glm::ivec4 GetTextureRect( ) const;

        /**
        * \brief Get the local bounds
        *
        * \return Output returns the sprite's local bounds
        */
		glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the global bounds
        *
        * \return Output returns the sprite's global bounds
        */
        glm::vec4 GetGlobalBounds( ) const;

        /**
        * \brief Check for pixel perfect collision (very heavy on the processing)
        *
		* \param object Object to check collision with
		* \param alphaLimit The threshold at which a pixel becomes "solid". If AlphaLimit is 127, a pixel with alpha value 128 will cause a collision and a pixel with alpha value 126 will not.
        *
        * \return Output returns true if the collision is successful
        */
        bool PixelPerfectCollisionCheck( const Sprite &object, const sf::Uint8 &alphaLimit = 0 );

        /**
        * \brief Get the underlying SFML sprite object
        *
        * \return Output returns SFML sprite object
        */
        const sf::Sprite &GetSFMLSprite( ) const;

    private:
        /**
        * \brief Sprite for the class
        */
        sf::Sprite _sprite;

        /**
        * \brief Texture for loading an image to be assigned to the sprite
        */
        Texture *_texture;

    };
}
