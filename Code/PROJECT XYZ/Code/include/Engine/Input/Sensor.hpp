#pragma once

namespace Sonar
{
    class Sensor
    {
    public:
        /**
         * \brief Types supported by the Sensor system
        */
        enum Type
        {
            Accelerometer,    ///< Measures the raw acceleration (m/s^2)
            Gyroscope,        ///< Measures the raw rotation rates (degrees/s)
            Magnetometer,     ///< Measures the ambient magnetic field (micro-teslas)
            Gravity,          ///< Measures the direction and intensity of gravity, independent of device acceleration (m/s^2)
            UserAcceleration, ///< Measures the direction and intensity of device acceleration, independent of the gravity (m/s^2)
            Orientation,      ///< Measures the absolute 3D orientation (degrees)

            Count             ///< Keep last -- the total number of sensor types
        };
    };
}
