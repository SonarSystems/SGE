#include "pch.hpp"

namespace Sonar
{  
	ScrollingBackground::ScrollingBackground( GameDataRef data ) : _data( data )
	{
		_speed = 100;

		_originalDirection = _direction = ScrollingBackground::DIRECTION::LEFT;
		_orientation = ScrollingBackground::ORIENTATION::HORIZONTAL;

		_isSingleScroll = false;

		_offsetX = _offsetY = 0;
	}

	ScrollingBackground::~ScrollingBackground( ) { }

	void ScrollingBackground::SetBackgrounds( const std::vector<Sprite *> &backgrounds )
	{
		_backgrounds = backgrounds;

		SetBackgroundPositions( );
	}

	void ScrollingBackground::SetBackgrounds( const std::vector<std::string> &backgrounds )
	{
		for ( auto filepath : backgrounds )
		{ _backgrounds.push_back( new Sprite( _data, filepath ) ); }

		SetBackgroundPositions( );
	}

	void ScrollingBackground::Update( const float &dt )
	{
		for ( unsigned int i = 0; i < _backgrounds.size( ); i++ )
		{
			if ( ScrollingBackground::DIRECTION::LEFT == _direction )
			{
				_backgrounds.at( i )->MoveX( dt * -_speed );

				if ( _backgrounds.at( i )->GetPositionX( ) + _backgrounds.at( i )->GetWidth( ) < 0 )
				{
					if ( 0 == i )
					{
						const int lastID = _backgrounds.size( ) - 1;

						_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) + _backgrounds.at( lastID )->GetWidth( ) + _offsetX + ( -_speed * dt ) );
					}
					else
					{
						const int lastID = i - 1;

						_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) + _backgrounds.at( lastID )->GetWidth( ) + _offsetX );
					}
				}
			}
			else if ( ScrollingBackground::DIRECTION::RIGHT == _direction )
			{
				_backgrounds.at( i )->MoveX( dt * _speed );

				if ( _backgrounds.at( i )->GetPositionX( ) > _data->window.GetSize( ).x )
				{
					if ( _backgrounds.size( ) - 1 == i )
					{
						const int lastID = 0;

						_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) - _backgrounds.at( i )->GetWidth( ) - _offsetX );
					}
					else
					{
						const int lastID = i + 1;

						_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) - _backgrounds.at( i )->GetWidth( ) - _offsetX + ( _speed * dt ) );
					}
				}
			}
			else if ( ScrollingBackground::DIRECTION::UP == _direction )
			{
				_backgrounds.at( i )->MoveY( dt * -_speed );

				if ( _backgrounds.at( i )->GetPositionY( ) + _backgrounds.at( i )->GetHeight( ) < 0 )
				{
					if ( 0 == i )
					{
						const int lastID = _backgrounds.size( ) - 1;

						_backgrounds.at( i )->SetPositionY( _backgrounds.at( lastID )->GetPositionY( ) + _backgrounds.at( lastID )->GetHeight( ) + _offsetY + ( -_speed * dt ) );
					}
					else
					{
						const int lastID = i - 1;

						_backgrounds.at( i )->SetPositionY( _backgrounds.at( lastID )->GetPositionY( ) + _backgrounds.at( lastID )->GetHeight( ) + _offsetY );
					}
				}
			}
			else if ( ScrollingBackground::DIRECTION::DOWN == _direction )
			{
				_backgrounds.at( i )->MoveY( dt * _speed );

				if ( _backgrounds.at( i )->GetPositionY( ) > _data->window.GetSize( ).y )
				{
					if ( _backgrounds.size( ) - 1 == i )
					{
						const int lastID = 0;

						_backgrounds.at( i )->SetPositionY( _backgrounds.at( lastID )->GetPositionY( ) - _backgrounds.at( i )->GetHeight( ) - _offsetY );
					}
					else
					{
						const int lastID = i + 1;

						_backgrounds.at( i )->SetPositionY( _backgrounds.at( lastID )->GetPositionY( ) - _backgrounds.at( i )->GetHeight( ) - _offsetY + ( _speed * dt ) );
					}
				}
			}
		}

		if ( _isSingleScroll )
		{
			_speed = 0;
			_isSingleScroll = false;
		}
	}

	void ScrollingBackground::Draw( )
	{
		for ( auto &background : _backgrounds )
		{ background->Draw( ); }
	}

	void ScrollingBackground::SetSpeed( const float &speed )
	{
		_speed = speed;

		if ( speed < 0 )
		{ _speed = 0; }
		else
		{ _speed = speed; }
	}

	float ScrollingBackground::GetSpeed( ) const
	{ return _speed; }

	void ScrollingBackground::SetDirection( const ScrollingBackground::DIRECTION &direction )
	{
		_originalDirection = _direction = direction;

		if ( ScrollingBackground::DIRECTION::LEFT == direction || ScrollingBackground::DIRECTION::RIGHT == direction )
		{ _orientation = ScrollingBackground::ORIENTATION::HORIZONTAL; }
		else
		{ _orientation = ScrollingBackground::ORIENTATION::VERTICAL; }

		SetBackgroundPositions( );
	}

	Sonar::ScrollingBackground::ScrollingBackground::DIRECTION ScrollingBackground::GetDirection( ) const
	{ return _direction; }

	void ScrollingBackground::SetOrientation( const ScrollingBackground::ORIENTATION &orientation )
	{ _orientation = orientation; }

	Sonar::ScrollingBackground::ScrollingBackground::ORIENTATION ScrollingBackground::GetOrientation( ) const
	{ return _orientation; };

	void ScrollingBackground::SetScrollToManual( const ScrollingBackground::ORIENTATION &orientation )
	{
		_orientation = orientation;
		_speed = 0;

		if ( ScrollingBackground::ORIENTATION::HORIZONTAL == orientation )
		{ SetDirection( ScrollingBackground::DIRECTION::RIGHT ); }
		else
		{ SetDirection( ScrollingBackground::DIRECTION::DOWN ); }
	}

	void ScrollingBackground::Move( const ScrollingBackground::DIRECTION &direction, const float &speed )
	{
		_direction = direction;
		_speed = speed;
		_isSingleScroll = true;
	}

	void ScrollingBackground::Reset( )
	{
		_direction = _originalDirection;
		SetBackgroundPositions( );
	}

	void ScrollingBackground::SetOffset( const float &offsetX, const float &offsetY )
	{
		_offsetX = offsetX;
		_offsetY = offsetY;

		SetBackgroundPositions( );
	}

	void ScrollingBackground::SetBackgroundPositions( )
	{
		if ( ScrollingBackground::DIRECTION::LEFT == _direction )
		{
			for ( unsigned int i = 0; i < _backgrounds.size( ); i++ )
			{
				if ( 0 == i )
				{ _backgrounds.at( i )->SetPosition( _offsetX, _offsetY ); }
				else
				{
					_backgrounds.at( i )->SetPosition
					(
						_backgrounds.at( i - 1 )->GetPositionX( ) + _backgrounds.at( i - 1 )->GetWidth( ) + _offsetX,
						_offsetY
					);
				}
			}
		}
		else if ( ScrollingBackground::DIRECTION::RIGHT == _direction )
		{
			for ( int i = _backgrounds.size( ) - 1; i >= 0; i-- )
			{
				if ( _backgrounds.size( ) - 1 == i )
				{ _backgrounds.at( i )->SetPosition( _offsetX, _offsetY ); }
				else
				{
					_backgrounds.at( i )->SetPosition
					(
						_backgrounds.at( i + 1 )->GetPositionX( ) - _backgrounds.at( i )->GetWidth( ) - _offsetX,
						_offsetY
					);
				}
			}
		}
		else if ( ScrollingBackground::DIRECTION::UP == _direction )
		{
			for ( unsigned int i = 0; i < _backgrounds.size( ); i++ )
			{
				if ( 0 == i )
				{ _backgrounds.at( i )->SetPosition( _offsetX, _offsetY ); }
				else
				{
					_backgrounds.at( i )->SetPosition
					(
						_offsetX,
						_backgrounds.at( i - 1 )->GetPositionY( ) + _backgrounds.at( i - 1 )->GetHeight( ) + _offsetY
					);
				}
			}
		}
		else if ( ScrollingBackground::DIRECTION::DOWN == _direction )
		{
			for ( int i = _backgrounds.size( ) - 1; i >= 0; i-- )
			{
				if ( _backgrounds.size( ) - 1 == i )
				{ _backgrounds.at( i )->SetPosition( _offsetX, _offsetY ); }
				else
				{
					_backgrounds.at( i )->SetPosition
					(
						_offsetX,
						_backgrounds.at( i + 1 )->GetPositionY( ) - _backgrounds.at( i )->GetHeight( ) - _offsetY
					);
				}
			}
		}
	}
}
