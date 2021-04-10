#include "Graphics/Menu.hpp"

namespace Sonar
{
	Menu::Menu( GameDataRef data ) : _data( data ) { }

	Menu::~Menu( ) { }

	void Menu::Draw( )
	{
		for ( auto component : _menuComponents )
		{ component->Draw( ); }
	}

	void Menu::Update( const float &dt )
	{
		for ( auto component : _menuComponents )
		{ component->Update( dt ); }
	}

	void Menu::AddComponent( MenuComponent * component )
	{ _menuComponents.push_back( component ); }

	void Menu::RemoveComponent( MenuComponent *component )
	{
		std::vector<MenuComponent *> newMenuComponentsVector( _menuComponents.size( ) );

		std::remove_copy( _menuComponents.begin( ), _menuComponents.end( ), newMenuComponentsVector.begin( ), component );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_menuComponents = newMenuComponentsVector;
		}
	}

	void Menu::RemoveComponent( const int &index )
	{
		if ( index < _menuComponents.size( ) )
		{ _menuComponents.erase( _menuComponents.begin( ) + index ); }
	}

	void Menu::RemoveFirstComponent( )
	{
		if ( 0 < _menuComponents.size( ) )
		{ _menuComponents.erase( _menuComponents.begin( ) ); }
	}

	void Menu::RemoveLastComponent( )
	{
		if ( _menuComponents.size( ) > 0 )
		{ _menuComponents.erase( _menuComponents.end( ) - 1 ); }
	}
}

