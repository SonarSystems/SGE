#include "Graphics/Parallax.hpp"

namespace Sonar
{  
	Parallax::Parallax( GameDataRef data ) : _data( data )
	{
		_speed = -100;

		_direction = Parallax::DIRECTION::LEFT;
	}

	Parallax::~Parallax( ) { }

	void Parallax::SetBackgrounds( const std::vector<Sprite *> &backgrounds )
	{
		/*_backgrounds.push_back( new Sprite( _data, "Resources/Background.jpg" ) );
		_backgrounds.push_back( new Sprite( _data, "Resources/Background.jpg" ) );
		_backgrounds.push_back( new Sprite( _data, "Resources/Background.jpg" ) );*/

		_backgrounds = backgrounds;

		for ( int i = 0; i < _backgrounds.size( ); i++ )
		{
			if ( 0 == i )
			{ _backgrounds.at( i )->SetPosition( 0, 0 ); }
			else
			{
				_backgrounds.at( i )->SetPosition
				( 
					_backgrounds.at( i - 1 )->GetPositionX( ) + _backgrounds.at( i - 1 )->GetWidth( ),
					0
				);
			}
		}
	}

	void Parallax::Update( const float &dt )
	{
		for ( int i = 0; i < _backgrounds.size( ); i++ )
		{
			_backgrounds.at( i )->MoveX( dt * _speed );

			if ( _backgrounds.at( i )->GetPositionX( ) + _backgrounds.at( i )->GetWidth( ) < 0 )
			{
				if ( 0 == i )
				{
					const int lastID = _backgrounds.size( ) - 1;

					_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) + _backgrounds.at( lastID )->GetWidth( ) + ( _speed * dt ) );
				}
				else
				{
					const int lastID = i - 1;

					_backgrounds.at( i )->SetPositionX( _backgrounds.at( lastID )->GetPositionX( ) + _backgrounds.at( lastID )->GetWidth( ) );
				}				
			}
		}
	}

	void Parallax::Draw( )
	{
		for ( auto &background : _backgrounds )
		{ background->Draw( ); }
	}

	void Parallax::SetSpeed( const float &speed )
	{
		_speed = speed;

		if ( speed < 0 )
		{ _speed = 0; }
		else
		{ _speed = speed; }
	}

	float Parallax::GetSpeed( ) const
	{ return _speed; }

}
