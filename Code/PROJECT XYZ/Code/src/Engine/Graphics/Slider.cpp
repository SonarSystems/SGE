#include "Graphics/Slider.hpp"

namespace Sonar
{
	Slider::Slider( GameDataRef data ) : _data( data )
	{
		_background = new Rectangle( _data );
		_knob = new Circle( _data );

		_value = DEFAULT_SLIDER_CURRENT_VALUE;
		_minimumValue = DEFAULT_SLIDER_MINIMUM_VALUE;
		_maximumValue = DEFAULT_SLIDER_MAXIMUM_VALUE;

		SetBackgroundColor( DEFAULT_SLIDER_BACKGROUND_COLOR );
		SetBackgroundBorderThickness( DEFAULT_SLIDER_BACKGROUND_BORDER_THICKNESS );
		SetBackgroundBorderColor( DEFAULT_SLIDER_BACKGROUND_BORDER_COLOR );

		SetKnobColor( DEFAULT_SLIDER_KNOB_COLOR );
		SetKnobBorderThickness( DEFAULT_SLIDER_KNOB_BORDER_THICKNESS );
		SetKnobBorderColor( DEFAULT_SLIDER_KNOB_BORDER_COLOR );

		SetBackgroundSize( DEFAULT_SLIDER_BACKGROUND_WIDTH, DEFAULT_SLIDER_BACKGROUND_HEIGHT );
		SetKnobRadius( DEFAULT_SLIDER_KNOB_RADIUS );

		_background->SetPosition( 100, 100 );
		SetPosition( _background->GetPosition( ) );
	}

	Slider::~Slider( ) { }

	void Slider::Draw( )
	{
		_background->Draw( );
		_knob->Draw( );
	}

	void Slider::Update( const float &dt )
	{
		_background->Update( dt );
		_knob->Update( dt );
	}

	glm::vec4 Slider::GetLocalBounds( ) const
	{ return _background->GetLocalBounds( ); }

	glm::vec4 Slider::GetGlobalBounds( ) const
	{ return _background->GetGlobalBounds( ); }

	void Slider::SetPosition( const glm::vec2 &position )
	{
		_background->SetPosition( position );

		float percentAlongNormalised = ( _value - _minimumValue ) / ( _maximumValue - _minimumValue );

		_knob->SetPosition
		(
			position.x - ( _knob->GetWidth( ) * 0.5 ) + ( _background->GetWidth( ) * percentAlongNormalised ),
			position.y + ( _background->GetHeight( ) * 0.5 ) - ( _knob->GetHeight( ) * 0.5 )
		);
	}

	void Slider::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Slider::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void Slider::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	glm::vec2 Slider::GetPosition( ) const
	{ return _background->GetPosition( ); }

	float Slider::GetPositionX( ) const
	{ return _background->GetPositionX( ); }

	float Slider::GetPositionY( ) const
	{ return _background->GetPositionY( ); }

	void Slider::SetBackgroundSize( const glm::vec2 &size )
	{ _background->SetSize( size ); }

	void Slider::SetBackgroundSize( const float &width, const float &height )
	{ _background->SetSize( width, height ); }

	void Slider::SetBackgroundWidth( const float &width )
	{ _background->SetWidth( width ); }

	void Slider::SetBackgroundHeight( const float &height )
	{ _background->SetHeight( height ); }

	glm::vec2 Slider::GetBackgroundSize( ) const
	{ return _background->GetSize( ); }

	float Slider::GetBackgroundWidth( ) const
	{ return _background->GetWidth( ); }

	float Slider::GetBackgroundHeight( ) const
	{ return _background->GetHeight( ); }

	void Slider::SetKnobRadius( const float &radius )
	{ _knob->SetRadius( radius ); }

	float Slider::GetKnobRadius( ) const
	{ return _knob->GetRadius( ); }

	void Slider::SetBackgroundColor( const Color &color )
	{ _background->SetInsideColor( color ); }

	void Slider::SetBackgroundBorderThickness( const float &thickness )
	{ _background->SetBorderThickness( thickness ); }

	void Slider::SetBackgroundBorderColor( const Color &color )
	{ _background->SetBorderColor( color ); }

	Color Slider::GetBackgroundColor( ) const
	{ return _background->GetInsideColor( ); }

	float Slider::GetBackgroundBorderThickness( ) const
	{ return _background->GetBorderThickness( ); }

	Color Slider::GetBackgroundBorderColor( ) const
	{ return _background->GetBorderColor( ); }

	void Slider::SetKnobColor( const Color &color )
	{ _knob->SetInsideColor( color ); }

	void Slider::SetKnobBorderThickness( const float &thickness )
	{ _knob->SetBorderThickness( thickness ); }

	void Slider::SetKnobBorderColor( const Color &color )
	{ _knob->SetBorderColor( color ); }

	Color Slider::GetKnobColor( ) const
	{ return _knob->GetInsideColor( ); }

	float Slider::GetKnobBorderThickness( ) const
	{ return _knob->GetBorderThickness( ); }

	Color Slider::GetKnobBorderColor( ) const
	{ return _knob->GetBorderColor( ); }

	void Slider::Move( const glm::vec2 &offset )
	{
		_background->Move( offset );
		_knob->Move( offset );
	}

	void Slider::Move( const float &x, const float &y )
	{
		_background->Move( x, y );
		_knob->Move( x, y );
	}

	void Slider::MoveX( const float &x )
	{
		_background->MoveX( x );
		_knob->MoveX( x );
	}

	void Slider::MoveY( const float &y )
	{
		_background->MoveY( y );
		_knob->MoveY( y );
	}

	void Slider::SetScale( const float &scale )
	{
		
	}

	void Slider::Scale( const float &scale )
	{
		
	}

	float Slider::GetScale( ) const
	{ return _background->GetScaleX( ); }

	void Slider::SetMouseButtonToClick( const Mouse::Button &button )
	{ _buttonToClick = button; }

	const Mouse::Button &Slider::GetMouseButtonToClick( ) const
	{ return _buttonToClick; }

	void Slider::SetValue( const float &value )
	{
		if ( value >= _minimumValue && value <= _maximumValue )
		{
			_value = value;
			SetPosition( GetPosition( ) );
		}
	}

	const float &Slider::GetValue( ) const
	{ return _value; }

	void Slider::SetMinimumValue( const float &value )
	{
		if ( value < _maximumValue )
		{
			_minimumValue = value;

			SetValue( _value );
		}
	}

	void Slider::SetMaximumValue( const float &value )
	{
		if ( value > _minimumValue )
		{
			_maximumValue = value;

			SetValue( _value );
		}
	}

	const float &Slider::GetMinimumValue( ) const
	{ return _minimumValue; }

	const float &Slider::GetMaximumValue( ) const
	{ return _maximumValue; }

	void Slider::Increment( )
	{ SetValue( _value + 1 ); }

	void Slider::Decrement( )
	{ SetValue( _value - 1 ); }
}

