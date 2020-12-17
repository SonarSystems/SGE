#pragma once

#include <SFML/Window.hpp>
#include <string>
#include <array>
#include <cmath>


namespace Sonar
{
    class Joystick
    {
    public:
        /**
         * \brief Maximum supported joysticks, buttons and axes
        */
        enum
        {
            Count       = 8,  // Maximum number of supported joysticks
            ButtonCount = 32, // Maximum number of supported buttons
            AxisCount   = 8   // Maximum number of supported axes
        };

        /**
         * \brief Axes supported by joysticks
        */
        enum Axis
        {
            X,    // The X axis
            Y,    // The Y axis
            Z,    // The Z axis
            R,    // The R axis
            U,    // The U axis
            V,    // The V axis
            PovX, // The X axis of the point-of-view hat
            PovY  // The Y axis of the point-of-view hat
        };

        /**
        * \brief Analogue Sticks
        */
        enum AnalogueStick
        {
            LeftStick,
            RightStick
        };

        /**
        * \brief Gesture Direction
        */
        enum Direction
        {
            Left,
            Right,
            Up,
            Down,
            LeftUp,
            RightUp,
            LeftDown,
            RightDown
        };

        /**
         * \brief Joystick information
        */
        struct Identification
        {
            std::string name; // Name of the joystick
            unsigned int vendorId; //  Manufacturer identifier
            unsigned int productId; //  Product identifier
        };
        
        /**
         * \brief Get information about a connected joystick
         *
         * \param joystick Joystick id
         *
         * \return Output returns the name, vendor id and product id of the joystick
        */
        static Identification GetIdentification( const unsigned int &joystick );
        
        /**
         * \brief Check if a joystick is connected
         *
         * \param joystick Joystick id
         *
         * \return Output returns true if the joystick is connected, false if it isn't
        */
        static bool IsConnected( const unsigned int &joystick );
        
        /**
         * \brief Return the number of buttons supported by a joystick
         *
         * \param joystick Joystick id
         *
         * \return Output returns how many buttons the joystick supports
        */
        static unsigned int GetButtonCount( const unsigned int &joystick );
        
        /**
         * \brief Check if a joystick supports a given axis
         *
         * \param joystick Joystick id
         * \param axis Joystick axis to check
         *
         * \return Output returns true if the joystick supports the axis and false if it doesn't
        */
        static bool HasAxis( const unsigned int &joystick, const Axis &axis );
        
        /**
         * \brief Check if a joystick button is pressed
         *
         * \param joystick Joystick id
         * \param button Joystick button id
         *
         * \return Output returns true if the button is pressed, false if it isn't
        */
        static bool IsPressed( const unsigned int &joystick, const unsigned int &button );
        
        /**
         * \brief Get the current position of a joystick axis
         *
         * \param joystick Joystick id
		 * \param axis Joystick axis to check
		 * \param deadzone The joystick axis deadzone for not returning a position other than 0
         *
         * \return Output returns the axis position
        */
        static float GetAxisPosition( const unsigned int &joystick, const Axis &axis, const float &deadzone = 0 );
        
        /**
         * \brief Check if multiple buttons have been pressed
         *
         * \param joystickButtons List of all the joysticks and buttons to check, first array parameter is the joystick id and second array parameter is the button id
         *
         * \return Output returns true if all buttons on all joysticks are pressed, false if not
         *
         * Checks if all buttons are being pressed at the same time across all joysticks
        */
        static bool ChordPressed( const std::initializer_list<std::array<int, 2>> &joystickButtons );
        
        /**
        * \brief Check if a basic gesture is triggered in a single direction
        *
        * \param joystickID ID of the joystick to be checked
        * \param analogueStick The analogue stick to be checked
        * \param direction Which direction/gesture is being checked
        *
        * \return Output returns true if all buttons on all joysticks are pressed, false if not
        */
        static bool IsGestureTriggered( const unsigned int &joystickID, const Joystick::AnalogueStick &analogueStick, const Direction &direction );

        /**
        * \brief Get the angle of a joystick (Left and no vertical is 0 and it goes clockwise)
        *
        * \param joystick Joystick id
        * \param xAxis Joystick x axis to check
		* \param yAxis Joystick y axis to check
		* \param isDegrees Degrees or radians (true for degrees by default and false for radians
		* \param deadzone The joystick deadzone for not returning a position other than 0
        *
        * \return Output returns the joystick angle
        */
        static float GetJoystickAngle( const unsigned int &joystick, const Axis &xAxis, const Axis &yAxis, const bool &isDegrees = true, const std::pair<float, float> &deadzone = { 0.0, 0.0 } );

        /**
        * \brief Get the distance of the joystick from the center/origin
        *
        * \param joystick Joystick id
        * \param xAxis Joystick x axis to check
		* \param yAxis Joystick y axis to check
		* \param deadzone The joystick deadzone for not returning a position other than 0
        *
        * \return Output returns the joystick distance
        */
        static float GetJoystickDistanceFromCenter( const unsigned int &joystick, const Axis &xAxis, const Axis &yAxis, const std::pair<float, float> &deadzone = { 0.0, 0.0 } );

    };
}
