#include "Graphics/Button.hpp"

#define DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX 19.0f / 128.0f

namespace Sonar
{
	Button::Button( GameDataRef data ) //: MenuComponent( data )
	{
		_buttonBackground = new Rectangle( data );
		_buttonBackground->SetSize( 400, 128 );
		_buttonBackground->SetInsideColor( Color::Black );
		_buttonBackground->SetPosition( 250, 300 );

		_buttonLabel = new Label( data );
		_buttonLabel->SetFontFilePath( "Resources/consola.ttf" );
		_buttonLabel->SetInsideColor( Color::Red );
		_buttonLabel->SetCharacterSize( 64 );
		_buttonLabel->SetPosition
		(
			_buttonBackground->GetPositionX( ) + ( _buttonBackground->GetWidth( ) * 0.5f ),
			_buttonBackground->GetPositionY( ) + ( _buttonBackground->GetHeight( ) * 0.5f ) - ( _buttonLabel->GetCharacterSize( ) * 0.5f ) + ( _buttonLabel->GetCharacterSize( ) * DODGY_LABEL_TEXT_HEIGHT_RATIO_FIX )
		);
		_buttonLabel->SetText( "HELLO WORLD" );
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
}

