#include "Core/Time.hpp"

namespace Sonar
{
	Time::Time( ) : _time( 0 )
	{ }

	Time::Time( const long long &microseconds ) : _time( microseconds )
	{ }

	float Time::AsSeconds( ) const
	{ return _time / 1000000.f; }

	int Time::AsMilliseconds( ) const
	{ return static_cast<int>( _time / 1000 ); }

	long long Time::AsMicroseconds( ) const
	{ return _time; }

	Time Seconds( const float &amount )
	{ return Time( static_cast<long long>( amount * 1000000 ) ); }

	Time Milliseconds( const int &amount )
	{ return Time( static_cast<long long>( amount ) * 1000 ); }

	Time Microseconds( const long long &amount )
	{ return Time( amount ); }

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
