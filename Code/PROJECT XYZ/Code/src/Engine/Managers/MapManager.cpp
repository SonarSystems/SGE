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
			{ _map[x][y] = 'a'; }
		}
	}

	MapManager::~MapManager( )
	{
		for ( int y = 0; y < _arraySize[1]; y++ )
		{ delete[] _map[y]; }

		delete[] _map;
	}

	void MapManager::InitializeMapWithAValue( const char &value )
	{
		for ( int y = 0; y < _arraySize[1]; y++ )
		{
			for ( int x = 0; x < _arraySize[0]; x++ )
			{ _map[x][y] = value; }
		}
	}

	void MapManager::SetValue( const char &value, const int &posX, const int &posY )
	{
		if ( posX < _arraySize[0] && posY < _arraySize[1] )
		{ _map[posX][posY] = value; }
	}

	char MapManager::GetValue( const int &posX, const int &posY ) const
	{
		if ( posX < _arraySize[0] && posY < _arraySize[1] )
		{ return _map[posX][posY]; }
		else
		{ return ' '; }
	}


}
