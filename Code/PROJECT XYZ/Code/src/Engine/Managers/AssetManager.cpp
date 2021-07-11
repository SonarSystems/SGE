#include "pch.hpp"

namespace Sonar
{
	void AssetManager::LoadTexture( const std::string &name, const std::string &fileName )
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	const sf::Texture &AssetManager::GetTexture( const std::string &name ) const
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont( const std::string &name, const std::string &fileName )
    {
        sf::Font font;

        if (font.loadFromFile(fileName))
        {
            this->_fonts[name] = font;
        }
    }

    const sf::Font &AssetManager::GetFont( const std::string &name ) const
    {
        return this->_fonts.at(name);
    }

    void AssetManager::LoadSound( const std::string &name, const std::string &fileName )
    {
        sf::SoundBuffer buffer;
        
        if (buffer.loadFromFile(fileName))
        {
            this->_sounds[name] = buffer;
        }
    }

    const sf::Sound &AssetManager::GetSound( const std::string &name ) const
    {
        static sf::Sound sound;
        
        sound.setBuffer(this->_sounds.at(name));
        
        return sound;
    }

    void AssetManager::LoadMusic( const std::string &name, const std::string &fileName )
    {
        sf::Music music;
                
        if (music.openFromFile(fileName))
        {
            this->_musics[name].openFromFile(fileName);
        }
    }

    const sf::Music &AssetManager::GetMusic( const std::string &name ) const
    {
        return _musics.at(name);
    }
}
