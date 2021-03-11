#include "Graphics/TextBox.hpp"

namespace Sonar
{
	TextBox::TextBox( GameDataRef data ) : Label( data )
	{
		_maxCharacters = DEFAULT_TEXTBOX_MAXIMUM_CHARACTERS;
	}

	TextBox::TextBox( GameDataRef data, const std::string &filepath ) : Label( data, filepath ) { }
	
	TextBox::~TextBox( ) { }

	void TextBox::PollInput( const float &dt, const Event &event )
	{
		if ( Event::TextEntered == event.type )
		{
			if ( GetText( ).size( ) + 1 <= _maxCharacters )
			{
				spdlog::info( "{0} - {1}", event.key.code, event.text.unicode );
				SetText( GetText( ) + ( char )event.text.unicode );
			}
		}
		else if ( Event::KeyReleased == event.type )
		{
			if ( Keyboard::Key::Backspace == event.key.code )
			{
				std::string str = GetText( );
				str.resize( str.size( ) - 2 );

				SetText( str );
			}
		}
	}

	void TextBox::SetMaximumCharacters( const unsigned int &maxCharacters, const bool &removeExtraCharacters /*= true */ )
	{
		_maxCharacters = maxCharacters;

		if ( removeExtraCharacters )
		{
			std::string str = GetText( );
			str.resize( maxCharacters );

			SetText( str );
		}
	}

	const unsigned int &TextBox::GetMaximumCharacters( ) const
	{ return _maxCharacters; }
}

