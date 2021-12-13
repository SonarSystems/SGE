#pragma once

namespace Sonar
{
    class Music
    {
    public:
        /**
         * \brief Class constructor
         *
         * \param data Game data object
        */
        Music( );
        
        /**
         * \brief Class constructor with music filepath
         *
         * \param filepath Filepath of the music file
        */
        Music( const std::string &filepath );
        
        /**
         * \brief Class destructor
        */
        ~Music( );

        

    private:
        /**
         * \brief Backend SFML music object
        */
        sf::Music _music;
        
    };
}
