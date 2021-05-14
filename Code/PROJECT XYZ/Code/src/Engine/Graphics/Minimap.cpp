#include "Graphics/Minimap.hpp"

namespace Sonar
{
	Minimap::Minimap( GameDataRef data ) : _data( data )
	{
		_background = new Rectangle( _data );

		SetBackgroundColor( DEFAULT_MINIMAP_BACKGROUND_COLOR );
		SetBackgroundBorderThickness( DEFAULT_MINIMAP_BACKGROUND_BORDER_THICKNESS );
		SetBackgroundBorderColor( DEFAULT_MINIMAP_BACKGROUND_BORDER_COLOR );

		_background->SetSize( DEFAULT_MINIMAP_BACKGROUND_WIDTH, DEFAULT_MINIMAP_BACKGROUND_HEIGHT );
		_mapSize = glm::vec2( DEFAULT_MINIMAP_INTERNAL_MAP_WIDTH, DEFAULT_MINIMAP_INTERNAL_MAP_HEIGHT );
	}

	Minimap::~Minimap( ) { }

	void Minimap::Draw( )
	{
		_background->Draw( );

		for ( auto object : _objects )
		{
			glm::vec2 positionPercentage;
			positionPercentage = object._position / _mapSize;

			object._shape->SetPosition( _background->GetPosition( ) + ( _background->GetSize( ) * positionPercentage ) );

			object._shape->Draw( );
		}
	}

	void Minimap::Update( const float &dt )
	{
		_background->Update( dt );
	}

	glm::vec4 Minimap::GetLocalBounds( ) const
	{ return _background->GetLocalBounds( ); }

	glm::vec4 Minimap::GetGlobalBounds( ) const
	{ return _background->GetGlobalBounds( ); }

	bool Minimap::IsMouseOver( ) const
	{ return _background->IsMouseOver( ); }

	void Minimap::SetMapSize( const glm::vec2 &size )
	{
		_mapSize = size;
	}

	void Minimap::SetMapSize( const float &width, const float &height )
	{ SetMapSize( glm::vec2( width, height ) ); }

	void Minimap::SetMapWidth( const float &width )
	{ SetMapSize( glm::vec2( width, GetMapHeight( ) ) ); }

	void Minimap::SetMapHeight( const float &height )
	{ SetMapSize( glm::vec2( GetMapWidth( ), height ) ); }

	glm::vec2 Minimap::GetMapSize( ) const
	{ return _mapSize; }

	float Minimap::GetMapWidth( ) const
	{ return _mapSize.x; }

	float Minimap::GetMapHeight( ) const
	{ return _mapSize.y; }

	void Minimap::AddObject( const std::string &type, const glm::vec2 &position, const float &radius, const Color &color )
	{
		ObjectProperty objectProperty;

		objectProperty._type = type;
		objectProperty._position = position;

		objectProperty._shape = new Circle( _data );
		objectProperty._shape->SetRadius( radius );
		objectProperty._shape->SetInsideColor( color );

		_objects.push_back( objectProperty );
	}

	void Minimap::SetPosition( const glm::vec2 &position )
	{
		_background->SetPosition( position );
	}

	void Minimap::SetPosition( const float &x, const float &y )
	{ SetPosition( glm::vec2( x, y ) ); }

	void Minimap::SetPosition( const POSITION &position )
	{
		switch ( position )
		{
			case POSITION::TOP_LEFT:
				_background->SetPosition( 0, 0 );

				break;

			case POSITION::TOP_CENTER:
				_background->SetPosition
				(
					( _data->window.getSize( ).x * 0.5 ) - ( _background->GetWidth( ) * 0.5 ),
					0
				);

				break;

			case POSITION::TOP_RIGHT:
				_background->SetPosition( _data->window.getSize( ).x - _background->GetWidth( ), 0 );

				break;

			case POSITION::RIGHT_CENTER:
				_background->SetPosition
				(
					_data->window.getSize( ).x - _background->GetWidth( ), 
					( _data->window.getSize( ).y * 0.5 ) - ( _background->GetHeight( ) * 0.5 )
				);

				break;

			case POSITION::BOTTOM_RIGHT:
				_background->SetPosition
				(
					_data->window.getSize( ).x - _background->GetWidth( ),
					_data->window.getSize( ).y - _background->GetHeight( )
				);

				break;

			case POSITION::BOTTOM_CENTER:
				_background->SetPosition
				(
					( _data->window.getSize( ).x * 0.5 ) - ( _background->GetWidth( ) * 0.5 ),
					_data->window.getSize( ).y - _background->GetHeight( )
				);

				break;

			case POSITION::BOTTOM_LEFT:
				_background->SetPosition
				(
					0, 
					_data->window.getSize( ).y - _background->GetHeight( )
				);

				break;

			case POSITION::LEFT_CENTER:
				_background->SetPosition
				(
					0,
					( _data->window.getSize( ).y * 0.5 ) - ( _background->GetHeight( ) * 0.5 )
				);

				break;

			case POSITION::CENTER:
				_background->SetPosition
				(
					( _data->window.getSize( ).x * 0.5 ) - ( _background->GetWidth( ) * 0.5 ),
					( _data->window.getSize( ).y * 0.5 ) - ( _background->GetHeight( ) * 0.5 )
				);

				break;
		}
	}

	void Minimap::SetPositionX( const float &x )
	{ SetPosition( glm::vec2( x, GetPositionY( ) ) ); }

	void Minimap::SetPositionY( const float &y )
	{ SetPosition( glm::vec2( GetPositionX( ), y ) ); }

	glm::vec2 Minimap::GetPosition( ) const
	{ return _background->GetPosition( ); }

	float Minimap::GetPositionX( ) const
	{ return _background->GetPositionX( ); }

	float Minimap::GetPositionY( ) const
	{ return _background->GetPositionY( ); }

	void Minimap::SetBackgroundSize( const glm::vec2 &size )
	{
		_background->SetSize( size );
	}

	void Minimap::SetBackgroundSize( const float &width, const float &height )
	{ SetBackgroundSize( glm::vec2( width, height ) ); }

	void Minimap::SetBackgroundWidth( const float &width )
	{ SetBackgroundSize( glm::vec2( width, _background->GetHeight( ) ) ); }

	void Minimap::SetBackgroundHeight( const float &height )
	{ SetBackgroundSize(glm::vec2(  _background->GetWidth( ), height ) ); }

	glm::vec2 Minimap::GetBackgroundSize( ) const
	{ return _background->GetSize( ); }

	float Minimap::GetBackgroundWidth( ) const
	{ return _background->GetWidth( ); }

	float Minimap::GetBackgroundHeight( ) const
	{ return _background->GetHeight( ); }

	void Minimap::SetBackgroundColor( const Color &color )
	{ _background->SetInsideColor( color ); }

	void Minimap::SetBackgroundBorderThickness( const float &thickness )
	{ _background->SetBorderThickness( thickness ); }

	void Minimap::SetBackgroundBorderColor( const Color &color )
	{ _background->SetBorderColor( color ); }

	Color Minimap::GetBackgroundColor( ) const
	{ return _background->GetInsideColor( ); }

	float Minimap::GetBackgroundBorderThickness( ) const
	{ return _background->GetBorderThickness( ); }

	Color Minimap::GetBackgroundBorderColor( ) const
	{ return _background->GetBorderColor( ); }

	void Minimap::Move( const glm::vec2 &offset )
	{
		_background->Move( offset );
	}

	void Minimap::Move( const float &x, const float &y )
	{ Move( glm::vec2( x, y ) ); }

	void Minimap::MoveX( const float &x )
	{ Move( glm::vec2( x, 0 ) ); }

	void Minimap::MoveY( const float &y )
	{ Move( glm::vec2( 0, y ) ); }

	void Minimap::SetScale( const float &scale )
	{
		_background->SetScale( scale, scale );

		SetPosition( _background->GetPosition( ) );
	}

	void Minimap::Scale( const float &scale )
	{
		_background->Scale( scale, scale );

		SetPosition( _background->GetPosition( ) );
	}

	float Minimap::GetScale( ) const
	{ return _background->GetScaleX( ); }
}

