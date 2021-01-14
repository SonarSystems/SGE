#include "Core/Time.hpp"

namespace Sonar
{
	Time::Time( ) : _time( 0 )
	{ }

	Time::Time( const long long &microseconds ) : _time( microseconds )
	{ }

	float Time::AsSeconds( ) const
	{ return _time * 0.000001f; }

	float Time::AsMilliseconds( ) const
	{ return static_cast<float>( _time * 0.001f ); }

	long long Time::AsMicroseconds( ) const
	{ return _time; }

	Time Seconds( const float &amount )
	{ return Time( static_cast<long long>( amount * 1000000 ) ); }

	Time Milliseconds( const float &amount )
	{ return Time( static_cast<long long>( amount ) * 1000 ); }

	Time Microseconds( const long long &amount )
	{ return Time( amount ); }

	static float SecondsToMilliseconds( float seconds )
	{ return seconds * 1000.0f; }

	static long long SecondsToMicroseconds( float seconds )
	{ return seconds * 1000000; }

	static float MillisecondsToSeconds( float milliseconds )
	{ return milliseconds * 0.001f; }

	static long long MillisecondsToMicroseconds( float milliseconds )
	{ return milliseconds * 1000; }

	static float MicrosecondsToSeconds( long long microseconds )
	{ return microseconds * 0.000001f; }

	static float MicrosecondsToMilliseconds( long long microseconds )
	{ return microseconds * 0.001f; }

	bool operator ==( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) == right.AsMicroseconds( ); }

	bool operator !=( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) != right.AsMicroseconds( ); }

	bool operator <( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) < right.AsMicroseconds( ); }

	bool operator >( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) > right.AsMicroseconds( ); }

	bool operator <=( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) <= right.AsMicroseconds( ); }

	bool operator >=( const Time &left, const Time &right )
	{ return left.AsMicroseconds( ) >= right.AsMicroseconds( ); }

	Time operator -( const Time &right )
	{ return Microseconds( -right.AsMicroseconds( ) ); }

	Time operator +( const Time &left, const Time &right )
	{ return Microseconds( left.AsMicroseconds( ) + right.AsMicroseconds( ) ); }

	Time& operator +=( Time &left, const Time &right )
	{ return left = left + right; }

	Time operator -( const Time &left, const Time &right )
	{ return Microseconds( left.AsMicroseconds( ) - right.AsMicroseconds( ) ); }

	Time& operator -=( Time &left, const Time &right )
	{ return left = left - right; }

	Time operator *( const Time &left, const float &right )
	{ return Seconds( left.AsSeconds( ) * right ); }

	Time operator *( const Time &left, const long long &right )
	{ return Microseconds( left.AsMicroseconds( ) * right ); }

	Time operator *( const float &left, const Time &right )
	{ return right * left; }

	Time operator *( const long long &left, const Time &right )
	{ return right * left; }

	Time& operator *=( Time &left, const float &right )
	{ return left = left * right; }

	Time& operator *=( Time &left, const long long &right )
	{ return left = left * right; }

	Time operator /( const Time &left, const float &right )
	{ return Seconds( left.AsSeconds( ) / right ); }

	Time operator /( const Time &left, const long long &right )
	{ return Microseconds( left.AsMicroseconds( ) / right ); }

	//Time& operator /=( Time &left, const float &right )
	//{ return left = left / right; }

	Time& operator /=( Time &left, const long long &right )
	{ return left = left / right; }

	float operator /( const Time &left, const Time &right )
	{ return left.AsSeconds( ) / right.AsSeconds( ); }

	Time operator %( const Time &left, const Time &right )
	{ return Microseconds( left.AsMicroseconds( ) % right.AsMicroseconds( ) ); }

	Time& operator %=( Time &left, const Time &right )
	{ return left = left % right; }
}
