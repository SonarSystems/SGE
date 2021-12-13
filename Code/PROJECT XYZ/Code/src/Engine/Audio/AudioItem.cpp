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

	const Sonar::AUDIO_STATUS &AudioItem::GetStatus( ) const
	{ return ( AUDIO_STATUS )_object->getStatus( ); }

	void Drawable::SetPosition( const glm::vec2 &position )
	{ _position = position; }

    void Drawable::SetPosition( const float &x, const float &y )
    {
        _position.x = x;
        _position.y = y;
    }

	void Drawable::SetPositionX( const float &x )
    { _position.x = x; }

    void Drawable::SetPositionY( const float &y )
    { _position.y = y; }

    float Drawable::GetPositionX( const OBJECT_POINTS &point ) const
    { return GetPosition( point ).x; }

    float Drawable::GetPositionY( const OBJECT_POINTS &point ) const
	{ return GetPosition( point ).y; }

    glm::vec2 Drawable::GetPosition( const OBJECT_POINTS &point ) const
    {
		switch ( point )
		{
			case OBJECT_POINTS::CENTER:
				return glm::vec2( _position.x + ( _size.x * 0.5 ), _position.y + ( _size.y * 0.5 ) );
				break;

			case OBJECT_POINTS::TOP_RIGHT:
				return glm::vec2( _position.x + _size.x, _position.y );
				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				return glm::vec2( _position.x + _size.x, _position.y + _size.y );
				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				return glm::vec2( _position.x, _position.y + _size.y );
				break;

			case OBJECT_POINTS::TOP_LEFT:
			default:
				return _position;
				break;
		}
	}

	void Drawable::Move( const glm::vec2 &offset )
	{ _position += offset; }

	void Drawable::Move( const float &x, const float &y )
    {
        _position.x += x;
        _position.y += y;
    }

	void Drawable::MoveX( const float &x )
    { _position.x += x; }

    void Drawable::MoveY( const float &y )
    { _position.y += y; }
}

