#include "Core/StateMachine.hpp"
#include <iostream>

namespace Sonar
{
	StateMachine::StateMachine( )
	{
		_isAdding = false;
		_isRemoving = false;
		_isReplacing = false;
	}

	StateMachine::~StateMachine( ) { }

	void StateMachine::AddState( StateRef newState, const bool &isReplacing )
	{
		_isAdding = true;
		_isReplacing = isReplacing;

		_newState = std::move( newState );
	}

	void StateMachine::RemoveState( )
	{ _isRemoving = true; }

	void StateMachine::ProcessStateChanges( )
	{
		if ( _isRemoving && !_states.empty( ) )
		{
			_states.pop( );

			if ( !_states.empty( ) )
			{ _states.top( )->Resume( ); }

			_isRemoving = false;
		}

		if ( _isAdding )
		{
			if ( !_states.empty( ) )
			{
				if ( _isReplacing )
				{ _states.pop( ); }
				else
				{ _states.top( )->Pause( ); }
			}

			_states.push( std::move( _newState ) );
			_states.top( )->Init( );
			_isAdding = false;
		}
	}

	StateRef &StateMachine::GetActiveState( )
	{ return _states.top( ); }
}
