#include "Graphics/TextBox.hpp"

#define BACKSPACE_TEXT_ENTERED_KEY_CODE 8
#define CURSOR_LETTER_SPACING_MULITPLIER 15

namespace Sonar
{
	TextBox::TextBox( GameDataRef data ) : Label( data )
	{
		_maxCharacters = DEFAULT_TEXTBOX_MAXIMUM_CHARACTERS;
		_isPostStringBlinkerShown = false;
		_isFocusedOn = false;

		_blinkerTime = DEFAULT_TEXTBOX_BLINKER_TIME;

		_buttonToClick = DEFAULT_TEXTBOX_CLICKED_MOUSE_BUTTON;
		_hoverCursor = DEFAULT_TEXTBOX_HOVER_CURSOR;

		_postStringBlinker = new Rectangle( data );
		_postStringBlinker->SetSize( 5, GetHeight( ) );
		_postStringBlinker->SetPosition( GetPositionX( ) + GetWidth( ), GetPositionY( ) + ( GetHeight( ) * 0.5 ) );
		_postStringBlinker->SetInsideColor( Color::Black );

		_minimumClickableSize = GetSize( );

		_clickableRect = new Rectangle( data );

		_isDebugDrawing = DEFAULT_TEXTBOX_IS_DEBUG_DRAWING;
	}

	TextBox::TextBox( GameDataRef data, const std::string &filepath ) : Label( data, filepath ) { }
	
	TextBox::~TextBox( ) { }

	void TextBox::PollInput( const float &dt, const Event &event )
	{
		if ( _isFocusedOn )
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

				_clock.Reset( );
				_isPostStringBlinkerShown = true;
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
		_clickableRect->SetInsideColor( Color( 0, 0, 255, 100 ) );
	
		if ( GetWidth( ) > _minimumClickableSize.x )
		{ _clickableRect->SetWidth( GetWidth( ) ); }
		else
		{ _clickableRect->SetWidth( _minimumClickableSize.x ); }

		if ( GetHeight( ) > _minimumClickableSize.y )
		{ _clickableRect->SetHeight( GetHeight( ) ); }
		else
		{ _clickableRect->SetHeight( _minimumClickableSize.y ); }
		
		_clickableRect->SetPosition( GetPosition( ) );

		if ( _clock.GetElapsedTime( ).AsSeconds( ) > _blinkerTime )
		{
			_clock.Reset( );
			_isPostStringBlinkerShown = !_isPostStringBlinkerShown;
		}

		if ( _clickableRect->IsMouseOver( ) )
		{ Mouse::ChangeCursor( _hoverCursor, _data->window ); }
		else
		{ Mouse::ChangeCursor( DEFAULT_TEXTBOX_NO_HOVER_CURSOR, _data->window ); }
		
		if ( _clickableRect->IsClicked( _buttonToClick ) )
		{
			_isFocusedOn = true;
			_clock.Reset( );
			_isPostStringBlinkerShown = true;
		}
		else
		{
			if ( Mouse::IsPressed( _buttonToClick ) )
			{
				auto mousePosition = Mouse::GetPosition( _data->window );

				if ( mousePosition.x < _clickableRect->GetPositionX( ) || mousePosition.x > _clickableRect->GetPositionX( ) + _clickableRect->GetWidth( ) || 
					mousePosition.y < _clickableRect->GetPositionY( ) || mousePosition.y > _clickableRect->GetPositionY( ) + _clickableRect->GetHeight( ) )
				{
					_isFocusedOn = false;
					_isPostStringBlinkerShown = false;
				}
			}
		}
	}

	void TextBox::Draw( )
	{
		if ( _isDebugDrawing )
		{ _clickableRect->Draw( ); }

		_postStringBlinker->SetHeight( GetCharacterSize( ) );
		_postStringBlinker->SetPosition( GetPositionX( ) + GetWidth( ) + GetLetterSpacing( ) * CURSOR_LETTER_SPACING_MULITPLIER, GetPositionY( ) + GetCharacterSize( ) - _postStringBlinker->GetHeight( ) );

		Label::Draw( );

		if ( _isPostStringBlinkerShown && _isFocusedOn )
		{ _postStringBlinker->Draw( ); }
	}

	void TextBox::SetBlinkerTime( const float &time )
	{ _blinkerTime = time; }

	const float &TextBox::GetBlinkerTime( ) const
	{ return _blinkerTime; }

	void TextBox::SetClickableSize( const glm::vec2 &size )
	{ _minimumClickableSize = size; }

	void TextBox::SetClickableSize( const float &width, const float &height )
	{ SetClickableSize( glm::vec2( width, height ) ); }

	void TextBox::SetClickableWidth( const float &width )
	{ SetClickableSize( glm::vec2( width, _minimumClickableSize.y ) ); }

	void TextBox::SetClickableHeight( const float &height )
	{ SetClickableSize( glm::vec2( _minimumClickableSize.x, height ) ); }

	glm::vec2 TextBox::GetClickableSize( ) const
	{ return _minimumClickableSize; }

	float TextBox::GetClickableWidth( ) const
	{ return _minimumClickableSize.x; }

	float TextBox::GetClickableHeight( ) const
	{ return _minimumClickableSize.y; }

	void TextBox::SetMouseButtonToClick( const Mouse::Button &button )
	{ _buttonToClick = button; }

	const Sonar::Mouse::Button &TextBox::GetMouseButtonToClick( ) const
	{ return _buttonToClick; }

	void TextBox::SetMouseHoverCursor( const Mouse::Cursor &cursor )
	{ _hoverCursor = cursor; }

	const Sonar::Mouse::Cursor &TextBox::GetMouseHoverCursor( ) const
	{ return _hoverCursor; }

	void TextBox::EnableDebugDraw( )
	{ _isDebugDrawing = true; }

	void TextBox::DisableDebugDraw( )
	{ _isDebugDrawing = false; }

	void TextBox::ToggleDebugDraw( )
	{ _isDebugDrawing = !_isDebugDrawing; }

	const bool &TextBox::IsDebugDrawing( ) const
	{ return _isDebugDrawing; }
}

