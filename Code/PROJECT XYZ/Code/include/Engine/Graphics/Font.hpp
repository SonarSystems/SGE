#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Sonar
{
    class Font
    {
    public:
        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Font(  );

        /**
        * \brief Class constructor
        *
        * \param filePath Font file path
        */
        Font( const std::string &filepath );

        /**
        * \brief Class destructor
        */
        ~Font( );

        /**
        * \brief Sets the font file
        *
        * \param filePath Font file path
        */
        void SetFontFile( const std::string &filepath );

        /**
        * \brief Gets the font's file path
        *
        * \return Output returns the font's file path
        */
        std::string GetFontFilePath( ) const;

        /**
        * \brief Get the font's line spacing
        *
        * \param characterSize Reference character size
        *
        * \return Output returns line spacing
        */
        float GetLineSpacing( const unsigned int &characterSize ) const;

        /**
        * \brief Get the font's underline position
        *
        * \param characterSize Reference character size
        *
        * \return Output returns the underline position
        */
        float GetUnderlinePosition( const unsigned int &characterSize ) const;

        /**
        * \brief Get the font's underline thickness
        *
        * \param characterSize Reference character size
        *
        * \return Output returns the underline thickness
        */
        float GetUnderlineThickness( const unsigned int &characterSize ) const;

    private:
        /**
        * \brief File path of the font
        */
        std::string _filePath;

        /**
        * \brief SFML font object
        */
        sf::Font _font;

    };
}
