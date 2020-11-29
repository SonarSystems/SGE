#pragma once

namespace Sonar
{
	class Time
	{
	public:
		// SONAR: Static methods for conversion for each 3 denominations

		/**
		 * \brief Class constructor
		 */
		Time( );
		
		/**
		 * \brief Class destructor
		 */
		~Time( ) { }
		
		/**
		 * \brief Construct from a number of microseconds
		 *
		 * \param microseconds Number of microseconds
		 *
		 */
		explicit Time( const long long &microseconds );
		
		/**
		 * \brief Get the time as seconds
		 *
		 * \return Output returns the time as seconds
		 */
		float AsSeconds( ) const;
		
		/**
		 * \brief Get the time as milliseconds
		 *
		 * \return Output returns the time as milliseconds
		 */
		float AsMilliseconds( ) const;
		
		/**
		 * \brief Get the time as microseconds
		 *
		 * \return Output returns the time as microseconds
		 */
		long long AsMicroseconds( ) const;

		/**
		* \brief Convert seconds to milliseconds
		*
		* \param seconds Seconds value to be converted
		*
		* \return Output returns the value converted to milliseconds
		*/
		static float SecondsToMilliseconds( float seconds );

		/**
		* \brief Convert seconds to microseconds
		*
		* \param seconds Seconds value to be converted
		*
		* \return Output returns the value converted to microseconds
		*/
		static long long SecondsToMicroseconds( float seconds );

		/**
		* \brief Convert milliseconds to seconds
		*
		* \param milliseconds Milliseconds value to be converted
		*
		* \return Output returns the value converted to seconds
		*/
		static float MillisecondsToSeconds( float milliseconds );

		/**
		* \brief Convert milliseconds to microseconds
		*
		* \param milliseconds Milliseconds value to be converted
		*
		* \return Output returns the value converted to microseconds
		*/
		static long long MillisecondsToMicroseconds( float milliseconds );

		/**
		* \brief Convert microseconds to seconds
		*
		* \param microseconds Microseconds value to be converted
		*
		* \return Output returns the value converted to seconds
		*/
		static float MicrosecondsToSeconds( long long microseconds );

		/**
		* \brief Convert microseconds to milliseconds
		*
		* \param microseconds Microseconds value to be converted
		*
		* \return Output returns the value converted to milliseconds
		*/
		static float MicrosecondsToMilliseconds( long long microseconds );

	private:
		friend Time Seconds( const float & );
		friend Time Milliseconds( const float & );
		friend Time Microseconds( const long long & );
		
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
	Time Seconds( const float &amount );
	
	/**
	 * \brief Construct a time value from a number of milliseconds
	 *
	 * \param amount Number of milliseconds
	 *
	 * \return Time value constructed from the amount of milliseconds
	 */
	Time Milliseconds( const int &amount );
	
	/**
	 * \brief Construct a time value from a number of microseconds
	 *
	 * \param amount Number of microseconds
	 *
	 * \return Time value constructed from the amount of microseconds
	 */
	Time Microseconds( const long long &amount );
	
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
