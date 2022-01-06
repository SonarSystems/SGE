#include "pch.hpp"

namespace Sonar
{
	Music::Music( const std::string &filepath ) : AudioItem( AUDIO_TYPE::MUSIC )
	{
		LoadFile( filepath );
		_music.openFromFile( filepath );

		_musicObject = &_music;
	}

	Music::~Music( ) { }

	const Time &Music::GetLength( ) const
	{ return Time( _music.getDuration( ).asMicroseconds( ) ); }
}

