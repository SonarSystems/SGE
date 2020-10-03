#include "QTE.hpp"

namespace Sonar
{
	QTE::QTE( const std::initializer_list<Keyboard::Key> &list ) : _started( false )
	{
		_eventList = list;
	}
	
	QTE::~QTE( )
	{ }
	
	const bool &QTE::HasStarted( ) const
	{ return _started; }
	
	const int &QTE::GetEventPosition( ) const
	{ return _eventPosition; }
	
	const int &QTE::GetEventCount( ) const
	{ return _eventList.size( ); }
	
	void QTE::NextInput( const Keyboard::Key &key )
	{
		for ( auto element : _eventList )
		{
			//total += element;
			std::cout << element << std::endl;
		}
		
		//std::cout << *_eventList.begin() << std::endl;
		
		//if ( key == *_eventList.begin() )
		{
			
		}
	}
}
