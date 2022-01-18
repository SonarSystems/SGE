#include "pch.hpp"

namespace Sonar
{
	void AssetManager::LoadTexture( const std::string &name, const std::string &fileName )
	{ _textures[name] = Texture( fileName); }

	const Texture &AssetManager::GetTexture( const std::string &name ) const
	{ return this->_textures.at( name ); }

	void AssetManager::LoadFont( const std::string &name, const std::string &fileName )
    { this->_fonts[name] = Font( fileName ); }

    const Font &AssetManager::GetFont( const std::string &name ) const
    { return _fonts.at( name ); }

    void AssetManager::LoadSound( const std::string &name, const std::string &fileName )
    {
        Sound s( fileName );
        _sounds[name] = s;
    }

    Sound &AssetManager::GetSound( const std::string &name )
    { return _sounds.at( name ); }

    void AssetManager::LoadMusic( const std::string &name, const std::string &fileName )
    { this->_musics[name].LoadFile( fileName ); }

    const Music &AssetManager::GetMusic( const std::string &name ) const
    { return _musics.at( name ); }
}
