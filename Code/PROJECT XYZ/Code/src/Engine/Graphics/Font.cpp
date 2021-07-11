#include "pch.hpp"

namespace Sonar
{
	Font::Font( ) { }

	Font::Font( const std::string &filepath )
	{ SetFontFile( filepath ); }

	Font::~Font( ) { }

	void Font::SetFontFile( const std::string &filepath )
	{
		_filePath = filepath;

		_font.loadFromFile( _filePath );
	}

	std::string Font::GetFontFilePath( ) const
	{ return _filePath; }

	float Font::GetLineSpacing( const unsigned int &characterSize ) const
	{ return _font.getLineSpacing( characterSize ); }

	float Font::GetUnderlinePosition( const unsigned int &characterSize ) const
	{ return _font.getUnderlinePosition( characterSize ); }

	float Font::GetUnderlineThickness( const unsigned int &characterSize ) const
	{ return _font.getUnderlineThickness( characterSize ); }

	const sf::Font &Font::GetSFMLFont( ) const
	{ return _font; }
}

