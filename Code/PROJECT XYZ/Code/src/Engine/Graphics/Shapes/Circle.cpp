#include "Graphics/Shapes/Circle.hpp"

namespace Sonar
{
    Circle::Circle( GameDataRef data ) : Drawable( data )
    {
		object = &_shape;
		_texture = new Texture( );
    }

    Circle::Circle( GameDataRef data, const float &radius ) : Drawable( data )
    {
		object = &_shape;
		_texture = new Texture( );

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

	void Circle::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_shape.setRotation( angle );
	}

	float Circle::GetRotation( ) const
	{ return _shape.getRotation( ); }

	void Circle::SetScale( const float &xScale, const float &yScale )
	{
		Drawable::SetScale( xScale, yScale );
		_shape.setScale( xScale, yScale );
	}

	void Circle::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_shape.setScale( scale[0], scale[1] );
	}

	void Circle::SetScaleX( const float &xScale )
	{
		Drawable::SetScaleX( xScale );
		_shape.setScale( xScale, _shape.getScale( ).y );
	}

	void Circle::SetScaleY( const float &yScale )
	{
		Drawable::SetScaleX( yScale );
		_shape.setScale( _shape.getScale( ).x, yScale );
	}

	void Circle::SetPivot( const float &xPoint, const float &yPoint )
	{
		Drawable::SetPivot( xPoint, yPoint );
		_shape.setOrigin( xPoint, yPoint );
	}

	void Circle::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_shape.setOrigin( pivot[0], pivot[1] );
	}

	void Circle::SetPivot( const OBJECT_POINTS &pivot )
	{
		switch ( pivot )
		{
			case OBJECT_POINTS::CENTER:
				Drawable::SetPivot( OBJECT_POINTS::CENTER );
				_shape.setOrigin( _shape.getLocalBounds( ).width * 0.5f, _shape.getLocalBounds( ).height * 0.5f );

				break;

			case OBJECT_POINTS::TOP_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_LEFT );
				_shape.setOrigin( 0, 0 );

				break;

			case OBJECT_POINTS::TOP_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_RIGHT );
				_shape.setOrigin( _shape.getLocalBounds( ).width, 0 );

				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_LEFT );
				_shape.setOrigin( 0, _shape.getLocalBounds( ).height );

				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_RIGHT );
				_shape.setOrigin( _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height );

				break;
		}
	}

	void Circle::SetPivotX( const float &xPoint )
	{
		Drawable::SetPivotX( xPoint );
		_shape.setOrigin( xPoint, _shape.getOrigin( ).y );
	}

	void Circle::SetPivotY( const float &yPoint )
	{
		Drawable::SetPivotY( yPoint );
		_shape.setOrigin( _shape.getOrigin( ).x, yPoint );
	}

	void Circle::SetTexture( const std::string &filepath, const bool &resetRect )
	{
		_texture->SetTexture( filepath );
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Circle::SetTexture( Texture *texture, const bool &resetRect )
	{
		_texture = texture;
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Circle::SetTextureRect( const glm::ivec4 &rectangle )
	{ _shape.setTextureRect( sf::IntRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	void Circle::SetTextureRect( const int &left, const int &top, const int &width, const int &height )
	{ _shape.setTextureRect( sf::IntRect( left, top, width, height ) ); }

	Texture *Circle::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Circle::GetTextureRect( ) const
	{ return glm::ivec4( _shape.getTextureRect( ).left, _shape.getTextureRect( ).top, _shape.getTextureRect( ).width, _shape.getTextureRect( ).height ); }

	glm::vec4 Circle::GetLocalBounds( ) const
	{ return glm::vec4( _shape.getLocalBounds( ).left, _shape.getLocalBounds( ).top, _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height ); }

	glm::vec4 Circle::GetGlobalBounds( ) const
	{ return glm::vec4( _shape.getGlobalBounds( ).left, _shape.getGlobalBounds( ).top, _shape.getGlobalBounds( ).width, _shape.getGlobalBounds( ).height ); }

}

