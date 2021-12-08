#pragma once

namespace Sonar
{
    class Slider : public MenuComponent
    {
    public:
        /**
        * \brief Slider's orientation
        */
        enum Orientation
        {
            HORIZONTAL = 0,
            VERTICAL
        };

        /**
        * \brief Class constructor
        *
		* \param data Game data object
		* \param orientation Slider's orientation (to change the orientation, the slider must be reinitialized)
        */
        Slider( GameDataRef data, const Orientation &orientation = Orientation::HORIZONTAL );

        /**
        * \brief Class destructor
        */
        ~Slider( );
        
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
        * \brief Set the components theme
        *
        * \param theme Theme to set
        */
        void SetTheme( const MenuComponent::Theme &theme );

        /**
        * \brief Poll the input from the Joystick, Keyboard and Mouse
        *
        * \param dt Delta time (difference between frames)
        * \param event Event to poll
        */
        void PollInput( const float &dt, const Event &event );

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
        * \brief Set the background size
        *
        * \param size Width and height of the background
        */
		void SetBackgroundSize( const glm::vec2 &size );

        /**
        * \brief Set the background size
        *
		* \param width Width of the background
		* \param height Height of the background
        */
		void SetBackgroundSize( const float &width, const float &height );

        /**
        * \brief Set the background width
        *
        * \param width Width of the background
        */
		void SetBackgroundWidth( const float &width );

        /**
        * \brief Set the background height
        *
        * \param height Height of the background
        */
		void SetBackgroundHeight( const float &height );

        /**
        * \brief Get the background size
        *
        * \return Output returns the background size
        */
        [[nodiscard]] glm::vec2 GetBackgroundSize( ) const;

        /**
        * \brief Get the background width
        *
        * \return Output returns the background width
        */
        [[nodiscard]] float GetBackgroundWidth( ) const;

        /**
        * \brief Get the background height
        *
        * \return Output returns the background height
        */
        [[nodiscard]] float GetBackgroundHeight( ) const;

        /**
        * \brief Set the knob size/radius
        *
        * \param radius Radius of the knob
        */
		void SetKnobRadius( const float &radius );

        /**
        * \brief Get the knob size/radius
        *
        * \return Output returns the knob size/radius
        */
        [[nodiscard]] float GetKnobRadius( ) const;

        /**
        * \brief Set the color of the background
        *
        * \param color Color object
        */
        void SetBackgroundColor( const Color &color );

        /**
        * \brief Set the background border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBackgroundBorderThickness( const float &thickness );

        /**
        * \brief Set the color of the background border
        *
        * \param color Color object
        */
        void SetBackgroundBorderColor( const Color &color );

        /**
        * \brief Get the background color
        *
        * \return Output returns the background color
        */
        [[nodiscard]] Color GetBackgroundColor( ) const;

        /**
        * \brief Get the background border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetBackgroundBorderThickness( ) const;

        /**
        * \brief Get the background border color
        *
        * \return Output returns the checked color
        */
        [[nodiscard]] Color GetBackgroundBorderColor( ) const;

        /**
        * \brief Set the color of the knob
        *
        * \param color Color object
        */
        void SetKnobColor( const Color &color );

        /**
        * \brief Set the knob border thickness
        *
        * \param thickness Thickness of the border
        *
        * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetKnobBorderThickness( const float &thickness );

        /**
        * \brief Set the color of the knob border
        *
        * \param color Color object
        */
        void SetKnobBorderColor( const Color &color );

        /**
        * \brief Get the knob color
        *
        * \return Output returns the knob color
        */
        [[nodiscard]] Color GetKnobColor( ) const;

        /**
        * \brief Get the knob border thickness
        *
        * \return Output returns the border thickness
        */
        [[nodiscard]] float GetKnobBorderThickness( ) const;

        /**
        * \brief Get the knob border color
        *
        * \return Output returns the checked color
        */
        [[nodiscard]] Color GetKnobBorderColor( ) const;

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
        * \param scale Scale factor
        */
        void SetScale( const float &scale );

        /**
        * \brief Scale the object relative to it's current scale
        *
        * \param scale Scale factor
        */
        void Scale( const float &scale );

        /**
        * \brief Get the scale factor
        *
        * \return Output returns the scale factor
        */
        [[nodiscard]] float GetScale( ) const;

        /**
        * \brief Get the local bounds (for the background)
        *
        * \return Output returns the shape's local bounds
        */
        [[nodiscard]] glm::vec4 GetLocalBounds( ) const;

        /**
        * \brief Get the global bounds (for the background)
        *
        * \return Output returns the shape's global bounds
        */
        [[nodiscard]] glm::vec4 GetGlobalBounds( ) const;

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

        /**
        * \brief Set the sliders current value
        *
        * \param value Current value
        */
        void SetValue( const float &value );

        /**
        * \brief Get the sliders current value
        *
        * \return Output returns the sliders current value
        */
        [[nodiscard]] const float &GetValue( ) const;

        /**
        * \brief Set sliders minimum value
        *
        * \param value Minimum value
        */
        void SetMinimumValue( const float &value );

        /**
        * \brief Set sliders maximum value
        *
        * \param value Maximum value
        */
        void SetMaximumValue( const float &value );

        /**
        * \brief Get the sliders minimum value
        *
        * \return Output returns the sliders minimum value
        */
        [[nodiscard]] const float &GetMinimumValue( ) const;

        /**
        * \brief Get the sliders maximum value
        *
        * \return Output returns the sliders maximum value
        */
        [[nodiscard]] const float &GetMaximumValue( ) const;

        /**
        * \brief Increment the sliders current value
        */
        void Increment( );

        /**
        * \brief Decrement the sliders current value
        */
        void Decrement( );

        /**
        * \brief Set the jump amount for the increment and decrement functions
        *
        * \param value Jump amount value
        */
        void SetJumpAmount( const float &value );

        /**
        * \brief Get the jump amount value
        *
        * \return Output returns the jump amount value
        */
        [[nodiscard]] const float &GetJumpAmount( ) const;

        /**
        * \brief Is the mouse hovering over the slider
        *
        * \return Output returns the true or false for the hover event
        */
        [[nodiscard]] bool IsMouseOver( ) const;

        /**
        * \brief Get the slider's orientation (to change the orientation, the slider must be reinitialized)
        *
        * \return Output returns which orientation the slider is in
        */
        [[nodiscard]] const Orientation &GetOrientation( ) const;

    private:
        /**
        * \brief Moves the knob, plain and simplessss
        */
        void MoveKnob( const int &position );

        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Which button triggers the clicked function
        */
        Mouse::Button _buttonToClick;

        /**
        * \brief Slider background
        */
        std::shared_ptr<Rectangle> _background;

        /**
        * \brief Slider knob
        */
        std::shared_ptr<Circle> _knob;

        /**
        * \brief Is the mouse currently down
        */
        bool _isMouseDown;

        /**
        * \brief Current, minimum & maximum slider values
        */
        float _value, _minimumValue, _maximumValue;

        /**
        * \brief The amount the increment/decrement methods increase/decrease the value by
        */
        float _jumpAmount;
        
        /**
        * \brief Is the mouse clicked down on the slider's knob
        */
        bool _isMouseDownOverKnob;

        /**
        * \brief Slider's orientation
        */
        Orientation _orientation;

    };
}
