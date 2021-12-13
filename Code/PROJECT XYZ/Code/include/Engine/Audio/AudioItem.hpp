/*
* EVERY CLASS INHERITING AUDIOITEM
* Music
* Sound
*/

#pragma once

namespace Sonar
{
    enum AUDIO_STATUS
    {
        STOPPED = 0,
        PAUSED,
        PLAYING
    };

    class AudioItem
    {
    public:
        /**
        * \brief Set the music's file
        *
        * \param filepath Filepath of the music file
        */
        void LoadFile( const std::string &filepath );

        /**
        * \brief Get the filepath of the currently loaded music file
        *
        * \return Output returns the music filepath
        */
        [[nodiscard]] const std::string &GetFilepath( ) const;

        /**
        * \brief Play the audio item
        */
        void Play( );

        /**
        * \brief Pause the audio item
        */
        void Pause( );

        /**
        * \brief Stop the audio item
        */
        void Stop( );

        /**
        * \brief Restart audio item
        */
        void Restart( );

        /**
        * \brief Get the status of the audio item
        */
        const AUDIO_STATUS &GetStatus( ) const;

        // Audio class - like drawable
        /**
        * rewind (set amount in seconds)
        * forward (set amount in seconds)
        * set volume (0 - 100)
        * get volume
        * channelcount
        * sample rate
        * pitch
        * set position
        */

        /**
        * \brief Set x and y position
        *
        * \param position X and Y position
        */
        void SetPosition( const glm::vec2 &position );

        /**
        * \brief Set x and y position
        *
        * \param x X position
        * \param y Y position
        */
        void SetPosition( const float &x, const float &y );

        /**
        * \brief Set x position
        *
        * \param x X position
        */
        void SetPositionX( const float &x );

        /**
        * \brief Set y position
        *
        * \param y Y position
        */
        void SetPositionY( const float &y );

        /**
		* \brief Get the x position
		*
		* \param point Point on the object to get the position for (default is top left)
        *
        * \return Output returns the x position
        */
        [[nodiscard]] float GetPositionX( const OBJECT_POINTS &point = OBJECT_POINTS::TOP_LEFT ) const;

        /**
		* \brief Get the y position
		*
		* \param point Point on the object to get the position for (default is top left)
        *
        * \return Output returns the y position
        */
        [[nodiscard]] float GetPositionY( const OBJECT_POINTS &point = OBJECT_POINTS::TOP_LEFT ) const;

        /**
        * \brief Get the position vector
        * 
        * \param point Point on the object to get the position for (default is top left)
        *
        * \return Output returns the position vector
        */
        [[nodiscard]] glm::vec2 GetPosition( const OBJECT_POINTS &point = OBJECT_POINTS::TOP_LEFT ) const;

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param offset Offset in x and y axis
        */
        void Move( const glm::vec2 &offset );

        /**
        * \brief Move the object relative to it's current position in the x and y axis
        *
        * \param x Offset in x axis
        * \param y Offset in y axis
        */
        void Move( const float &x, const float &y );

        /**
        * \brief Move the object relative to it's current position in the x axis
        *
        * \param x Offset in x axis
        */
        void MoveX( const float &x );

        /**
        * \brief Move the object relative to it's current position in the y axis
        *
        * \param y Offset in y axis
        */
        void MoveY( const float &y );

    protected:
        /**
        * \brief Class constructor
        */
        AudioItem( );

        /**
        * \brief Class destructor
        */
        ~AudioItem( );

    private:
        /**
        * \brief Object to be listened to
        */
        sf::SoundStream *_object;

        /**
        * \brief Filepath of the music file
        */
        std::string _filepath;

    };
}
