#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Rectangle.hpp"
#include "Input/Mouse.hpp"

namespace Sonar
{
    class Button : public MenuComponent
    {
    public:
        /**
        * \brief Anchor of the label within the button's background
        */
		enum LABEL_ANCHOR_X
		{
			LEFT = 0,
			CENTER_X,
			RIGHT
		};

		enum LABEL_ANCHOR_Y
		{
			TOP = 0,
			CENTER_Y,
			BOTTOM
		};

        struct ButtonStyle
        {
            Color _backgroundColor = DEFAULT_BUTTON_HOVER_BACKGROUND_COLOR;
            Color _borderColor = DEFAULT_BUTTON_HOVER_BORDER_COLOR;
            Color _labelColor = DEFAULT_BUTTON_HOVER_LABEL_COLOR;
            Color _labelBorderColor = DEFAULT_BUTTON_HOVER_LABEL_BORDER_COLOR;

            unsigned int _characterSize = DEFAULT_BUTTON_HOVER_LABEL_CHARACTER_SIZE;
            unsigned int _textStyle = DEFAULT_BUTTON_HOVER_LABEL_TEXT_STYLE;

            unsigned int _borderThickness = DEFAULT_BUTTON_HOVER_BORDER_THICKNESS;
            unsigned int _labelBorderThickness = DEFAULT_BUTTON_HOVER_LABEL_BORDER_THICKNESS;

            glm::vec2 _scale = DEFAULT_BUTTON_HOVER_SCALE; // BUYER BEWARE (SHOULDN'T BE USED UNLESS YOU WANT TO LIVE LIFE ON THE EDGE)

            //Mouse::Cursor _cursor = Mouse::Cursor::Arrow;
        };

        /**
        * \brief Class constructor
        *
        * \param data Game data object
        */
        Button( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Button( );

        /**
        * \brief Draw the classes objects
        */
        void Draw( );

        /**
        * \brief Set the button's background rectangle (most of the time leave as is)
        *
		* \param rectangle Pointer to the rectangle
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetRectangleBackground( Rectangle *rectangle, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the button's label (most of the time leave as is)
        *
		* \param label Pointer to the label
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelBackground( Label *label, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the buttons background rectangle
        *
        * \return Output returns the buttons background rectangle
        */
		Rectangle *GetRectangleBackground( ) const;

        /**
        * \brief Get the buttons label
        *
        * \return Output returns the buttons label
        */
		Label *GetRectangleLabel( ) const;

        /**
        * \brief Set extra padding around the text
        *
		* \param padding Background padding
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
		void SetPadding( const glm::vec2 &padding, const bool &updateDefaultStyle = true );

        /**
        * \brief Set extra padding around the text
        *
        * \param x Background padding x axis (left and right)
		* \param y Background padding y axis (top and bottom)
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
		void SetPadding( const float &x, const float &y, const bool &updateDefaultStyle = true );

        /**
        * \brief Set extra padding around the text's x axis (left and right)
        *
		* \param x Background padding x axis (left and right)
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
		void SetPaddingX( const float &x, const bool &updateDefaultStyle = true );

        /**
        * \brief Set extra padding around the text's y axis (top and bottom)
        *
		* \param y Background padding y axis (top and bottom)
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
		void SetPaddingY( const float &y, const bool &updateDefaultStyle = true );

        /**
        * \brief Get padding around the text
        *
        * \return Output returns the padding
        */
        const glm::vec2 &GetPadding( ) const;

        /**
        * \brief Get padding around the text's x axis (left and right)
        *
        * \return Output returns the x padding
        */
        float GetPaddingX( ) const;

        /**
        * \brief Get padding around the text's y axis (top and bottom)
        *
        * \return Output returns the y padding
        */
        float GetPaddingY( ) const;

        /**
        * \brief Set width and height
        *
		* \param size Size of the object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetSize( const glm::vec2 &size, const bool &updateDefaultStyle = true );

        /**
        * \brief Set width and height
        *
        * \param width Width of the object
		* \param height Height of the object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetSize( const float &width, const float &height, const bool &updateDefaultStyle = true );

        /**
        * \brief Set width
        *
		* \param width Width of the object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetWidth( const float &width, const bool &updateDefaultStyle = true );

        /**
        * \brief Set height
        *
		* \param height Height of the object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetHeight( const float &height, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the size vector
        *
        * \return Output returns the size vector
        */
        glm::vec2 GetSize( ) const;

        /**
        * \brief Get the width
        *
        * \return Output returns the width
        */
        float GetWidth( ) const;

        /**
        * \brief Get the height
        *
        * \return Output returns the height
        */
        float GetHeight( ) const;

        /**
        * \brief Set the label's x anchor
        *
        * \param anchor Which position to anchor the label in the x axis
        * \param usePadding Whether or not to use padding
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelAnchorX( const LABEL_ANCHOR_X &anchor, const bool &usePadding = false, const bool &updateDefaultStyle = true );

        /**
		* \brief Set the label's y anchor
		*
		* \param anchor Which position to anchor the label in the x axis
		* \param usePadding Whether or not to use padding
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelAnchorY( const LABEL_ANCHOR_Y &anchor, const bool &usePadding = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the button's text
        *
		* \param string The string for the text to be displayed
		* \param resetButtonSize Whether or not to reset the button size
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetText( const std::string &string, const bool &resetButtonSize = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the button's text
        *
        * \return Output returns the button's text
        */
        const std::string &GetText( ) const;

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

        /**
        * \brief Set x and y position
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
        * \brief Get the x position
        *
        * \return Output returns the x position
        */
        float GetPositionX( ) const;

        /**
        * \brief Get the y position
        *
        * \return Output returns the y position
        */
        float GetPositionY( ) const;

        /**
        * \brief Get the position vector
        *
        * \return Output returns the position vector
        */
        glm::vec2 GetPosition( ) const;

        /**
        * \brief Set the character size in pixels
        *
		* \param size Size of the characters in pixels
		* \param usePadding Whether or not to use padding
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetCharacterSize( const unsigned int &size, const bool &usePadding = true, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the characters size in pixels
        *
        * \return Output returns the character size
        */
        unsigned int GetCharacterSize( ) const;

        /**
        * \brief Set the background's inside color (fill color)
        *
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetBackgroundInsideColor( const Color &color, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the background's border color
        *
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * SetBorderThickness method required as well
        */
        void SetBackgroundBorderColor( const Color &color, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the background's border thickness
        *
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBackgroundBorderThickness( const float &thickness, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the background's inside color (fill color)
        *
        * \return Output returns the inside color
        */
        Color GetBackgroundInsideColor( ) const;

        /**
        * \brief Get the background's border color
        *
        * \return Output returns the border color
        */
        Color GetBackgroundBorderColor( ) const;

        /**
        * \brief Get the background's border thickness
        *
        * \return Output returns the border thickness
        */
        float GetBackgroundBorderThickness( ) const;

        /**
        * \brief Set the label's inside color (fill color)
        *
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelInsideColor( const Color &color, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the label's border color
        *
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * SetBorderThickness method required as well
        */
        void SetLabelBorderColor( const Color &color, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the label's border thickness
        *
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetLabelBorderThickness( const float &thickness, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the label's inside color (fill color)
        *
        * \return Output returns the inside color
        */
        Color GetLabelInsideColor( ) const;

        /**
        * \brief Get the label's border color
        *
        * \return Output returns the border color
        */
        Color GetLabelBorderColor( ) const;

        /**
        * \brief Get the label's border thickness
        *
        * \return Output returns the border thickness
        */
        float GetLabelBorderThickness( ) const;

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
        * \brief Set the scale factor
        *
        * \param xScale Scale in x axis
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetScale( const float &xScale, const float &yScale, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the scale factor
        *
		* \param scale Scale in x and y axes
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetScale( const glm::vec2 &scale, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the x axis scale factor
        *
		* \param xScale Scale in x axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetScaleX( const float &xScale, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the y axis scale factor
        *
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetScaleY( const float &yScale, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the scale factor for both axes
        *
        * \return Output returns scale factor for both axes
        */
        glm::vec2 GetScale( ) const;

        /**
        * \brief Get the scale factor for x axis
        *
        * \return Output returns scale factor for the x axis
        */
        float GetScaleX( ) const;

        /**
        * \brief Get the scale factor for y axis
        *
        * \return Output returns scale factor for the y axis
        */
        float GetScaleY( ) const;

        /**
        * \brief Set the label's font
        *
        * \param font Font for the label
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetFont( const Font &font, const bool &resize = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Sets the font file
        *
		* \param filePath Font file path
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetFontFilePath( const std::string &filepath, const bool &resize = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the label's font object
        *
        * \return Output returns the font used for the label
        */
        const Font &GetFont( ) const;

        /**
        * \brief Gets the font's file path
        *
        * \return Output returns the font's file path
        */
        std::string GetFontFilePath( ) const;

        /**
        * \brief Set a particular style for the label
        *
        * \param style Which style to change
		* \param isActivated True to enable the style and false to disable it
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelStyle( const Label::STYLE &style, const bool &isActivated, const bool &resize = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Set a particular style for the label
        *
		* \param style Style int to use
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelStyle( const unsigned int &style, const bool &resize = false, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the overall style
        *
        * \return Output returns the overall style
        */
        unsigned int GetLabelStyle( ) const;

        /**
        * \brief Check if a particular style is enabled
        *
        * \param style Style to check
        *
        * \return Output returns true if the style is enabled and false if it is disabled
        */
        bool IsStyleEnabled( const Label::STYLE &style ) const;

        /**
        * \brief Reset the labels position within the background
        *
        * \param usePadding Whether or not to factor in padding around the label
        */
        void ResetLabelPosition( const bool &usePadding = true );

        /**
        * \brief Recalculates the padding
        */
        void RecalculatePadding( );

        /**
        * \brief Toggle the button background
        */
        void ToggleBackground( );

        /**
        * \brief Enable the button background
        */
        void EnableBackground( );

        /**
        * \brief Disable the button background
        */
        void DisableBackground( );

        /**
        * \brief Is the button background enabled
        *
        * \return Output returns the button background enabled status
        */
        const bool &IsBackgroundEnabled( ) const;

        /**
        * \brief Check if the object is clicked by the mouse
        *
        * \param button The mouse button to check
        *
        * \return Output returns true if the mouse is being clicked over the object and false otherwise
        */
        bool IsClicked( const Mouse::Button &button ) const;

        /**
        * \brief Is the mouse hovering
        *
        * \return Output returns the mouse hover status, true if the mouse is in the item and false if it isn't
        */
        bool IsMouseOver( ) const;

        /**
        * \brief Update the button
        */
        void Update( );

        /**
        * \brief Set the overall button style
        *
		* \param style Style to be applied to the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetButtonStyle( const Button::ButtonStyle &style, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the hover button style
        *
        * \param style Style to be applied to the button's hover event
        */
        void SetHoverButtonStyle( const Button::ButtonStyle &style );

        /**
        * \brief Get the default button style
        *
        * \return Output returns the default button style
        */
        const ButtonStyle &GetDefaultButtonStyle( ) const;

        /**
        * \brief Get the hover button style
        *
        * \return Output returns the hover button style
        */
        const ButtonStyle &GetHoverButtonStyle( ) const;

    private:
        /**
        * \brief Updates the buttons default style
        */
        void UpdateDefaultStyle( );

        /**
        * \brief Button background
        */
        Rectangle *_background;

        /**
        * \brief Button label
        */
        Label *_label;

        /**
        * \brief Padding around the label
        */
        glm::vec2 _padding;

        /**
        * \brief Anchor of the label with in the button's background in the x axis
        */
		LABEL_ANCHOR_X _anchorX;

        /**
        * \brief Anchor of the label with in the button's background in the y axis
        */
		LABEL_ANCHOR_Y _anchorY;

        /**
        * \brief Is the button background enabled or disabled
        */
        bool _isBackgroundEnabled;

        /**
        * \brief Hover and default styles
        */
        ButtonStyle _hoverStyle, _defaultStyle, _clickedStyle;

    };
}
