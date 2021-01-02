#include "Input/RBM.hpp"

namespace Sonar
{
	RBM::RBM( const float &threshold, const float &amountToTickUp, const Time &tickDownTime, const float &tickDownAmount ) : _started( false ), _failureCount( 0 ), _thresholdGoal( threshold ), _amountToTickUp( amountToTickUp ), _tickDownTime( tickDownTime ), _tickDownAmount( tickDownAmount ), _counter( 0 )
	{ }

	RBM::~RBM( )
	{ }

	bool RBM::HasStarted( ) const
	{ return _started; } 

	bool RBM::IsComplete( ) const
	{
		if ( _counter >= _thresholdGoal )
		{ return true; }
		else
		{ return false; }
	}

	Clock RBM::GetClock( ) const
	{ return _clock; }

	void RBM::Restart( )
	{
		_counter = 0;
		_clock.Reset( );
	}

	void RBM::Update( )
	{
		if ( _clock.GetElapsedTime( ) >= _tickDownTime && !IsComplete( ) )
		{
			_counter -=_tickDownAmount;
			_clock.Reset( );

			if ( _counter <= 0 )
			{
				_failureCount++;

				Restart( );
			}
		}
	}

	int RBM::GetFailureCount( ) const
	{ return _failureCount; }

	void RBM::TickUp( )
	{
		_started = true;
		_counter += _amountToTickUp;
	}

	float RBM::GetCounter( ) const
	{ return _counter; }
}
