#pragma once

#include <External/glm/glm.hpp>
#include <spdlog/spdlog.h>

#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Time.hpp"
#include "External/csv.hpp"
#include "Managers/FileManager.hpp"

namespace Sonar
{
	class MapManager
	{
	public:
		/**
		 * \brief Default class constructor
		*/
		MapManager( const int &arraySizeX, const int &arraySizeY );

		/**
		 * \brief Class destructor
		*/
		~MapManager( );

		/**
		* \brief Set all the map spaces with a specific value (overrides the entire map)
		*
		* \param value Value to be inserted in the map
		*/
		void InitializeMapWithAValue( const char &value );

		/**
		* \brief Set a map value at a specific position
		*
		* \param value Value to be inserted in the map
		* \param posX X position in the map
		* \param posY Y position in the map
		*/
		void SetValue( const char &value, const unsigned int &posX, const unsigned int &posY );

		/**
		* \brief Get a map value at a specific position
		*
		* \param posX X position in the map
		* \param posY Y position in the map
		*
		* \return Output returns a map value
		*/
		char GetValue( const unsigned int &posX, const unsigned int &posY ) const;

		/**
		* \brief Save the map array
		*
		* \param filePath File path of the file
		*/
		void SaveMap( const std::string &filepath );

		/**
		* \brief Load the map array
		*
		* \param filePath File path of the file
		*/
		void LoadMap( const std::string &filepath );

		/**
		* \brief Get the map size
		*
		* \return Output returns the map size
		*/
		glm::uvec2 GetSize( ) const;

		/**
		* \brief Get the map size x
		*
		* \return Output returns the map size x
		*/
		unsigned int GetSizeX( ) const;

		/**
		* \brief Get the map size y
		*
		* \return Output returns the map size y
		*/
		unsigned int GetSizeY( ) const;

	private:
		/**
		* \brief Delete the map pointer
		*/
		void DeleteMapPointer( );

		/**
		* \brief 2D map of dynamic size
		*/
		char **_map;

		/**
		* \brief Size of the 2D map
		*/
		glm::uvec2 _arraySize;

	};
}
