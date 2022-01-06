#include "pch.hpp"

namespace Sonar
{
	void AudioItem::LoadFile( const std::string &filepath )
	{ _filepath = filepath; }

	const std::string &AudioItem::GetFilepath( ) const
	{ return _filepath; }

	void AudioItem::Play( )
	{
		if ( _isMusic )
		{ _musicObject->play( ); }
		else
		{ _soundObject->play( ); }
	}

	void AudioItem::Pause( )
	{
		if ( _isMusic )
		{ _musicObject->pause( ); }
		else
		{ _soundObject->pause( ); }		
	}

	void AudioItem::Stop( )
	{
		if ( _isMusic )
		{ _musicObject->stop( ); }
		else
		{ _musicObject->stop( ); }
	}

	void AudioItem::Restart( )
	{
		if ( _isMusic )
		{
			_musicObject->stop( );
			_musicObject->play( );
		}
		else
		{
			_soundObject->stop( );
			_soundObject->play( );
		}
	}

	void AudioItem::SetVolume( const float &volume )
	{
		if ( _isMusic )
		{ _musicObject->setVolume( volume ); }
		else
		{ _soundObject->setVolume( volume ); }
	}

	const float AudioItem::GetVolume( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getVolume( );
	}

	const unsigned int &AudioItem::GetChannelCount( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getChannelCount( );
	}

	const unsigned int &AudioItem::GetSampleRate( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getSampleRate( );
	}

	void AudioItem::SetPitch( const float &pitch )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPitch( pitch );
	}

	const float &AudioItem::GetPitch( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getPitch( );
	}

	const Sonar::AUDIO_STATUS &AudioItem::GetStatus( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return ( AUDIO_STATUS )_musicObject->getStatus( );
	}

	const float &AudioItem::GetPlayingPosition( const Time::DENOMINATION &denomination ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				return _musicObject->getPlayingOffset( ).asMicroseconds( );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				return _musicObject->getPlayingOffset( ).asMilliseconds( );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				return _musicObject->getPlayingOffset( ).asSeconds( );

				break;
		}
		
	}

	void AudioItem::Forward( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		sf::Time time;

		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				time = sf::microseconds( displacement );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				time = sf::milliseconds( displacement );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				time = sf::seconds( displacement );

				break;
		}

		_musicObject->setPlayingOffset( _musicObject->getPlayingOffset( ) + time );
	}

	void AudioItem::Rewind( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		sf::Time time;

		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				time = sf::microseconds( displacement );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				time = sf::milliseconds( displacement );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				time = sf::seconds( displacement );

				break;
		}

		_musicObject->setPlayingOffset( _musicObject->getPlayingOffset( ) - time );
	}

	void AudioItem::SetAttenuation( const float &attenuation )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setAttenuation( attenuation );
	}

	const float &AudioItem::GetAttenuation( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getAttenuation( );
	}

	void AudioItem::EnableLooping( )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setLoop( true );
	}

	void AudioItem::DisableLooping( )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setLoop( false );
	}

	void AudioItem::ToggleLooping( )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setLoop( !_musicObject->getLoop( ) );
	}

	const bool &AudioItem::IsLooping( )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getLoop( );
	}

	void AudioItem::SetPosition( const glm::vec3 &position )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( Math::GLMvec3ToSFMLVector3F( position ) );
	}

    void AudioItem::SetPosition( const float &x, const float &y, const float &z )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( x, y, z );
	}

	void AudioItem::SetPositionX( const float &x )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( x, _musicObject->getPosition( ).y, _musicObject->getPosition( ).z );
	}

	void AudioItem::SetPositionY( const float &y )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( _musicObject->getPosition( ).x, y, _musicObject->getPosition( ).z );
	}
	
	void AudioItem::SetPositionZ( const float &z )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( _musicObject->getPosition( ).x, _musicObject->getPosition( ).y, z );
	}

    const float &AudioItem::GetPositionX( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getPosition( ).x;
	}

    const float &AudioItem::GetPositionY( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getPosition( ).y;
	}

	const float &AudioItem::GetPositionZ( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return _musicObject->getPosition( ).z;
	}

    const glm::vec3 &AudioItem::GetPosition( ) const
	{
		if ( _isMusic )
		{ }
		else
		{ }

		return Math::SFMLVector3FToGLMvec3( _musicObject->getPosition( ) );
	}

	void AudioItem::Move( const glm::vec3 &offset )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( _musicObject->getPosition( ) + Math::GLMvec3ToSFMLVector3F( offset ) );
	}

	void AudioItem::Move( const float &x, const float &y, const float &z )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject->setPosition( _musicObject->getPosition( ) + sf::Vector3f( x, y, z ) );
	}

	void AudioItem::MoveX( const float &x )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		SetPositionX( GetPositionX( ) + x );
	}

    void AudioItem::MoveY( const float &y )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		SetPositionY( GetPositionY( ) + y );
	}

	void AudioItem::MoveZ( const float &z )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		SetPositionZ( GetPositionZ( ) + z );
	}

	AudioItem::AudioItem( const AUDIO_TYPE &audioType )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		if ( AUDIO_TYPE::MUSIC == audioType )
		{ _isMusic = true; }
		else
		{ _isMusic = false; }
	}

	AudioItem::~AudioItem( )
	{
		if ( _isMusic )
		{ }
		else
		{ }

		_musicObject = NULL;
		delete _musicObject;
	}
}

