#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Core/Debug.hpp"

namespace Sonar
{
	class AssetManager
	{
	public:
		/**
		 * \brief Default class constructor
		*/
		AssetManager( ) { }

		/**
		 * \brief Class destructor
		*/
		~AssetManager( ) { }

		/**
		 * \brief Load a texture in the engine for later use
		 *
		 * \param name Texture name (used to retrieve it)
		 * \param fileName Filepath and filename to the texture
		*/
		void LoadTexture( const std::string &name, const std::string &fileName );

		/**
		 * \brief Get a texture
		 *
		 * \param name Texture name
		 *
		 * \return Output returns the requested texture
		*/
		const sf::Texture &GetTexture( const std::string &name ) const;

		/**
		 * \brief Load a font in the engine for later use
		 *
		 * \param name Font name (used to retrieve it)
		 * \param fileName Filepath and filename to the font
		*/
		void LoadFont( const std::string &name, const std::string &fileName );

		/**
		 * \brief Get a font
		 *
		 * \param name Font name
		 *
		 * \return Output returns the requested font
		*/
		const sf::Font &GetFont( const std::string &name ) const;

		/**
		 * \brief Load a sound in the engine for later use
		 *
		 * \param name Sound name (used to retrieve it)
		 * \param fileName Filepath and filename to the sound
		*/
		void LoadSound( const std::string &name, const std::string &fileName );

		/**
		 * \brief Get a sound
		 *
		 * \param name Sound name
		 *
		 * \return Output returns the requested sound
		*/
		const sf::Sound &GetSound( const std::string &name ) const;

		/**
		 * \brief Load a music in the engine for later use
		 *
		 * \param name Music name (used to retrieve it)
		 * \param fileName Filepath and filename to the music
		*/
		void LoadMusic( const std::string &name, const std::string &fileName );

		/**
		 * \brief Get a music
		 *
		 * \param name Music name
		 *
		 * \return Output returns the requested music
		*/
		const sf::Music &GetMusic( const std::string &name ) const;

	private:
		/**
		 * \brief Textures map
		*/
		std::map<std::string, sf::Texture> _textures;

		/**
		 * \brief Fonts map
		*/
		std::map<std::string, sf::Font> _fonts;

		/**
		 * \brief Sounds map
		*/
		std::map<std::string, sf::SoundBuffer> _sounds;

		/**
		 * \brief Musics map
		*/
		std::map<std::string, sf::Music> _musics;

	};
}
