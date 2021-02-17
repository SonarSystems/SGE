#include "Graphics/Button.hpp"

namespace Sonar
{
	Button::Button( GameDataRef data ) : MenuComponent( data )
	{
		_buttonBackground = new Rectangle( _data );
		_buttonBackground->SetSize( 300, 50 );
		_buttonBackground->SetInsideColor( Color::Black );

		_buttonLabel = new Label( _data );
		_buttonLabel->SetFontFilePath( "Resources/arial.ttf" );
		_buttonLabel->SetInsideColor( Color::Red );
		_buttonLabel->SetCharacterSize( 32 );
		_buttonLabel->SetText( "CLICK ME!" );
	}

	Button::Button( GameDataRef data, const std::string &filepath ) : MenuComponent( data )
	{
		
	}

	Button::~Button( ) { }

	void Button::Draw( )
	{
		_buttonBackground->Draw( );
		_buttonLabel->Draw( );
	}
}

