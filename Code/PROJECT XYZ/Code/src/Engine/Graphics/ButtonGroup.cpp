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
		{
			if ( _currentIndex == i )
			{
				_buttons.at( i )->UpdateForButtonGroup( dt, true );
			}
			else
			{
				_buttons.at( i )->UpdateForButtonGroup( dt, false );
			}
		}

		UpdateButtons( );
	}

	void ButtonGroup::PollInput( const float &dt, const Event &event )
	{
		for ( auto &button : _buttons )
		{ button->PollInput( dt, event ); }

		if ( Event::KeyReleased == event.type )
		{
			if ( Keyboard::Up == event.key.code )
			{
				MoveUp( );

				//spdlog::info( "Up" );
			}
			else if ( Keyboard::Down == event.key.code )
			{
				MoveDown( );

				//spdlog::info( "Down" );
			}
		}
	}

	void ButtonGroup::AddButton( Button *button, const bool &overrideStyle )
	{
		if ( overrideStyle )
		{ button->SetTheme( _theme ); }

		_buttons.push_back( button );

		UpdateButtons( );
	}

	void ButtonGroup::RemoveButton( Button *button )
	{
		std::vector<Button *> newMenuComponentsVector( _buttons.size( ) );

		std::remove_copy( _buttons.begin( ), _buttons.end( ), newMenuComponentsVector.begin( ), button );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_buttons = newMenuComponentsVector;

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveButton( const int &index )
	{
		if ( index < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) + index );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveFirstButton( )
	{
		if ( 0 < _buttons.size( ) )
		{
			_buttons.erase( _buttons.begin( ) );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
	}

	void ButtonGroup::RemoveLastButton( )
	{
		if ( _buttons.size( ) > 0 )
		{
			_buttons.erase( _buttons.end( ) - 1 );

			if ( _buttons.size( ) <= _currentIndex )
			{
				_currentIndex = _buttons.size( ) - 1;

				if ( 0 > _currentIndex )
				{ _currentIndex = 0; }
			}

			UpdateButtons( );
		}
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
		if ( _currentIndex - ( int )moveAmount >= 0 )
		{
			//menu[selectedItemIndex].setColor( sf::Color::White );
			_currentIndex -= moveAmount;
			//spdlog::info( _currentIndex );
			//menu[selectedItemIndex].setColor( sf::Color::Red );
		}
		else if ( cycleDown && _buttons.size( ) > 0 )
		{ _currentIndex = _buttons.size( ) - 1; }
			
		UpdateButtons( );
	}

	void ButtonGroup::MoveDown( const bool &cycleUp, const unsigned int &moveAmount )
	{
		if ( _currentIndex + moveAmount < _buttons.size( ) )
		{
			//menu[selectedItemIndex].setColor( sf::Color::White );
			_currentIndex += moveAmount;
			//spdlog::info( _currentIndex );
			//menu[selectedItemIndex].setColor( sf::Color::Red );
		}
		else if ( cycleUp && _buttons.size( ) > 0 )
		{ _currentIndex = 0; }
		
		UpdateButtons( );
	}

	void ButtonGroup::JumpToIndex( const unsigned int &index )
	{
		if ( index < _buttons.size( ) )
		{ _currentIndex = index; }

		UpdateButtons( );
	}

	unsigned int ButtonGroup::GetCurrentIndex( ) const
	{ return _currentIndex; }

	void ButtonGroup::UpdateButtons( )
	{
		for ( int i = 0; i < _buttons.size( ); i++ )
		{
			if ( i == _currentIndex )
			{ 
				//spdlog::info( "CURRENT" );
				auto button = _buttons.at( i );
				button->SetButtonStyle( button->GetHighlightedButtonStyle( ), false );
			}
			else
			{
				//spdlog::info( "NOT CURRENT" );
				auto button = _buttons.at( i );
				button->SetButtonStyle( button->GetDefaultButtonStyle( ), false );
			}
		}

		//spdlog::warn( "--------------------------" );
	}
}

