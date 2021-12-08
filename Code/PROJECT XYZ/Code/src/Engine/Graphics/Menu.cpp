#include "pch.hpp"

namespace Sonar
{
	Menu::Menu( GameDataRef data ) : _data( data )
	{ _theme = DEFAULT_MENU_THEME; }

	Menu::~Menu( ) { }

	void Menu::Draw( )
	{
		for ( const auto &component : _menuComponents )
		{ component->Draw( ); }
	}

	void Menu::Update( const float &dt )
	{
		for ( const auto &component : _menuComponents )
		{ component->Update( dt ); }
	}

	void Menu::PollInput( const float &dt, const Event &event )
	{
		for ( const auto &component : _menuComponents )
		{ component->PollInput( dt, event ); }
	}

	void Menu::AddComponent( std::shared_ptr<MenuComponent> component, const bool &overrideStyle )
	{
		if ( overrideStyle )
		{ component->SetTheme( _theme ); }

		_menuComponents.push_back( component );
	}

	void Menu::RemoveComponent( std::shared_ptr<MenuComponent> component )
	{
		std::vector<std::shared_ptr<MenuComponent> > newMenuComponentsVector( _menuComponents.size( ) );

		std::remove_copy( _menuComponents.begin( ), _menuComponents.end( ), newMenuComponentsVector.begin( ), component );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_menuComponents = newMenuComponentsVector;
		}
	}

	void Menu::RemoveComponent( const unsigned int &index )
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

	void Menu::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		ResetThemeForAllComponents( );
	}

	void Menu::ResetThemeForAllComponents( )
	{
		for ( auto component : _menuComponents )
		{ component->SetTheme( _theme ); }
	}

	const Sonar::MenuComponent::Theme &Menu::GetTheme( ) const
	{ return _theme; }
}

