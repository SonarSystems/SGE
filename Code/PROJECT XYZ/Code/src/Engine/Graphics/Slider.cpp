#include "Graphics/Slider.hpp"

namespace Sonar
{
	Slider::Slider( GameDataRef data ) : _data( data )
	{
		_background = new Rectangle( _data );
		_knob = new Circle( _data );

		_isMouseDownOverKnob = false;

		_value = DEFAULT_SLIDER_CURRENT_VALUE;
		_minimumValue = DEFAULT_SLIDER_MINIMUM_VALUE;
		_maximumValue = DEFAULT_SLIDER_MAXIMUM_VALUE;
		_jumpAmount = DEFAULT_SLIDER_JUMP_AMOUNT;

		_buttonToClick = DEFAULT_SLIDER_MOUSE_BUTTON;

		SetBackgroundColor( DEFAULT_SLIDER_BACKGROUND_COLOR );
		SetBackgroundBorderThickness( DEFAULT_SLIDER_BACKGROUND_BORDER_THICKNESS );
		SetBackgroundBorderColor( DEFAULT_SLIDER_BACKGROUND_BORDER_COLOR );

		SetKnobColor( DEFAULT_SLIDER_KNOB_COLOR );
		SetKnobBorderThickness( DEFAULT_SLIDER_KNOB_BORDER_THICKNESS );
		SetKnobBorderColor( DEFAULT_SLIDER_KNOB_BORDER_COLOR );

		SetBackgroundSize( DEFAULT_SLIDER_BACKGROUND_WIDTH, DEFAULT_SLIDER_BACKGROUND_HEIGHT );
		SetKnobRadius( DEFAULT_SLIDER_KNOB_RADIUS );

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

	void Slider::PollInput( const float &dt, const Event &event )
	{
		if ( Event::MouseButtonPressed == event.type )
		{
			if ( event.mouseButton.button == _buttonToClick )
			{
				if ( _knob->IsClicked( _buttonToClick ) || _background->IsClicked( _buttonToClick ) )
				{
					_isMouseDownOverKnob = true;
					MoveKnob( event.mouseButton.x );
				}
			}
		}
		else if ( Event::MouseButtonReleased == event.type )
		{
			if ( event.mouseButton.button == _buttonToClick )
			{ _isMouseDownOverKnob = false; }
		}
		else if ( Event::MouseMoved == event.type )
		{
			if ( _isMouseDownOverKnob )
			{ MoveKnob( event.mouseMove.x ); }
		}
	}

	void Slider::MoveKnob( const float &xPosition )
	{
		float scale = _background->GetScaleX( );
		float knobRadiusScaled = _knob->GetRadius( ) * scale;
		float backgroundWidthScaled = _background->GetWidth( ) * scale;
		float backgroundXPosition = _background->GetPositionX( );

		if ( xPosition - knobRadiusScaled >= backgroundXPosition - knobRadiusScaled
			&& xPosition - knobRadiusScaled <= backgroundXPosition + backgroundWidthScaled - knobRadiusScaled )
		{
			_knob->SetPositionX( xPosition - knobRadiusScaled );

			float percentageMovedNormalised = ( ( _knob->GetPositionX( ) + knobRadiusScaled ) - backgroundXPosition ) / ( ( backgroundXPosition + backgroundWidthScaled ) - backgroundXPosition );

			_value = ( _maximumValue - _minimumValue ) * percentageMovedNormalised;

			_value = _jumpAmount * round( _value / _jumpAmount );

			if ( _value > _maximumValue )
			{ _value = _maximumValue; }
			else if ( _value < _minimumValue )
			{ _value = _minimumValue; }

			SetPosition( _background->GetPosition( ) );
		}
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
			position.x - ( _knob->GetWidth( ) * 0.5 * _knob->GetScaleX( ) ) + ( _background->GetWidth( ) * percentAlongNormalised * _background->GetScaleX( ) ),
			position.y + ( _background->GetHeight( ) * 0.5 * _background->GetScaleX( ) ) - ( _knob->GetHeight( ) * 0.5 * _knob->GetScaleX( ) )
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
	{
		_background->SetSize( size );
		SetPosition( _background->GetPosition( ) );
	}

	void Slider::SetBackgroundSize( const float &width, const float &height )
	{ SetBackgroundSize( glm::vec2( width, height ) ); }

	void Slider::SetBackgroundWidth( const float &width )
	{ SetBackgroundSize( glm::vec2( width, _background->GetHeight( ) ) ); }

	void Slider::SetBackgroundHeight( const float &height )
	{ SetBackgroundSize(glm::vec2(  _background->GetWidth( ), height ) ); }

	glm::vec2 Slider::GetBackgroundSize( ) const
	{ return _background->GetSize( ); }

	float Slider::GetBackgroundWidth( ) const
	{ return _background->GetWidth( ); }

	float Slider::GetBackgroundHeight( ) const
	{ return _background->GetHeight( ); }

	void Slider::SetKnobRadius( const float &radius )
	{
		_knob->SetRadius( radius );
		SetPosition( _background->GetPosition( ) );
	}

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
		_background->SetScale( scale, scale );
		_knob->SetScale( scale, scale );

		SetPosition( _background->GetPosition( ) );
	}

	void Slider::Scale( const float &scale )
	{
		_background->Scale( scale, scale );
		_knob->Scale( scale, scale );

		SetPosition( _background->GetPosition( ) );
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
		else if ( value < _minimumValue )
		{
			_value = _minimumValue;
			SetPosition( GetPosition( ) );
		}
		else if ( value > _maximumValue )
		{
			_value = _maximumValue;
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
	{ SetValue( _value + _jumpAmount ); }

	void Slider::Decrement( )
	{ SetValue( _value - _jumpAmount ); }

	void Slider::SetJumpAmount( const float &value )
	{ _jumpAmount = value; }

	const float &Slider::GetJumpAmount( ) const
	{ return _jumpAmount; }

	bool Slider::IsMouseOver( ) const
	{ return _background->IsMouseOver( ) || _knob->IsMouseOver( ); }
}

