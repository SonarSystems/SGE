#include "pch.hpp"

namespace Sonar
{
	Checkbox::Checkbox( GameDataRef data ) : _data( data )
	{
		_outerLayer = new Rectangle( _data );
		_insideLayer = new Rectangle( _data );

		_outerLayer->SetSize( DEFAULT_CHECKBOX_OUTER_LAYER_SIZE );
		_outerLayer->SetBorderThickness( DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_THICKNESS );
		_outerLayer->SetBorderColor( DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_COLOR );
		_outerLayer->SetInsideColor( DEFAULT_CHECKBOX_OUTSIDE_LAYER_INSIDE_COLOR );
		_outerLayer->SetPosition( 0, 0 );

		SetSize( GetSize( ) );

		_insideLayer->SetInsideColor( DEFAULT_CHECKBOX_INSIDE_LAYER_INSIDE_COLOR );
		_checkedColor = _insideLayer->GetInsideColor( );
		_insideLayer->SetPosition
		(
			GetPositionX( ) + ( GetSize( ) * 0.5f ) - ( _insideLayer->GetWidth( ) * 0.5f ),
			GetPositionY( ) + ( GetSize( ) * 0.5f ) - ( _insideLayer->GetHeight( ) * 0.5f )
		);

		_buttonToClick = DEFAULT_CHECKBOX_CLICKED_MOUSE_BUTTON;

		_isSelected = DEFAULT_CHECKBOX_IS_CLICKED_STATUS;

		_isMouseDown = false;
	}

	Checkbox::~Checkbox( ) { }

	void Checkbox::Draw( )
	{
		_outerLayer->Draw( );

		if ( _isSelected )
		{ _insideLayer->Draw( ); }
	}

	void Checkbox::Update( const float &dt )
	{
		_outerLayer->Update( dt );
		_insideLayer->Update( dt );

		if ( _outerLayer->IsClicked( _buttonToClick ) )
		{
			if ( !_isMouseDown )
			{
				_isSelected = !_isSelected;
				_isMouseDown = true;
			}
		}
		else if ( _outerLayer->IsMouseOver( ) )
		{
			Color checkedColor = _checkedColor;
			checkedColor.SetAlpha( ( unsigned int )( checkedColor.GetAlpha( ) * DEFAULT_CHECKBOX_IS_MOUSE_OVER_ALPHA_MULTIPLIER ) );

			_insideLayer->SetInsideColor( checkedColor );

			_isMouseDown = false;
		}
		else
		{
			_insideLayer->SetInsideColor( _checkedColor );

			_isMouseDown = false;
		}
	}

	void Checkbox::PollInput( const float &dt, const Event &event ) { }

	void Checkbox::SetTheme( const MenuComponent::Theme &theme )
	{
		switch ( theme )
		{
			case MenuComponent::Theme::DARK:
				SetColor( Color::Black );
				SetCheckedColor( Color::Black );
				SetInsideColor( Color::White );

				break;

			case MenuComponent::Theme::LIGHT:
				SetColor( Color::White );
				SetCheckedColor( Color::White );
				SetInsideColor( Color::Black );

				break;
		}
	}

	glm::vec4 Checkbox::GetLocalBounds( ) const
	{ return _outerLayer->GetLocalBounds( ); }

	glm::vec4 Checkbox::GetGlobalBounds( ) const
	{ return _outerLayer->GetGlobalBounds( ); }

	void Checkbox::SetPosition( const glm::vec2 &position )
	{
		_outerLayer->SetPosition( position );

		_insideLayer->SetPosition
		(
			position.x + ( GetSize( ) * 0.5f ) - ( _insideLayer->GetWidth( ) * 0.5f ),
			position.y + ( GetSize( ) * 0.5f ) - ( _insideLayer->GetHeight( ) * 0.5f )
		);
	}

	void Checkbox::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Checkbox::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, _outerLayer->GetPositionY( ) ) ); }

	void Checkbox::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( _outerLayer->GetPositionX( ), y ) ); }

	float Checkbox::GetPositionX( ) const
	{ return _outerLayer->GetPositionX( ); }

	float Checkbox::GetPositionY( ) const
	{ return _outerLayer->GetPositionY( ); }

	glm::vec2 Checkbox::GetPosition( ) const
	{ return _outerLayer->GetPosition( ); }

	void Checkbox::SetSize( const float &size )
	{
		_outerLayer->SetSize( size, size );
		_insideLayer->SetSize( size - ( _outerLayer->GetBorderThickness( ) * 2 ), size - ( _outerLayer->GetBorderThickness( ) * 2 ) );

		SetPosition( _outerLayer->GetPosition( ) );
	}

	float Checkbox::GetSize( ) const
	{ return _outerLayer->GetWidth( ); }

	void Checkbox::SetColor( const Color &color )
	{ _outerLayer->SetBorderColor( color ); }

	void Checkbox::SetInsideColor( const Color &color )
	{ _outerLayer->SetInsideColor( color ); }

	void Checkbox::SetCheckedColor( const Color &color )
	{
		_insideLayer->SetInsideColor( color );
		_checkedColor = color;
	}

	void Checkbox::SetBorderThickness( const float &thickness )
	{
		_outerLayer->SetBorderThickness( thickness );

		SetSize( GetSize( ) );
	}

	Sonar::Color Checkbox::GetColor( ) const
	{ return _outerLayer->GetBorderColor( ); }

	Sonar::Color Checkbox::GetInsideColor( ) const
	{ return _outerLayer->GetInsideColor( ); }

	Sonar::Color Checkbox::GetCheckedColor( ) const
	{ return _insideLayer->GetInsideColor( ); }

	float Checkbox::GetBorderThickness( ) const
	{ return _outerLayer->GetBorderThickness( ); }

	void Checkbox::Move( const glm::vec2 &offset )
	{
		_outerLayer->Move( offset );
		_insideLayer->Move( offset );
	}

	void Checkbox::Move( const float &x, const float &y )
	{
		_outerLayer->Move( x, y );
		_insideLayer->Move( x, y );
	}

	void Checkbox::MoveX( const float &x )
	{
		_outerLayer->MoveX( x );
		_insideLayer->MoveX( x );
	}

	void Checkbox::MoveY( const float &y )
	{
		_outerLayer->MoveY( y );
		_insideLayer->MoveY( y );
	}

	void Checkbox::SetScale( const float &scale )
	{
		_outerLayer->SetScale( scale, scale );
		_insideLayer->SetScale( scale, scale );

		SetPosition( GetPosition( ) );
	}

	void Checkbox::Scale( const float &scale )
	{
		_outerLayer->Scale( scale, scale );
		_insideLayer->Scale( scale, scale );

		SetPosition( GetPosition( ) );
	}

	float Checkbox::GetScale( ) const
	{ return _outerLayer->GetScaleX( ); }

	void Checkbox::SetMouseButtonToClick( const Mouse::Button &button )
	{ _buttonToClick = button; }

	const Sonar::Mouse::Button &Checkbox::GetMouseButtonToClick( ) const
	{ return _buttonToClick; }

	const bool &Checkbox::IsSelected( ) const
	{ return _isSelected; }
}

