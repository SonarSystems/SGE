#include "Input/Sequence.hpp"

namespace Sonar
{
    Sequence::Sequence( )
    {
        _count = 0;
        _min = 0;
        _max = 100;
    }

    void Sequence::TickUp( const float &amount, const bool &canGoOver )
    {
        _count += amount;
        
        if ( !canGoOver && _count > _max )
        { _count = _max; }
    }

    void Sequence::TickDown( const float &amount, const bool &canGoUnder )
    {
        _count -= amount;
        
        if ( !canGoUnder && _count < _min )
        { _count = _min; }
    }

    float Sequence::GetCount( ) const
    { return _count; }
    
    float Sequence::GetMin( ) const
    { return _min; }

    float Sequence::GetMax( ) const
    { return _max; }


    void Sequence::MousePress( const Mouse::Button &button, const float &amount, const DIRECTION &direction, const bool &canGoBeyond )
    {
        if ( Mouse::IsPressed( button ) )
        {
			if ( DIRECTION::UP == direction )
			{ TickUp( amount, canGoBeyond ); }
			else
			{ TickDown( amount, canGoBeyond ); }
		}
    }

    void Sequence::KeyboardPress( const Keyboard::Key &key, const float &amount, const DIRECTION &direction, const bool &canGoBeyond )
    {
        if ( Keyboard::IsPressed( key ) )
		{
			if ( DIRECTION::UP == direction )
			{ TickUp( amount, canGoBeyond ); }
			else
			{ TickDown( amount, canGoBeyond ); }
		}
    }

    void Sequence::JoystickPress( const unsigned int joystickID, const unsigned int &button, const float &amount, const DIRECTION &direction, const bool &canGoBeyond )
    {
        if ( Joystick::IsPressed( joystickID, button ) )
		{
			if ( DIRECTION::UP == direction )
			{ TickUp( amount, canGoBeyond ); }
			else
			{ TickDown( amount, canGoBeyond ); }
		}
    }

    void Sequence::SetCount( const float &count )
    { _count = count; }

    void Sequence::SetMin( const float &min )
    { _min = min; }

    void Sequence::SetMax( const float &max )
    { _max = max; }

	Time Sequence::KeyboardPressedTimer( const Keyboard::Key &key )
	{
		if ( !Keyboard::IsPressed( key ) )
		{
			_clock.Reset( );
			
			// Return a time of 0 to overcome small time gap between reset and GetElapsedTime return statement
			return Time( 0 );
		}
		
		return _clock.GetElapsedTime( );
	}
	
	Time Sequence::MousePressedTimer( const Mouse::Button &button )
	{
		if ( !Mouse::IsPressed( button ) )
		{
			_clock.Reset( );
			
			// Return a time of 0 to overcome small time gap between reset and GetElapsedTime return statement
			return Time( 0 );
		}
		
		return _clock.GetElapsedTime( );
	}
	
	Time Sequence::JoystickPressedTimer( const unsigned int &joystick, const unsigned int &button )
	{
		if ( !Joystick::IsPressed( joystick, button ) )
		{
			_clock.Reset( );
			
			// Return a time of 0 to overcome small time gap between reset and GetElapsedTime return statement
			return Time( 0 );
		}
		
		return _clock.GetElapsedTime( );
	}
}
