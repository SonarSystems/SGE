#pragma once

namespace Sonar
{
	class Time
	{
	public:
		/**
		 * \brief Class constructor
		 */
		Time( );
		
		/**
		 * \brief Class destructor
		 */
		~Time( ) { }
		
		/**
		 * \brief Get the time as seconds
		 *
		 * \return Output returns the time as seconds
		 */
		const float &asSeconds( ) const;
		
		/**
		 * \brief Get the time as milliseconds
		 *
		 * \return Output returns the time as milliseconds
		 */
		const int &asMilliseconds( ) const;
		
		/**
		 * \brief Get the time as microseconds
		 *
		 * \return Output returns the time as microseconds
		 */
		const long long &asMicroseconds( ) const;
		
	private:
		friend Time seconds( const float & );
		friend Time milliseconds( const int & );
		friend Time microseconds( const long long & );
		
		/**
		 * \brief Construct from a number of microseconds
		 *
		 * \param microseconds Number of microseconds
		 *
		 */
		explicit Time( const long long &microseconds );
		
		/**
		 * \brief Time variable
		 */
		long long _time;
		
	};
	
	/**
	 * \brief Construct a time value from a number of seconds
	 *
	 * \param amount Number of seconds
	 *
	 * \return Time value constructed from the amount of seconds
	 */
	Time seconds( const float &amount );
	
	/**
	 * \brief Construct a time value from a number of milliseconds
	 *
	 * \param amount Number of milliseconds
	 *
	 * \return Time value constructed from the amount of milliseconds
	 */
	Time milliseconds( const int &amount );
	
	/**
	 * \brief Construct a time value from a number of microseconds
	 *
	 * \param amount Number of microseconds
	 *
	 * \return Time value constructed from the amount of microseconds
	 */
	Time microseconds( const long long &amount );
	
	/**
	 * \brief Overload of == operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if both time values are equal
	 *
	 */
	bool operator ==( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of != operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if both time values are different
	 *
	 */
	bool operator !=( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of < operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if \a left is lesser than \a right
	 *
	 */
	bool operator <( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of > operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if \a left is greater than \a right
	 *
	 */
	bool operator >( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of <= operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if \a left is lesser or equal than \a right
	 *
	 */
	bool operator <=( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of >= operator to compare two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return True if \a left is greater or equal than \a right
	 *
	 */
	bool operator >=( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of unary - operator to negate a time value
	 *
	 * \param right Right operand (a time)
	 *
	 * \return Opposite of the time value
	 *
	 */
	Time operator -( const Time &right );
	
	/**
	 * \brief Overload of binary + operator to add two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return Sum of the two times values
	 *
	 */
	Time operator +( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary += operator to add/assign two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return Sum of the two times values
	 *
	 */
	Time& operator +=( Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary - operator to subtract two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return Difference of the two times values
	 *
	 */
	Time operator -( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary -= operator to subtract/assign two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return Difference of the two times values
	 *
	 */
	Time& operator -=( Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary * operator to scale a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time operator *( const Time &left, const float &right );
	
	/**
	 * \brief Overload of binary * operator to scale a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time operator *( const Time &left, const long long &right );
	
	/**
	 * \brief Overload of binary * operator to scale a time value
	 *
	 * \param left  Left operand (a number)
	 * \param right Right operand (a time)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time operator *( const float &left, const Time &right );
	
	/**
	 * \brief Overload of binary * operator to scale a time value
	 *
	 * \param left  Left operand (a number)
	 * \param right Right operand (a time)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time operator *( const long long &left, const Time &right );
	
	/**
	 * \brief Overload of binary *= operator to scale/assign a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time& operator *=( Time &left, const float &right );
	
	/**
	 * \brief Overload of binary *= operator to scale/assign a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left multiplied by \a right
	 *
	 */
	Time& operator *=( Time &left, const long long &right );
	
	/**
	 * \brief Overload of binary / operator to scale a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left divided by \a right
	 *
	 */
	Time operator /( const Time &left, float right );
	
	/**
	 * \brief Overload of binary / operator to scale a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left divided by \a right
	 *
	 */
	Time operator /( const Time &left, const long long &right );
	
	/**
	 * \brief Overload of binary /= operator to scale/assign a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left divided by \a right
	 *
	 */
	//Time& operator /=( Time &left, const float &right );
	
	/**
	 * \brief Overload of binary /= operator to scale/assign a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a number)
	 *
	 * \return \a left divided by \a right
	 *
	 */
	Time& operator /=( Time &left, const long long &right );
	
	/**
	 * \brief Overload of binary / operator to compute the ratio of two time values
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return \a left divided by \a right
	 *
	 */
	float operator /( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary % operator to compute remainder of a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return \a left modulo \a right
	 *
	 */
	Time operator %( const Time &left, const Time &right );
	
	/**
	 * \brief Overload of binary %= operator to compute/assign remainder of a time value
	 *
	 * \param left  Left operand (a time)
	 * \param right Right operand (a time)
	 *
	 * \return \a left modulo \a right
	 *
	 */
	Time& operator %=( Time &left, const Time &right );
	
}
