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
		_insideLayer->SetInsideColor( Color::Red );
		_insideLayer->SetPosition
		(
			GetPositionX( ) + ( GetSize( ) * 0.5 ) - ( _insideLayer->GetWidth( ) * 0.5 ),
			GetPositionY( ) + ( GetSize( ) * 0.5 ) - ( _insideLayer->GetHeight( ) * 0.5 )
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
		_outerLayer->SetPosition( position );

		_insideLayer->SetPosition
		(
			position.x + ( GetSize( ) * 0.5 ) - ( _insideLayer->GetWidth( ) * 0.5 ),
			position.y + ( GetSize( ) * 0.5 ) - ( _insideLayer->GetHeight( ) * 0.5 )
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

	void Checkbox::SetCheckedColor( const Color &color )
	{ _insideLayer->SetInsideColor( color ); }

	void Checkbox::SetBorderThickness( const float &thickness )
	{
		_outerLayer->SetBorderThickness( thickness );

		SetSize( GetSize( ) );
	}

	Sonar::Color Checkbox::GetColor( ) const
	{ return _outerLayer->GetBorderColor( ); }

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

}

