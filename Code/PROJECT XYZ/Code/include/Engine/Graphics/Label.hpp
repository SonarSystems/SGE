#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Font.hpp"
#include "Graphics/MenuComponent.hpp"

namespace Sonar
{
    class Label : public Drawable, public MenuComponent
    {
    public:
        /**
        * \brief Style of the text in the label
        */
        enum STYLE
        {
			Regular = 0,            //< Regular characters, no style, disables all other styling
			Bold = 1 << 0,          //< Bold characters
			Italic = 1 << 1,        //< Italic characters
			Underlined = 1 << 2,    //< Underlined characters
			StrikeThrough = 1 << 3  //< Strike through characters
        };

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Label( GameDataRef data );

        /**
        * \brief Class constructor
        *
        * \param filePath Font file path
        */
        Label( GameDataRef data, const std::string &filepath );

        /**
        * \brief Class destructor
        */
        ~Label( );

        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Set the components theme
        *
        * \param theme Theme to set
        */
        void SetTheme( const MenuComponent::Theme &theme );

        /**
        * \brief Sets the font file
        *
        * \param filePath Font file path
        */
        void SetFontFilePath( const std::string &filepath );

        /**
        * \brief Gets the font's file path
        *
        * \return Output returns the font's file path
        */
        std::string GetFontFilePath( ) const;

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

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

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
        * \brief Rotate the object relative to it's current angle
        *
        * \param angle Angle of the rotation
        */
        void Rotate( const float &angle );

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
        * \brief Scale the object relative to it's current scale
        *
        * \param scale Scale in the x and y axis
        */
        void Scale( const glm::vec2 &scale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param xScale Scale in x axis
        * \param yScale Scale in y axis
        */
        void Scale( const float &xScale, const float &yScale );

        /**
        * \brief Scale the object relative to it's current x scale
        *
        * \param xScale Scale in x axis
        */
        void ScaleX( const float &xScale );

        /**
        * \brief Scale the object relative to it's current y scale
        *
        * \param yScale Scale in y axis
        */
        void ScaleY( const float &yScale );

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
        * \brief Set the label's text
        *
        * \param string The string for the text to be displayed
        */
		void SetText( const std::string &string );

        /**
        * \brief Set the label's font
        *
        * \param font Font for the label
        */
		void SetFont( const Font &font );

        /**
        * \brief Set the character size in pixels
        *
        * \param size Size of the characters in pixels
        */
		void SetCharacterSize( const unsigned int &size );

        /**
        * \brief Get the characters size in pixels
        *
        * \return Output returns the character size
        */
        unsigned int GetCharacterSize( ) const;

        /**
        * \brief Set line spacing
        *
        * \param spacingFactor Amount of line spacing
        */
		void SetLineSpacing( const float &spacingFactor );

        /**
        * \brief Set letter spacing
        *
        * \param spacingFactor Amount of letter spacing
        */
		void SetLetterSpacing( const float &spacingFactor );

        /**
        * \brief Get line spacing
        *
        * \return Output returns line spacing
        */
        float GetLineSpacing( ) const;

        /**
        * \brief Get letter spacing
        *
        * \return Output returns letter spacing
        */
        float GetLetterSpacing( ) const;

        /**
        * \brief Set a particular style for the label
        *
		* \param style Which style to change
		* \param isActivated True to enable the style and false to disable it
        */
		void SetStyle( const STYLE &style, const bool &isActivated );

        /**
        * \brief Set a particular style for the label
        *
        * \param style Style int to use
        */
        void SetStyle( const unsigned int &style );

        /**
        * \brief Get the label's text
        *
        * \return Output returns the label's text
        */
		const std::string &GetText( ) const;

        /**
        * \brief Get the label's font object
        *
        * \return Output returns the font used for the label
        */
		const Font &GetFont( ) const;

        /**
        * \brief Get the overall style
        *
        * \return Output returns the overall style
        */
		unsigned int GetStyle( ) const;

        /**
        * \brief Check if a particular style is enabled
        *
        * \param style Style to check
        *
        * \return Output returns true if the style is enabled and false if it is disabled
        */
        bool IsStyleEnabled( const STYLE &style ) const;

        /**
        * \brief Get the position of a particular character
        *
        * \param index Which character to check, 0 is the first character
        *
        * \return Output returns the characters position
        */
		glm::vec2 FindCharacterPos( const std::size_t &index ) const;

        /**
        * \brief Get the length of the label's string
        * 
        * \return Output returns the label's length
        */
        unsigned int GetStringLength( ) const;

    private:
        /**
        * \brief Initialize the class (used to abstract common code from all constructors)
        *
		* \param data Game data object
        */
        void Init( GameDataRef data );

        /**
        * \brief File path of the font
        */
        std::string _filePath;

        /**
        * \brief Font object
        */
        Font _font;

        /**
        * \brief SFML text object
        */
        sf::Text _text;

        /**
        * \brief Label's string to be displayed
        */
        std::string _string;

        /**
        * \brief Is a particular style enabled
        */
        STYLE isBold, isItalic, isUnderlined, isStrikeThrough;

    };
}
