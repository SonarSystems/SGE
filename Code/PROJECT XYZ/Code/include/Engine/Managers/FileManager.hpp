#pragma once

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
			NOT_OPENED,
			DOESNT_EXIST
		};

		/**
		* \brief How the file is to be used
		*/
		enum ACCESS_METHOD
		{
			READING = 0,
			WRITING
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
		* \brief Write to the open file
		*
		* \param filePath File path of the file
		* \param data Data to be written
		* \param writeProperty [OPTIONAL] Property dictating how to write to the file (default adds the data to a new line)
		*/
		void WriteToFile( const std::string &filepath, const std::string &data, const WRITE_PROPERTY &writeProperty = WRITE_PROPERTY::ADD_TO_NEW_LINE, const bool &createIfDoesntExist = true, const bool &overwriteIfExists = false );

		/**
		* \brief Write multiple lines to the open file
		*
		* \param filePath File path of the file
		* \param data Data to be written
		* \param writeProperty [OPTIONAL] Property dictating how to write to the file (default adds the data to a new line)
		*/
		void WriteToFile( const std::string &filepath, const std::vector<std::string> &data, const WRITE_PROPERTY &writeProperty = WRITE_PROPERTY::ADD_TO_NEW_LINE, const bool &createIfDoesntExist = true, const bool &overwriteIfExists = false );

		/**
		* \brief Get all the file's data
		*
		* \return Output returns the while file data
		*/
		std::vector<std::string> GetFileContents( const std::string &filepath );

		/**
		* \brief Get a specific line from the file (0 is the first line, last is n - 1)
		*
		* \param filePath File path of the file
		* \param lineNumber The line to get contents from (invalid line number will result in an empty string being returned)
		*
		* \return Output returns the specified line
		*/
		std::string GetLineFromFile( const std::string &filepath,const unsigned int &lineNumber );

	private:
		/**
		* \brief Open a file (call again to get updated version of the contents)
		*
		* \param filePath File path of the file
		* \param accessMethod Is the file opened for reading or writing
		* \param createIfDoesntExist [OPTIONAL] Creates the file if it doesn't exist
		* \param overwriteIfExists [OPTIONAL] Overwrites the file if it exists
		*/
		void OpenFile( const std::string &filepath, const ACCESS_METHOD &accessMethod, const bool &createIfDoesntExist = true, const bool &overwriteIfExists = false );

		/**
		* \brief Close the open file
		*/
		void CloseFile( );

		/**
		* \brief File
		*/
		std::fstream _file;

		/**
		* \brief Loaded file data stored in memory
		*/
		std::vector<std::string> _fileData;

		/**
		* \brief File status (default is CLOSED)
		*/
		FILE_STATUS _fileStatus;

		/**
		* \brief Is the file open for reading of writing
		*/
		ACCESS_METHOD _accessMethod;

	};
}
