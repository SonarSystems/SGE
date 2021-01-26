#pragma once

#include <fstream>
#include <iostream>
#include <String>
#include <filesystem>

namespace Sonar
{
	class FileManager
	{
	public:
		/**
		* \brief How should the data be written to the file
		*/
		enum WRITE_PROPERTY
		{
			ADD_TO_NEW_LINE = 0,
			ADD_TO_CURRENT_LINE
		};

		/**
		* \brief Status of the file
		*/
		enum FILE_STATUS
		{
			OPEN = 0,
			UNKNOWN_ERROR,
			IS_FOLDER_NOT_A_FILE,
			CLOSED,
			DOESNT_EXIST
		};

		/**
		 * \brief Default class constructor
		*/
		FileManager( );

		/**
		 * \brief Class destructor
		*/
		~FileManager( );

		/**
		* \brief Get the status of the file
		*
		* \return Output returns the file status
		*/
		FILE_STATUS GetStatus( );

		/**
		* \brief Open a file
		*
		* \param filepath Variable description
		* \param createIfDoesntExist [OPTIONAL] Creates the file if it doesn't exist
		* \param overwriteIfExists [OPTIONAL] Overwrites the file if it exists
		*/
		void OpenFile( const std::string &filepath, const bool &createIfDoesntExist = true, const bool &overwriteIfExists = false );

		/**
		* \brief Close the open file
		*/
		void CloseFile( );

		/**
		* \brief Write to the open file
		*
		* \param data Data to be written
		* \param writeProperty [OPTIONAL] Property dictating how to write to the file (default adds the data to a new line)
		*/
		void WriteToFile( const std::string &data, const WRITE_PROPERTY &writeProperty = WRITE_PROPERTY::ADD_TO_NEW_LINE );


	private:
		/**
		* \brief File
		*/
		std::fstream file;

		/**
		* \brief File status (default is CLOSED)
		*/
		FILE_STATUS fileStatus;

	};
}
