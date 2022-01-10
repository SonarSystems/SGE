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

        /**
        * \brief Get the audio files channel count
        */
        [[nodiscard]] const unsigned int &GetChannelCount( ) const;

        /**
        * \brief Get the audio files sample rate
        */
        [[nodiscard]] const unsigned int &GetSampleRate( ) const;

        /**
        * \brief Get the current time that has been played
        *
        * \param denomination Get playing position in microseconds, milliseconds or seconds
        * 
        * \return Output returns the playing position (default in seconds)
        */
        [[nodiscard]] const float &GetPlayingPosition( const Time::DENOMINATION &denomination = Time::DENOMINATION::SECONDS ) const;

        /**
        * \brief Forward the audio item
        *
        * \param displacement Amount to forward (defaultin seconds)
        * \param denomination Is the displacement in microseconds, milliseconds or seconds
        */
        void Forward( const unsigned int &displacement, const Time::DENOMINATION &denomination = Time::DENOMINATION::SECONDS );

        /**
        * \brief Rewind the audio item
        *
        * \param displacement Amount to rewind (default in seconds)
        * \param denomination Is the displacement in microseconds, milliseconds or seconds
        */
        void Rewind( const unsigned int &displacement, const Time::DENOMINATION &denomination = Time::DENOMINATION::SECONDS );

        /**
        * \brief Enable looping
        */
        void EnableLooping( );

        /**
        * \brief Disable looping
        */
        void DisableLooping( );

        /**
        * \brief Toggle looping
        */
        void ToggleLooping( );

        /**
        * \brief Is the audio item looping
        *
        * \return Output returns the looping status
        */
        [[nodiscard]] const bool &IsLooping( );

    private:
        /**
         * \brief Backend SFML music object
        */
        sf::Music _music;
        
    };
}
