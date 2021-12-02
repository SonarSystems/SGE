#pragma once

#include "Graphics/Label.hpp"

namespace Sonar
{
    class Rectangle;
    class Font;

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
        * \brief State of the mouse on the button
        */
        enum class MOUSE_STATE
        {
            NOT_INTERACTING = 0,
            HOVER,
            CLICKED
        };

        /**
        * \brief Button style struct
        */
        struct ButtonStyle
        {
            Color _backgroundColor = DEFAULT_BUTTON_HOVER_BACKGROUND_COLOR;
            Color _borderColor = DEFAULT_BUTTON_HOVER_BORDER_COLOR;
            Color _labelColor = DEFAULT_BUTTON_HOVER_LABEL_COLOR;
            Color _labelBorderColor = DEFAULT_BUTTON_HOVER_LABEL_BORDER_COLOR;

            unsigned int _characterSize = DEFAULT_BUTTON_HOVER_LABEL_CHARACTER_SIZE;
            unsigned int _textStyle = DEFAULT_BUTTON_HOVER_LABEL_TEXT_STYLE;

            float _borderThickness = DEFAULT_BUTTON_HOVER_BORDER_THICKNESS;
            float _labelBorderThickness = DEFAULT_BUTTON_HOVER_LABEL_BORDER_THICKNESS;

            glm::vec2 _scale = DEFAULT_BUTTON_HOVER_SCALE; // BUYER BEWARE (SHOULDN'T BE USED UNLESS YOU WANT TO LIVE LIFE ON THE EDGE)

            Mouse::Cursor _cursor = DEFAULT_BUTTON_CURSOR;
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
        * \brief Update the classes objects
        *
        * \param dt Delta time (difference between frames)
        */
        void Update( const float &dt );

        /**
        * \brief Update the classes objects
        *
        * \param dt Delta time (difference between frames)
        */
        [[nodiscard]] MOUSE_STATE UpdateForButtonGroup( const float &dt, const bool &isDefaultStyleEnabled );

        /**
        * \brief Poll the input from the Joystick, Keyboard and Mouse
        *
        * \param dt Delta time (difference between frames)
        * \param event Event to poll
        */
        void PollInput( const float &dt, const Event &event );

        /**
        * \brief Set the components theme
        *
        * \param theme Theme to set
        */
        void SetTheme( const MenuComponent::Theme &theme );

        /**
        * \brief Set the button's background rectangle (most of the time leave as is)
        *
		* \param rectangle Pointer to the rectangle
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetRectangleBackground( std::shared_ptr<Rectangle>rectangle, const bool &updateDefaultStyle = true );

        /**
        * \brief Set the button's label (most of the time leave as is)
        *
		* \param label Pointer to the label
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetLabelBackground( std::shared_ptr<Label>label, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the buttons background rectangle
        *
        * \return Output returns the buttons background rectangle
        */
        [[nodiscard]] std::shared_ptr<Rectangle> GetRectangleBackground( ) const;

        /**
        * \brief Get the buttons label
        *
        * \return Output returns the buttons label
        */
        [[nodiscard]] std::shared_ptr<Label> GetRectangleLabel( ) const;

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
        [[nodiscard]] const glm::vec2 &GetPadding( ) const;

        /**
        * \brief Get padding around the text's x axis (left and right)
        *
        * \return Output returns the x padding
        */
        [[nodiscard]] float GetPaddingX( ) const;

        /**
        * \brief Get padding around the text's y axis (top and bottom)
        *
        * \return Output returns the y padding
        */
        [[nodiscard]] float GetPaddingY( ) const;

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
        [[nodiscard]] glm::vec2 GetSize( ) const;

        /**
        * \brief Get the width
        *
        * \return Output returns the width
        */
        [[nodiscard]] float GetWidth( ) const;

        /**
        * \brief Get the height
        *
        * \return Output returns the height
        */
        [[nodiscard]] float GetHeight( ) const;

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
        [[nodiscard]] const std::string &GetText( ) const;

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
        [[nodiscard]] float GetPositionX( ) const;

        /**
        * \brief Get the y position
        *
        * \return Output returns the y position
        */
        [[nodiscard]] float GetPositionY( ) const;

        /**
        * \brief Get the position vector
        *
        * \return Output returns the position vector
        */
        [[nodiscard]] glm::vec2 GetPosition( ) const;

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
        [[nodiscard]] unsigned int GetCharacterSize( ) const;

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
        [[nodiscard]] Color GetBackgroundInsideColor( ) const;

        /**
        * \brief Get the background's border color
        *
        * \return Output returns the border color
        */
        [[nodiscard]] Color GetBackgroundBorderColor( ) const;

        /**
        * \brief Get the background's border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetBackgroundBorderThickness( ) const;

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
        [[nodiscard]] Color GetLabelInsideColor( ) const;

        /**
        * \brief Get the label's border color
        *
        * \return Output returns the border color
        */
        [[nodiscard]] Color GetLabelBorderColor( ) const;

        /**
        * \brief Get the label's border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetLabelBorderThickness( ) const;

		/**
		* \brief Set the hover character size in pixels
		*
		* \param size Size of the characters in pixels
		* \param usePadding Whether or not to use padding
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverCharacterSize( const unsigned int &size );

		/**
		* \brief Get the hover characters size in pixels
		*
		* \return Output returns the character size
		*/
        [[nodiscard]] unsigned int GetHoverCharacterSize( ) const;

		/**
		* \brief Set the hover background's inside color (fill color)
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverBackgroundInsideColor( const Color &color );

		/**
		* \brief Set the hover background's border color
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* SetBorderThickness method required as well
		*/
		void SetHoverBackgroundBorderColor( const Color &color );

		/**
		* \brief Set the hover background's border thickness
		*
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* Required for border, otherwise border is to set 0 thickness and cannot be seen
		*/
		void SetHoverBackgroundBorderThickness( const float &thickness );

		/**
		* \brief Get the hover background's inside color (fill color)
		*
		* \return Output returns the inside color
		*/
        [[nodiscard]] Color GetHoverBackgroundInsideColor( ) const;

		/**
		* \brief Get the hover background's border color
		*
		* \return Output returns the border color
		*/
        [[nodiscard]] Color GetHoverBackgroundBorderColor( ) const;

		/**
		* \brief Get the hover background's border thickness
		*
		* \return Output returns the border thickness
		*/
        [[nodiscard]] float GetHoverBackgroundBorderThickness( ) const;

		/**
		* \brief Set the hover label's inside color (fill color)
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverLabelInsideColor( const Color &color );

		/**
		* \brief Set the hover label's border color
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* SetBorderThickness method required as well
		*/
		void SetHoverLabelBorderColor( const Color &color );

		/**
		* \brief Set the hover label's border thickness
		*
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* Required for border, otherwise border is to set 0 thickness and cannot be seen
		*/
		void SetHoverLabelBorderThickness( const float &thickness );

		/**
		* \brief Get the hover label's inside color (fill color)
		*
		* \return Output returns the inside color
		*/
        [[nodiscard]] Color GetHoverLabelInsideColor( ) const;

		/**
		* \brief Get the hover label's border color
		*
		* \return Output returns the border color
		*/
        [[nodiscard]] Color GetHoverLabelBorderColor( ) const;

		/**
		* \brief Get the hover label's border thickness
		*
		* \return Output returns the border thickness
		*/
        [[nodiscard]] float GetHoverLabelBorderThickness( ) const;

		/**
		* \brief Set a particular style for the hover label
		*
		* \param style Style int to use
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverLabelStyle( const unsigned int &style );

		/**
		* \brief Get the overall hover style
		*
		* \return Output returns the overall style
		*/
        [[nodiscard]] unsigned int GetHoverLabelStyle( ) const;

		/**
		* \brief Set the hover scale factor
		*
		* \param xScale Scale in x axis
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverScale( const float &xScale, const float &yScale );

		/**
		* \brief Set the hover scale factor
		*
		* \param scale Scale in x and y axes
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverScale( const glm::vec2 &scale );

		/**
		* \brief Set the x axis hover scale factor
		*
		* \param xScale Scale in x axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverScaleX( const float &xScale );

		/**
		* \brief Set the y axis hover scale factor
		*
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHoverScaleY( const float &yScale );

		/**
		* \brief Scale the hover object relative to it's current scale
		*
		* \param scale Scale in the x and y axis
		*/
		void HoverScale( const glm::vec2 &scale );

		/**
		* \brief Scale the hover object relative to it's current scale
		*
		* \param xScale Scale in x axis
		* \param yScale Scale in y axis
		*/
		void HoverScale( const float &xScale, const float &yScale );

		/**
		* \brief Scale the hover object relative to it's current x scale
		*
		* \param xScale Scale in x axis
		*/
		void HoverScaleX( const float &xScale );

		/**
		* \brief Scale the hover object relative to it's current y scale
		*
		* \param yScale Scale in y axis
		*/
		void HoverScaleY( const float &yScale );

		/**
		* \brief Get the hover scale factor for both axes
		*
		* \return Output returns scale factor for both axes
		*/
        [[nodiscard]] glm::vec2 GetHoverScale( ) const;

		/**
		* \brief Get the hover scale factor for x axis
		*
		* \return Output returns scale factor for the x axis
		*/
        [[nodiscard]] float GetHoverScaleX( ) const;

		/**
		* \brief Get the hover scale factor for y axis
		*
		* \return Output returns scale factor for the y axis
		*/
        [[nodiscard]] float GetHoverScaleY( ) const;

        /**
        * \brief Set the clicked character size in pixels
        *
        * \param size Size of the characters in pixels
        * \param usePadding Whether or not to use padding
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedCharacterSize( const unsigned int &size );

        /**
        * \brief Get the clicked characters size in pixels
        *
        * \return Output returns the character size
        */
        [[nodiscard]] unsigned int GetClickedCharacterSize( ) const;

        /**
        * \brief Set the clicked background's inside color (fill color)
        *
        * \param color Color object
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedBackgroundInsideColor( const Color &color );

        /**
        * \brief Set the clicked background's border color
        *
        * \param color Color object
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * SetBorderThickness method required as well
        */
        void SetClickedBackgroundBorderColor( const Color &color );

        /**
        * \brief Set the clicked background's border thickness
        *
        * \param thickness Thickness of the border
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetClickedBackgroundBorderThickness( const float &thickness );

        /**
        * \brief Get the clicked background's inside color (fill color)
        *
        * \return Output returns the inside color
        */
        [[nodiscard]] Color GetClickedBackgroundInsideColor( ) const;

        /**
        * \brief Get the clicked background's border color
        *
        * \return Output returns the border color
        */
        [[nodiscard]] Color GetClickedBackgroundBorderColor( ) const;

        /**
        * \brief Get the clicked background's border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetClickedBackgroundBorderThickness( ) const;

        /**
        * \brief Set the clicked label's inside color (fill color)
        *
        * \param color Color object
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedLabelInsideColor( const Color &color );

        /**
        * \brief Set the clicked label's border color
        *
        * \param color Color object
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * SetBorderThickness method required as well
        */
        void SetClickedLabelBorderColor( const Color &color );

        /**
        * \brief Set the clicked label's border thickness
        *
        * \param thickness Thickness of the border
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetClickedLabelBorderThickness( const float &thickness );

        /**
        * \brief Get the clicked label's inside color (fill color)
        *
        * \return Output returns the inside color
        */
        [[nodiscard]] Color GetClickedLabelInsideColor( ) const;

        /**
        * \brief Get the clicked label's border color
        *
        * \return Output returns the border color
        */
        [[nodiscard]] Color GetClickedLabelBorderColor( ) const;

        /**
        * \brief Get the clicked label's border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetClickedLabelBorderThickness( ) const;

        /**
        * \brief Set a particular style for the clicked label
        *
        * \param style Style int to use
        * \param resize Whether or not to resize the button
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedLabelStyle( const unsigned int &style );

        /**
        * \brief Get the overall clicked style
        *
        * \return Output returns the overall style
        */
        [[nodiscard]] unsigned int GetClickedLabelStyle( ) const;

        /**
        * \brief Set the clicked scale factor
        *
        * \param xScale Scale in x axis
        * \param yScale Scale in y axis
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedScale( const float &xScale, const float &yScale );

        /**
        * \brief Set the clicked scale factor
        *
        * \param scale Scale in x and y axes
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedScale( const glm::vec2 &scale );

        /**
        * \brief Set the x axis clicked scale factor
        *
        * \param xScale Scale in x axis
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedScaleX( const float &xScale );

        /**
        * \brief Set the y axis clicked scale factor
        *
        * \param yScale Scale in y axis
        * \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
        */
        void SetClickedScaleY( const float &yScale );

        /**
        * \brief Scale the clicked object relative to it's current scale
        *
        * \param scale Scale in the x and y axis
        */
        void ClickedScale( const glm::vec2 &scale );

        /**
        * \brief Scale the clicked object relative to it's current scale
        *
        * \param xScale Scale in x axis
        * \param yScale Scale in y axis
        */
        void ClickedScale( const float &xScale, const float &yScale );

        /**
        * \brief Scale the clicked object relative to it's current x scale
        *
        * \param xScale Scale in x axis
        */
        void ClickedScaleX( const float &xScale );

        /**
        * \brief Scale the clicked object relative to it's current y scale
        *
        * \param yScale Scale in y axis
        */
        void ClickedScaleY( const float &yScale );

        /**
        * \brief Get the clicked scale factor for both axes
        *
        * \return Output returns scale factor for both axes
        */
        [[nodiscard]] glm::vec2 GetClickedScale( ) const;

        /**
        * \brief Get the clicked scale factor for x axis
        *
        * \return Output returns scale factor for the x axis
        */
        [[nodiscard]] float GetClickedScaleX( ) const;

        /**
        * \brief Get the clicked scale factor for y axis
        *
        * \return Output returns scale factor for the y axis
        */
        [[nodiscard]] float GetClickedScaleY( ) const;

		/**
		* \brief Set the highlighted character size in pixels
		*
		* \param size Size of the characters in pixels
		* \param usePadding Whether or not to use padding
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedCharacterSize( const unsigned int &size );

		/**
		* \brief Get the highlighted characters size in pixels
		*
		* \return Output returns the character size
		*/
        [[nodiscard]] unsigned int GetHighlightedCharacterSize( ) const;

		/**
		* \brief Set the highlighted background's inside color (fill color)
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedBackgroundInsideColor( const Color &color );

		/**
		* \brief Set the highlighted background's border color
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* SetBorderThickness method required as well
		*/
		void SetHighlightedBackgroundBorderColor( const Color &color );

		/**
		* \brief Set the highlighted background's border thickness
		*
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* Required for border, otherwise border is to set 0 thickness and cannot be seen
		*/
		void SetHighlightedBackgroundBorderThickness( const float &thickness );

		/**
		* \brief Get the highlighted background's inside color (fill color)
		*
		* \return Output returns the inside color
		*/
        [[nodiscard]] Color GetHighlightedBackgroundInsideColor( ) const;

		/**
		* \brief Get the highlighted background's border color
		*
		* \return Output returns the border color
		*/
        [[nodiscard]] Color GetHighlightedBackgroundBorderColor( ) const;

		/**
		* \brief Get the highlighted background's border thickness
		*
		* \return Output returns the border thickness
		*/
        [[nodiscard]] float GetHighlightedBackgroundBorderThickness( ) const;

		/**
		* \brief Set the highlighted label's inside color (fill color)
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedLabelInsideColor( const Color &color );

		/**
		* \brief Set the highlighted label's border color
		*
		* \param color Color object
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* SetBorderThickness method required as well
		*/
		void SetHighlightedLabelBorderColor( const Color &color );

		/**
		* \brief Set the highlighted label's border thickness
		*
		* \param thickness Thickness of the border
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*
		* Required for border, otherwise border is to set 0 thickness and cannot be seen
		*/
		void SetHighlightedLabelBorderThickness( const float &thickness );

		/**
		* \brief Get the highlighted label's inside color (fill color)
		*
		* \return Output returns the inside color
		*/
        [[nodiscard]] Color GetHighlightedLabelInsideColor( ) const;

		/**
		* \brief Get the highlighted label's border color
		*
		* \return Output returns the border color
		*/
        [[nodiscard]] Color GetHighlightedLabelBorderColor( ) const;

		/**
		* \brief Get the highlighted label's border thickness
		*
		* \return Output returns the border thickness
		*/
        [[nodiscard]] float GetHighlightedLabelBorderThickness( ) const;

		/**
		* \brief Set a particular style for the highlighted label
		*
		* \param style Style int to use
		* \param resize Whether or not to resize the button
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedLabelStyle( const unsigned int &style );

		/**
		* \brief Get the overall highlighted style
		*
		* \return Output returns the overall style
		*/
        [[nodiscard]] unsigned int GetHighlightedLabelStyle( ) const;

		/**
		* \brief Set the highlighted scale factor
		*
		* \param xScale Scale in x axis
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedScale( const float &xScale, const float &yScale );

		/**
		* \brief Set the highlighted scale factor
		*
		* \param scale Scale in x and y axes
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedScale( const glm::vec2 &scale );

		/**
		* \brief Set the x axis highlighted scale factor
		*
		* \param xScale Scale in x axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedScaleX( const float &xScale );

		/**
		* \brief Set the y axis highlighted scale factor
		*
		* \param yScale Scale in y axis
		* \param updateDefaultStyle Whether or not to update the default style (recommended to leave on true)
		*/
		void SetHighlightedScaleY( const float &yScale );

		/**
		* \brief Scale the highlighted object relative to it's current scale
		*
		* \param scale Scale in the x and y axis
		*/
		void HighlightedScale( const glm::vec2 &scale );

		/**
		* \brief Scale the highlighted object relative to it's current scale
		*
		* \param xScale Scale in x axis
		* \param yScale Scale in y axis
		*/
		void HighlightedScale( const float &xScale, const float &yScale );

		/**
		* \brief Scale the highlighted object relative to it's current x scale
		*
		* \param xScale Scale in x axis
		*/
		void HighlightedScaleX( const float &xScale );

		/**
		* \brief Scale the highlighted object relative to it's current y scale
		*
		* \param yScale Scale in y axis
		*/
		void HighlightedScaleY( const float &yScale );

		/**
		* \brief Get the highlighted scale factor for both axes
		*
		* \return Output returns scale factor for both axes
		*/
        [[nodiscard]] glm::vec2 GetHighlightedScale( ) const;

		/**
		* \brief Get the highlighted scale factor for x axis
		*
		* \return Output returns scale factor for the x axis
		*/
        [[nodiscard]] float GetHighlightedScaleX( ) const;

		/**
		* \brief Get the highlighted scale factor for y axis
		*
		* \return Output returns scale factor for the y axis
		*/
        [[nodiscard]] float GetHighlightedScaleY( ) const;

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
		* \brief Scale the object relative to it's current scale
		*
		* \param scale Scale in the x and y axis
		*/
		void Scale( const glm::vec2 &scale, const bool &updateDefaultStyle = true );

		/**
		* \brief Scale the object relative to it's current scale
		*
		* \param xScale Scale in x axis
		* \param yScale Scale in y axis
		*/
		void Scale( const float &xScale, const float &yScale, const bool &updateDefaultStyle = true );

		/**
		* \brief Scale the object relative to it's current x scale
		*
		* \param xScale Scale in x axis
		*/
		void ScaleX( const float &xScale, const bool &updateDefaultStyle = true );

		/**
		* \brief Scale the object relative to it's current y scale
		*
		* \param yScale Scale in y axis
		*/
		void ScaleY( const float &yScale, const bool &updateDefaultStyle = true );

        /**
        * \brief Get the scale factor for both axes
        *
        * \return Output returns scale factor for both axes
        */
        [[nodiscard]] glm::vec2 GetScale( ) const;

        /**
        * \brief Get the scale factor for x axis
        *
        * \return Output returns scale factor for the x axis
        */
        [[nodiscard]] float GetScaleX( ) const;

        /**
        * \brief Get the scale factor for y axis
        *
        * \return Output returns scale factor for the y axis
        */
        [[nodiscard]] float GetScaleY( ) const;

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
        [[nodiscard]] const Font &GetFont( ) const;

        /**
        * \brief Gets the font's file path
        *
        * \return Output returns the font's file path
        */
        [[nodiscard]] std::string GetFontFilePath( ) const;

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
        [[nodiscard]] unsigned int GetLabelStyle( ) const;

        /**
        * \brief Check if a particular style is enabled
        *
        * \param style Style to check
        *
        * \return Output returns true if the style is enabled and false if it is disabled
        */
        [[nodiscard]] bool IsStyleEnabled( const Label::STYLE &style ) const;

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
        [[nodiscard]] const bool &IsBackgroundEnabled( ) const;

        /**
        * \brief Check if the object is clicked by the mouse
        *
        * \param button The mouse button to check
        *
        * \return Output returns true if the mouse is being clicked over the object and false otherwise
        */
        [[nodiscard]] bool IsClicked( const Mouse::Button &button ) const;

        /**
        * \brief Is the mouse hovering
        *
        * \return Output returns the mouse hover status, true if the mouse is in the item and false if it isn't
        */
        [[nodiscard]] bool IsMouseOver( ) const;

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
        * \brief Set the clicked button style
        *
        * \param style Style to be applied to the button's clicked event
        */
        void SetClickedButtonStyle( const Button::ButtonStyle &style );

        /**
        * \brief Set the highlighted button style
        *
        * \param style Style to be applied to the button's highlighted event
        */
        void SetHighlightedButtonStyle( const Button::ButtonStyle &style );

        /**
        * \brief Get the default button style
        *
        * \return Output returns the default button style
        */
        [[nodiscard]] const ButtonStyle &GetDefaultButtonStyle( ) const;

        /**
        * \brief Get the hover button style
        *
        * \return Output returns the hover button style
        */
        [[nodiscard]] const ButtonStyle &GetHoverButtonStyle( ) const;

        /**
        * \brief Get the clicked button style
        *
        * \return Output returns the clicked button style
        */
        [[nodiscard]] const ButtonStyle &GetClickedButtonStyle( ) const;

        /**
        * \brief Get the highlighted button style
        *
        * \return Output returns the highlighted button style
        */
        [[nodiscard]] const ButtonStyle &GetHighlightedButtonStyle( ) const;

        /**
        * \brief Enable the hover functionality
        */
        void EnableHover( ); 

        /**
        * \brief Disable the hover functionality
        */
        void DisableHover( );

        /**
        * \brief Toggle the hover functionality
        */
        void ToggleHover( );

        /**
        * \brief Get the hover enabled/disabled status
        *
        * \return Output returns the hover enabled/disabled status
        */
        [[nodiscard]] bool GetHoverStatus( );

        /**
        * \brief Enable the click functionality
        */
        void EnableClick( ); 

        /**
        * \brief Disable the click functionality
        */
        void DisableClick( );

        /**
        * \brief Toggle the click functionality
        */
        void ToggleClick( );

        /**
        * \brief Get the click enabled/disabled status
        *
        * \return Output returns the click enabled/disabled status
        */
        [[nodiscard]] bool GetClickStatus( );

        /**
        * \brief Set the buttons minimum size
        *
        * \param size Minimum size of the button
        */
        void SetMinimumSize( const glm::vec2 &size );

        /**
        * \brief Set the buttons minimum size
        *
        * \param width Minimum width
        * \param height Minimum height
        */
        void SetMinimumSize( const float &width, const float &height );

        /**
        * \brief Set the buttons minimum width
        *
        * \param width Minimum width
        */
        void SetMinimumWidth( const float &width );

        /**
        * \brief Set the buttons minimum height
        *
        * \param width Minimum height
        */
        void SetMinimumHeight( const float &height );

        /**
        * \brief Get the buttons minimum size
        *
        * \return Output returns the minimum size
        */
        [[nodiscard]] const glm::vec2 &GetMinimumSize( ) const;

        /**
        * \brief Get the buttons minimum width
        *
        * \return Output returns the minimum width
        */
        [[nodiscard]] float GetMinimumWidth( ) const;

        /**
        * \brief Get the buttons minimum height
        *
        * \return Output returns the minimum height
        */
        [[nodiscard]] float GetMinimumHeight( ) const;

        /**
        * \brief Set the buttons Maximum size
        *
        * \param size Maximum size of the button
        */
        void SetMaximumSize( const glm::vec2 &size );

        /**
        * \brief Set the buttons Maximum size
        *
        * \param width Maximum width
        * \param height Maximum height
        */
        void SetMaximumSize( const float &width, const float &height );

        /**
        * \brief Set the buttons Maximum width
        *
        * \param width Maximum width
        */
        void SetMaximumWidth( const float &width );

        /**
        * \brief Set the buttons Maximum height
        *
        * \param width Maximum height
        */
        void SetMaximumHeight( const float &height );

        /**
        * \brief Get the buttons Maximum size
        *
        * \return Output returns the Maximum size
        */
        [[nodiscard]] const glm::vec2 &GetMaximumSize( ) const;

        /**
        * \brief Get the buttons Maximum width
        *
        * \return Output returns the Maximum width
        */
        [[nodiscard]] float GetMaximumWidth( ) const;

        /**
        * \brief Get the buttons Maximum height
        *
        * \return Output returns the Maximum height
        */
        [[nodiscard]] float GetMaximumHeight( ) const;

        /**
        * \brief Set the mousee button which would trigger the click function
        *
        * \param button Mouse button
        */
        void SetMouseButtonToClick( const Mouse::Button &button );

        /**
        * \brief Get the current mouse button which would trigger the click function
        *
        * \return Output returns the mouse button
        */
        [[nodiscard]] const Mouse::Button &GetMouseButtonToClick( ) const;

    private:
        /**
        * \brief Updates the buttons default style
        */
        void UpdateDefaultStyle( );

        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Button background
        */
        std::shared_ptr<Rectangle> _background;

        /**
        * \brief Button label
        */
        std::shared_ptr<Label> _label;

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
        * \brief Button styles
        * 
        * Hover style - when the mosue is hovering over the button
        * Default style - normal style
        * Clicked style - when the button is clicked
        * Highlighted style - when grouped in a ButtonGroup component
        */
        ButtonStyle _hoverStyle, _defaultStyle, _clickedStyle, _highlightedStyle;

        /**
        * \brief Which button triggers the clicked function
        */
        Mouse::Button _buttonToClick;

        /**
        * \brief Hover and click button enable status
        */
        bool _isHoverEnabled, _isClickEnabled;

        /**
        * \brief Minimum and maximum size allowed for the button
        */
        glm::vec2 _minSize, _maxSize;

    };
}
