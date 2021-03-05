#include "Graphics/Sprite.hpp"

namespace Sonar
{
    Sprite::Sprite( GameDataRef data ) : Drawable( data )
    {
		_object = &_sprite;
		_texture = new Texture( );

		_globalBounds = _sprite.getGlobalBounds( );
	}

    Sprite::Sprite( GameDataRef data, const std::string &filepath ) : Drawable( data )
    {
		_object = &_sprite;
		_texture = new Texture( );

		SetTexture( filepath );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	Sprite::Sprite( GameDataRef data, Texture *texture ) : Drawable( data )
	{
		_object = &_sprite;

		_texture = new Texture( );
		SetTexture( texture );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	Sprite::~Sprite( )
	{ delete _texture; }

	void Sprite::SetPosition( const glm::vec2 &position )
	{
		Drawable::SetPosition( position );
		_sprite.setPosition( position.x, position.y );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	void Sprite::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Sprite::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void Sprite::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	void Sprite::SetColor( const Color &color )
	{ _sprite.setColor( sf::Color( color.GetRed( ), color.GetGreen( ), color.GetBlue( ), color.GetAlpha( ) ) ); }

	Color Sprite::GetColor( ) const
	{ return Color( _sprite.getColor( ).r, _sprite.getColor( ).g, _sprite.getColor( ).b, _sprite.getColor( ).a  ); }

	void Sprite::Move( const glm::vec2 &offset )
	{
		Drawable::Move( offset );
		_sprite.move( offset.x, offset.y );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	void Sprite::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void Sprite::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void Sprite::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void Sprite::SetRotation( const float &angle )
	{
		Drawable::SetRotation( angle );
		_sprite.setRotation( angle );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	float Sprite::GetRotation( ) const
	{ return _sprite.getRotation( ); }

	void Sprite::SetScale( const glm::vec2 &scale )
	{
		Drawable::SetScale( scale[0], scale[1] );
		_sprite.setScale( scale[0], scale[1] );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	void Sprite::SetScale( const float &xScale, const float &yScale )
	{ SetScale( glm::vec2( xScale, yScale ) ); }

	void Sprite::SetScaleX( const float &xScale )
	{ SetScale( glm::vec2( xScale, GetScaleY( ) ) ); }

	void Sprite::SetScaleY( const float &yScale )
	{ SetScale( glm::vec2( GetScaleX( ), yScale ) ); }

	void Sprite::SetPivot( const glm::vec2 &pivot )
	{
		Drawable::SetPivot( pivot );
		_sprite.setOrigin( pivot[0], pivot[1] );
		_globalBounds = _sprite.getGlobalBounds( );
	}

	void Sprite::SetPivot( const float &xPoint, const float &yPoint )
	{ SetPivot( glm::vec2( xPoint, yPoint ) ); }

	void Sprite::SetPivot( const OBJECT_POINTS &pivot )
	{
		switch ( pivot )
		{
			case OBJECT_POINTS::CENTER:
				Drawable::SetPivot( OBJECT_POINTS::CENTER );
				_sprite.setOrigin( _sprite.getLocalBounds( ).width * 0.5f, _sprite.getLocalBounds( ).height * 0.5f );

				break;

			case OBJECT_POINTS::TOP_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_LEFT );
				_sprite.setOrigin( 0, 0 );

				break;

			case OBJECT_POINTS::TOP_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::TOP_RIGHT );
				_sprite.setOrigin( _sprite.getLocalBounds( ).width, 0 );

				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_LEFT );
				_sprite.setOrigin( 0, _sprite.getLocalBounds( ).height );

				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				Drawable::SetPivot( OBJECT_POINTS::BOTTOM_RIGHT );
				_sprite.setOrigin( _sprite.getLocalBounds( ).width, _sprite.getLocalBounds( ).height );

				break;
		}

		_globalBounds = _sprite.getGlobalBounds( );
	}

	void Sprite::SetPivotX( const float &xPoint )
	{ SetPivot( glm::vec2( xPoint, GetPivotY( ) ) ); }

	void Sprite::SetPivotY( const float &yPoint )
	{ SetPivot( glm::vec2( GetPivotX( ), yPoint ) ); }

	void Sprite::Update( const float &dt )
	{
		Drawable::Update( dt );

		SetScale( Drawable::GetScale( ) );
	}

	void Sprite::SetTexture( const std::string &filepath, const bool &resetRect )
	{
		_texture->SetTexture( filepath );
		_sprite.setTexture( *_texture->GetTexture( ), resetRect );

		SetPosition( _sprite.getPosition( ).x, _sprite.getPosition( ).y );
		SetSize( _sprite.getLocalBounds( ).width, _sprite.getLocalBounds( ).height );
	}

	void Sprite::SetTexture( Texture *texture, const bool &resetRect )
	{
		_texture = texture;
		_sprite.setTexture( *_texture->GetTexture( ), resetRect );

		SetPosition( _sprite.getPosition( ).x, _sprite.getPosition( ).y );
		SetSize( _sprite.getLocalBounds( ).width, _sprite.getLocalBounds( ).height );
	}

	void Sprite::SetTextureRect( const glm::ivec4 &rectangle )
	{ _sprite.setTextureRect( sf::IntRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	void Sprite::SetTextureRect( const int &left, const int &top, const int &width, const int &height )
	{ SetTextureRect( glm::ivec4( left, top, width, height ) ); }

	Texture *Sprite::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Sprite::GetTextureRect( ) const
	{ return glm::ivec4( _sprite.getTextureRect( ).left, _sprite.getTextureRect( ).top, _sprite.getTextureRect( ).width, _sprite.getTextureRect( ).height ); }

	glm::vec4 Sprite::GetLocalBounds( ) const
	{ return glm::vec4( _sprite.getLocalBounds( ).left, _sprite.getLocalBounds( ).top, _sprite.getLocalBounds( ).width, _sprite.getLocalBounds( ).height ); }

	glm::vec4 Sprite::GetGlobalBounds( ) const
	{ return glm::vec4( _sprite.getGlobalBounds( ).left, _sprite.getGlobalBounds( ).top, _sprite.getGlobalBounds( ).width, _sprite.getGlobalBounds( ).height ); }

	bool Sprite::PixelPerfectCollisionCheck( const Sprite &object, const unsigned char &alphaLimit /*= 0 */ )
	{ return Collision::PixelPerfectTest( _sprite, object.GetSFMLSprite( ), alphaLimit ); }

	const sf::Sprite &Sprite::GetSFMLSprite( ) const
	{ return _sprite; }
}

