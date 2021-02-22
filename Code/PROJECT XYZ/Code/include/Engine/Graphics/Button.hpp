#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Graphics/Color.hpp"
#include "Graphics/Drawable.hpp"
#include "Graphics/Label.hpp"
#include "Graphics/MenuComponent.hpp"
#include "Graphics/Shapes/Rectangle.hpp"

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
        */
        void SetRectangleBackground( Rectangle *rectangle );

        /**
        * \brief Set the button's label (most of the time leave as is)
        *
        * \param label Pointer to the label
        */
        void SetLabelBackground( Label *label );

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
        */
		void SetPadding( const glm::vec2 &padding );

        /**
        * \brief Set extra padding around the text
        *
        * \param x Background padding x axis (left and right)
        * \param y Background padding y axis (top and bottom)
        */
		void SetPadding( const float &x, const float &y );

        /**
        * \brief Set extra padding around the text's x axis (left and right)
        *
        * \param x Background padding x axis (left and right)
        */
		void SetPaddingX( const float &x );

        /**
        * \brief Set extra padding around the text's y axis (top and bottom)
        *
		* \param y Background padding y axis (top and bottom)
        */
		void SetPaddingY( const float &y );

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
        */
        void SetSize( const glm::vec2 &size );

        /**
        * \brief Set width and height
        *
        * \param width Width of the object
        * \param height Height of the object
        */
        void SetSize( const float &width, const float &height );

        /**
        * \brief Set width
        *
        * \param width Width of the object
        */
        void SetWidth( const float &width );

        /**
        * \brief Set height
        *
        * \param height Height of the object
        */
        void SetHeight( const float &height );

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
        */
        void SetLabelAnchorX( const LABEL_ANCHOR_X &anchor, const bool &usePadding = false );

        /**
        * \brief Set the label's y anchor
        */
        void SetLabelAnchorY( const LABEL_ANCHOR_Y &anchor, const bool &usePadding = false );

        /**
        * \brief Set the button's text
        *
        * \param string The string for the text to be displayed
        */
        void SetText( const std::string &string, const bool &resetButtonSize = false );

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
        */
        void SetCharacterSize( const unsigned int &size, const bool &usePadding = true );

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
        */
        void SetBackgroundInsideColor( const Color &color );

        /**
        * \brief Set the background's border color
        *
        * \param color Color object
        *
        * SetBorderThickness method required as well
        */
        void SetBackgroundBorderColor( const Color &color );

        /**
        * \brief Set the background's border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBackgroundBorderThickness( const float &thickness );

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
        */
        void SetLabelInsideColor( const Color &color );

        /**
        * \brief Set the label's border color
        *
        * \param color Color object
        *
        * SetBorderThickness method required as well
        */
        void SetLabelBorderColor( const Color &color );

        /**
        * \brief Set the label's border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetLabelBorderThickness( const float &thickness );

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

    private:
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
        * \brief Button background
        */
        Rectangle *_buttonBackground;

        /**
        * \brief Button label
        */
        Label *_buttonLabel;

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

    };
}
