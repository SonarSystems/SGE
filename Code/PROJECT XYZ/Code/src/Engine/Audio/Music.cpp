#include "pch.hpp"

namespace Sonar
{
	Music::Music( const std::string &filepath ) : AudioItem( )
	{
		LoadFile( filepath );
		_music.openFromFile( filepath );

		_object = &_music;
	}

	Music::~Music( ) { }

	const Time &Music::GetLength( ) const
	{ return Time( _music.getDuration( ).asMicroseconds( ) ); }
}

