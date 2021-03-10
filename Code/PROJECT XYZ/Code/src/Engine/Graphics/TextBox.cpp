#include "Graphics/TextBox.hpp"

namespace Sonar
{
	TextBox::TextBox( GameDataRef data ) : Drawable( data )
	{ Init( data ); }

	TextBox::TextBox( GameDataRef data, const std::string &filepath ) : Drawable( data )
	{
		SetFontFilePath( filepath );

		Init( data );
	}

	void TextBox::Init( GameDataRef data )
	{
		_object = &_text;

		_string = DEFAULT_LABEL_TEXT;
		SetCharacterSize( DEFAULT_LABEL_CHARACTER_SIZE );
		SetInsideColor( DEFAULT_LABEL_TEXT_COLOR );

		SetText( _string );

		_globalBounds = _text.getGlobalBounds( );

		isBold = isItalic = isUnderlined = isStrikeThrough = STYLE::Regular;
	}

	void TextBox::Draw( )
	{ Drawable::Draw( ); }

	TextBox::~TextBox( ) { }

	void TextBox::SetFontFilePath( const std::string &filepath )
	{
		_filePath = filepath;

		_font.SetFontFile( _filePath );
		SetFont( _font );
	}

	std::string TextBox::GetFontFilePath( ) const
	{ return _filePath; }

	float TextBox::GetLineSpacing( ) const
	{ return _text.getLineSpacing( ); }

	float TextBox::GetLetterSpacing( ) const
	{ return _text.getLetterSpacing( ); }

	float TextBox::GetUnderlinePosition( const unsigned int &characterSize ) const
	{ return _font.GetUnderlinePosition( characterSize ); }

	float TextBox::GetUnderlineThickness( const unsigned int &characterSize ) const
	{ return _font.GetUnderlineThickness( characterSize ); }

	void TextBox::SetPosition( const glm::vec2 &position )
	{
		Drawable::SetPosition( position );
		_text.setPosition( position.x, position.y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void TextBox::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void TextBox::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void TextBox::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	void TextBox::SetInsideColor( const Color &color )
	{
		Drawable::SetInsideColor( color );
		_text.setFillColor( color.GetColor( ) );
	}

	void TextBox::SetBorderColor( const Color &color )
	{
		Drawable::SetBorderColor( color );
		_text.setOutlineColor( color.GetColor( ) );
	}

	void TextBox::SetBorderThickness( const float &thickness )
	{
		Drawable::SetBorderThickness( thickness );
		_text.setOutlineThickness( thickness );
	}

	Color TextBox::GetInsideColor( ) const
	{ return Color( _text.getFillColor( ).r, _text.getFillColor( ).g, _text.getFillColor( ).b, _text.getFillColor( ).a ); }

	Color TextBox::GetBorderColor( ) const
	{ return Color( _text.getOutlineColor( ).r, _text.getOutlineColor( ).g, _text.getOutlineColor( ).b, _text.getOutlineColor( ).a ); }


	float TextBox::GetBorderThickness( ) const
	{ return _text.getOutlineThickness( ); }

	void TextBox::Move( const glm::vec2 &offset )
	{
		Drawable::Move( offset );
		_text.move( offset.x, offset.y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void TextBox::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void TextBox::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void TextBox::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void TextBox::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_text.setRotation( angle );
		_globalBounds = _text.getGlobalBounds( );
	}

	void TextBox::Rotate( const float &angle )
	{ SetRotation( GetRotation( ) + angle ); }

	float TextBox::GetRotation( ) const
	{ return _text.getRotation( ); }

	void TextBox::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_text.setScale( scale[0], scale[1] );
		_globalBounds = _text.getGlobalBounds( );
	}
	
	void TextBox::SetScale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( xScale, yScale ) ); }

	void TextBox::SetScaleX( const float &xScale )
	{ SetScale( glm::vec2( xScale, GetScaleY( ) ) ); }

	void TextBox::SetScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), yScale ) ); }

	void TextBox::Scale( const glm::vec2 & scale )
	{ SetScale( GetScaleX( ) * scale ); }

	void TextBox::Scale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) * yScale ) ); }
	
	void TextBox::ScaleX( const float &xScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) ) ); }

	void TextBox::ScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), GetScaleY( ) * yScale ) ); }

	void TextBox::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_text.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _text.getGlobalBounds( );
	}

	void TextBox::SetPivot( const float &xPoint, const float &yPoint )
	{ SetPivot( glm::vec2( xPoint, yPoint ) ); }

	void TextBox::SetPivot( const OBJECT_POINTS &pivot )
	{
		switch ( pivot )
		{
			case OBJECT_POINTS::CENTER:
				Drawable::SetPivot( OBJECT_POINTS::CENTER );
				_text.setOrigin( _text.getLocalBounds( ).width * 0.5f, _text.getLocalBounds( ).height * 0.5f );

				break;

			case OBJECT_POINTS::TOP_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_LEFT );
				_text.setOrigin( 0, 0 );

				break;

			case OBJECT_POINTS::TOP_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_RIGHT );
				_text.setOrigin( _text.getLocalBounds( ).width, 0 );

				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_LEFT );
				_text.setOrigin( 0, _text.getLocalBounds( ).height );

				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_RIGHT );
				_text.setOrigin( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );

				break;
		}

		_globalBounds = _text.getGlobalBounds( );
	}

	void TextBox::SetPivotX( const float &xPoint )
	{ SetPivot( glm::vec2( xPoint, GetPivotY( ) ) ); }

	void TextBox::SetPivotY( const float &yPoint )
	{ SetPivot( glm::vec2( GetPivotX( ), yPoint ) ); }

	void TextBox::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	glm::vec4 TextBox::GetLocalBounds( ) const
	{ return glm::vec4( _text.getLocalBounds( ).left, _text.getLocalBounds( ).top, _text.getLocalBounds( ).width, _text.getLocalBounds( ).height ); }

	glm::vec4 TextBox::GetGlobalBounds( ) const
	{ return glm::vec4( _text.getGlobalBounds( ).left, _text.getGlobalBounds( ).top, _text.getGlobalBounds( ).width, _text.getGlobalBounds( ).height ); }

	void TextBox::SetText( const std::string &string )
	{
		_string = string;
		_text.setString( _string );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	void TextBox::SetFont( const Font &font )
	{
		_font = font;
		_filePath = _font.GetFontFilePath( );
		_text.setFont( _font.GetSFMLFont( ) );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	void TextBox::SetCharacterSize( const unsigned int &size )
	{
		_text.setCharacterSize( size );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	unsigned int TextBox::GetCharacterSize( ) const
	{ return _text.getCharacterSize( ); }

	void TextBox::SetLineSpacing( const float &spacingFactor )
	{ _text.setLineSpacing( spacingFactor ); }

	void TextBox::SetLetterSpacing( const float &spacingFactor )
	{ _text.setLetterSpacing( spacingFactor ); }

	void TextBox::SetStyle( const STYLE &style, const bool &isActivated )
	{
		switch ( style )
		{
			case STYLE::Bold:
				if ( isActivated )
				{ isBold = STYLE::Bold; }
				else
				{ isBold = STYLE::Regular; }

				break;

			case STYLE::Italic:
				if ( isActivated )
				{ isItalic = STYLE::Italic; }
				else
				{ isItalic = STYLE::Regular; }

				break;

			case STYLE::Regular:
				if ( isActivated )
				{ isBold = isItalic = isUnderlined = isStrikeThrough = STYLE::Regular; }

				break;

			case STYLE::StrikeThrough:
				if ( isActivated )
				{ isStrikeThrough = STYLE::StrikeThrough; }
				else
				{ isStrikeThrough = STYLE::Regular; }

				break;

			case STYLE::Underlined:
				if ( isActivated )
				{ isUnderlined = STYLE::Underlined; }
				else
				{ isUnderlined = STYLE::Regular; }

				break;
		}
		
		_text.setStyle( isBold | isItalic | isUnderlined | isStrikeThrough );
	}

	void TextBox::SetStyle( const unsigned int &style )
	{ _text.setStyle( style ); }

	const std::string &TextBox::GetText( ) const
	{ return _string; }

	const Sonar::Font &TextBox::GetFont( ) const
	{ return _font; }

	unsigned int TextBox::GetStyle( ) const
	{ return _text.getStyle( ); }

	bool TextBox::IsStyleEnabled( const STYLE &style ) const
	{
		switch ( style )
		{
			case STYLE::Bold:
				if ( STYLE::Regular == isBold )
				{ return false; }
				else
				{ return true; }

				break;

			case STYLE::Italic:
				if ( STYLE::Regular == isItalic )
				{ return false; }
				else
				{ return true; }

				break;

			

			case STYLE::StrikeThrough:
				if ( STYLE::Regular == isStrikeThrough )
				{ return false; }
				else
				{ return true; }

				break;

			case STYLE::Underlined:
				if ( STYLE::Regular == isUnderlined )
				{ return false; }
				else
				{ return true; }

				break;
			
			case STYLE::Regular:
			default:
				if ( STYLE::Regular == isBold && STYLE::Regular == isItalic &&
					STYLE::Regular == isStrikeThrough && STYLE::Regular == isUnderlined )
				{ return true; }
				else
				{ return false; }

				break;
		}
	}

	glm::vec2 TextBox::FindCharacterPos( const std::size_t &index ) const
	{
		auto characterPos = _text.findCharacterPos( index );
		return glm::vec2( characterPos.x, characterPos.y );
	}

}

