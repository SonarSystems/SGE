#include "Graphics/Parallax.hpp"

namespace Sonar
{  
	Parallax::Parallax( GameDataRef data )
	{ _data = data; }

	Parallax::~Parallax( ) { }

	void Parallax::Update( const float &dt )
	{
		for ( unsigned int i = 0; i < _layers.size( ); i++ )
		{
			if ( _layerStatus.at( i ).first )
			{ _layers.at( i ).Update( dt ); }
		}
	}

	void Parallax::Draw( )
	{
		for ( unsigned int i = 0; i < _layers.size( ); i++ )
		{
			if ( _layerStatus.at( i ).first )
			{ _layers.at( i ).Draw( ); }
		}
	}

	void Parallax::AddLayer( const ScrollingBackground &layer )
	{
		_layers.push_back( layer );

		_layerStatus.push_back( std::make_pair( true, true ) );
	}

	void Parallax::AddLayer( const std::vector<Sprite *> &backgrounds )
	{
		ScrollingBackground scrollingBackground( _data );
		scrollingBackground.SetBackgrounds( backgrounds );

		AddLayer( scrollingBackground );
	}

	void Parallax::AddLayer( const std::vector<std::string> &backgrounds )
	{
		ScrollingBackground scrollingBackground( _data );
		scrollingBackground.SetBackgrounds( backgrounds );

		AddLayer( scrollingBackground );
	}

	void Parallax::DeleteLayer( const unsigned int &index )
	{
		_layers.erase( _layers.begin( ) + index );
		_layerStatus.erase( _layerStatus.begin( ) + index );
	}

	void Parallax::EnableLayer( const unsigned int &index )
	{ _layerStatus.at( index ).first = _layerStatus.at( index ).second = true; }

	void Parallax::DisableLayer( const unsigned int &index )
	{ _layerStatus.at( index ).first = _layerStatus.at( index ).second = false; }

	void Parallax::EnableUpdatingForLayer( const unsigned int &index )
	{ _layerStatus.at( index ).first = true; }

	void Parallax::DisableUpdatingForLayer( const unsigned int &index )
	{ _layerStatus.at( index ).first = false; }

	void Parallax::EnableDrawingForLayer( const unsigned int &index )
	{ _layerStatus.at( index ).second = true; }

	void Parallax::DisableDrawingForLayer( const unsigned int &index )
	{ _layerStatus.at( index ).second = false; }

	void Parallax::SetDirection( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction )
	{ _layers.at( layerIndex ).SetDirection( direction ); }

	void Parallax::SetDirectionForAllLayers( const ScrollingBackground::DIRECTION &direction )
	{
		for ( auto layer : _layers )
		{ layer.SetDirection( direction ); }
	}

	void Parallax::SetOrientation( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation )
	{ _layers.at( layerIndex ).SetOrientation( orientation ); }

	void Parallax::SetOrientationForAllLayers( const ScrollingBackground::ORIENTATION &orientation )
	{
		for ( auto layer : _layers )
		{ layer.SetOrientation( orientation ); }
	}

	void Parallax::SetScrollToManual( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation )
	{ _layers.at( layerIndex ).SetScrollToManual( orientation ); }

	void Parallax::SetScrollToManualForAllLayers( const ScrollingBackground::ORIENTATION &orientation )
	{
		for ( auto layer : _layers )
		{ layer.SetScrollToManual( orientation ); }
	}

	void Parallax::MoveLayer( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction, const float &speed )
	{ _layers.at( layerIndex ).Move( direction, speed ); }

	void Parallax::MoveAllLayers( const ScrollingBackground::DIRECTION &direction, const float &speed )
	{
		for ( auto layer : _layers )
		{ layer.Move( direction, speed ); }
	}

	void Parallax::SetOffset( const unsigned int &layerIndex, const float &offsetX, const float &offsetY )
	{ _layers.at( layerIndex ).SetOffset( offsetX, offsetY ); }

	void Parallax::SetOffsetForAllLayers( const float &offsetX, const float &offsetY )
	{
		for ( auto layer : _layers )
		{ layer.SetOffset( offsetX, offsetY ); }
	}

	void Parallax::SetSpeed( const unsigned int &layerIndex, const float &speed )
	{ _layers.at( layerIndex ).SetSpeed( speed ); }

	void Parallax::SetSpeedForAllLayers( const float &speed )
	{
		for ( auto layer : _layers )
		{ layer.SetSpeed( speed ); }
	}

	void Parallax::Reset( const unsigned int &layerIndex )
	{ _layers.at( layerIndex ).Reset( ); }

	void Parallax::ResetAllLayers( )
	{
		for ( auto layer : _layers )
		{ layer.Reset( ); }
	}

}
