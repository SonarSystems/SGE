#include "pch.hpp"

namespace Sonar
{
	Music::Music( const std::string &filepath ) : AudioItem( AUDIO_TYPE::MUSIC )
	{
		LoadFile( filepath );
		_music.openFromFile( filepath );

		_musicObject = &_music;
	}

	Music::~Music( ) { }

	const Time &Music::GetLength( ) const
	{ return Time( _music.getDuration( ).asMicroseconds( ) ); }

	const unsigned int &Music::GetChannelCount( ) const
	{ return _music.getChannelCount( ); }

	const unsigned int &Music::GetSampleRate( ) const
	{ return _music.getSampleRate( ); }

	const float &Music::GetPlayingPosition( const Time::DENOMINATION &denomination ) const
	{
		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				return _music.getPlayingOffset( ).asMicroseconds( );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				return _music.getPlayingOffset( ).asMilliseconds( );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				return _music.getPlayingOffset( ).asSeconds( );

				break;
		}
	}

	void Music::Forward( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
		sf::Time time;

		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				time = sf::microseconds( displacement );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				time = sf::milliseconds( displacement );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				time = sf::seconds( displacement );

				break;
		}

		_music.setPlayingOffset( _music.getPlayingOffset( ) + time );
	}

	void Music::Rewind( const unsigned int &displacement, const Time::DENOMINATION &denomination )
	{
		sf::Time time;

		switch ( denomination )
		{
			case Time::DENOMINATION::MICROSECONDS:
				time = sf::microseconds( displacement );

				break;

			case Time::DENOMINATION::MILLISECONDS:
				time = sf::milliseconds( displacement );

				break;

			case Time::DENOMINATION::SECONDS:
			default:
				time = sf::seconds( displacement );

				break;
		}

		_music.setPlayingOffset( _music.getPlayingOffset( ) - time );
	}

	void Music::EnableLooping( )
	{ _music.setLoop( true ); }

	void Music::DisableLooping( )
	{ _music.setLoop( false ); }

	void Music::ToggleLooping( )
	{ _music.setLoop( !_music.getLoop( ) ); }

	const bool &Music::IsLooping( )
	{ return _music.getLoop( ); }
}