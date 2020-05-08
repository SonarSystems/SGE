#pragma once

#include <SFML/Window.hpp>
#include <String>

namespace Sonar
{
    class Joystick
    {
    public:
        enum
        {
            Count       = 8,  // Maximum number of supported joysticks
            ButtonCount = 32, // Maximum number of supported buttons
            AxisCount   = 8   // Maximum number of supported axes
        };

        // Axes supported by Sonar joysticks
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
        
        struct Identification
        {
            std::string name; // Name of the joystick
            unsigned int vendorId; //  Manufacturer identifier
            unsigned int productId; //  Product identifier
        };
        
        static Identification GetIdentification( const unsigned int &joystick );
        
        // Check if a joystick is connected
        static bool IsConnected( const unsigned int &joystick );
        
        // Return the number of buttons supported by a joystick
        static unsigned int GetButtonCount( const unsigned int &joystick );
        
        // Check if a joystick supports a given axis
        static bool HasAxis( const unsigned int &joystick, const Axis &axis );
        
        // Check if a joystick button is pressed
        static bool IsPressed( const unsigned int &joystick, const unsigned int &button);
        
        // Get the current position of a joystick axis
        static float GetAxisPosition( const unsigned int &joystick, const Axis &axis);
        
        
    };
}
