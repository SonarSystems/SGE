#include "Managers/FileManager.hpp"

namespace Sonar
{
	FileManager::FileManager( )
	{ _fileStatus =FILE_STATUS::CLOSED; }

	FileManager::~FileManager( ) { }

	Sonar::FileManager::FILE_STATUS FileManager::GetStatus( )
	{ return _fileStatus; }

	void FileManager::OpenFile( const std::string &filepath, const ACCESS_METHOD &accessMethod, const bool &createIfDoesntExist /*= true*/, const bool &overwriteIfExists /*= false */ )
	{
		_accessMethod = accessMethod;

		if ( !std::filesystem::exists( filepath ) && !createIfDoesntExist )
		{
			_fileStatus = FILE_STATUS::DOESNT_EXIST;

			return;
		}

		if ( !std::filesystem::is_directory( std::filesystem::status( filepath ) ) )
		{
			char bitmaskIO;

			if ( ACCESS_METHOD::READING == accessMethod )
			{ bitmaskIO = std::ios::in; }
			else
			{ bitmaskIO = std::ios::out; }

			if ( overwriteIfExists )
			{ _file.open( filepath, std::ios::trunc | bitmaskIO ); }
			else
			{ _file.open( filepath, std::ios::binary | std::ios::app | bitmaskIO ); }

			if ( _file.is_open( ) )
			{ _fileStatus = FILE_STATUS::OPEN; }
			else
			{ _fileStatus = FILE_STATUS::UNKNOWN_ERROR; }
		}
		else
		{ _fileStatus = FILE_STATUS::IS_FOLDER_NOT_A_FILE; }

		if ( ACCESS_METHOD::READING == accessMethod )
		{
			std::string lineData;

			while ( std::getline( _file, lineData ) )
			{ _fileData.push_back( lineData ); }
		}
	}

	void FileManager::CloseFile( )
	{ _file.close( ); }

	void FileManager::WriteToFile( const std::string &data, const WRITE_PROPERTY &writeProperty /*= WRITE_PROPERTY::ADD_TO_NEW_LINE */ )
	{
		if ( ACCESS_METHOD::WRITING == _accessMethod )
		{
			if ( _file.is_open( ) )
			{
				switch ( writeProperty )
				{
					case WRITE_PROPERTY::ADD_TO_NEW_LINE:
						_file << "\n" << data;
						break;

					case WRITE_PROPERTY::ADD_TO_CURRENT_LINE:
						_file << data;
						break;
				}

				_file.flush( );
			}
		}
	}

	void FileManager::WriteToFile( const std::vector<std::string> &data, const WRITE_PROPERTY &writeProperty /*= WRITE_PROPERTY::ADD_TO_NEW_LINE */ )
	{
		if ( ACCESS_METHOD::WRITING == _accessMethod )
		{
			if ( _file.is_open( ) )
			{
				for ( auto &line : data )
				{
					switch ( writeProperty )
					{
						case WRITE_PROPERTY::ADD_TO_NEW_LINE:
							_file << "\n" << line;
							break;

						case WRITE_PROPERTY::ADD_TO_CURRENT_LINE:
							_file << line;
							break;
					}
				}

				_file.flush( );
			}
		}
	}

	std::vector<std::string> FileManager::GetFileContents( )
	{ return _fileData; }

	std::string FileManager::GetLineFromFile( const unsigned int &lineNumber )
	{
		for ( unsigned int i = 0; i < _fileData.size( ); i++ )
		{
			if ( lineNumber == i )
			{ return _fileData.at( i ); }
		}

		return "";
	}

}
