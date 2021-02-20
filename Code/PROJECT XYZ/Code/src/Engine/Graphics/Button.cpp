#include "Graphics/Button.hpp"

#define DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX 19.0f / 128.0f

namespace Sonar
{
	Button::Button( GameDataRef data ) //: MenuComponent( data )
	{
		_anchorX = LABEL_ANCHOR_X::CENTER_X;
		_anchorY = LABEL_ANCHOR_Y::CENTER_Y;

		_buttonBackground = new Rectangle( data );
		_buttonBackground->SetInsideColor( Color::Black );
		_buttonBackground->SetPosition( 50, 100);

		_buttonLabel = new Label( data );
		_buttonLabel->SetFontFilePath( "Resources/consola.ttf" );
		_buttonLabel->SetInsideColor( Color::Red );
		_buttonLabel->SetCharacterSize( 64 );

		_padding.x = _buttonLabel->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_X_RATIO;
		_padding.y = _buttonLabel->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_Y_RATIO;

		SetSize( _buttonLabel->GetSize( ) );

		ResetLabelPosition( );

		_buttonLabel->SetText( DEFAULT_LABEL_TEXT );
		_buttonLabel->SetPivot( OBJECT_POINTS::CENTER );
	}

	Button::~Button( ) { }

	void Button::Draw( )
	{
		_buttonBackground->Draw( );
		_buttonLabel->Draw( );
	}

	void Button::SetRectangleBackground( Rectangle *rectangle )
	{ _buttonBackground = rectangle; }

	void Button::SetLabelBackground( Label *label )
	{ _buttonLabel = label; }

	Rectangle *Button::GetRectangleBackground( ) const
	{ return _buttonBackground; }

	Label *Button::GetRectangleLabel( ) const
	{ return _buttonLabel; }

	void Button::SetPadding( const glm::vec2 &padding )
	{
		_padding = padding;
		SetSize( _buttonBackground->GetSize( ) );
	}

	void Button::SetPadding( const float &x, const float &y )
	{
		_padding.x = x;
		_padding.y = y;
		SetSize( _buttonBackground->GetSize( ) );
	}

	void Button::SetPaddingX( const float &x )
	{
		_padding.x = x;
		SetSize( _buttonBackground->GetSize( ) );
	}

	void Button::SetPaddingY( const float &y )
	{
		_padding.y = y;
		SetSize( _buttonBackground->GetSize( ) );
	}

	const glm::vec2 &Button::GetPadding( ) const
	{ return _padding; }

	float Button::GetPaddingX( ) const
	{ return _padding.x; }

	float Button::GetPaddingY( ) const
	{ return _padding.y; }

	void Button::SetSize( const glm::vec2 &size )
	{
		_buttonBackground->SetSize( size + ( _padding * 2.0f ) );
		ResetLabelPosition( );
	}

	void Button::SetSize( const float &width, const float &height )
	{ SetSize( glm::vec2( width, height ) ); }

	void Button::SetWidth( const float &width )
	{ SetSize( glm::vec2( width, _buttonBackground->GetHeight( ) ) ); }

	void Button::SetHeight( const float &height )
	{ SetSize( glm::vec2( _buttonBackground->GetWidth( ), height ) ); }

	glm::vec2 Button::GetSize( ) const
	{ return _buttonBackground->GetSize( ); }

	float Button::GetWidth( ) const
	{ return _buttonBackground->GetWidth( ); }

	float Button::GetHeight( ) const
	{ return _buttonBackground->GetHeight( ); }

	void Button::SetLabelAnchorX( const LABEL_ANCHOR_X &anchor, const bool &usePadding )
	{
		_anchorX = anchor;
		ResetLabelPosition( usePadding );
	}

	void Button::SetLabelAnchorY( const LABEL_ANCHOR_Y &anchor, const bool &usePadding )
	{
		_anchorY = anchor;
		ResetLabelPosition( usePadding );
	}

	void Button::ResetLabelPosition( const bool &usePadding )
	{
		float positionX, positionY;

		float paddingX = 0, paddingY = 0;

		if ( usePadding )
		{ paddingX = _padding.x; }

		if ( usePadding )
		{ paddingY = _padding.y; }

		switch ( _anchorX )
		{
			case LABEL_ANCHOR_X::LEFT:
				positionX = _buttonBackground->GetPositionX( ) + ( _buttonLabel->GetWidth( ) * 0.5f ) + paddingX;

				break;

			case LABEL_ANCHOR_X::CENTER_X:
				positionX = _buttonBackground->GetPositionX( ) + ( _buttonBackground->GetWidth( ) * 0.5f );

				break;

			case LABEL_ANCHOR_X::RIGHT:
				positionX = _buttonBackground->GetPositionX( ) + _buttonBackground->GetWidth( ) - ( _buttonLabel->GetWidth( ) * 0.5f ) - paddingX;

				break;
		}

		switch ( _anchorY )
		{
			case LABEL_ANCHOR_Y::TOP:
				positionY = _buttonBackground->GetPositionY( ) + ( _buttonLabel->GetHeight( ) * 0.5f ) + paddingY - ( _buttonLabel->GetCharacterSize( ) * 0.5f ) + ( _buttonLabel->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX );

				break;

			case LABEL_ANCHOR_Y::CENTER_Y:
				positionY = _buttonBackground->GetPositionY( ) + ( _buttonBackground->GetHeight( ) * 0.5f ) - ( _buttonLabel->GetCharacterSize( ) * 0.5f ) + ( _buttonLabel->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX );

				break;

			case LABEL_ANCHOR_Y::BOTTOM:
				positionY = _buttonBackground->GetPositionY( ) + _buttonBackground->GetHeight( ) - ( _buttonLabel->GetHeight( ) * 0.5f ) - paddingY - ( _buttonLabel->GetCharacterSize( ) * 0.5f ) + ( _buttonLabel->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX );

				break;
		}

		_buttonLabel->SetPosition( positionX, positionY );
	}
}

