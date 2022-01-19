#include "pch.hpp"

namespace Sonar
{
	void AssetManager::LoadTexture( const std::string &name, const std::string &fileName )
	{ _textures[name] = std::make_shared<Texture>( fileName); }

	Texture &AssetManager::GetTexture( const std::string &name ) const
	{ return *_textures.at( name ); }

	void AssetManager::LoadFont( const std::string &name, const std::string &fileName )
    { _fonts[name] = std::make_shared<Font>( fileName ); }

    Font &AssetManager::GetFont( const std::string &name ) const
    { return *_fonts.at( name ); }

    void AssetManager::LoadSound( const std::string &name, const std::string &fileName )
    { _sounds[name] = std::make_shared<Sound>( fileName ); }

    Sound &AssetManager::GetSound( const std::string &name ) const
    { return *_sounds.at( name ); }

    void AssetManager::LoadMusic( const std::string &name, const std::string &fileName )
    { _musics[name] = std::make_shared<Music>( fileName ); }

    Music &AssetManager::GetMusic( const std::string &name ) const
    { return *_musics.at( name ); }
}
