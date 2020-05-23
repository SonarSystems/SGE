#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Sonar
{
    class Color
    {
    public:
        /**
         * \brief Default class constructor (0, 0, 0, 255) - opaque black
        */
        Color( );
        
        /**
         * \brief Custom class constructor for red, green and blue value
        */
        Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue );
                
        /**
         * \brief Custom class constructor for red, green, blue and alpha values
        */
        Color( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha );
        
        /**
         * \brief Custom class constructor with a Color object
        */
        Color( const Color &color );
        
        /**
         * \brief Class destructor
        */
        ~Color( );
        
        /**
         * \brief Set color's red, green and blue values
         *
         * \param red red value (0 - 255)
         * \param green green value (0 - 255)
         * \param blue blue value (0 - 255)
        */
        void SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue );
        
        /**
         * \brief Set color's red, green, blue and alpha values
         *
         * \param red red value (0 - 255)
         * \param green green value (0 - 255)
         * \param blue blue value (0 - 255)
         * \param alpha alpha value (0 - 255)
        */
        void SetColor( const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha );
        
        /**
         * \brief Set color's properties using a color object
         *
         * \param color color object
        */
        void SetColor( const Color &color );
        
        /**
         * \brief Set color's red value
         *
         * \param red red value (0 - 255)
        */
        void SetRed( const uint8_t &red );
        
        /**
         * \brief Set color's green value
         *
         * \param green green value (0 - 255)
        */
        void SetGreen( const uint8_t &green );
        
        /**
         * \brief Set color's blue value
         *
         * \param blue blue value (0 - 255)
        */
        void SetBlue( const uint8_t &blue );
        
        /**
         * \brief Set color's alpha value
         *
         * \param alpha alpha value (0 - 255)
        */
        void SetAlpha( const uint8_t &alpha );
        
        /**
         * \brief Get the backend SFML color object
         *
         * \return Output returns the SFML color object
        */
        const sf::Color &GetColor( ) const;
        
        /**
         * \brief Get the red color value
         *
         * \return Output returns the red value
        */
        const uint8_t &GetRed( ) const;
        
        /**
         * \brief Get the green color value
         *
         * \return Output returns the green value
        */
        const uint8_t &GetGreen( ) const;
        
       /**
        * \brief Get the blue color value
        *
        * \return Output returns the blue value
       */
        const uint8_t &GetBlue( ) const;
        
        /**
         * \brief Get the alpha color value
         *
         * \return Output returns the alpha value
        */
        const uint8_t &GetAlpha( ) const;

        /**
         * \brief Predefined Black color object
        */
        static const Color Black;
        
        /**
         * \brief Predefined White color object
        */
        static const Color White;
        
        /**
         * \brief Predefined Red color object
        */
        static const Color Red;
        
        /**
         * \brief Predefined Green color object
        */
        static const Color Green;
        
        /**
         * \brief Predefined Blue color object
        */
        static const Color Blue;
        
        /**
         * \brief Predefined Yellow color object
        */
        static const Color Yellow;
        
        /**
         * \brief Predefined Magenta color object
        */
        static const Color Magenta;
        
        /**
         * \brief Predefined Cyan color object
        */
        static const Color Cyan;
        
        /**
         * \brief Predefined Transparent color object
        */
        static const Color Transparent;
        
    private:
        /**
         * \brief Backend SFML color object
        */
        sf::Color _color;
        
        /**
         * \brief Red value
        */
        uint8_t _red;
        
        /**
         * \brief Green value
        */
        uint8_t _green;
        
        /**
         * \brief Blue value
        */
        uint8_t _blue;
        
        /**
         * \brief Alpha value
        */
        uint8_t _alpha;
        
    };
}
