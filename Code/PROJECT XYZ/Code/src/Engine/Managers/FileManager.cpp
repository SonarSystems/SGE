#include "Managers/FileManager.hpp"

namespace Sonar
{
	FileManager::FileManager( )
	{ fileStatus =FILE_STATUS::CLOSED; }

	FileManager::~FileManager( ) { }

	Sonar::FileManager::FILE_STATUS FileManager::GetStatus( )
	{ return fileStatus; }

	void FileManager::OpenFile( const std::string &filepath, const bool &createIfDoesntExist /*= true */, const bool &overwriteIfExists /*= false*/ )
	{
		if ( !std::filesystem::exists( filepath ) && !createIfDoesntExist )
		{
			fileStatus = FILE_STATUS::DOESNT_EXIST;

			return;
		}

		if ( !std::filesystem::is_directory( std::filesystem::status( filepath ) ) )
		{
			if ( overwriteIfExists )
			{ file.open( filepath, std::ios::trunc ); }
			else
			{ file.open( filepath, std::ios::binary | std::ios::app ); }

			if ( file.is_open( ) )
			{ fileStatus = FILE_STATUS::OPEN; }
			else
			{ fileStatus = FILE_STATUS::UNKNOWN_ERROR; }
		}
		else
		{ fileStatus = FILE_STATUS::IS_FOLDER_NOT_A_FILE; }
	}

	void FileManager::CloseFile( )
	{ file.close( ); }

	void FileManager::WriteToFile( const std::string &data, const WRITE_PROPERTY &writeProperty /*= WRITE_PROPERTY::ADD_TO_NEW_LINE */ )
	{
		if ( file.is_open( ) )
		{
			switch ( writeProperty )
			{
				case WRITE_PROPERTY::ADD_TO_NEW_LINE:
					file << "\n" << data;
					break;

				case WRITE_PROPERTY::ADD_TO_CURRENT_LINE:
					file << data;
					break;
			}
		}
	}

}
