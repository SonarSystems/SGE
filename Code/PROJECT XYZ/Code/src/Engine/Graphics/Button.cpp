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

		RecalculatePadding( );

		SetSize( _buttonLabel->GetSize( ) );

		ResetLabelPosition( );

		_buttonLabel->SetText( DEFAULT_LABEL_TEXT );
		
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

	void Button::SetText( const std::string &string, const bool &resetButtonSize )
	{
		_buttonLabel->SetText( string );

		if ( resetButtonSize )
		{ SetSize( _buttonLabel->GetSize( ) ); }

		ResetLabelPosition( true );
	}

	const std::string &Button::GetText( ) const
	{ return _buttonLabel->GetText( ); }

	void Button::SetPosition( const glm::vec2 &position )
	{
		_buttonBackground->SetPosition( position );

		ResetLabelPosition( true );
	}

	void Button::SetPosition( const float &x, const float &y )
	{
		_buttonBackground->SetPosition( x, y );

		ResetLabelPosition( true );
	}

	void Button::SetPositionX( const float &x )
	{
		_buttonBackground->SetPositionX( x );

		ResetLabelPosition( true );
	}

	void Button::SetPositionY( const float &y )
	{
		_buttonBackground->SetPositionY( y );

		ResetLabelPosition( true );
	}

	float Button::GetPositionX( ) const
	{ return _buttonBackground->GetPositionX( ); }

	float Button::GetPositionY( ) const
	{ return _buttonBackground->GetPositionY( ); } 

	glm::vec2 Button::GetPosition( ) const
	{ return _buttonBackground->GetPosition( ); }

	void Button::SetCharacterSize( const unsigned int &size, const bool &usePadding )
	{
		_buttonLabel->SetCharacterSize( size );

		RecalculatePadding( );

		SetSize( _buttonLabel->GetSize( ) );

		ResetLabelPosition( usePadding );
	}

	unsigned int Button::GetCharacterSize( ) const
	{ return _buttonLabel->GetCharacterSize( ); }

	void Button::SetBackgroundInsideColor( const Color &color )
	{ _buttonBackground->SetInsideColor( color ); }

	void Button::SetBackgroundBorderColor( const Color &color )
	{ _buttonBackground->SetBorderColor( color ); }

	void Button::SetBackgroundBorderThickness( const float &thickness )
	{ _buttonBackground->SetBorderThickness( thickness ); }

	Color Button::GetBackgroundInsideColor( ) const
	{ return _buttonBackground->GetInsideColor( ); }

	Color Button::GetBackgroundBorderColor( ) const
	{ return _buttonBackground->GetBorderColor( ); }

	float Button::GetBackgroundBorderThickness( ) const
	{ return _buttonBackground->GetBorderThickness( ); }

	void Button::SetLabelInsideColor( const Color &color )
	{ _buttonLabel->SetInsideColor( color ); }

	void Button::SetLabelBorderColor( const Color &color )
	{ _buttonLabel->SetBorderColor( color ); }

	void Button::SetLabelBorderThickness( const float &thickness )
	{ _buttonLabel->SetBorderThickness( thickness ); }

	Color Button::GetLabelInsideColor( ) const
	{ return _buttonLabel->GetInsideColor( ); }

	Color Button::GetLabelBorderColor( ) const
	{ return _buttonLabel->GetBorderColor( ); }

	float Button::GetLabelBorderThickness( ) const
	{ return _buttonLabel->GetBorderThickness( ); }

	void Button::Move( const glm::vec2 &offset )
	{
		_buttonBackground->Move( offset );
		_buttonLabel->Move( offset );
	}

	void Button::Move( const float &x, const float &y )
	{
		_buttonBackground->Move( x, y );
		_buttonLabel->Move( x, y );
	}

	void Button::MoveX( const float &x )
	{
		_buttonBackground->MoveX( x );
		_buttonLabel->MoveX( x );
	}

	void Button::MoveY( const float &y )
	{
		_buttonBackground->MoveY( y );
		_buttonLabel->MoveY( y );
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
		
		_buttonLabel->SetPivot( OBJECT_POINTS::CENTER );
	}

	void Button::RecalculatePadding( )
	{
		_padding.x = _buttonLabel->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_X_RATIO;
		_padding.y = _buttonLabel->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_Y_RATIO;
	}
}

