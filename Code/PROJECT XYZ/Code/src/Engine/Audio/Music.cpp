#include "pch.hpp"

namespace Sonar
{
	Music::Music( )
	{ _filepath = ""; }

	Music::Music( const std::string &filepath )
	{
		if ( _music.openFromFile( filepath ) )
		{ _filepath = filepath; }
		else
		{ _filepath = ""; }
	}

	Music::~Music( ) { }

	
}

