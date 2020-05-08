#pragma once

#include "Events.hpp"

namespace Sonar
{
	class State
	{
	public:
        virtual ~State() { }
        
		virtual void Init( ) = 0;

		virtual void PollInput( const float &dt, const Event &event ) = 0;
		virtual void Update( const float &dt ) = 0;
		virtual void Draw( const float &dt ) = 0;

		virtual void Pause( ) { }
		virtual void Resume( ) { }
	};
}
