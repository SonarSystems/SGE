#pragma once

#include <External/glm/glm.hpp>
#include <spdlog/spdlog.h>

#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Time.hpp"
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
		* \brief Set all the map spaces with a specific value
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
		void SetValue( const char &value, const int &posX, const int &posY );

		/**
		* \brief Get a map value at a specific position
		*
		* \param posX X position in the map
		* \param posY Y position in the map
		*
		* \return Output returns a map value
		*/
		char GetValue( const int &posX, const int &posY ) const;

		/**
		* \brief Save the map array
		*
		* \param filePath File path of the file
		*/
		void SaveMap( const std::string &filepath );

		LOADFILE

	private:
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
