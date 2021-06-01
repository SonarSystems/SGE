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

	Minimap::~Minimap( )
	{
		delete _background;
		_background = nullptr;

		for ( auto &object : _objects )
		{
			delete object.second._shape;
			object.second._shape = nullptr;
		}
	}

	void Minimap::Draw( )
	{
		_background->Draw( );

		for ( const auto &object : _objects )
		{
			if ( object.second._isShowing )
			{
				if ( std::find( _typesToHide.begin( ), _typesToHide.end( ), object.second._type ) == _typesToHide.end( ) )
				{
					glm::vec2 positionPercentage;
					positionPercentage = object.second._position / _mapSize;

					object.second._shape->SetPosition( _background->GetPosition( ) + ( _background->GetSize( ) * positionPercentage ) );

					if ( object.second._shape->BoundingBoxCollision( *_background ) )
					{
						if ( IsPointWithinRange( object.second._shape->GetPositionX( ), _background->GetPositionX( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionX( OBJECT_POINTS::TOP_RIGHT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionY( ), _background->GetPositionY( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionY( OBJECT_POINTS::BOTTOM_LEFT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionX( OBJECT_POINTS::TOP_RIGHT ), _background->GetPositionX( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionX( OBJECT_POINTS::TOP_RIGHT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionY( OBJECT_POINTS::TOP_RIGHT ), _background->GetPositionY( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionY( OBJECT_POINTS::BOTTOM_LEFT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionX( OBJECT_POINTS::BOTTOM_RIGHT ), _background->GetPositionX( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionX( OBJECT_POINTS::TOP_RIGHT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionY( OBJECT_POINTS::BOTTOM_RIGHT ), _background->GetPositionY( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionY( OBJECT_POINTS::BOTTOM_LEFT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionX( OBJECT_POINTS::BOTTOM_LEFT ), _background->GetPositionX( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionX( OBJECT_POINTS::TOP_RIGHT ) )
							&& IsPointWithinRange( object.second._shape->GetPositionY( OBJECT_POINTS::BOTTOM_LEFT ), _background->GetPositionY( OBJECT_POINTS::TOP_LEFT ), _background->GetPositionY( OBJECT_POINTS::BOTTOM_LEFT ) ) )
						{ object.second._shape->Draw( ); }
					}
				}
			}
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

	unsigned int Minimap::AddObject( const std::string &type, const glm::vec2 &position, const float &radius, const Color &color )
	{
		ObjectProperty objectProperty;

		objectProperty._type = type;
		objectProperty._position = position;

		objectProperty._shape = new Circle( _data );
		objectProperty._shape->SetRadius( radius );
		objectProperty._shape->SetInsideColor( color );

		_objects[_objects.size( )] = objectProperty;

		return _objects.size( ) - 1;
	}

	void Minimap::RemoveObjectByID( const unsigned int &id )
	{
		if ( DoesObjectExist( id ) )
		{
			delete _objects.at( id )._shape;
			_objects.at( id )._shape = nullptr;

			_objects.erase( id );
		}
	}

	void Minimap::RemoveObjectByType( const std::string &type )
	{
		for ( auto it = _objects.begin( ); it != _objects.end( ); ) 
		{
			if ( it->second._type == type )
			{
				delete it->second._shape;
				it->second._shape = nullptr;

				it = _objects.erase( it );
			}
			else
			{ ++it; }
		}
	}

	void Minimap::HideObjectByType( const std::string &type )
	{
		if ( std::find( _typesToHide.begin( ), _typesToHide.end( ), type ) == _typesToHide.end( ) )
		{ _typesToHide.push_back( type ); }
	}

	void Minimap::ShowObjectByType( const std::string &type )
	{ _typesToHide.erase( std::remove( _typesToHide.begin( ), _typesToHide.end( ), type ), _typesToHide.end( ) ); }

	void Minimap::HideObjectByID( const unsigned int &id )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._isShowing = false; }
	}

	void Minimap::ShowObjectByID( const unsigned int &id )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._isShowing = true; }
	}

	void Minimap::UpdateObjectByID( const unsigned int &id, const std::string &type, const glm::vec2 &position, const float &radius, const Color &color )
	{
		if ( DoesObjectExist( id ) )
		{
			_objects.at( id )._type = type;
			_objects.at( id )._position = position;

			_objects.at( id )._shape->SetRadius( radius );
			_objects.at( id )._shape->SetInsideColor( color );
		}
	}

	void Minimap::UpdateObjectTypeByID( const unsigned int &id, const std::string &type )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._type = type; }
	}

	void Minimap::UpdateObjectPositionByID( const unsigned int &id, const glm::vec2 &position )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._position = position; }
	}

	void Minimap::UpdateObjectRadiusByID( const unsigned int &id, const float &radius )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._shape->SetRadius( radius ); }
	}

	void Minimap::UpdateObjectColorByID( const unsigned int &id, const Color &color )
	{
		if ( DoesObjectExist( id ) )
		{ _objects.at( id )._shape->SetInsideColor( color ); }
	}

	void Minimap::UpdateObjectByType( const std::string &oldType, const std::string &type, const glm::vec2 &position, const float &radius, const Color &color )
	{
		for ( auto &object : _objects )
		{
			if ( oldType == object.second._type )
			{
				object.second._type = type;
				object.second._position = position;

				object.second._shape->SetRadius( radius );
				object.second._shape->SetInsideColor( color );
			}
		}
	}

	void Minimap::UpdateObjectTypeByType( const std::string &oldType, const std::string &type )
	{
		for ( auto &object : _objects )
		{
			if ( oldType == object.second._type )
			{ object.second._type = type; }
		}
	}

	void Minimap::UpdateObjectPositionByType( const std::string &type, const glm::vec2 &position )
	{
		for ( auto &object : _objects )
		{
			if ( type == object.second._type )
			{ object.second._position = position; }
		}
	}

	void Minimap::UpdateObjectRadiusByType( const std::string &type, const float &radius )
	{
		for ( auto &object : _objects )
		{
			if ( type == object.second._type )
			{ object.second._shape->SetRadius( radius ); }
		}
	}

	void Minimap::UpdateObjectColorByType( const std::string &type, const Color &color )
	{
		for ( auto &object : _objects )
		{
			if ( type == object.second._type )
			{ object.second._shape->SetInsideColor( color ); }
		}
	}

	bool Minimap::IsPointWithinRange( const float &point, const float &start, const float &end ) const
	{
		if ( point >= start && point <= end )
		{ return true; }
		else
		{ return false; }
	}

	bool Minimap::DoesObjectExist( const unsigned int &id )
	{
		if ( id < _objects.size( ) )
		{
			if ( _objects.find( id ) != _objects.end( ) )
			{ return true; }
		}

		return false;
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

