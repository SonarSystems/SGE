#include "pch.hpp"

namespace Sonar
{
	Texture::Texture( )
	{ _texture = new sf::Texture( ); }

    Texture::Texture( const std::string &filepath )
	{
		_texture = new sf::Texture( );
		_texture->loadFromFile( filepath );
	}

	Texture::~Texture( )
	{
		delete _texture;
		_texture = nullptr;
	}

	void Texture::SetTexture( const std::string &filepath )
	{ _texture->loadFromFile( filepath ); }

	void Texture::SetTexture( const Texture &texture )
	{ _texture = texture.GetTexture( ); }

	sf::Texture *Texture::GetTexture( ) const
	{ return _texture; }

	glm::vec2 Texture::GetSize( ) const
	{ return glm::vec2( _texture->getSize( ).x, _texture->getSize( ).y ); }

	void Texture::SetRepeated( const bool &repeated )
	{ _texture->setRepeated( repeated ); }

	bool Texture::IsRepeated( ) const
	{ return _texture->isRepeated( ); }

}

