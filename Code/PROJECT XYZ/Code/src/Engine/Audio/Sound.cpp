#include "pch.hpp"

namespace Sonar
{
	Sound::Sound( const std::string &filepath ) : AudioItem( )
	{
		LoadFile( filepath );
		_buffer.loadFromFile( filepath );
		_sound.setBuffer( _buffer );

		_object = &_sound;
	}

	Sound::~Sound( ) { }

	const Time &Sound::GetLength( ) const
	{ return Time( _sound.getDuration( ).asMicroseconds( ) ); }
}

