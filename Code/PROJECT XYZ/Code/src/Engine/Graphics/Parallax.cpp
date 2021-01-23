#include "Graphics/Parallax.hpp"

namespace Sonar
{  
	Parallax::Parallax( GameDataRef data )
	{ _data = data; }

	Parallax::~Parallax( ) { }

	void Parallax::Update( const float &dt )
	{
		for ( auto layer: _layers )
		{ layer.Update( dt ); }
	}

	void Parallax::Draw( )
	{
		for ( auto layer : _layers )
		{ layer.Draw( ); }
	}

	void Parallax::AddLayer( const ScrollingBackground &layer )
	{ _layers.push_back( layer ); }

	void Parallax::AddLayer( const std::vector<Sprite *> &backgrounds )
	{
		ScrollingBackground scrollingBackground( _data );
		scrollingBackground.SetBackgrounds( backgrounds );

		_layers.push_back( scrollingBackground );
	}

	void Parallax::AddLayer( const std::vector<std::string> &backgrounds )
	{
		ScrollingBackground scrollingBackground( _data );
		scrollingBackground.SetBackgrounds( backgrounds );

		_layers.push_back( scrollingBackground );
	}
}
