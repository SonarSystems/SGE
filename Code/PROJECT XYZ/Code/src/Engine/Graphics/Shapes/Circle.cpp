#include "pch.hpp"

namespace Sonar
{
    Circle::Circle( GameDataRef data ) : Drawable( data )
    {
		_object = &_shape;
		_texture = std::make_shared<Texture>( );

		_globalBounds = _shape.getGlobalBounds( );
    }

    Circle::Circle( GameDataRef data, const float &radius ) : Drawable( data )
    {
		_object = &_shape;
		_texture = std::make_shared<Texture>( );

        SetRadius( radius );
		SetInsideColor( Color::Black );
        SetPosition( 0, 0 );
        SetSize( radius );
		SetPointCount( 36 );
		_globalBounds = _shape.getGlobalBounds( );
    }

    Circle::~Circle( ) { }

	void Circle::SetRadius( const float &radius )
	{
		_shape.setRadius( radius );
		SetSize( radius );
	}

	float Circle::GetRadius( ) const
	{ return _shape.getRadius( ); }

	void Circle::SetPointCount( const unsigned int &count )
	{
		_shape.setPointCount( count );
		_globalBounds = _shape.getGlobalBounds( );
	}

	int Circle::GetPointCount( ) const
	{ return _shape.getPointCount( ); }

	void Circle::SetPosition( const glm::vec2 &position )
	{
		Drawable::SetPosition( position );
		_shape.setPosition( position.x, position.y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Circle::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void Circle::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	void Circle::SetSize( const float &radius )
	{
		Drawable::SetSize( radius * 2, radius * 2 );
		_globalBounds = _shape.getGlobalBounds( );
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

	void Circle::Move( const glm::vec2 &offset )
	{
		Drawable::Move( offset );
		_shape.move( offset.x, offset.y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void Circle::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void Circle::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void Circle::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_shape.setRotation( angle );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::Rotate( const float &angle )
	{ SetRotation( GetRotation( ) + angle ); }

	float Circle::GetRotation( ) const
	{ return _shape.getRotation( ); }

	void Circle::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_shape.setScale( scale[0], scale[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::SetScale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( xScale, yScale ) ); }

	void Circle::SetScaleX( const float &xScale )
	{ SetScale( glm::vec2( xScale, GetScaleY( ) ) ); }

	void Circle::SetScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), yScale ) ); }

	void Circle::Scale( const glm::vec2 &scale )
	{ SetScale( GetScaleX( ) * scale ); }

	void Circle::Scale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) * yScale ) ); }

	void Circle::ScaleX( const float &xScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) ) ); }

	void Circle::ScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), GetScaleY( ) * yScale ) ); }

	void Circle::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_shape.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::SetPivot( const float &xPoint, const float &yPoint )
	{ SetPivot( glm::vec2( xPoint, yPoint ) ); }

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

		_globalBounds = _shape.getGlobalBounds( );
	}

	void Circle::SetPivotX( const float &xPoint )
	{ SetPivot( glm::vec2( xPoint, GetPivotY( ) ) ); }

	void Circle::SetPivotY( const float &yPoint )
	{ SetPivot( glm::vec2( GetPivotX( ), yPoint ) ); }

	void Circle::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	void Circle::SetTexture( const std::string &filepath, const bool &resetRect )
	{
		_texture->SetTexture( filepath );
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Circle::SetTexture( std::shared_ptr<Texture> texture, const bool &resetRect )
	{
		_texture = texture;
		_shape.setTexture( _texture->GetTexture( ), resetRect ); 

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Circle::SetTextureRect( const glm::ivec4 &rectangle )
	{ _shape.setTextureRect( sf::IntRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	void Circle::SetTextureRect( const int &left, const int &top, const int &width, const int &height )
	{ SetTextureRect( glm::ivec4( left, top, width, height ) ); }

	std::shared_ptr<Texture>Circle::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Circle::GetTextureRect( ) const
	{ return glm::ivec4( _shape.getTextureRect( ).left, _shape.getTextureRect( ).top, _shape.getTextureRect( ).width, _shape.getTextureRect( ).height ); }

	glm::vec4 Circle::GetLocalBounds( ) const
	{ return glm::vec4( _shape.getLocalBounds( ).left, _shape.getLocalBounds( ).top, _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height ); }

	glm::vec4 Circle::GetGlobalBounds( ) const
	{ return glm::vec4( _shape.getGlobalBounds( ).left, _shape.getGlobalBounds( ).top, _shape.getGlobalBounds( ).width, _shape.getGlobalBounds( ).height ); }

}

