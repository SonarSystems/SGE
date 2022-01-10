#pragma once

namespace Sonar
{
    class Sound : public AudioItem
    {
    public:
        /**
         * \brief Class constructor with sound filepath
         *
         * \param filepath Filepath of the sound file
        */
        Sound( const std::string &filepath );
        
        /**
         * \brief Class destructor
        */
        ~Sound( );

    private:
        /**
         * \brief Backend SFML music object
        */
        sf::Sound _sound;

        sf::SoundBuffer _buffer;
        
    };
}
