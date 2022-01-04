#include "pch.hpp"

namespace Sonar
{
	void AudioItem::LoadFile( const std::string &filepath )
	{ _filepath = filepath; }

	const std::string &AudioItem::GetFilepath( ) const
	{ return _filepath; }

	void AudioItem::Play( )
	{ _object->play( ); }

	void AudioItem::Pause( )
	{ _object->pause( ); }

	void AudioItem::Stop( )
	{ _object->stop( ); }

	void AudioItem::Restart( )
	{
		_object->stop( );
		_object->play( );
	}

	void AudioItem::SetVolume( const float &volume )
	{ _object->setVolume( volume ); }

	const float AudioItem::GetVolume( ) const
	{ return _object->getVolume( ); }

	const unsigned int &AudioItem::GetChannelCount( ) const
	{ return _object->getChannelCount( ); }

	const unsigned int &AudioItem::GetSampleRate( ) const
	{ return _object->getSampleRate( ); }

	void AudioItem::SetPitch( const float &pitch )
	{ _object->setPitch( pitch ); }

	const float &AudioItem::GetPitch( ) const
	{ return _object->getPitch( ); }

	const Sonar::AUDIO_STATUS &AudioItem::GetStatus( ) const
	{ return ( AUDIO_STATUS )_object->getStatus( ); }

	const float &AudioItem::GetPlayingPosition( const Time::DENOMINATION &denomination ) const
	{
		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				return _object->getPlayingOffset( ).asMicroseconds( );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				return _object->getPlayingOffset( ).asMilliseconds( );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				return _object->getPlayingOffset( ).asSeconds( );

				break;
		}
		
	}

	void AudioItem::Forward( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
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

		_object->setPlayingOffset( _object->getPlayingOffset( ) + time );
	}

	void AudioItem::Rewind( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
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

		_object->setPlayingOffset( _object->getPlayingOffset( ) - time );
	}

	void AudioItem::SetAttenuation( const float &attenuation )
	{ _object->setAttenuation( attenuation ); }

	const float &AudioItem::GetAttenuation( ) const
	{ return _object->getAttenuation( ); }

	void AudioItem::EnableLooping( )
	{ _object->setLoop( true ); }

	void AudioItem::DisableLooping( )
	{ _object->setLoop( false ); }

	void AudioItem::ToggleLooping( )
	{ _object->setLoop( !_object->getLoop( ) ); }

	const bool &AudioItem::IsLooping( )
	{ return _object->getLoop( ); }

	void AudioItem::SetPosition( const glm::vec3 &position )
	{ _object->setPosition( Math::GLMvec3ToSFMLVector3F( position ) ); }

    void AudioItem::SetPosition( const float &x, const float &y, const float &z )
    { _object->setPosition( x, y, z ); }

	void AudioItem::SetPositionX( const float &x )
    { _object->setPosition( x, _object->getPosition( ).y, _object->getPosition( ).z ); }

	void AudioItem::SetPositionY( const float &y )
	{ _object->setPosition( _object->getPosition( ).x, y, _object->getPosition( ).z ); }
	
	void AudioItem::SetPositionZ( const float &z )
	{ _object->setPosition( _object->getPosition( ).x, _object->getPosition( ).y, z ); }

    const float &AudioItem::GetPositionX( ) const
    { return _object->getPosition( ).x; }

    const float &AudioItem::GetPositionY( ) const
	{ return _object->getPosition( ).y; }

	const float &AudioItem::GetPositionZ( ) const
	{ return _object->getPosition( ).z; }

    const glm::vec3 &AudioItem::GetPosition( ) const
    { return Math::SFMLVector3FToGLMvec3( _object->getPosition( ) ); }

	void AudioItem::Move( const glm::vec3 &offset )
	{ _object->setPosition( _object->getPosition( ) + Math::GLMvec3ToSFMLVector3F( offset ) ); }

	void AudioItem::Move( const float &x, const float &y, const float &z )
    { _object->setPosition( _object->getPosition( ) + sf::Vector3f( x, y, z ) ); }

	void AudioItem::MoveX( const float &x )
    { SetPositionX( GetPositionX( ) + x ); }

    void AudioItem::MoveY( const float &y )
	{ SetPositionY( GetPositionY( ) + y ); }

	void AudioItem::MoveZ( const float &z )
	{ SetPositionZ( GetPositionZ( ) + z ); }

	AudioItem::AudioItem( ) { }

	AudioItem::~AudioItem( )
	{
		_object = NULL;
		delete _object;
	}
}

