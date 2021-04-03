#include "Graphics/Slider.hpp"

namespace Sonar
{
	Slider::Slider( GameDataRef data ) : _data( data )
	{
		_background = new Rectangle( _data );
		_knob = new Circle( _data );
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
		
	}

	void Slider::SetPosition( const float &x, const float &y )
	{

	}

	void Slider::SetPositionX( const float &x )
	{

	}

	void Slider::SetPositionY( const float &y )
	{

	}

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

	void Slider::SetColor( const Color &color )
	{
		
	}

	void Slider::SetCheckedColor( const Color &color )
	{
		
	}

	void Slider::SetBorderThickness( const float &thickness )
	{
		
	}

	Color Slider::GetColor( ) const
	{

	}

	Color Slider::GetCheckedColor( ) const
	{

	}

	float Slider::GetBorderThickness( ) const
	{

	}

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
}

