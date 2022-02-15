#pragma once

#define SPDLOG_EOL "\n"
#include <spdlog/spdlog.h>

#include "Core/Clock.hpp"

// Starting state of the Debug system, true being enabled and false being disabled
#define START_STATE true
#define PHYSICS_START_STATE true

namespace Sonar
{
    /**
    * \brief Frame rate data
    */
    struct FrameData
    {
        float _FPS;
        float _frameTime; // CALCULATED AND STORED IN MILLISECONDS
        unsigned long long int _totalFrames = 0;
    };

    class Debug
    {
    public:
        /**
        * \brief DOOM style verbosity
        */
        enum Verbosity
        {
            NONE = 0,
            MINIMAL,
            MEDIUM,
            HIGH,
            SUPER_HIGH
        };

        /**
        * \brief Get the singleton instance (create one if it hasn't been already)
        *
        * \return Output returns the singleton instance
        */
        [[nodiscard]] static Debug *getInstance();

        /**
         * \brief Enable the debugger
        */
        void Enable( );
        /**
         * \brief Disable the debugger
        */
        void Disable( );
        /**
         * \brief Toggle the debugger on and off
        */
        void Toggle( );
        
        /**
         * \brief Check if the debugger is enabled
         *
         * \return Output returns true if the debugger is enabled and false if it isn't
        */
        [[nodiscard]] bool IsEnabled( ) const;

        /**
        * \brief Enable the physics debug drawing
        */
        void EnablePhysics( );
        /**
        * \brief Disable the physics debug drawing
        */
        void DisablePhysics( );
        /**
        * \brief Toggle the physics debug drawing on and off
        */
        void TogglePhysics( );

        /**
        * \brief Check if the physics debug drawing is enabled
        *
        * \return Output returns true if the physics debug drawing is enabled and false if it isn't
        */
        [[nodiscard]] bool IsPhysicsEnabled( ) const;
        
        /**
         * \brief Print a message to the terminal
         *
         * \param message Message to print
         * \param newLine Whether a new line tag should be at the end (optional, true by default)
        */
		void Log( const std::string &message, const std::string &category, const bool &newLine = true );

        /**
         * \brief Print a message to the terminal (static so isn't affected by debugger settings)
         *
         * \param message Message to print
         * \param newLine Whether a new line tag should be at the end (optional, true by default)
        */
		static void LogStatic( const std::string &message, const bool &newLine = true );

        /**
        * \brief Add a category manually
        *
		* \param category Message's category
		* \param isEnabled Is the category enabled from the start (true by default)
        */
        void AddCategory( const std::string &category, const bool &isEnabled = true );

        /**
        * \brief Remove a category manually
        *
        * \param category Message's category
        */
        void RemoveCategory( const std::string &category );

        /**
        * \brief Update an existing category if it is present
        *
        * \param category Message's category
        * \param isEnabled Is the category enabled from the start (true by default)
        */
        void UpdateCategory( const std::string &category, const bool &isEnabled );

        /**
        * \brief Check if a category is enabled
        *
        * \param category Message's category
        */
        [[nodiscard]] bool IsCategoryEnabled( const std::string &category );

        /**
        * \brief Gets all the categories
        *
        * \return Output returns a vector of all the categories
        */
        [[nodiscard]] std::vector<std::pair<std::string, bool>> GetCategories( ) const;

        /**
        * \brief Convert a string to lower case
        *
        * \param string String to be converted to lower case
        *
        * \return Output returns lower case value of a string
        */
        [[nodiscard]] std::string Debug::ToLower( std::string string );

        /**
        * \brief Update the frame data
        *
        * \param frameTime Time between frames
        */
        void UpdateFrameData( const float frameTime );

        /**
        * \brief Get the system information (CPU, Memory, GPU, OS, Motherboard stats)
        *
        * \return Output returns the system information
        */
        [[nodiscard]] const SystemInformation &GetSystemInformation( ) const;

        /**
        * \brief Get the frame data
        *
        * \return Output returns the frame data
        */
        [[nodiscard]] const FrameData &GetFrameData( ) const;

        /**
        * \brief Description
        *
		* \param pOpen Is the stats overlay open
		* \param screenSize Size of the window
		* \param verbosity How many stats should be shown
		* \param opacity Opacity of the background
        */
        void DrawComputerStats( bool *pOpen, const glm::uvec2 &windowSize, const Verbosity verbosity = Verbosity::SUPER_HIGH, const float opacity = COMPUTER_STATS_BACKGROUND_OPACITY );
        
        /**
        * \brief Enable the debug grid
        */
        void EnableGrid( );

        /**
        * \brief Disable the debug grid
        */
        void DisableGrid( );

        /**
        * \brief Toggle the debug grid
        */
        void ToggleGrid( );

        /**
        * \brief Check if the debug grid is enabled
        *
        * \return Output returns the debug grid status
        */
        [[nodiscard]] const bool IsGridEnabled( ) const;

    private:
        /**
         * \brief Class constructor
        */
        Debug( );
        
        /**
         * \brief Tracks the debugger's enabled status
        */
        bool _isEnabled;

        /**
        * \brief Tracks the physics debug drawing enabled status
        */
        bool _isPhysicsEnabled;
        
        /**
         * \brief Static class instance
        */
        static Debug *_instance;
        
        /**
        * \brief Message categories
        */
        std::vector<std::pair<std::string, bool>> _categories;

        /**
        * \brief System information object for getting well system information
        */
        SysInfo _sysInfo;

        /**
        * \brief System information
        */
        SystemInformation _systemInformation;

        /**
        * \brief Frame rate data
        */
        FrameData _frameData;

        /**
        * \brief Clock for the frame rate updating
        */
        Clock _clock, _cpuLoadClock, _graphClock;

        /**
        * \brief Points for the graphs
        */
        std::vector<float> _fpsGraphPoints, _cpuGraphPoints, _ramGraphPoints;

        /**
        * \brief Tracks the status of the grid
        */
        bool _isGridEnabled = DEFAULT_IS_DEBUG_GRID_ENABLED;
        
    };
}
