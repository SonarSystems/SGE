#include "Graphics/RadioButton.hpp"

namespace Sonar
{
	RadioButton::RadioButton( GameDataRef data ) : _data( data )
	{
		_outerLayer = new Circle( _data );
		_insideLayer = new Circle( _data );

		_outerLayer->SetRadius( 50 );
		_outerLayer->SetBorderThickness( DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_THICKNESS );
		_outerLayer->SetBorderColor( DEFAULT_CHECKBOX_OUTSIDE_LAYER_BORDER_COLOR );
		_outerLayer->SetInsideColor( DEFAULT_CHECKBOX_OUTSIDE_LAYER_INSIDE_COLOR );
		_outerLayer->SetPosition( 0, 0 );

		SetRadius( GetRadius( ) );

		_insideLayer->SetInsideColor( DEFAULT_CHECKBOX_INSIDE_LAYER_INSIDE_COLOR );
		_checkedColor = _insideLayer->GetInsideColor( );
		_insideLayer->SetPosition
		(
			GetPositionX( ) + ( GetRadius( ) * 0.5 ) - ( _insideLayer->GetWidth( ) * 0.5 ),
			GetPositionY( ) + ( GetRadius( ) * 0.5 ) - ( _insideLayer->GetHeight( ) * 0.5 )
		);

		_buttonToClick = DEFAULT_CHECKBOX_CLICKED_MOUSE_BUTTON;

		_isSelected = DEFAULT_CHECKBOX_IS_CLICKED_STATUS;

		_isMouseDown = false;
	}

	RadioButton::~RadioButton( ) { }

	void RadioButton::Draw( )
	{
		_outerLayer->Draw( );

		if ( _isSelected )
		{ _insideLayer->Draw( ); }
	}

	void RadioButton::Update( const float &dt )
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
			checkedColor.SetAlpha( checkedColor.GetAlpha( ) * DEFAULT_CHECKBOX_IS_MOUSE_OVER_ALPHA_MULTIPLIER );

			_insideLayer->SetInsideColor( checkedColor );

			_isMouseDown = false;
		}
		else
		{
			_insideLayer->SetInsideColor( _checkedColor );

			_isMouseDown = false;
		}
	}

	glm::vec4 RadioButton::GetLocalBounds( ) const
	{ return _outerLayer->GetLocalBounds( ); }

	glm::vec4 RadioButton::GetGlobalBounds( ) const
	{ return _outerLayer->GetGlobalBounds( ); }

	void RadioButton::SetPosition( const glm::vec2 &position )
	{
		_outerLayer->SetPosition( position );

		_insideLayer->SetPosition
		(
			position.x + ( GetRadius( ) * 0.5 ) - ( _insideLayer->GetWidth( ) * 0.5 ),
			position.y + ( GetRadius( ) * 0.5 ) - ( _insideLayer->GetHeight( ) * 0.5 )
		);
	}

	void RadioButton::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void RadioButton::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, _outerLayer->GetPositionY( ) ) ); }

	void RadioButton::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( _outerLayer->GetPositionX( ), y ) ); }

	float RadioButton::GetPositionX( ) const
	{ return _outerLayer->GetPositionX( ); }

	float RadioButton::GetPositionY( ) const
	{ return _outerLayer->GetPositionY( ); }

	glm::vec2 RadioButton::GetPosition( ) const
	{ return _outerLayer->GetPosition( ); }

	void RadioButton::SetRadius( const float &radius )
	{
		_outerLayer->SetRadius( radius );
		_insideLayer->SetRadius( radius - ( _outerLayer->GetBorderThickness( ) * 2 ) );

		SetPosition( _outerLayer->GetPosition( ) );
	}

	float RadioButton::GetRadius( ) const
	{ return _outerLayer->GetRadius( ); }

	void RadioButton::SetColor( const Color &color )
	{
		_outerLayer->SetBorderColor( color );
	}

	void RadioButton::SetCheckedColor( const Color &color )
	{
		_insideLayer->SetInsideColor( color );
		_checkedColor = color;
	}

	void RadioButton::SetBorderThickness( const float &thickness )
	{
		_outerLayer->SetBorderThickness( thickness );

		SetRadius( GetRadius( ) );
	}

	Sonar::Color RadioButton::GetColor( ) const
	{ return _outerLayer->GetBorderColor( ); }

	Sonar::Color RadioButton::GetCheckedColor( ) const
	{ return _insideLayer->GetInsideColor( ); }

	float RadioButton::GetBorderThickness( ) const
	{ return _outerLayer->GetBorderThickness( ); }

	void RadioButton::Move( const glm::vec2 &offset )
	{
		_outerLayer->Move( offset );
		_insideLayer->Move( offset );
	}

	void RadioButton::Move( const float &x, const float &y )
	{
		_outerLayer->Move( x, y );
		_insideLayer->Move( x, y );
	}

	void RadioButton::MoveX( const float &x )
	{
		_outerLayer->MoveX( x );
		_insideLayer->MoveX( x );
	}

	void RadioButton::MoveY( const float &y )
	{
		_outerLayer->MoveY( y );
		_insideLayer->MoveY( y );
	}

	void RadioButton::SetScale( const float &scale )
	{
		_outerLayer->SetScale( scale, scale );
		_insideLayer->SetScale( scale, scale );

		SetPosition( GetPosition( ) );
	}

	void RadioButton::Scale( const float &scale )
	{
		_outerLayer->Scale( scale, scale );
		_insideLayer->Scale( scale, scale );

		SetPosition( GetPosition( ) );
	}

	float RadioButton::GetScale( ) const
	{ return _outerLayer->GetScaleX( ); }

	void RadioButton::SetMouseButtonToClick( const Mouse::Button &button )
	{ _buttonToClick = button; }

	const Sonar::Mouse::Button &RadioButton::GetMouseButtonToClick( ) const
	{ return _buttonToClick; }

	const bool &RadioButton::IsSelected( ) const
	{ return _isSelected; }
}

