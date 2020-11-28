#include "Input/RBM.hpp"

namespace Sonar
{
	RBM::RBM( const Keyboard::Key &key, const float &threshold, const float &amountToTickUp, const float &tickDownTime, const float &tickDownAmount ) : _started( false ), _failureCount( 0 ), _key( key ), _thresholdGoal( threshold ), _amountToTickUp( amountToTickUp ), _tickDownTime( tickDownTime ), _tickDownAmount( tickDownAmount ), _counter( 0 )
	{ }

	RBM::~RBM( )
	{ }

	bool RBM::HasStarted( ) const
	{ return _started; } 

	bool RBM::IsComplete( ) const
	{
		return true;
	}

	Clock RBM::GetClock( ) const
	{ return _clock; }

	void RBM::Restart( )
	{
		
	}

	void RBM::Update( )
	{
		
	}

	int RBM::GetFailureCount( ) const
	{ return _failureCount; }
}
