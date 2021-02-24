#include "Graphics/Button.hpp"

#define DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX 19.0f / 128.0f

namespace Sonar
{
	Button::Button( GameDataRef data ) //: MenuComponent( data )
	{
		_anchorX = LABEL_ANCHOR_X::CENTER_X;
		_anchorY = LABEL_ANCHOR_Y::CENTER_Y;

		_background = new Rectangle( data );
		_background->SetInsideColor( Color::Black );


		_label = new Label( data );
		_label->SetFontFilePath( "Resources/arial.ttf" );
		_label->SetInsideColor( Color::Red );
		_label->SetCharacterSize( 64 );

		RecalculatePadding( );

		SetSize( _label->GetSize( ) );

		ResetLabelPosition( );

		_label->SetText( DEFAULT_LABEL_TEXT );
		
	}

	Button::~Button( ) { }

	void Button::Draw( )
	{
		_background->Draw( );
		_label->Draw( );
	}

	void Button::SetRectangleBackground( Rectangle *rectangle )
	{ _background = rectangle; }

	void Button::SetLabelBackground( Label *label )
	{ _label = label; }

	Rectangle *Button::GetRectangleBackground( ) const
	{ return _background; }

	Label *Button::GetRectangleLabel( ) const
	{ return _label; }

	void Button::SetPadding( const glm::vec2 &padding )
	{
		_padding = padding;
		SetSize( _background->GetSize( ) );
	}

	void Button::SetPadding( const float &x, const float &y )
	{
		_padding.x = x;
		_padding.y = y;
		SetSize( _background->GetSize( ) );
	}

	void Button::SetPaddingX( const float &x )
	{
		_padding.x = x;
		SetSize( _background->GetSize( ) );
	}

	void Button::SetPaddingY( const float &y )
	{
		_padding.y = y;
		SetSize( _background->GetSize( ) );
	}

	const glm::vec2 &Button::GetPadding( ) const
	{ return _padding; }

	float Button::GetPaddingX( ) const
	{ return _padding.x; }

	float Button::GetPaddingY( ) const
	{ return _padding.y; }

	void Button::SetSize( const glm::vec2 &size )
	{
		_background->SetSize( size + ( _padding * 2.0f ) );
		ResetLabelPosition( );
	}

	void Button::SetSize( const float &width, const float &height )
	{ SetSize( glm::vec2( width, height ) ); }

	void Button::SetWidth( const float &width )
	{ SetSize( glm::vec2( width, _background->GetHeight( ) ) ); }

	void Button::SetHeight( const float &height )
	{ SetSize( glm::vec2( _background->GetWidth( ), height ) ); }

	glm::vec2 Button::GetSize( ) const
	{ return _background->GetSize( ); }

	float Button::GetWidth( ) const
	{ return _background->GetWidth( ); }

	float Button::GetHeight( ) const
	{ return _background->GetHeight( ); }

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
		_label->SetText( string );

		if ( resetButtonSize )
		{ SetSize( _label->GetSize( ) ); }

		ResetLabelPosition( true );
	}

	const std::string &Button::GetText( ) const
	{ return _label->GetText( ); }

	void Button::SetPosition( const glm::vec2 &position )
	{
		_background->SetPosition( position );

		ResetLabelPosition( true );
	}

	void Button::SetPosition( const float &x, const float &y )
	{
		_background->SetPosition( x, y );

		ResetLabelPosition( true );
	}

	void Button::SetPositionX( const float &x )
	{
		_background->SetPositionX( x );

		ResetLabelPosition( true );
	}

	void Button::SetPositionY( const float &y )
	{
		_background->SetPositionY( y );

		ResetLabelPosition( true );
	}

	float Button::GetPositionX( ) const
	{ return _background->GetPositionX( ); }

	float Button::GetPositionY( ) const
	{ return _background->GetPositionY( ); } 

	glm::vec2 Button::GetPosition( ) const
	{ return _background->GetPosition( ); }

	void Button::SetCharacterSize( const unsigned int &size, const bool &usePadding )
	{
		_label->SetCharacterSize( size );

		RecalculatePadding( );

		SetSize( _label->GetSize( ) );

		ResetLabelPosition( usePadding );
	}

	unsigned int Button::GetCharacterSize( ) const
	{ return _label->GetCharacterSize( ); }

	void Button::SetBackgroundInsideColor( const Color &color )
	{ _background->SetInsideColor( color ); }

	void Button::SetBackgroundBorderColor( const Color &color )
	{ _background->SetBorderColor( color ); }

	void Button::SetBackgroundBorderThickness( const float &thickness )
	{ _background->SetBorderThickness( thickness ); }

	Color Button::GetBackgroundInsideColor( ) const
	{ return _background->GetInsideColor( ); }

	Color Button::GetBackgroundBorderColor( ) const
	{ return _background->GetBorderColor( ); }

	float Button::GetBackgroundBorderThickness( ) const
	{ return _background->GetBorderThickness( ); }

	void Button::SetLabelInsideColor( const Color &color )
	{ _label->SetInsideColor( color ); }

	void Button::SetLabelBorderColor( const Color &color )
	{ _label->SetBorderColor( color ); }

	void Button::SetLabelBorderThickness( const float &thickness )
	{ _label->SetBorderThickness( thickness ); }

	Color Button::GetLabelInsideColor( ) const
	{ return _label->GetInsideColor( ); }

	Color Button::GetLabelBorderColor( ) const
	{ return _label->GetBorderColor( ); }

	float Button::GetLabelBorderThickness( ) const
	{ return _label->GetBorderThickness( ); }

	void Button::Move( const glm::vec2 &offset )
	{
		_background->Move( offset );
		_label->Move( offset );
	}

	void Button::Move( const float &x, const float &y )
	{
		_background->Move( x, y );
		_label->Move( x, y );
	}

	void Button::MoveX( const float &x )
	{
		_background->MoveX( x );
		_label->MoveX( x );
	}

	void Button::MoveY( const float &y )
	{
		_background->MoveY( y );
		_label->MoveY( y );
	}

	void Button::SetScale( const float &xScale, const float &yScale )
	{
		_background->SetScale( xScale, yScale );
		_label->SetScale( xScale, yScale );

		RecalculatePadding( );

		SetSize( _label->GetSize( ) );

		ResetLabelPosition( );
	}

	void Button::SetScale( const glm::vec2 &scale )
	{
		_background->SetScale( scale );
		_label->SetScale( scale );
	}

	void Button::SetScaleX( const float &xScale )
	{
		_background->SetScaleX( xScale );
		_label->SetScaleX( xScale );
	}

	void Button::SetScaleY( const float &yScale )
	{
		_background->SetScaleY( yScale );
		_label->SetScaleY( yScale );
	}

	glm::vec2 Button::GetScale( ) const
	{ return _background->GetScale( ); }

	float Button::GetScaleX( ) const
	{ return _background->GetScaleX( ); }

	float Button::GetScaleY( ) const
	{ return _background->GetScaleY( ); }

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
				positionX = _background->GetPositionX( ) + ( _label->GetWidth( ) * 0.5f ) + paddingX - _background->GetPivotX( );

				break;

			case LABEL_ANCHOR_X::CENTER_X:
				positionX = _background->GetPositionX( ) + ( _background->GetWidth( ) * GetScaleX( ) * 0.5f ) - _background->GetPivotX( );

				break;

			case LABEL_ANCHOR_X::RIGHT:
				positionX = _background->GetPositionX( ) + _background->GetWidth( ) - ( _label->GetWidth( ) * 0.5f ) - paddingX - _background->GetPivotX( );

				break;
		}

		switch ( _anchorY )
		{
			case LABEL_ANCHOR_Y::TOP:
				positionY = _background->GetPositionY( ) + ( _label->GetHeight( ) * 0.5f ) + paddingY - ( _label->GetCharacterSize( ) * 0.5f ) + ( _label->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

				break;

			case LABEL_ANCHOR_Y::CENTER_Y:
				positionY = _background->GetPositionY( ) + ( _background->GetHeight( ) * GetScaleY( ) * 0.5f ) - ( _label->GetCharacterSize( ) * GetScaleY( ) * 0.5f ) + ( _label->GetCharacterSize( ) * GetScaleY( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

				break;

			case LABEL_ANCHOR_Y::BOTTOM:
				positionY = _background->GetPositionY( ) + _background->GetHeight( ) - ( _label->GetHeight( ) * 0.5f ) - paddingY - ( _label->GetCharacterSize( ) * 0.5f ) + ( _label->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

				break;
		}

		_label->SetPosition( positionX, positionY );
		
		_label->SetPivot( OBJECT_POINTS::CENTER );
	}

	void Button::RecalculatePadding( )
	{
		_padding.x = _label->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_X_RATIO;
		_padding.y = _label->GetCharacterSize( ) * DEFAULT_BUTTON_PADDING_Y_RATIO;
	}
}

