#include "Graphics/Drawable.hpp"

namespace Sonar
{
    Drawable::Drawable( GameDataRef data ) : _data( data )
    {
        _rotation = 0;
        _scale[0] = _scale[1] = 1;
        _pivot[0] = _pivot[1] = 0;

		_initialPulseScale[0] = _initialPulseScale[1] = 1;
        _endPulseScale[0] = _endPulseScale[1] = 1;
        _timeBetweenPulses = Seconds( 0 );
        _pulseAmount = 0;
        _pulseCounter = 0;
    }

    Drawable::~Drawable( ) { }

    void Drawable::Draw( )
    {
		// Check if the object is within the visible window
		// If not cull it
		if ( _position.x + ( _size.x * _scale[0] ) < 0 // Check if it's beyond the left boundary
			|| _position.x > _data->window.getSize( ).x // Check if it's beyond the right boundary
			|| _position.y + ( _size.y * _scale[1] ) < 0 // Check if it's beyond the top boundary
			|| _position.y > _data->window.getSize( ).y // Check if it's beyond the bottom boundary
			)
		{ return; }

		_data->window.draw( *_object );
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

	void Drawable::SetSize( const glm::vec2 &size )
	{ _size = size; }

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

	void Drawable::SetRotation( const float &angle )
	{ _rotation = angle; }

	float Drawable::GetRotation( ) const
    { return _rotation; }

	void Drawable::SetScale( const float &xScale, const float &yScale )
	{
        _scale[0] = xScale;
        _scale[1] = yScale;
	}

	void Drawable::SetScale( const glm::vec2 &scale )
	{ _scale = scale; }

	void Drawable::SetScaleX( const float &xScale )
	{ _scale[0] = xScale; }

	void Drawable::SetScaleY( const float &yScale )
	{ _scale[1] = yScale; }

	glm::vec2 Drawable::GetScale( ) const
	{ return _scale; }

	float Drawable::GetScaleX( ) const
	{ return _scale[0]; }

	float Drawable::GetScaleY( ) const
    { return _scale[1]; }

	void Drawable::SetPivot( const float &xPoint, const float &yPoint )
	{
        _pivot[0] = xPoint;
        _pivot[1] = yPoint;
	}

	void Drawable::SetPivot( const glm::vec2 &pivot )
	{ _pivot = pivot; }

	void Drawable::SetPivot( const OBJECT_POINTS &pivot )
	{
        switch ( pivot )
        {
			case OBJECT_POINTS::CENTER:
				SetPivot( _size[0] * 0.5f, _size[1] * 0.5f );

				break;

			case OBJECT_POINTS::TOP_LEFT:
				SetPivot( 0, 0 );

				break;

			case OBJECT_POINTS::TOP_RIGHT:
				SetPivot( _size[0], 0 );

				break;

			case OBJECT_POINTS::BOTTOM_LEFT:
				SetPivot( 0, _size[1] );

				break;

			case OBJECT_POINTS::BOTTOM_RIGHT:
				SetPivot( _size[0], _size[1] );

				break;
        }
	}

	void Drawable::SetPivotX( const float &xPoint )
	{ _pivot[0] = xPoint; }

	void Drawable::SetPivotY( const float &yPoint )
    { _pivot[1] = yPoint; }

	glm::vec2 Drawable::GetPivot( ) const
	{ return _pivot; }

	float Drawable::GetPivotX( ) const
	{ return _pivot[0]; }

	float Drawable::GetPivotY( ) const
    { return _pivot[1]; }

	void Drawable::SetPulse( const float &endScaleX, const float &endScaleY, const Time &timeBetweenPulses, const int &pulseAmount )
	{
        _initialPulseScale = glm::vec2( GetScaleX( ), GetScaleY( ) );
        _endPulseScale = glm::vec2( endScaleX, endScaleY );
        _timeBetweenPulses = timeBetweenPulses;

        _pulseAmount = pulseAmount;

		_clock.Reset( );
	}

	glm::vec2 Drawable::GetPulse( ) const
	{ return _endPulseScale; }

	int Drawable::GetPulseAmount( ) const
	{ return +_pulseAmount; }

	int Drawable::GetPulseCounter( ) const
	{ return _pulseCounter; }

	void Drawable::StopPulse( )
	{
		_pulseCounter = 0;
		_endPulseScale = _initialPulseScale;

		SetScale( _initialPulseScale );
	}

	void Drawable::Update( const float &dt )
	{
		if ( ( _pulseAmount > 0 && _pulseCounter < _pulseAmount ) || 0 == _pulseAmount )
		{
			if ( _clock.GetElapsedTime( ).AsMicroseconds( ) > _timeBetweenPulses.AsMicroseconds( ) )
			{
				_clock.Reset( );
				_pulseCounter++;
			}
			else
			{
				if ( _clock.GetElapsedTime( ).AsMicroseconds( ) < _timeBetweenPulses.AsMicroseconds( ) / 2 )
				{
					float multiplier = _clock.GetElapsedTime( ).AsSeconds( ) / ( _timeBetweenPulses.AsSeconds( ) * 0.5f );

					glm::vec2 pulseDelta = glm::vec2( _initialPulseScale[0], _initialPulseScale[1] ) - _endPulseScale;
					glm::vec2 interimPulse = glm::vec2( _initialPulseScale[0], _initialPulseScale[1] ) - ( pulseDelta * multiplier );

					SetScale( interimPulse );
				}
				else
				{
					float interimPulseX;
					float interimPulseY;

					float halfTotalTime = _timeBetweenPulses.AsSeconds( ) / 2;

					if ( _endPulseScale[0] < _initialPulseScale[0] )
					{ interimPulseX = _endPulseScale[0] + ( ( ( _clock.GetElapsedTime( ).AsSeconds( ) - halfTotalTime ) / halfTotalTime ) * ( _initialPulseScale[0] - _endPulseScale[0] ) ); }
					else
					{ interimPulseX = _endPulseScale[0] - ( ( ( _clock.GetElapsedTime( ).AsSeconds( ) - halfTotalTime ) / halfTotalTime ) * ( _endPulseScale[0] - _initialPulseScale[0] ) ); }

					if ( _endPulseScale[1] < _initialPulseScale[1] )
					{ interimPulseY = _endPulseScale[1] + ( ( ( _clock.GetElapsedTime( ).AsSeconds( ) - halfTotalTime ) / halfTotalTime ) * ( _initialPulseScale[1] - _endPulseScale[1] ) ); }
					else
					{ interimPulseY = _endPulseScale[1] - ( ( ( _clock.GetElapsedTime( ).AsSeconds( ) - halfTotalTime ) / halfTotalTime ) * ( _endPulseScale[1] - _initialPulseScale[1] ) ); }

					SetScale( interimPulseX, interimPulseY );
				}
			}
        }
	}

	bool Drawable::IsClicked( const Mouse::Button &button ) const
    {
        if ( sf::Mouse::isButtonPressed( ( sf::Mouse::Button )button ) )
        {
            sf::IntRect buttonRect( _position.x, _position.y, _size.x, _size.y );

            if ( buttonRect.contains( sf::Mouse::getPosition( _data->window ) ) )
            { return true; }
        }

        return false;
    }
	
	bool Drawable::IsMouseOver( ) const
	{
		sf::IntRect buttonRect( _position.x, _position.y, _size.x, _size.y );

		if ( buttonRect.contains( sf::Mouse::getPosition( _data->window ) ) )
		{ return true; }
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

	bool Drawable::CircleCollision( const Drawable &object ) const
	{
		sf::FloatRect shape1 = _globalBounds; // This object
		sf::FloatRect shape2 = sf::FloatRect( object.GetGlobalBounds( )[0], object.GetGlobalBounds( )[1], object.GetGlobalBounds( )[2], object.GetGlobalBounds( )[3] ); // Passed in object

		float dx = ( _position[0] + ( shape1.width / 2 ) ) - ( object.GetPositionX( ) + ( shape2.width / 2 ) );
		float dy = ( _position[1] + ( shape1.height / 2 ) ) - ( object.GetPositionY( ) + ( shape2.height / 2 ) );
		float distance = std::sqrt( ( dx * dx ) + ( dy * dy ) );

		if ( distance <= ( shape1.width / 2 ) + ( shape2.width / 2 ) )
		{ return true; }
		else
		{ return false; }
	}

	glm::vec4 Drawable::GetGlobalBounds( ) const
	{ return glm::vec4( _globalBounds.left, _globalBounds.top, _globalBounds.width, _globalBounds.height); }

}

