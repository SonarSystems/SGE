#include "pch.hpp"

namespace Sonar
{
	Sound::Sound( const std::string &filepath ) : AudioItem( AUDIO_TYPE::SOUND )
	{
		LoadFile( filepath );
		_buffer.loadFromFile( filepath );
		_sound.setBuffer( _buffer );

		_soundObject = &_sound;
	}

	Sound::~Sound( ) { }
}

