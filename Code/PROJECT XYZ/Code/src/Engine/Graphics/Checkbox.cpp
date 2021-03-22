#include "Graphics/Checkbox.hpp"

namespace Sonar
{
	Checkbox::Checkbox( GameDataRef data ) : _data( data )
	{
		_outerLayer = new Rectangle( _data );
		_insideLayer = new Rectangle( _data );

		_outerLayer->SetSize( 100, 100 );
		_outerLayer->SetBorderThickness( 10 );
		_outerLayer->SetBorderColor( Color::Black );
		_outerLayer->SetInsideColor( Color::Transparent );
		_outerLayer->SetPosition( 40, 40 );

		_insideLayer->SetSize( 80, 80 );
		_insideLayer->SetInsideColor( Color::Black );
		_insideLayer->SetPosition
		(
			_outerLayer->GetPositionX( ) + ( _outerLayer->GetWidth( ) / 0.5 ) - ( _insideLayer->GetWidth( ) * 0.5 ),
			_outerLayer->GetPositionY( ) + ( _outerLayer->GetHeight( ) / 0.5 ) - ( _insideLayer->GetHeight( ) * 0.5 )
		);
	}

	Checkbox::~Checkbox( ) { }

	void Checkbox::Draw( )
	{
		_outerLayer->Draw( );
		_insideLayer->Draw( );
	}

	void Checkbox::Update( const float &dt )
	{
		_outerLayer->Update( dt );
		_insideLayer->Update( dt );
	}

	glm::vec4 Checkbox::GetLocalBounds( ) const
	{ return _outerLayer->GetLocalBounds( ); }

	glm::vec4 Checkbox::GetGlobalBounds( ) const
	{ return _outerLayer->GetGlobalBounds( ); }

	void Checkbox::SetPosition( const glm::vec2 &position )
	{

	}

	void Checkbox::SetPosition( const float &x, const float &y )
	{

	}

	void Checkbox::SetPositionX( const float &x )
	{

	}

	void Checkbox::SetPositionY( const float &y )
	{

	}

	void Checkbox::SetSize( const glm::vec2 &size )
	{

	}

	void Checkbox::SetSize( const float &width, const float &height )
	{

	}

	void Checkbox::SetWidth( const float &width )
	{

	}

	void Checkbox::SetHeight( const float &height )
	{

	}



	void Checkbox::SetColor( const Color &color )
	{

	}

	void Checkbox::SetCheckedColor( const Color &color )
	{

	}

	void Checkbox::SetBorderThickness( const float &thickness )
	{

	}


	Sonar::Color Checkbox::GetColor( ) const
	{ return _outerLayer->GetBorderColor( ); }

	Sonar::Color Checkbox::GetCheckedColor( ) const
	{ return _insideLayer->GetInsideColor( ); }

	float Checkbox::GetBorderThickness( ) const
	{ return _outerLayer->GetBorderThickness( ); }

	void Checkbox::Move( const glm::vec2 &offset )
	{

	}

	void Checkbox::Move( const float &x, const float &y )
	{

	}

	void Checkbox::MoveX( const float &x )
	{

	}

	void Checkbox::MoveY( const float &y )
	{

	}

	void Checkbox::SetRotation( const float &angle )
	{

	}

	void Checkbox::Rotate( const float &angle )
	{

	}

	float Checkbox::GetRotation( ) const
	{ return _outerLayer->GetRotation( ); }

	void Checkbox::SetScale( const float &xScale, const float &yScale )
	{

	}

	void Checkbox::SetScale( const glm::vec2 &scale )
	{

	}

	void Checkbox::SetScaleX( const float &xScale )
	{

	}

	void Checkbox::SetScaleY( const float &yScale )
	{

	}

	void Checkbox::Scale( const glm::vec2 &scale )
	{

	}

	void Checkbox::Scale( const float &xScale, const float &yScale )
	{

	}

	void Checkbox::ScaleX( const float &xScale )
	{

	}

	void Checkbox::ScaleY( const float &yScale )
	{

	}

	void Checkbox::SetPivot( const float &xPoint, const float &yPoint )
	{

	}

	void Checkbox::SetPivot( const glm::vec2 &pivot )
	{

	}

	void Checkbox::SetPivot( const OBJECT_POINTS &pivot )
	{

	}

	void Checkbox::SetPivotX( const float &xPoint )
	{

	}

	void Checkbox::SetPivotY( const float &yPoint )
	{

	}

	void Checkbox::SetMouseButtonToClick( const Mouse::Button &button )
	{ _buttonToClick = button; }

	const Sonar::Mouse::Button &Checkbox::GetMouseButtonToClick( ) const
	{ return _buttonToClick; }

}

