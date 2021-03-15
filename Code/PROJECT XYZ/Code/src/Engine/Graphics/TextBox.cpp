#include "Graphics/TextBox.hpp"

#define BACKSPACE_TEXT_ENTERED_KEY_CODE 8

namespace Sonar
{
	TextBox::TextBox( GameDataRef data ) : Label( data )
	{
		_maxCharacters = DEFAULT_TEXTBOX_MAXIMUM_CHARACTERS;
		_isVerticalPipeShown = false;
		_originalText = GetText( );

		_postStringBlinker = new Rectangle( data );
		_postStringBlinker->SetSize( 5, GetHeight( ) );
		_postStringBlinker->SetPosition( GetPositionX( ) + GetWidth( ), GetPositionY( ) + ( GetHeight( ) * 0.5 ) );
		_postStringBlinker->SetInsideColor( Color::Black );
	}

	TextBox::TextBox( GameDataRef data, const std::string &filepath ) : Label( data, filepath ) { }
	
	TextBox::~TextBox( ) { }

	void TextBox::PollInput( const float &dt, const Event &event )
	{
		if ( Event::TextEntered == event.type )
		{
			if ( BACKSPACE_TEXT_ENTERED_KEY_CODE == event.key.code )
			{
				if ( GetText( ).size( ) > 0 )
				{
					std::string str = GetText( );
					str.resize( str.size( ) - 1 );

					SetText( str );
				}
			}
			else if ( GetText( ).size( ) + 1 <= _maxCharacters )
			{
				if ( !IsRestrictedCharacter( event.text.unicode ) )
				{ SetText( GetText( ) + ( char )event.text.unicode ); }
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

	void TextBox::AddRestrictedCharacter( const unsigned int &unicodeCharacter )
	{
		if ( !IsRestrictedCharacter( unicodeCharacter ) )
		{ _restrictedCharacters.push_back( unicodeCharacter ); }
	}

	void TextBox::AddRestrictedCharacter( const char &character )
	{ AddRestrictedCharacter( ( unsigned int )character ); }

	void TextBox::RemoveRestrictedCharacter( const unsigned int &unicodeCharacter )
	{
		_restrictedCharacters.erase
		( 
			std::remove( _restrictedCharacters.begin( ), _restrictedCharacters.end( ), unicodeCharacter ), 
			_restrictedCharacters.end( )
		);
	}

	void TextBox::RemoveRestrictedCharacter( const char &character )
	{ RemoveRestrictedCharacter( ( unsigned int )character ); }

	const std::vector<unsigned int> TextBox::GetRestrictedCharacterList( ) const
	{ return _restrictedCharacters; }

	bool TextBox::IsRestrictedCharacter( const unsigned int &unicodeCharacter ) const
	{ return std::find( _restrictedCharacters.begin( ), _restrictedCharacters.end( ), unicodeCharacter ) != _restrictedCharacters.end( ); }

	bool TextBox::IsRestrictedCharacter( const char &character ) const
	{ return IsRestrictedCharacter( ( unsigned int )character ); }

	void TextBox::Update( const float &dt )
	{
		/*Label::Update( dt );

		std::string text = GetText( );

		if ( _isVerticalPipeShown )
		{
			text = text.substr( 0, text.size( ) - 1 );

			SetText( text );
		}
		else
		{
			text += "|";

			SetText( text );
		}
		

		_isVerticalPipeShown = !_isVerticalPipeShown;*/
	}

	void TextBox::Draw( )
	{
		_postStringBlinker->SetHeight( GetCharacterSize( ) );
		_postStringBlinker->SetPosition( GetPositionX( ) + GetWidth( ) + GetLetterSpacing( ), GetPositionY( ) + GetCharacterSize( ) - _postStringBlinker->GetHeight( ) );

		Label::Draw( );
		_postStringBlinker->Draw( );
	}

}

