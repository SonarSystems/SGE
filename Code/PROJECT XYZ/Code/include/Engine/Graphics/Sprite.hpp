#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <External/glm/glm.hpp>
#include "Graphics/Drawable.hpp"

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

		void SetTexture( const Texture &texture, bool resetRect = false );

		void SetTextureRect( const IntRect &rectangle );



		const Texture *GetTexture( ) const;

		const IntRect &GetTextureRect( ) const;


		FloatRect getLocalBounds( ) const;

		FloatRect getGlobalBounds( ) const;

    private:
        // sprite for the class
        sf::Sprite _sprite;
        // texture for loading an image to be assigned to the sprite
        sf::Texture _texture;
        

        
    };
}
