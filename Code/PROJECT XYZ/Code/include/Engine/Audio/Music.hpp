#pragma once

namespace Sonar
{
    class Music : public AudioItem
    {
    public:
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

        /**
        * \brief Get the total length of the music item 
        *
        * \return Output returns the total length
        */
        const Time &GetLength( ) const;

    private:
        /**
         * \brief Backend SFML music object
        */
        sf::Music _music;
        
    };
}
