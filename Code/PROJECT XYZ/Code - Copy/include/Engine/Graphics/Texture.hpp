#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Drawable.hpp"

namespace Sonar
{
    class Texture
    {
    public:
        /**
        * \brief Default class constructor
        */
        Texture( );

        /**
        * \brief Class constructor
        *
        * \param filepath File path of the image
        */
        Texture( const std::string &filepath );
        
        /**
        * \brief Class destructor
        */
        ~Texture( );

        /**
        * \brief Set the texture from an image file
        *
		* \param filepath File path of the image
        */
        void SetTexture( const std::string &filepath );
        
        /**
        * \brief Set the texture from another texture
        *
        * \param texture Texture object
        */
        void SetTexture( const Texture &texture );

        /**
        * \brief Get the SFML texture object
        *
        * \return Output returns the texture
        */
        sf::Texture *GetTexture( ) const;

        /**
        * \brief Get the texture size
        *
        * \return Output returns the size of the texture
        */
        glm::vec2 GetSize( ) const;

        /**
        * \brief Set the repeat status
        *
        * \param repeated Does the texture repeat
        */
        void SetRepeated( const bool &repeated );

        /**
        * \brief Is the texture set to repeat
        *
        * \return Output returns the repeat status
        */
        bool IsRepeated( ) const;

    private:
        /**
        * \brief SFML texture object
        */
        sf::Texture *_texture;
        
    };
}
