#pragma once

#include <Graphics/Texture.hpp>
#include <Graphics/Font.hpp>
#include <Audio/Sound.hpp>
#include <Audio/Music.hpp>

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
		[[nodiscard]] const Texture &GetTexture( const std::string &name ) const;

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
		[[nodiscard]] const Font &GetFont( const std::string &name ) const;

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
		[[nodiscard]] Sound &GetSound( const std::string &name );

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
		[[nodiscard]] const Music &GetMusic( const std::string &name ) const;

	private:
		/**
		 * \brief Textures map
		*/
		std::map<std::string, Texture> _textures;

		/**
		 * \brief Fonts map
		*/
		std::map<std::string, Font> _fonts;

		/**
		 * \brief Sounds map
		*/
		std::map<std::string, Sound> _sounds;

		/**
		 * \brief Musics map
		*/
		std::map<std::string, Music> _musics;

	};
}
