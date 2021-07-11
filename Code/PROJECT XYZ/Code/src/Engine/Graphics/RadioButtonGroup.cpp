#include "pch.hpp"

namespace Sonar
{
	RadioButtonGroup::RadioButtonGroup( GameDataRef data ) : _data( data ) { }

	RadioButtonGroup::~RadioButtonGroup( ) { }

	void RadioButtonGroup::Draw( )
	{
		for ( auto &button : _radioButtons )
		{ button->Draw( ); }
	}

	void RadioButtonGroup::Update( const float &dt )
	{
		int selectedIndex = -1;
		long long timeSelected = 0;

		for ( unsigned int i = 0; i < _radioButtons.size( ); i++ )
		{
			_radioButtons.at( i )->Update( dt );

			if ( _radioButtons.at( i )->GetSelectedTime( ) > timeSelected )
			{
				timeSelected = _radioButtons.at( i )->GetSelectedTime( );

				selectedIndex = i;
			}
		}

		if ( selectedIndex >= 0 )
		{
			for ( unsigned int i = 0; i < _radioButtons.size( ); i++ )
			{
				if ( i != selectedIndex )
				{ _radioButtons.at( i )->DisableSelection( ); }
			}
		}
		else
		{
			if ( _radioButtons.size( ) >= 0 )
			{ _radioButtons.front( )->EnableSelection( ); }
		}
	}

	void RadioButtonGroup::PollInput( const float &dt, const Event &event )
	{
		for ( auto &button : _radioButtons )
		{ button->PollInput( dt, event ); }
	}

	void RadioButtonGroup::AddRadioButton( RadioButton *radioButton, const bool &overrideStyle )
	{
		if ( overrideStyle )
		{ radioButton->SetTheme( _theme ); }

		_radioButtons.push_back( radioButton );
	}

	void RadioButtonGroup::RemoveRadioButton( RadioButton *radioButton )
	{
		std::vector<RadioButton *> newMenuComponentsVector( _radioButtons.size( ) );

		std::remove_copy( _radioButtons.begin( ), _radioButtons.end( ), newMenuComponentsVector.begin( ), radioButton );

		if ( newMenuComponentsVector.at( newMenuComponentsVector.size( ) - 1 ) == NULL )
		{
			newMenuComponentsVector.pop_back( );

			_radioButtons = newMenuComponentsVector;
		}
	}

	void RadioButtonGroup::RemoveRadioButton( const unsigned int &index )
	{
		if ( index < _radioButtons.size( ) )
		{ _radioButtons.erase( _radioButtons.begin( ) + index ); }
	}

	void RadioButtonGroup::RemoveFirstRadioButton( )
	{
		if ( 0 < _radioButtons.size( ) )
		{ _radioButtons.erase( _radioButtons.begin( ) ); }
	}

	void RadioButtonGroup::RemoveLastRadioButton( )
	{
		if ( _radioButtons.size( ) > 0 )
		{ _radioButtons.erase( _radioButtons.end( ) - 1 ); }
	}

	unsigned int RadioButtonGroup::GetSize( ) const
	{ return _radioButtons.size( ); }

	void RadioButtonGroup::SetTheme( const MenuComponent::Theme &theme )
	{
		_theme = theme;

		for ( auto &button : _radioButtons )
		{ button->SetTheme( _theme ); }
	}

}

