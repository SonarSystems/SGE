#include "pch.hpp"

namespace Sonar
{
    Rectangle::Rectangle( GameDataRef data ) : Drawable( data )
    {
		_object = &_shape;
		_texture = new Texture( );

        SetPosition( 0, 0 );
		_globalBounds = _shape.getGlobalBounds( );
    }

    Rectangle::Rectangle( GameDataRef data, const float &width, const float &height ) : Drawable( data )
    {
		_object = &_shape;
		_texture = new Texture( );

        SetPosition( 0, 0 );
        SetSize( width, height );
		_globalBounds = _shape.getGlobalBounds( );
    }

    Rectangle::~Rectangle( ) { }

	void Rectangle::SetPosition( const glm::vec2 &position )
	{
		Drawable::SetPosition( position );
		_shape.setPosition( position.x, position.y );
		_globalBounds = _shape.getGlobalBounds( );
	}

    void Rectangle::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Rectangle::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

    void Rectangle::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	void Rectangle::SetSize( const glm::vec2 &size )
	{
		Drawable::SetSize( size );
		_shape.setSize( sf::Vector2f( size.x, size.y ) );
		_globalBounds = _shape.getGlobalBounds( );
	}

    void Rectangle::SetSize( const float &width, const float &height )
	{ SetSize( glm::vec2( width, height ) ); }

	void Rectangle::SetWidth( const float &width )
	{ SetSize( glm::vec2( width, GetHeight( ) ) ); }

    void Rectangle::SetHeight( const float &height )
	{ SetSize( glm::vec2( GetWidth( ), height ) ); }

    void Rectangle::SetInsideColor( const Color &color )
    {
        Drawable::SetInsideColor( color );
        _shape.setFillColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderColor( const Color &color )
    {
        Drawable::SetBorderColor( color );
        _shape.setOutlineColor( color.GetColor( ) );
    }

    void Rectangle::SetBorderThickness( const float &thickness )
    {
        Drawable::SetBorderThickness( thickness );
        _shape.setOutlineThickness( thickness );
    }

	Color Rectangle::GetInsideColor( ) const
	{ return Color( _shape.getFillColor( ).r, _shape.getFillColor( ).g, _shape.getFillColor( ).b, _shape.getFillColor( ).a ); }

	Color Rectangle::GetBorderColor( ) const
	{ return Color( _shape.getOutlineColor( ).r, _shape.getOutlineColor( ).g, _shape.getOutlineColor( ).b, _shape.getOutlineColor( ).a ); }


	float Rectangle::GetBorderThickness( ) const
    { return _shape.getOutlineThickness( ); }

	void Rectangle::Move( const glm::vec2 &offset )
	{
		Drawable::Move( offset );
		_shape.move( offset.x, offset.y );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Rectangle::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void Rectangle::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

    void Rectangle::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void Rectangle::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_shape.setRotation( angle );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Rectangle::Rotate( const float &angle )
	{ SetRotation( GetRotation( ) + angle ); }

	float Rectangle::GetRotation( ) const
	{ return _shape.getRotation( ); }

	void Rectangle::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_shape.setScale( scale[0], scale[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Rectangle::SetScale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( xScale, yScale ) ); }

	void Rectangle::SetScaleX( const float &xScale )
	{ SetScale( glm::vec2( xScale, GetScaleY( ) ) ); }

	void Rectangle::SetScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), yScale ) ); }

	void Rectangle::Scale( const glm::vec2 & scale )
	{ SetScale( GetScaleX( ) * scale ); }

	void Rectangle::Scale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) * yScale ) ); }

	void Rectangle::ScaleX( const float &xScale )
	{ SetScale( glm::vec2( GetScaleX( ) * xScale, GetScaleY( ) ) ); }

	void Rectangle::ScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), GetScaleY( ) * yScale ) ); }

	void Rectangle::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_shape.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _shape.getGlobalBounds( );
	}

	void Rectangle::SetPivot( const float &xPoint, const float &yPoint )
	{ SetPivot( glm::vec2( xPoint, yPoint ) ); }

	void Rectangle::SetPivot( const OBJECT_POINTS &pivot )
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

	void Rectangle::SetPivotX( const float &xPoint )
	{ SetPivot( glm::vec2( xPoint, GetPivotY( ) ) ); }

	void Rectangle::SetPivotY( const float &yPoint )
	{ SetPivot( glm::vec2( GetPivotX( ), yPoint ) ); }

	void Rectangle::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	void Rectangle::SetTexture( const std::string &filepath, const bool &resetRect )
	{
		_texture->SetTexture( filepath );
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Rectangle::SetTexture( Texture *texture, const bool &resetRect )
	{
		_texture = texture;
		_shape.setTexture( _texture->GetTexture( ), resetRect );

		SetPosition( _shape.getPosition( ).x, _shape.getPosition( ).y );
	}

	void Rectangle::SetTextureRect( const glm::ivec4 &rectangle )
	{ _shape.setTextureRect( sf::IntRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	void Rectangle::SetTextureRect( const int &left, const int &top, const int &width, const int &height )
	{ SetTextureRect( glm::ivec4( left, top, width, height ) ); }

	Texture *Rectangle::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Rectangle::GetTextureRect( ) const
	{ return glm::ivec4( _shape.getTextureRect( ).left, _shape.getTextureRect( ).top, _shape.getTextureRect( ).width, _shape.getTextureRect( ).height ); }

	glm::vec4 Rectangle::GetLocalBounds( ) const
	{ return glm::vec4( _shape.getLocalBounds( ).left, _shape.getLocalBounds( ).top, _shape.getLocalBounds( ).width, _shape.getLocalBounds( ).height ); }

	glm::vec4 Rectangle::GetGlobalBounds( ) const
	{ return glm::vec4( _shape.getGlobalBounds( ).left, _shape.getGlobalBounds( ).top, _shape.getGlobalBounds( ).width, _shape.getGlobalBounds( ).height ); }

}

