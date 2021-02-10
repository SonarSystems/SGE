#include "Managers/MapManager.hpp"

namespace Sonar
{
	MapManager::MapManager( const int &arraySizeX, const int &arraySizeY )
	{
		_arraySize[0] = arraySizeX;
		_arraySize[1] = arraySizeY;

		_map = new char *[arraySizeY];

		for ( int i = 0; i < arraySizeY; i++ )
		{ _map[i] = new char[arraySizeX]; }

		for ( int y = 0; y < arraySizeY; y++ )
		{
			for ( int x = 0; x < arraySizeX; x++ )
			{ _map[y][x] = ' '; }
		}
	}

	MapManager::~MapManager( )
	{ DeleteMapPointer( ); }

	void MapManager::InitializeMapWithAValue( const char &value )
	{
		for ( int y = 0; y < _arraySize[1]; y++ )
		{
			for ( int x = 0; x < _arraySize[0]; x++ )
			{ _map[y][x] = value; }
		}
	}

	void MapManager::SetValue( const char &value, const int &posX, const int &posY )
	{
		if ( posX < _arraySize[0] && posY < _arraySize[1] )
		{ _map[posY][posX] = value; }
	}

	char MapManager::GetValue( const int &posX, const int &posY ) const
	{
		if ( posX < _arraySize[0] && posY < _arraySize[1] )
		{ return _map[posY][posX]; }
		else
		{ return ' '; }
	}

	void MapManager::SaveMap( const std::string &filepath )
	{
		std::string mapCSV = "";

		for ( int y = 0; y < _arraySize[1]; y++ )
		{
			for ( int x = 0; x < _arraySize[0]; x++ )
			{
				mapCSV += _map[x][y];

				if ( !( y + 1 == _arraySize[1] && x + 1 == _arraySize[0] ) )
				{ mapCSV += ","; }
			}

			mapCSV += "\n";
		}

		FileManager fileManager;

		fileManager.WriteToFile( filepath, mapCSV, FileManager::WRITE_PROPERTY::ADD_TO_CURRENT_LINE, true, true );
	}

	void MapManager::LoadMap( const std::string &filepath )
	{
		DeleteMapPointer( );

		FileManager fileManager;

		csv::CSVFormat csvFormat;
		csvFormat.no_header( );

		csv::CSVReader *reader = new csv::CSVReader( filepath, csvFormat );

		for ( csv::CSVRow &row : *reader ) { }

		_arraySize.y = reader->n_rows( ) + 1;

		reader = new csv::CSVReader( filepath, csvFormat );

		int x = 0, y = 0;

		_map = new char *[_arraySize.y];

		for ( csv::CSVRow &row : *reader )
		{
			x = 0;

			std::vector<char> allCharsInARow;

			for ( csv::CSVField &field : row )
			{
				const std::string strValue = field.get<>( );

				if ( "" != strValue )
				{
					allCharsInARow.push_back( strValue[0] );
					x++;
				}
			}
			
			_map[y] = new char[x];

			for ( int i = 0; i < allCharsInARow.size( ); i++ )
			{ _map[y][i] = allCharsInARow.at( i ); }

			y++;
		}

		_arraySize.x = x;
	}

	glm::uvec2 MapManager::GetSize( ) const
	{ return _arraySize; }

	unsigned int MapManager::GetSizeX( ) const
	{ return _arraySize.x; }

	unsigned int MapManager::GetSizeY( ) const
	{ return _arraySize.y; }

	void MapManager::DeleteMapPointer( )
	{ delete _map; }
}
