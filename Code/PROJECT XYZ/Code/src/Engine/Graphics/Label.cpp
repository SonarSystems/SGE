#include "Graphics/Label.hpp"

namespace Sonar
{
	Label::Label( GameDataRef data ) : Drawable( data )
	{
		_object = &_text;

		_string = "";
		SetText( _string );

		_globalBounds = _text.getGlobalBounds( );

		isBold = isItalic = isUnderlined = isStrikeThrough = STYLE::Regular;
	}

	Label::Label( GameDataRef data, const std::string &filepath ) : Drawable( data )
	{
		_object = &_text;
		SetFontFilePath( filepath );

		_string = "";
		SetText( _string );

		_globalBounds = _text.getGlobalBounds( );

		isBold = isItalic = isUnderlined = isStrikeThrough = STYLE::Regular;
	}

	Label::~Label( ) { }

	void Label::SetFontFilePath( const std::string &filepath )
	{
		_filePath = filepath;

		_font.SetFontFile( _filePath );
		SetFont( _font );

		_text.setFont( _font.GetSFMLFont( ) );
	}

	std::string Label::GetFontFilePath( ) const
	{ return _filePath; }

	float Label::GetLineSpacing( const unsigned int &characterSize ) const
	{ return _font.GetLineSpacing( characterSize ); }

	float Label::GetUnderlinePosition( const unsigned int &characterSize ) const
	{ return _font.GetUnderlinePosition( characterSize ); }

	float Label::GetUnderlineThickness( const unsigned int &characterSize ) const
	{ return _font.GetUnderlineThickness( characterSize ); }

	void Label::SetPosition( const float &x, const float &y )
	{
		Drawable::SetPosition( x, y );
		_text.setPosition( x, y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPositionX( const float &x )
	{
		Drawable::SetPositionX( x );
		_text.setPosition( x, _text.getPosition( ).y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPositionY( const float &y )
	{
		Drawable::SetPositionY( y );
		_text.setPosition( _text.getPosition( ).x, y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetInsideColor( const Color &color )
	{
		Drawable::SetInsideColor( color );
		_text.setFillColor( color.GetColor( ) );
	}

	void Label::SetBorderColor( const Color &color )
	{
		Drawable::SetBorderColor( color );
		_text.setOutlineColor( color.GetColor( ) );
	}

	void Label::SetBorderThickness( const float &thickness )
	{
		Drawable::SetBorderThickness( thickness );
		_text.setOutlineThickness( thickness );
	}

	Color Label::GetInsideColor( ) const
	{ return Color( _text.getFillColor( ).r, _text.getFillColor( ).g, _text.getFillColor( ).b, _text.getFillColor( ).a ); }

	Color Label::GetBorderColor( ) const
	{ return Color( _text.getOutlineColor( ).r, _text.getOutlineColor( ).g, _text.getOutlineColor( ).b, _text.getOutlineColor( ).a ); }


	float Label::GetBorderThickness( ) const
	{ return _text.getOutlineThickness( ); }

	void Label::Move( const float &x, const float &y )
	{
		Drawable::Move( x, y );
		_text.move( x, y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::MoveX( const float &x )
	{
		Drawable::MoveX( x );
		_text.move( x, 0 );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::MoveY( const float &y )
	{
		Drawable::MoveY( y );
		_text.move( 0, y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_text.setRotation( angle );
		_globalBounds = _text.getGlobalBounds( );
	}

	float Label::GetRotation( ) const
	{ return _text.getRotation( ); }

	void Label::SetScale( const float &xScale, const float &yScale )
	{
		Drawable::SetScale( xScale, yScale );
		_text.setScale( xScale, yScale );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_text.setScale( scale[0], scale[1] );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetScaleX( const float &xScale )
	{
		Drawable::SetScaleX( xScale );
		_text.setScale( xScale, _text.getScale( ).y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetScaleY( const float &yScale )
	{
		Drawable::SetScaleX( yScale );
		_text.setScale( _text.getScale( ).x, yScale );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPivot( const float &xPoint, const float &yPoint )
	{
		Drawable::SetPivot( xPoint, yPoint );
		_text.setOrigin( xPoint, yPoint );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_text.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPivot( const OBJECT_POINTS &pivot )
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

	void Label::SetPivotX( const float &xPoint )
	{
		Drawable::SetPivotX( xPoint );
		_text.setOrigin( xPoint, _text.getOrigin( ).y );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::SetPivotY( const float &yPoint )
	{
		Drawable::SetPivotY( yPoint );
		_text.setOrigin( _text.getOrigin( ).x, yPoint );
		_globalBounds = _text.getGlobalBounds( );
	}

	void Label::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	glm::vec4 Label::GetLocalBounds( ) const
	{ return glm::vec4( _text.getLocalBounds( ).left, _text.getLocalBounds( ).top, _text.getLocalBounds( ).width, _text.getLocalBounds( ).height ); }

	glm::vec4 Label::GetGlobalBounds( ) const
	{ return glm::vec4( _text.getGlobalBounds( ).left, _text.getGlobalBounds( ).top, _text.getGlobalBounds( ).width, _text.getGlobalBounds( ).height ); }

	void Label::SetText( const std::string &string )
	{
		_string = string;
		_text.setString( _string );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	void Label::SetFont( const Font &font )
	{
		_font = font;
		_text.setFont( _font.GetSFMLFont( ) );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	void Label::SetCharacterSize( const unsigned int &size )
	{
		_text.setCharacterSize( size );

		SetPosition( _text.getPosition( ).x, _text.getPosition( ).y );
		SetSize( _text.getLocalBounds( ).width, _text.getLocalBounds( ).height );
	}

	void Label::SetStyle( const STYLE &style, const bool &isActivated )
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

	void Label::SetStyle( const unsigned int &style )
	{ _text.setStyle( style ); }

	const std::string &Label::GetText( ) const
	{ return _string; }

	const Sonar::Font &Label::GetFont( ) const
	{ return _font; }

	unsigned int Label::GetStyle( ) const
	{ return _text.getStyle( ); }

	bool Label::IsStyleEnabled( const STYLE &style ) const
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

			case STYLE::Regular:
				if ( STYLE::Regular == isBold && STYLE::Regular == isItalic &&
					STYLE::Regular == isStrikeThrough && STYLE::Regular == isUnderlined )
				{ return true; }
				else
				{ return false; }

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
		}
	}

	glm::vec2 Label::FindCharacterPos( const std::size_t &index ) const
	{
		auto characterPos = _text.findCharacterPos( index );
		return glm::vec2( characterPos.x, characterPos.y );
	}

}

