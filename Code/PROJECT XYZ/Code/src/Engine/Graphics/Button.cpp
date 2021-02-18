#include "Graphics/Button.hpp"

namespace Sonar
{
	Button::Button( GameDataRef data ) //: MenuComponent( data )
	{
		_buttonBackground = new Rectangle( data );
		_buttonBackground->SetSize( 300, 50 );
		_buttonBackground->SetInsideColor( Color::Black );

		_buttonLabel = new Label( data );
		_buttonLabel->SetFontFilePath( "Resources/arial.ttf" );
		_buttonLabel->SetInsideColor( Color::Red );
	}

	Button::~Button( ) { }

	void Button::Draw( )
	{
		_buttonBackground->Draw( );
		_buttonLabel->Draw( );
	}
}

