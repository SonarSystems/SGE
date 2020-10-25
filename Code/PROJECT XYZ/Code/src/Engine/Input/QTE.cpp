#include "QTE.hpp"

namespace Sonar
{
	QTE::QTE( const std::vector<Keyboard::Key> &list ) : _started( false ), _eventPosition( 0 ), _eventList( list )
	{ }
	
	QTE::~QTE( )
	{ }
	
	const bool &QTE::HasStarted( ) const
	{ return _started; }
	
	const int &QTE::GetEventPosition( ) const
	{ return _eventPosition; }
	
	void QTE::SetEventPosition( const int &position )
	{ _eventPosition = position; }
	
	const int &QTE::GetEventCount( ) const
	{ return _eventList.size( ); }
	
	const std::vector<Keyboard::Key> &QTE::GetEventList( ) const
	{ return _eventList; }
	
	const bool &QTE::IsComplete( ) const
	{
		if ( _eventList.size( ) <= _eventPosition )
		{ return true; }
		else
		{ return false; }
	}
	
	void QTE::NextInput( const Keyboard::Key &key )
	{
		if ( key == _eventList[_eventPosition] )
		{ _eventPosition++; }
	}
	
	void QTE::Restart( )
	{ _eventPosition = 0; }
}
