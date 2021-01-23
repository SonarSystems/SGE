#include "Input/QTE.hpp"

namespace Sonar
{
	QTE::QTE( const std::vector<Keyboard::Key> &eventList, const std::vector<float> &times, const int &resetAmount ) : _started( false ), _eventPosition( 0 ), _eventListKeyboard( eventList ), _eventTimeList( times ), _resetAmount( resetAmount ), _failureCount( 0 ), _eventCount( eventList.size( ) ) { }

	QTE::QTE( const std::vector<std::array<int, 2>> &eventList, const std::vector<float> &times, const int &resetAmount ) : _started( false ), _eventPosition( 0 ), _eventListJoystick( eventList ), _eventTimeList( times ), _resetAmount( resetAmount ), _failureCount( 0 ), _eventCount( eventList.size( ) ) { }

	QTE::QTE( const std::vector<Mouse::Button> &eventList, const std::vector<float> &times, const int &resetAmount ) : _started( false ), _eventPosition( 0 ), _eventListMouse( eventList ), _eventTimeList( times ), _resetAmount( resetAmount ), _failureCount( 0 ), _eventCount( eventList.size( ) ) { }

	QTE::~QTE( ) { }

	bool QTE::HasStarted( ) const
	{ return _started; } 

	int QTE::GetEventPosition( ) const
	{ return _eventPosition; }

	void QTE::SetEventPosition( const int &position )
	{ _eventPosition = position; }

	int QTE::GetEventCount( ) const
	{ return _eventCount; }

	std::vector<Keyboard::Key> QTE::GetEventListKeyboard( ) const
	{ return _eventListKeyboard; }

	std::vector<std::array<int, 2>> QTE::GetEventListJoystick( ) const
	{ return _eventListJoystick; }

	bool QTE::IsComplete( ) const
	{
		if ( _eventCount <= _eventPosition )
		{ return true; }
		else
		{ return false; }
	}

	Clock QTE::GetClock( ) const
	{ return _clock; }

	void QTE::NextInputKeyboard( const Keyboard::Key &key )
	{
		if ( _eventPosition < _eventCount )
		{
			if ( key == _eventListKeyboard[_eventPosition] )
			{
				_eventPosition++;
				_clock.Reset( );
				_started = true;
			}
		}
	}

	void QTE::NextInputJoystick( const unsigned int &joystickID, const unsigned int &joystickButton )
	{
		if ( _eventPosition < _eventCount )
		{
			if ( joystickID == _eventListJoystick[_eventPosition][0] && joystickButton == _eventListJoystick[_eventPosition][1] )
			{
				_eventPosition++;
				_clock.Reset( );
				_started = true;
			}
		}
	}

	void QTE::NextInputMouse( const Mouse::Button &button )
	{
		if ( _eventPosition < _eventCount )
		{
			if ( button == _eventListMouse[_eventPosition] )
			{
				_eventPosition++;
				_clock.Reset( );
				_started = true;
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
		if ( _eventPosition < _eventCount )
		{
			if ( ( float )_clock.GetElapsedTime( ).AsSeconds( ) >= ( float )_eventTimeList[_eventPosition] && _eventTimeList[_eventPosition] > 0 )
			{
				Restart( );
				_clock.Reset( );
				_failureCount++;
			}
		}
	}

	unsigned int QTE::GetFailureCount( ) const
	{ return _failureCount; }
}
