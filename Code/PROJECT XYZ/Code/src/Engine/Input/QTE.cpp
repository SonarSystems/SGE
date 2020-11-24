#include "Input/QTE.hpp"

namespace Sonar
{
	QTE::QTE( const std::vector<Keyboard::Key> &list, const std::vector<float> &times, const int &resetAmount ) : _started( false ), _eventPosition( 0 ), _eventList( list ), _eventTimeList( times ), _resetAmount( resetAmount )
	{ }

	QTE::~QTE( )
	{ }

	bool QTE::HasStarted( ) const
	{ return _started; }

	int QTE::GetEventPosition( ) const
	{ return _eventPosition; }

	void QTE::SetEventPosition( const int &position )
	{ _eventPosition = position; }

	int QTE::GetEventCount( ) const
	{ return _eventList.size( ); }

	std::vector<Keyboard::Key> QTE::GetEventList( ) const
	{ return _eventList; }

	bool QTE::IsComplete( ) const
	{
		if ( _eventList.size( ) <= _eventPosition )
		{ return true; }
		else
		{ return false; }
	}

	Clock QTE::GetClock( ) const
	{ return _clock; }

	void QTE::NextInput( const Keyboard::Key &key )
	{
		if ( _eventPosition < _eventList.size( ) )
		{
			if ( key == _eventList[_eventPosition] )
			{
				_eventPosition++;
				_clock.Reset( );
			}
		}
	}

	void QTE::Restart( )
	{
		if ( 0 == _resetAmount )
		{ _eventPosition = 0; }
		else
		{
			_eventPosition -= _resetAmount;

			if ( _eventPosition < 0 )
			{ _eventPosition = 0; }
		}
	}

	void QTE::Update( )
	{
		std::cout << "Event Size: " << _eventList.size( ) << std::endl;

		if ( _eventPosition < _eventList.size( ) )
		{
			std::cout << _clock.GetElapsedTime( ).AsSeconds( ) << " : " << _eventTimeList[_eventPosition] << std::endl;

			if ( ( float )_clock.GetElapsedTime( ).AsSeconds( ) >= ( float )_eventTimeList[_eventPosition] && _eventTimeList[_eventPosition] > 0 )
			{
				Restart( );
				_clock.Reset( );
			}
		}
	}
}
