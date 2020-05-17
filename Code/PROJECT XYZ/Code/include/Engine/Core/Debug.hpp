#pragma once

#include <iostream>
#include <string>

// Starting state of the Debug system, true being enabled and false being disabled
#define START_STATE true

namespace Sonar
{
    class Debug
    {
    public:
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
        bool IsEnabled( );
        
        /**
         * \brief Print a message to the terminal
         *
         * \param message String to print
         * \param newLine Whether a new line tag should be at the end (optional, true by default)
        */
        void Log( std::string message, bool newLine = true );
        /**
         * \brief Print a message to the terminal (static so isn't affected by debugger settings)
         *
         * \param message String to print
         * \param newLine Whether a new line tag should be at the end (optional, true by default)
        */
        static void Print( std::string message, bool newLine = true );

        /**
         * \brief Get the singleton instance (create one if it hasn't been already)
         *
         * \return Output returns the singleton instance
        */
        static Debug *getInstance();
        
    private:
        /**
         * \brief Class constructor
        */
        Debug( );
        
        /**
         * \brief Tracks the debugger's enabled status
        */
        bool isEnabled;
        
        /**
         * \brief Static class instance
        */
        static Debug *instance;
        
        
        
    };
}
