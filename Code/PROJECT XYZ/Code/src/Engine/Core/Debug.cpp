#include "Debug.hpp"

namespace Sonar
{
    Debug *Debug::instance = 0;

    Debug *Debug::getInstance( )
    {
        if ( 0 == instance )
        {
            instance = new Debug( );
        }

        return instance;
    }

    Debug::Debug( )
    {
        isEnabled = START_STATE;
    }

    void Debug::Enable( )
    {
        isEnabled = true;
    }

    void Debug::Disable( )
    {
        isEnabled = false;
    }

    void Debug::Toggle( )
    {
        isEnabled = !isEnabled;
    }

    bool Debug::IsEnabled( )
    {
        return isEnabled;
    }

    void Debug::Log( std::string message, bool newLine )
    {
        if ( newLine )
        {
            std::cout << message << std::endl;
        }
        else
        {
            std::cout << message;
        }
    }
}
