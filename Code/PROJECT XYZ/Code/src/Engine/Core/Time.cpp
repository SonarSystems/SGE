#include "Time.hpp"

namespace Sonar
{
	Time::Time( ) : _time( 0 )
	{ }
	
	Time::Time( const long long &microseconds) : _time( microseconds )
	{ }
	
	const float &Time::asSeconds( ) const
	{ return _time / 1000000.f; }
	
	const int &Time::asMilliseconds( ) const
	{ return static_cast<int>( _time / 1000 ); }
	
	const long long &Time::asMicroseconds( ) const
	{ return _time; }
	
	Time seconds( const float &amount )
	{ return Time( static_cast<long long>( amount * 1000000 ) ); }
	
	Time milliseconds( const int &amount )
	{ return Time( static_cast<long long>( amount ) * 1000 ); }
	
	Time microseconds( const long long &amount )
	{ return Time( amount ); }
	
	bool operator ==( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) == right.asMicroseconds( ); }
	
	bool operator !=( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) != right.asMicroseconds( ); }
	
	bool operator <( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) < right.asMicroseconds( ); }
	
	bool operator >( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) > right.asMicroseconds( ); }
	
	bool operator <=( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) <= right.asMicroseconds( ); }
	
	bool operator >=( const Time &left, const Time &right )
	{ return left.asMicroseconds( ) >= right.asMicroseconds( ); }
	
	Time operator -( const Time &right )
	{ return microseconds( -right.asMicroseconds( ) ); }
	
	Time operator +( const Time &left, const Time &right )
	{ return microseconds( left.asMicroseconds( ) + right.asMicroseconds( ) ); }
	
	Time& operator +=( Time &left, const Time &right )
	{ return left = left + right; }
	
	Time operator -( const Time &left, const Time &right )
	{ return microseconds( left.asMicroseconds( ) - right.asMicroseconds( ) ); }
	
	Time& operator -=( Time &left, const Time &right )
	{ return left = left - right; }
	
	Time operator *( const Time &left, const float &right )
	{ return seconds( left.asSeconds( ) * right ); }
	
	Time operator *( const Time &left, const long long &right )
	{ return microseconds( left.asMicroseconds( ) * right ); }
	
	Time operator *( const float &left, const Time &right )
	{ return right * left; }
	
	Time operator *( const long long &left, const Time &right )
	{ return right * left; }
	
	Time& operator *=( Time &left, const float &right )
	{ return left = left * right; }
	
	Time& operator *=( Time &left, const long long &right )
	{ return left = left * right; }
	
	Time operator /( const Time &left, const float &right )
	{ return seconds( left.asSeconds( ) / right ); }
	
	Time operator /( const Time &left, const long long &right )
	{ return microseconds( left.asMicroseconds( ) / right ); }
	
	//Time& operator /=( Time &left, const float &right )
	//{ return left = left / right; }
	
	Time& operator /=( Time &left, const long long &right )
	{ return left = left / right; }
	
	float operator /( const Time &left, const Time &right )
	{ return left.asSeconds( ) / right.asSeconds( ); }
	
	Time operator %( const Time &left, const Time &right )
	{ return microseconds( left.asMicroseconds( ) % right.asMicroseconds( ) ); }
	
	Time& operator %=( Time &left, const Time &right )
	{ return left = left % right; }
}
