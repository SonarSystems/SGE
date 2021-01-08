#include "Graphics/Shapes/Triangle.hpp"

namespace Sonar
{
    Triangle::Triangle( GameDataRef data ) : Drawable( data )
    {
        object = &_shape;
    }

    Triangle::Triangle( GameDataRef data, const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 ) : Drawable( data )
    {
        object = &_shape;

		_shape.setPointCount( 3 );

		_shape.setPoint( 0, sf::Vector2f( point1.x, point1.y ) );
		_shape.setPoint( 1, sf::Vector2f( point2.x, point2.y ) );
		_shape.setPoint( 2, sf::Vector2f( point3.x, point3.y ) );

		SetInsideColor( Color::Black );
        SetPosition( 0, 0 );
        SetSize( point1, point2, point3 );
    }

    Triangle::~Triangle( ) { }

	void Triangle::SetPosition( const float &x, const float &y )
	{
		Drawable::SetPosition( x, y );
		_shape.setPosition( x, y );
	}

	void Triangle::SetPositionX( const float &x )
	{
		Drawable::SetPositionX( x );
		_shape.setPosition( x, _shape.getPosition( ).y );
	}

	void Triangle::SetPositionY( const float &y )
	{
		Drawable::SetPositionY( y );
		_shape.setPosition( _shape.getPosition( ).x, y );
	}

	void Triangle::SetSize( const glm::vec2 &point1, const glm::vec2 &point2, const glm::vec2 &point3 )
	{
		float xMin = point1.x, xMax = point1.x;
		float yMin = point1.y, yMax = point1.y;

		if ( point2.x < xMin )
		{ xMin = point2.x; }
		else if ( point2.x > xMax )
		{ xMax = point2.x; }

		if ( point3.x < xMin )
		{ xMin = point3.x; }
		else if ( point3.x > xMax )
		{ xMax = point3.x; }

		if ( point2.y < yMin )
		{ yMin = point2.y; }
		else if ( point2.y > yMax )
		{ yMax = point2.y; }

		if ( point3.y < yMin )
		{ yMin = point3.y; }
		else if ( point3.y > yMax )
		{ yMax = point3.y; }

		float width = xMax - xMin;
		float height = yMax - yMin;

		Drawable::SetSize( width, height );
	}

	void Triangle::SetInsideColor( const Color &color )
	{
		Drawable::SetInsideColor( color );
		_shape.setFillColor( color.GetColor( ) );
	}

	void Triangle::SetBorderColor( const Color &color )
	{
		Drawable::SetBorderColor( color );
		_shape.setOutlineColor( color.GetColor( ) );
	}

	void Triangle::SetBorderThickness( const float &thickness )
	{
		Drawable::SetBorderThickness( thickness );
		_shape.setOutlineThickness( thickness );
	}

	Color Triangle::GetInsideColor( ) const
	{ return Color( _shape.getFillColor( ).r, _shape.getFillColor( ).g, _shape.getFillColor( ).b, _shape.getFillColor( ).a ); }

	Color Triangle::GetBorderColor( ) const
	{ return Color( _shape.getOutlineColor( ).r, _shape.getOutlineColor( ).g, _shape.getOutlineColor( ).b, _shape.getOutlineColor( ).a ); }


	float Triangle::GetBorderThickness( ) const
	{ return _shape.getOutlineThickness( ); }

	void Triangle::Move( const float &x, const float &y )
	{
		Drawable::Move( x, y );
		_shape.move( x, y );
	}

	void Triangle::MoveX( const float &x )
	{
		Drawable::MoveX( x );
		_shape.move( x, 0 );
	}

	void Triangle::MoveY( const float &y )
	{
		Drawable::MoveY( y );
		_shape.move( 0, y );
	}
}

