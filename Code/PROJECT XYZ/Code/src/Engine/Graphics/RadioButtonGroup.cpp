#include "Graphics/RadioButtonGroup.hpp"

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
		unsigned int timeSelected = 0;

		for ( int i = 0; i < _radioButtons.size( ); i++ )
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
			for ( int i = 0; i < _radioButtons.size( ); i++ )
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

	void RadioButtonGroup::AddRadioButton( RadioButton *radioButton )
	{ _radioButtons.push_back( radioButton ); }

	unsigned int RadioButtonGroup::GetSize( ) const
	{ return _radioButtons.size( ); }
}

