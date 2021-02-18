#include "Graphics/Menu.hpp"

namespace Sonar
{
	Menu::Menu( GameDataRef data ) : _data( data ) { }

	Menu::~Menu( ) { }

	void Menu::AddComponent(  MenuComponent *component )
	{ _menuComponents.push_back( component ); }

	void Menu::Draw( )
	{
		for ( auto component : _menuComponents )
		{ component->Draw( ); }
	}
}

