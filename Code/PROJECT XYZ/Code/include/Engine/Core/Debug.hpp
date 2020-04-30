#pragma once

#include <iostream>
#include <string>

#define START_STATE false

namespace Sonar
{
    class Debug
    {
    public:
        void Enable( );
        void Disable( );
        void Toggle( );
        
        bool IsEnabled( );
        
        void Log( std::string message, bool newLine = true );
        static void Print( std::string message, bool newLine = true );

        static Debug *getInstance();
        
    private:
        Debug( );
        
        bool isEnabled;
        
        static Debug *instance;
        
        
        
    };
}
