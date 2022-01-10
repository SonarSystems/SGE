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
		{ return _musicObject->getVolume( ); }
		else
		{ return _soundObject->getVolume( ); }
	}

	void AudioItem::SetPitch( const float &pitch )
	{
		if ( _isMusic )
		{ _musicObject->setPitch( pitch ); }
		else
		{ _soundObject->setPitch( pitch ); }
	}

	const float &AudioItem::GetPitch( ) const
	{
		if ( _isMusic )
		{ return _musicObject->getPitch( ); }
		else
		{ return _soundObject->getPitch( ); }
	}

	const Sonar::AUDIO_STATUS &AudioItem::GetStatus( ) const
	{
		if ( _isMusic )
		{ return ( AUDIO_STATUS )_musicObject->getStatus( ); }
		else
		{ return ( AUDIO_STATUS )_soundObject->getStatus( ); }
	}

	void AudioItem::SetAttenuation( const float &attenuation )
	{
		if ( _isMusic )
		{ _musicObject->setAttenuation( attenuation ); }
		else
		{ _soundObject->setAttenuation( attenuation ); }
	}

	const float &AudioItem::GetAttenuation( ) const
	{
		if ( _isMusic )
		{ return _musicObject->getAttenuation( ); }
		else
		{ return _soundObject->getAttenuation( ); }
	}

	void AudioItem::SetPosition( const glm::vec3 &position )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( Math::GLMvec3ToSFMLVector3F( position ) ); }
		else
		{ _soundObject->setPosition( Math::GLMvec3ToSFMLVector3F( position ) ); }
	}

    void AudioItem::SetPosition( const float &x, const float &y, const float &z )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( x, y, z ); }
		else
		{ _soundObject->setPosition( x, y, z ); }
	}

	void AudioItem::SetPositionX( const float &x )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( x, _musicObject->getPosition( ).y, _musicObject->getPosition( ).z ); }
		else
		{ _soundObject->setPosition( x, _soundObject->getPosition( ).y, _soundObject->getPosition( ).z ); }
	}

	void AudioItem::SetPositionY( const float &y )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( _musicObject->getPosition( ).x, y, _musicObject->getPosition( ).z ); }
		else
		{ _soundObject->setPosition( _soundObject->getPosition( ).x, y, _soundObject->getPosition( ).z ); }
	}
	
	void AudioItem::SetPositionZ( const float &z )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( _musicObject->getPosition( ).x, _musicObject->getPosition( ).y, z ); }
		else
		{ _soundObject->setPosition( _soundObject->getPosition( ).x, _soundObject->getPosition( ).y, z ); }	
	}

    const float &AudioItem::GetPositionX( ) const
	{
		if ( _isMusic )
		{ return _musicObject->getPosition( ).x; }
		else
		{ return _soundObject->getPosition( ).x; }
	}

    const float &AudioItem::GetPositionY( ) const
	{
		if ( _isMusic )
		{ return _musicObject->getPosition( ).y; }
		else
		{ return _soundObject->getPosition( ).y; }
	}

	const float &AudioItem::GetPositionZ( ) const
	{
		if ( _isMusic )
		{ return _musicObject->getPosition( ).z; }
		else
		{ return _soundObject->getPosition( ).z; }
	}

    const glm::vec3 &AudioItem::GetPosition( ) const
	{
		if ( _isMusic )
		{ return Math::SFMLVector3FToGLMvec3( _musicObject->getPosition( ) ); }
		else
		{ return Math::SFMLVector3FToGLMvec3( _soundObject->getPosition( ) ); }
	}

	void AudioItem::Move( const glm::vec3 &offset )
	{
		if ( _isMusic )
		{ _musicObject->setPosition( _musicObject->getPosition( ) + Math::GLMvec3ToSFMLVector3F( offset ) ); }
		else
		{ _soundObject->setPosition( _soundObject->getPosition( ) + Math::GLMvec3ToSFMLVector3F( offset ) ); }
	}

	void AudioItem::Move( const float &x, const float &y, const float &z )
	{ SetPosition( GetPositionX( ) + x, GetPositionY( ) + y, GetPositionZ( ) + z ); }

	void AudioItem::MoveX( const float &x )
	{ SetPositionX( GetPositionX( ) + x ); }

    void AudioItem::MoveY( const float &y )
	{ SetPositionY( GetPositionY( ) + y ); }

	void AudioItem::MoveZ( const float &z )
	{ SetPositionZ( GetPositionZ( ) + z ); }

	AudioItem::AudioItem( const AUDIO_TYPE &audioType )
	{
		if ( AUDIO_TYPE::MUSIC == audioType )
		{ _isMusic = true; }
		else
		{ _isMusic = false; }
	}

	AudioItem::~AudioItem( )
	{
		_musicObject = NULL;
		_soundObject = NULL;

		delete _musicObject;
		delete _soundObject;
	}
}

