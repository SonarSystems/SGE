#include "Graphics/Parallax.hpp"

namespace Sonar
{  
	Parallax::Parallax( GameDataRef data ) : _data( data ) { }

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

	// IMPLEMENT A RESET AFTER IT's GONE OFF THE SCREEN
	void Parallax::Update( const float &dt )
	{
		for ( auto &background : _backgrounds )
		{
			background->MoveX( dt * -350 );
		}
	}

	void Parallax::Draw( )
	{
		for ( auto &background : _backgrounds )
		{ background->Draw( ); }
	}

}
