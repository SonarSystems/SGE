#include "Graphics/Drawable.hpp"

namespace Sonar
{
    Drawable::Drawable( GameDataRef data ) : _data( data ) { }

    Drawable::~Drawable( ) { }

    void Drawable::Draw( )
    {
		// Check if the object is within the visible window
		// If not cull it
		if ( _position.x + _size.x < 0 // Check if it's beyond the left boundary
			|| _position.x > _data->window.getSize( ).x // Check if it's beyond the right boundary
			|| _position.y + _size.y < 0 // Check if it's beyond the top boundary
			|| _position.y > _data->window.getSize( ).y // Check if it's beyond the bottom boundary
			)
		{ return; }

		_data->window.draw( *object );
	}

    void Drawable::SetPosition( const float &x, const float &y )
    {
        _position.x = x;
        _position.y = y;
    }

    void Drawable::SetPositionX( const float &x )
    { _position.x = x; }

    void Drawable::SetPositionY( const float &y )
    { _position.y = y; }

    float Drawable::GetPositionX( ) const
    { return _position.x; }

    float Drawable::GetPositionY( ) const
    { return _position.y; }

    glm::vec2 Drawable::GetPosition( ) const
    { return _position; }

    void Drawable::SetSize( const float &width, const float &height )
    {
        _size.x = width;
        _size.y = height;
    }

    void Drawable::SetWidth( const float &width )
    { _size.x = width; }

    void Drawable::SetHeight( const float &height )
    { _size.y = height; }
    
    float Drawable::GetWidth( ) const
    { return _size.x; }

    float Drawable::GetHeight( ) const
    { return _size.y; }

    glm::vec2 Drawable::GetSize( ) const
    { return _size; }

    void Drawable::SetInsideColor( const Color &color )
    { _color = color; }

    void Drawable::SetBorderColor( const Color &color )
    { _borderColor = color; }

    void Drawable::SetBorderThickness( const float &thickness )
    { _borderThickness = thickness; }

    Color Drawable::GetInsideColor( ) const
    { return _color; }

    Color Drawable::GetBorderColor( ) const
    { return _borderColor; }

    float Drawable::GetBorderThickness( ) const
    { return _borderThickness; }

    void Drawable::Move( const float &x, const float &y )
    {
        _position.x += x;
        _position.y += y;
    }

    void Drawable::MoveX( const float &x )
    { _position.x += x; }

    void Drawable::MoveY( const float &y )
    { _position.y += y; }

    bool Drawable::IsClicked( const Mouse::Button &button ) const
    {
        if ( sf::Mouse::isButtonPressed( ( sf::Mouse::Button )button ) )
        {
            sf::IntRect playButtonRect( _position.x, _position.y, _size.x, _size.y );

            if ( playButtonRect.contains( sf::Mouse::getPosition( _data->window ) ) )
            { return true; }
        }

        return false;
    }
	
	bool Drawable::BoundingBoxCollision( const Drawable &object ) const
	{
		if ( _position.x < object.GetPositionX( ) + object.GetWidth( ) &&
			_position.x + _size.x > object.GetPositionX( ) &&
			_position.y < object.GetPositionY( ) + object.GetHeight( ) &&
			_position.y + _size.y > object.GetPositionY( ) )
		{ return true; }
		else
		{ return false; }
	}
}

