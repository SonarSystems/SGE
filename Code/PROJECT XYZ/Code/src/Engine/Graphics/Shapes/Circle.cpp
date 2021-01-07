#include "Graphics/Shapes/Circle.hpp"

namespace Sonar
{
    Circle::Circle( GameDataRef data ) : Drawable( data )
    {
        object = &_shape;
    }

    Circle::Circle( GameDataRef data, const float &radius ) : Drawable( data )
    {
        object = &_shape;

        SetRadius( radius );
		SetInsideColor( Color::Black );
        SetPosition( 0, 0 );
        SetSize( radius );
		SetPointCount( 36 );
    }

    Circle::~Circle( ) { }

	void Circle::SetRadius( const float &radius )
	{ _shape.setRadius( radius ); }

	float Circle::GetRadius( ) const
	{ return _shape.getRadius( ); }

	void Circle::SetPointCount( const unsigned int &count )
	{ _shape.setPointCount( count ); }

	int Circle::GetPointCount( ) const
	{ return _shape.getPointCount( ); }

	void Circle::SetPosition( const float &x, const float &y )
	{
		Drawable::SetPosition( x, y );
		_shape.setPosition( x, y );
	}

	void Circle::SetPositionX( const float &x )
	{
		Drawable::SetPositionX( x );
		_shape.setPosition( x, _shape.getPosition( ).y );
	}

	void Circle::SetPositionY( const float &y )
	{
		Drawable::SetPositionY( y );
		_shape.setPosition( _shape.getPosition( ).x, y );
	}

	void Circle::SetSize( const float &radius )
	{
		Drawable::SetSize( radius * 2, radius * 2 );
	}

	void Circle::SetInsideColor( const Color &color )
	{
		Drawable::SetInsideColor( color );
		_shape.setFillColor( color.GetColor( ) );
	}

	void Circle::SetBorderColor( const Color &color )
	{
		Drawable::SetBorderColor( color );
		_shape.setOutlineColor( color.GetColor( ) );
	}

	void Circle::SetBorderThickness( const float &thickness )
	{
		Drawable::SetBorderThickness( thickness );
		_shape.setOutlineThickness( thickness );
	}

	Color Circle::GetInsideColor( ) const
	{ return Color( _shape.getFillColor( ).r, _shape.getFillColor( ).g, _shape.getFillColor( ).b, _shape.getFillColor( ).a ); }

	Color Circle::GetBorderColor( ) const
	{ return Color( _shape.getOutlineColor( ).r, _shape.getOutlineColor( ).g, _shape.getOutlineColor( ).b, _shape.getOutlineColor( ).a ); }


	float Circle::GetBorderThickness( ) const
	{ return _shape.getOutlineThickness( ); }

	void Circle::Move( const float &x, const float &y )
	{
		Drawable::Move( x, y );
		_shape.move( x, y );
	}

	void Circle::MoveX( const float &x )
	{
		Drawable::MoveX( x );
		_shape.move( x, 0 );
	}

	void Circle::MoveY( const float &y )
	{
		Drawable::MoveY( y );
		_shape.move( 0, y );
	}
}

