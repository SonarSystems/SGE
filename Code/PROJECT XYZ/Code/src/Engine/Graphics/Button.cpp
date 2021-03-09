#include "Graphics/Button.hpp"

#define DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX 19.0f / 128.0f

namespace Sonar
{
	Button::Button( GameDataRef data ) : _data( data )
	{
		_minSize.x = -1; // NO MIN
		_minSize.y = -1; // NO MIN
		_maxSize.x = -1; // NO MIN
		_maxSize.y = -1; // NO MIN

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

		_hoverStyle._cursor = DEFAULT_BUTTON_HOVER_CURSOR;

		_clickedStyle._backgroundColor = DEFAULT_BUTTON_CLICKED_BACKGROUND_COLOR;
		_clickedStyle._borderColor = DEFAULT_BUTTON_CLICKED_BORDER_COLOR;
		_clickedStyle._labelColor = DEFAULT_BUTTON_CLICKED_LABEL_COLOR;
		_clickedStyle._labelBorderColor = DEFAULT_BUTTON_CLICKED_LABEL_BORDER_COLOR;
		_clickedStyle._characterSize = DEFAULT_BUTTON_CLICKED_LABEL_CHARACTER_SIZE;
		_clickedStyle._textStyle = DEFAULT_BUTTON_CLICKED_LABEL_TEXT_STYLE;
		_clickedStyle._borderThickness = DEFAULT_BUTTON_CLICKED_BORDER_THICKNESS;
		_clickedStyle._labelBorderThickness = DEFAULT_BUTTON_CLICKED_LABEL_BORDER_THICKNESS;
		_clickedStyle._scale = DEFAULT_BUTTON_CLICKED_SCALE;
		_clickedStyle._cursor = DEFAULT_BUTTON_CLICKED_CURSOR;

		_buttonToClick = DEFAULT_BUTTON_CLICKED_MOUSE_BUTTON;

		_isHoverEnabled = DEFAULT_BUTTON_HOVER_STATUS;
		_isClickEnabled = DEFAULT_BUTTON_CLICK_STATUS;
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
	{ SetPadding( glm::vec2( x, y ), updateDefaultStyle ); }

	void Button::SetPaddingX( const float &x, const bool &updateDefaultStyle )
	{ SetPadding( glm::vec2( x, _padding.y ), updateDefaultStyle ); }

	void Button::SetPaddingY( const float &y, const bool &updateDefaultStyle )
	{ SetPadding( glm::vec2( _padding.x, y ), updateDefaultStyle ); }

	const glm::vec2 &Button::GetPadding( ) const
	{ return _padding; }

	float Button::GetPaddingX( ) const
	{ return _padding.x; }

	float Button::GetPaddingY( ) const
	{ return _padding.y; }

	void Button::SetSize( const glm::vec2 &size, const bool &updateDefaultStyle )
	{
		glm::vec2 tempSize = size;

		if ( _minSize.x > 0 )
		{
			if ( tempSize.x < _minSize.x )
			{ tempSize.x = _minSize.x; };
		}

		if ( _minSize.y > 0 )
		{
			if ( tempSize.y < _minSize.y )
			{ tempSize.y = _minSize.y; };
		}

		if ( _maxSize.x > 0 )
		{
			if ( _maxSize.x < tempSize.x )
			{ tempSize.x = _maxSize.x; };
		}

		if ( _maxSize.y > 0 )
		{
			if ( _maxSize.y < tempSize.y )
			{ tempSize.y = _maxSize.y; };
		}

		_background->SetSize( tempSize + ( _padding * 2.0f ) );
		ResetLabelPosition( );

		if ( updateDefaultStyle )
		{ UpdateDefaultStyle( ); }
	}

	void Button::SetSize( const float &width, const float &height, const bool &updateDefaultStyle )
	{ SetSize( glm::vec2( width, height ), updateDefaultStyle ); }

	void Button::SetWidth( const float &width, const bool &updateDefaultStyle )
	{ SetSize( glm::vec2( width, _background->GetHeight( ) ), updateDefaultStyle ); }

	void Button::SetHeight( const float &height, const bool &updateDefaultStyle )
	{ SetSize( glm::vec2( _background->GetWidth( ), height ), updateDefaultStyle ); }

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
	{ SetPosition( glm::vec2( x, y ) ); }

	void Button::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void Button::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

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
	{ Move( glm::vec2( x, y ) ); }

	void Button::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void Button::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

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

	void Button::SetScale( const float &xScale, const float &yScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( xScale, yScale), updateDefaultStyle ); }

	void Button::SetScaleX( const float &xScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( xScale, GetScaleY( ) ), updateDefaultStyle ); }

	void Button::SetScaleY( const float &yScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( GetScaleX( ), yScale ), updateDefaultStyle ); }

	void Button::Scale( const glm::vec2 &scale, const bool &updateDefaultStyle )
	{ SetScale( _label->GetScale( ) * scale, updateDefaultStyle ); }

	void Button::Scale( const float &xScale, const float &yScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( _label->GetScaleX( ) * xScale, _label->GetScaleY( ) * yScale), updateDefaultStyle ); }

	void Button::ScaleX( const float &xScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( _label->GetScaleX( ) * xScale, GetScaleY( ) ), updateDefaultStyle ); }

	void Button::ScaleY( const float &yScale, const bool &updateDefaultStyle )
	{ SetScale( glm::vec2( GetScaleX( ), _label->GetScaleY( ) * yScale ), updateDefaultStyle ); }

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
		if ( IsClicked( _buttonToClick ) && _isClickEnabled )
		{ SetButtonStyle( _clickedStyle, false ); }
		else
		{
			if ( IsMouseOver( ) && _isHoverEnabled )
			{ SetButtonStyle( _hoverStyle, false ); }
			else
			{ SetButtonStyle( _defaultStyle, false ); }
		}
	}

	void Button::Update( const float &dt )
	{
		_label->Update( dt );
		_background->Update( dt );
	}

	void Button::SetButtonStyle( const Button::ButtonStyle &style, const bool &updateDefaultStyle )
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

		Mouse::ChangeCursor( style._cursor, _data->window );
	}

	void Button::SetHoverButtonStyle( const Button::ButtonStyle &style )
	{ _hoverStyle = style; }

	const Sonar::Button::ButtonStyle &Button::GetDefaultButtonStyle( ) const
	{ return _defaultStyle; }

	const Sonar::Button::ButtonStyle &Button::GetHoverButtonStyle( ) const
	{ return _hoverStyle; }

	void Button::EnableHover( )
	{ _isHoverEnabled = true; }

	void Button::DisableHover( )
	{ _isHoverEnabled = false; }

	void Button::ToggleHover( )
	{ _isHoverEnabled = !_isHoverEnabled; }

	bool Button::GetHoverStatus( )
	{ return _isHoverEnabled; }

	void Button::EnableClick( )
	{ _isClickEnabled = true; }

	void Button::DisableClick( )
	{ _isClickEnabled = false; }

	void Button::ToggleClick( )
	{ _isClickEnabled = !_isClickEnabled; }

	bool Button::GetClickStatus( )
	{ return _isClickEnabled; }

	void Button::SetMinimumSize( const glm::vec2 &size )
	{ _minSize = size; }

	void Button::SetMinimumSize( const float &width, const float &height )
	{ SetMinimumSize( glm::vec2( width, height ) ); }

	void Button::SetMinimumWidth( const float &width )
	{ SetMinimumSize( glm::vec2( width, _minSize.y ) ); }

	void Button::SetMinimumHeight( const float &height )
	{ SetMinimumSize( glm::vec2( _minSize.x, height ) ); }

	const glm::vec2 &Button::GetMinimumSize( ) const
	{ return _minSize; }

	float Button::GetMinimumWidth( ) const
	{ return _minSize.x; }

	float Button::GetMinimumHeight( ) const
	{ return _minSize.y; }

	void Button::SetMaximumSize( const glm::vec2 &size )
	{ _maxSize = size; }

	void Button::SetMaximumSize( const float &width, const float &height )
	{ SetMaximumSize( glm::vec2( width, height ) ); }

	void Button::SetMaximumWidth( const float &width )
	{ SetMaximumSize( glm::vec2( width, _maxSize.y ) ); }

	void Button::SetMaximumHeight( const float &height )
	{ SetMaximumSize( glm::vec2( _maxSize.x, height ) ); }

	const glm::vec2 &Button::GetMaximumSize( ) const
	{ return _maxSize; }

	float Button::GetMaximumWidth( ) const
	{ return _maxSize.x; }

	float Button::GetMaximumHeight( ) const
	{ return _maxSize.y; }

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
		_defaultStyle._cursor = Mouse::GetCurrentCursor( );
	}
}

