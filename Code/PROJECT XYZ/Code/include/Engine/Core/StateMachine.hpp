#pragma once

namespace Sonar
{
    class State;

	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
        /**
         * \brief Class constructor
        */
		StateMachine( );
        /**
         * \brief Class destructor
        */
		~StateMachine( );

        /**
         * \brief Add a new state onto the stack
         *
         * \param newState State to be added
         * \param isReplacing is the state being replaced or added (replaced by default)
        */
		void AddState( StateRef newState, const bool &isReplacing = true );
        /**
         * \brief Remove the current state from the stack
        */
		void RemoveState( );
        /**
         * \brief Run at start of each loop cycle in Game.cpp
        */
		void ProcessStateChanges( );
        
        /**
         * \brief Get the active state (state ontop of the stack)
         *
         * \return Output returns the state reference
        */
		StateRef &GetActiveState( );

	private:
        /**
         * \brief Stack of states
        */
		std::stack<StateRef> _states;
        /**
         * \brief New state reference
        */
		StateRef _newState;

        /**
         * \brief Is the state being removed
        */
		bool _isRemoving;
        /**
         * \brief Is the state being added
        */
        bool _isAdding;
        /**
         * \brief Is the state being replaced
        */
        bool _isReplacing;
	};
}
