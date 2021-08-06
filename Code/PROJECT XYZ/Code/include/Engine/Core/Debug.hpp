#pragma once

#define SPDLOG_EOL "\n"
#include <spdlog/spdlog.h>

// Starting state of the Debug system, true being enabled and false being disabled
#define START_STATE true
#define PHYSICS_START_STATE true

namespace Sonar
{
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
        * \brief Get the singleton instance (create one if it hasn't been already)
        *
        * \return Output returns the singleton instance
        */
        static Debug *getInstance();

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
        bool IsEnabled( ) const;

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
        bool IsPhysicsEnabled( ) const;
        
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
        bool IsCategoryEnabled( const std::string &category );

        /**
        * \brief Gets all the categories
        *
        * \return Output returns a vector of all the categories
        */
        std::vector<std::pair<std::string, bool>> GetCategories( ) const;

        /**
        * \brief Convert a string to lower case
        *
        * \param string String to be converted to lower case
        *
        * \return Output returns lower case value of a string
        */
        std::string Debug::ToLower( std::string string );

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
        const SystemInformation &GetSystemInformation( ) const;

        /**
        * \brief Get the frame data
        *
        * \return Output returns the frame data
        */
        const FrameData &GetFrameData( ) const;

        void ShowExampleAppSimpleOverlay( bool *p_open );
        
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
        
    };
}
