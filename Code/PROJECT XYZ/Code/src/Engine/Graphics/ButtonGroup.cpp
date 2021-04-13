#include "Graphics/ButtonGroup.hpp"

namespace Sonar
{
	ButtonGroup::ButtonGroup( GameDataRef data ) : _data( data )
	{
		_currentIndex = 0;
	}

	ButtonGroup::~ButtonGroup( ) { }

	void ButtonGroup::Draw( )
	{
		for ( auto &button : _buttons )
		{ button->Draw( ); }
	}

	void ButtonGroup::Update( const float &dt )
	{
		for ( int i = 0; i < _buttons.size( ); i++ )
		{ _buttons.at( i )->Update( dt ); }
	}

	void ButtonGroup::AddButton( Button *button, const bool &overrideStyle )
	{
		if ( overrideStyle )
		{ button->SetTheme( _theme ); }

		_buttons.push_back( button );
	}

	void ButtonGroup::RemoveButton( Button *button )
	{
		std::vector<Button *> newMenuComponentsVector( _buttons.size( ) );

		std::remove_copy( _buttons.begin( ), _buttons.end( ), newMenuComponentsVector.begin( ), button );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_buttons = newMenuComponentsVector;
		}
	}

	void ButtonGroup::RemoveButton( const int &index )
	{
		if ( index < _buttons.size( ) )
		{ _buttons.erase( _buttons.begin( ) + index ); }
	}

	void ButtonGroup::RemoveFirstButton( )
	{
		if ( 0 < _buttons.size( ) )
		{ _buttons.erase( _buttons.begin( ) ); }
	}

	void ButtonGroup::RemoveLastButton( )
	{
		if ( _buttons.size( ) > 0 )
		{ _buttons.erase( _buttons.end( ) - 1 ); }
	}

	unsigned int ButtonGroup::GetSize( ) const
	{ return _buttons.size( ); }

	void ButtonGroup::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		for ( auto &button : _buttons )
		{ button->SetTheme( theme ); }
	}

	void ButtonGroup::MoveUp( const bool &cycleDown, const unsigned int &moveAmount )
	{
		if ( _currentIndex - moveAmount >= 0 )
		{
			//menu[selectedItemIndex].setColor( sf::Color::White );
			_currentIndex -= moveAmount;
			UpdateButtons( );
			//menu[selectedItemIndex].setColor( sf::Color::Red );
		}
	}

	void ButtonGroup::MoveDown( const bool &cycleUp, const unsigned int &moveAmount )
	{
		if ( _currentIndex + moveAmount < _buttons.size( ) )
		{
			//menu[selectedItemIndex].setColor( sf::Color::White );
			_currentIndex += moveAmount;
			UpdateButtons( );
			//menu[selectedItemIndex].setColor( sf::Color::Red );
		}
	}

	void ButtonGroup::JumpToIndex( const unsigned int &index )
	{
		if ( index < _buttons.size( ) )
		{
			_currentIndex = index;
		}
	}

	unsigned int ButtonGroup::GetCurrentIndex( ) const
	{ return _currentIndex; }

	void ButtonGroup::UpdateButtons( )
	{

	}
}

