#include "Graphics/Sprite.hpp"

namespace Sonar
{
    Sprite::Sprite( GameDataRef data ) : Drawable( data )
    {
		object = &_sprite;
		_texture = new Texture( );
	}

    Sprite::Sprite( GameDataRef data, const std::string &filepath ) : Drawable( data )
    {
		object = &_sprite;

		_texture = new Texture( );
		SetTexture( filepath );
	}

	Sprite::Sprite( GameDataRef data, Texture *texture ) : Drawable( data )
	{
		object = &_sprite;

		_texture = new Texture( );
		SetTexture( texture );
	}

	Sprite::~Sprite( )
	{ delete _texture; }

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
	{ _sprite.setTextureRect( sf::IntRect( left, top, width, height ) ); }

	Texture *Sprite::GetTexture( ) const
	{ return _texture; }

	glm::ivec4 Sprite::GetTextureRect( ) const
	{ return glm::ivec4( _sprite.getTextureRect( ).left, _sprite.getTextureRect( ).top, _sprite.getTextureRect( ).width, _sprite.getTextureRect( ).height ); }

	glm::vec4 Sprite::GetLocalBounds( ) const
	{ return glm::vec4( _sprite.getLocalBounds( ).left, _sprite.getLocalBounds( ).top, _sprite.getLocalBounds( ).width, _sprite.getLocalBounds( ).height ); }

	glm::vec4 Sprite::GetGlobalBounds( ) const
	{ return glm::vec4( _sprite.getGlobalBounds( ).left, _sprite.getGlobalBounds( ).top, _sprite.getGlobalBounds( ).width, _sprite.getGlobalBounds( ).height ); }

}

