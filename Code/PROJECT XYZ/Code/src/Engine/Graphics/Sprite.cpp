#include "Graphics/Sprite.hpp"

namespace Sonar
{
    Sprite::Sprite( GameDataRef data ) : Drawable( data )
    {
        
    }

    Sprite::Sprite( GameDataRef data, const std::string &filepath ) : Drawable( data )
    {
        _texture.loadFromFile( filepath );
        _sprite.setTexture( _texture );
    }

    Sprite::~Sprite( ) { }

	void Sprite::SetPosition( const float &x, const float &y )
	{
		Drawable::SetPosition( x, y );
		_sprite.setPosition( x, y );
	}

	void Sprite::SetPositionX( const float &x )
	{
		Drawable::SetPositionX( x );
		_sprite.setPosition( x, _sprite.getPosition( ).y );
	}

	void Sprite::SetPositionY( const float &y )
	{
		Drawable::SetPositionY( y );
		_sprite.setPosition( _sprite.getPosition( ).x, y );
	}

	void Sprite::SetColor( const Color &color )
	{ _sprite.setColor( sf::Color( color.GetRed( ), color.GetGreen( ), color.GetBlue( ), color.GetAlpha( ) ) ); }

	Color Sprite::GetColor( ) const
	{ return Color( _sprite.getColor( ).r, _sprite.getColor( ).g, _sprite.getColor( ).b, _sprite.getColor( ).a  ); }

	void Sprite::Move( const float &x, const float &y )
	{
		Drawable::Move( x, y );
		_sprite.move( x, y );
	}

	void Sprite::MoveX( const float &x )
	{
		Drawable::MoveX( x );
		_sprite.move( x, 0 );
	}

	void Sprite::MoveY( const float &y )
	{
		Drawable::MoveY( y );
		_sprite.move( 0, y );
	}
}

