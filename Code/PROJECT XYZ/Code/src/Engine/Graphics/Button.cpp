#include "Graphics/Button.hpp"

#define DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX 19.0f / 128.0f

namespace Sonar
{
	Button::Button( GameDataRef data ) //: MenuComponent( data )
	{
		_anchorX = LABEL_ANCHOR_X::CENTER_X;
		_anchorY = LABEL_ANCHOR_Y::CENTER_Y;

		_background = new Rectangle( data );
		_background->SetInsideColor( DEFAULT_BUTTON_BACKGROUND_COLOR );

		_label = new Label( data );
		_label->SetFontFilePath( "Resources/arial.ttf" );
		_label->SetInsideColor( DEFAULT_BUTTON_LABEL_COLOR );
		_label->SetCharacterSize( DEFAULT_BUTTON_LABEL_CHARACTER_SIZE );

		RecalculatePadding( );

		SetSize( _label->GetSize( ) );

		ResetLabelPosition( );

		_label->SetText( DEFAULT_LABEL_TEXT );

		UpdateDefaultStyle( );
	}

	Button::~Button( ) { }

	void Button::Draw( )
	{
		if ( _isBackgroundEnabled )
		{ _background->Draw( ); }

		_label->Draw( );
	}

	void Button::SetRectangleBackground( Rectangle *rectangle, const bool &updateDefaultStyle )
	{
		_background = rectangle;

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetLabelBackground( Label *label, const bool &updateDefaultStyle )
	{
		_label = label;

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	Rectangle *Button::GetRectangleBackground( ) const
	{ return _background; }

	Label *Button::GetRectangleLabel( ) const
	{ return _label; }

	void Button::SetPadding( const glm::vec2 &padding, const bool &updateDefaultStyle )
	{
		_padding = padding;
		SetSize( _background->GetSize( ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetPadding( const float &x, const float &y, const bool &updateDefaultStyle )
	{
		_padding.x = x;
		_padding.y = y;
		SetSize( _background->GetSize( ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetPaddingX( const float &x, const bool &updateDefaultStyle )
	{
		_padding.x = x;
		SetSize( _background->GetSize( ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetPaddingY( const float &y, const bool &updateDefaultStyle )
	{
		_padding.y = y;
		SetSize( _background->GetSize( ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	const glm::vec2 &Button::GetPadding( ) const
	{ return _padding; }

	float Button::GetPaddingX( ) const
	{ return _padding.x; }

	float Button::GetPaddingY( ) const
	{ return _padding.y; }

	void Button::SetSize( const glm::vec2 &size, const bool &updateDefaultStyle )
	{
		_background->SetSize( size + ( _padding * 2.0f ) );
		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetSize( const float &width, const float &height, const bool &updateDefaultStyle )
	{
		SetSize( glm::vec2( width, height ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetWidth( const float &width, const bool &updateDefaultStyle )
	{
		SetSize( glm::vec2( width, _background->GetHeight( ) ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetHeight( const float &height, const bool &updateDefaultStyle )
	{
		SetSize( glm::vec2( _background->GetWidth( ), height ), updateDefaultStyle );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	glm::vec2 Button::GetSize( ) const
	{ return _background->GetSize( ); }

	float Button::GetWidth( ) const
	{ return _background->GetWidth( ); }

	float Button::GetHeight( ) const
	{ return _background->GetHeight( ); }

	void Button::SetLabelAnchorX( const LABEL_ANCHOR_X &anchor, const bool &usePadding, const bool &updateDefaultStyle )
	{
		_anchorX = anchor;
		ResetLabelPosition( usePadding );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetLabelAnchorY( const LABEL_ANCHOR_Y &anchor, const bool &usePadding, const bool &updateDefaultStyle )
	{
		_anchorY = anchor;
		ResetLabelPosition( usePadding );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetText( const std::string &string, const bool &resetButtonSize, const bool &updateDefaultStyle )
	{
		_label->SetText( string );

		if ( resetButtonSize )
		{ SetSize( _label->GetSize( ), updateDefaultStyle ); }

		ResetLabelPosition( true );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
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

	void Button::SetCharacterSize( const unsigned int &size, const bool &usePadding, const bool &updateDefaultStyle )
	{
		_label->SetCharacterSize( size );

		RecalculatePadding( );

		SetSize( _label->GetSize( ), updateDefaultStyle );

		ResetLabelPosition( usePadding );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	unsigned int Button::GetCharacterSize( ) const
	{ return _label->GetCharacterSize( ); }

	void Button::SetBackgroundInsideColor( const Color &color, const bool &updateDefaultStyle )
	{
		_background->SetInsideColor( color );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetBackgroundBorderColor( const Color &color, const bool &updateDefaultStyle )
	{
		_background->SetBorderColor( color );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetBackgroundBorderThickness( const float &thickness, const bool &updateDefaultStyle )
	{
		_background->SetBorderThickness( thickness );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	Color Button::GetBackgroundInsideColor( ) const
	{ return _background->GetInsideColor( ); }

	Color Button::GetBackgroundBorderColor( ) const
	{ return _background->GetBorderColor( ); }

	float Button::GetBackgroundBorderThickness( ) const
	{ return _background->GetBorderThickness( ); }

	void Button::SetLabelInsideColor( const Color &color, const bool &updateDefaultStyle )
	{
		_label->SetInsideColor( color );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetLabelBorderColor( const Color &color, const bool &updateDefaultStyle )
	{
		_label->SetBorderColor( color );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetLabelBorderThickness( const float &thickness, const bool &updateDefaultStyle )
	{
		_label->SetBorderThickness( thickness );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

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

	void Button::SetScale( const float &xScale, const float &yScale, const bool &updateDefaultStyle )
	{
		_background->SetScale( xScale, yScale );
		_label->SetScale( xScale, yScale );

		RecalculatePadding( );

		SetSize( _label->GetSize( ), updateDefaultStyle );

		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetScale( const glm::vec2 &scale, const bool &updateDefaultStyle )
	{
		_background->SetScale( scale );
		_label->SetScale( scale );

		RecalculatePadding( );

		SetSize( _label->GetSize( ), updateDefaultStyle );

		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetScaleX( const float &xScale, const bool &updateDefaultStyle )
	{
		_background->SetScaleX( xScale );
		_label->SetScaleX( xScale );

		RecalculatePadding( );

		SetSize( _label->GetSize( ), updateDefaultStyle );

		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetScaleY( const float &yScale, const bool &updateDefaultStyle )
	{
		_background->SetScaleY( yScale );
		_label->SetScaleY( yScale );

		RecalculatePadding( );

		SetSize( _label->GetSize( ), updateDefaultStyle );

		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	glm::vec2 Button::GetScale( ) const
	{ return _background->GetScale( ); }

	float Button::GetScaleX( ) const
	{ return _background->GetScaleX( ); }

	float Button::GetScaleY( ) const
	{ return _background->GetScaleY( ); }

	void Button::SetFont( const Font &font, const bool &resize, const bool &updateDefaultStyle )
	{
		_label->SetFont( font );

		if ( resize )
		{
			RecalculatePadding( );

			SetSize( _label->GetSize( ), updateDefaultStyle );

			ResetLabelPosition( );
		}

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetFontFilePath( const std::string &filepath, const bool &resize, const bool &updateDefaultStyle )
	{
		_label->SetFontFilePath( filepath );

		if ( resize )
		{
			RecalculatePadding( );

			SetSize( _label->GetSize( ), updateDefaultStyle );

			ResetLabelPosition( );
		}

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	const Font &Button::GetFont( ) const
	{ return _label->GetFont( ); }

	std::string Button::GetFontFilePath( ) const
	{ return _label->GetFontFilePath( ); }

	void Button::SetLabelStyle( const Label::STYLE &style, const bool &isActivated, const bool &resize, const bool &updateDefaultStyle )
	{
		_label->SetStyle( style, isActivated );

		if ( resize )
		{
			RecalculatePadding( );

			SetSize( _label->GetSize( ), updateDefaultStyle );

			ResetLabelPosition( );
		}

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetLabelStyle( const unsigned int &style, const bool &resize, const bool &updateDefaultStyle )
	{
		_label->SetStyle( style );

		if ( resize )
		{
			RecalculatePadding( );

			SetSize( _label->GetSize( ), updateDefaultStyle );

			ResetLabelPosition( );
		}



		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	unsigned int Button::GetLabelStyle( ) const
	{ return _label->GetStyle( ); }

	bool Button::IsStyleEnabled( const Label::STYLE &style ) const
	{ return _label->IsStyleEnabled( style ); }

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
				positionX = _background->GetPositionX( ) + ( _label->GetWidth( ) * GetScaleX( ) * 0.5f ) + ( paddingX * GetScaleX( ) ) - _background->GetPivotX( );

				break;

			case LABEL_ANCHOR_X::CENTER_X:
				positionX = _background->GetPositionX( ) + ( _background->GetWidth( ) * GetScaleX( ) * 0.5f ) - _background->GetPivotX( );

				break;

			case LABEL_ANCHOR_X::RIGHT:
				positionX = _background->GetPositionX( ) + ( _background->GetWidth( ) * GetScaleX( ) ) - ( _label->GetWidth( ) * GetScaleX( ) * 0.5f ) - ( paddingX * GetScaleX( ) ) - _background->GetPivotX( );

				break;
		}

		switch ( _anchorY )
		{
			case LABEL_ANCHOR_Y::TOP:
				positionY = _background->GetPositionY( ) + ( _label->GetHeight( ) * GetScaleY( ) * 0.5f ) + ( paddingY * GetScaleY( ) ) - ( _label->GetCharacterSize( ) * GetScaleY( ) * 0.5f ) + ( _label->GetCharacterSize( ) * GetScaleY( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

				break;

			case LABEL_ANCHOR_Y::CENTER_Y:
				positionY = _background->GetPositionY( ) + ( _background->GetHeight( ) * GetScaleY( ) * 0.5f ) - ( _label->GetCharacterSize( ) * GetScaleY( ) * 0.5f ) + ( _label->GetCharacterSize( ) * GetScaleY( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

				break;

			case LABEL_ANCHOR_Y::BOTTOM:
				positionY = _background->GetPositionY( ) + ( _background->GetHeight( ) * GetScaleY( ) ) - ( _label->GetHeight( ) * GetScaleY( ) * 0.5f ) - ( paddingY * GetScaleY( ) ) - ( _label->GetCharacterSize( ) * GetScaleY( ) * 0.5f ) + ( _label->GetCharacterSize( ) * GetScaleY( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX ) - _background->GetPivotY( );

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

	void Button::ToggleBackground( )
	{ _isBackgroundEnabled = !_isBackgroundEnabled; }

	void Button::EnableBackground( )
	{ _isBackgroundEnabled = true; }

	void Button::DisableBackground( )
	{ _isBackgroundEnabled = false; }

	const bool &Button::IsBackgroundEnabled( ) const
	{ return _isBackgroundEnabled; }

	bool Button::IsClicked( const Mouse::Button &button ) const
	{ return _background->IsClicked( button ); }

	bool Button::IsMouseOver( ) const
	{ return _background->IsMouseOver( ); }

	void Button::Update( )
	{
		if ( IsMouseOver( ) )
		{ SetButtonStyle( _hoverStyle, false ); }
		else
		{ SetButtonStyle( _defaultStyle, false ); }
	}

	void Button::SetButtonStyle( const Button::InteractStyle &style, const bool &updateDefaultStyle )
	{
		SetBackgroundInsideColor( Color( style._backgroundColor.GetRed( ), style._backgroundColor.GetGreen( ), style._backgroundColor.GetBlue( ) ), updateDefaultStyle );
		SetBackgroundBorderColor( Color( style._borderColor.GetRed( ), style._borderColor.GetGreen( ), style._borderColor.GetBlue( ) ), updateDefaultStyle );
		SetLabelInsideColor( Color( style._labelColor.GetRed( ), style._labelColor.GetGreen( ), style._labelColor.GetBlue( ) ), updateDefaultStyle );
		SetLabelBorderColor( Color( style._labelBorderColor.GetRed( ), style._labelBorderColor.GetGreen( ), style._labelBorderColor.GetBlue( ) ), updateDefaultStyle );

		SetCharacterSize( style._characterSize, false, updateDefaultStyle );
		SetLabelStyle( style._textStyle, false, updateDefaultStyle );

		SetBackgroundBorderThickness( style._borderThickness, updateDefaultStyle );
		SetLabelBorderThickness( style._labelBorderThickness, updateDefaultStyle );

		SetScale( style._scale, updateDefaultStyle );
	}

	void Button::SetHoverButtonStyle( const Button::InteractStyle &style )
	{ _hoverStyle = style; }

	const Sonar::Button::InteractStyle &Button::GetDefaultButtonStyle( ) const
	{ return _defaultStyle; }

	const Sonar::Button::InteractStyle &Button::GetHoverButtonStyle( ) const
	{ return _hoverStyle; }

	void Button::UpdateDefaultStyle( )
	{
		_defaultStyle._backgroundColor = _background->GetInsideColor( );
		_defaultStyle._borderColor = _background->GetBorderColor( );
		_defaultStyle._labelColor = _label->GetInsideColor( );
		_defaultStyle._labelBorderColor = _label->GetBorderColor( );
		_defaultStyle._characterSize = _label->GetCharacterSize( );
		_defaultStyle._textStyle = _label->GetStyle( );
		_defaultStyle._borderThickness = _background->GetBorderThickness( );
		_defaultStyle._labelBorderThickness = _background->GetBorderThickness( );
		_defaultStyle._scale = _background->GetScale( );
	}
}

