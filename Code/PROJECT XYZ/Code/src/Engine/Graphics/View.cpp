#include "Graphics/View.hpp"

namespace Sonar
{   
    View::View( GameDataRef data ) : _data( data )
    {
		_view = new sf::View( );

		c1 = new Circle( _data, 10 );
		c1->SetInsideColor( Color::Red );
	}
    
	View::View( GameDataRef data, const glm::vec4 &rectangle ) : _data( data )
	{ _view = new sf::View( sf::FloatRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	View::View( GameDataRef data, const glm::vec2 &center, const glm::vec2 &size ) : _data( data )
	{ _view = new sf::View( sf::Vector2f( center.x, center.y ), sf::Vector2f( size.x, size.y ) ); }

	View::~View( )
	{
		_view->~View( );

		delete _view;
	}

	void View::Draw( )
	{
		_data->window.setView( *_view );

		// DRAW ALL THE OBJECTS IN THE VIEW SET ABOVE
		c1->Draw( );
		//c1->MoveX( 0.1f );

		_data->window.setView( _data->window.getDefaultView( ) );
	}

	void View::Update( const float &dt ) { }

	void View::SetCenter( const float &x, const float &y )
	{ _view->setCenter( x, y ); }

	void View::SetCenter( const glm::vec2 &center )
	{ _view->setCenter( sf::Vector2f( center.x, center.y ) ); }

	void View::SetSize( const float &width, const float &height )
	{ _view->setSize( width, height ); }

	void View::SetSize( const glm::vec2 &size )
	{ _view->setSize( sf::Vector2f( size.x, size.y ) ); }

	void View::SetRotation( const float &angle )
	{ _view->setRotation( angle ); }

	void View::SetViewport( const glm::vec4 &viewport )
	{ _view->setViewport( sf::FloatRect( viewport.x, viewport.y, viewport.z, viewport.w ) ); }

	void View::Reset( const glm::vec4 &rectangle )
	{ _view->reset( sf::FloatRect( rectangle.x, rectangle.y, rectangle.z, rectangle.w ) ); }

	const glm::vec2 &View::GetCenter( ) const
	{
		sf::Vector2f center = _view->getCenter( );

		return glm::vec2( center.x, center.y );
	}

	const glm::vec2 &View::GetSize( ) const
	{
		sf::Vector2f size = _view->getSize( );

		return glm::vec2( size.x, size.y );
	}

	const float &View::GetRotation( ) const
	{ return _view->getRotation( ); }

	const glm::vec4 &View::GetViewport( ) const
	{
		sf::FloatRect viewport = _view->getViewport( );

		return glm::vec4( viewport.left, viewport.top, viewport.width, viewport.height );
	}

	void View::Move( const float &offsetX, const float &offsetY )
	{ _view->move( offsetX, offsetY ); }

	void View::Move( const glm::vec2 &offset )
	{ _view->move( sf::Vector2f( offset.x, offset.y ) ); }

	void View::Rotate( const float &angle )
	{ _view->rotate( angle ); }

	void View::Zoom( const float &factor )
	{ _view->zoom( factor ); }

	const sf::Transform &View::GetTransform( ) const
	{ return _view->getTransform( ); }

	const sf::Transform &View::GetInverseTransform( ) const
	{ return _view->getInverseTransform( ); }
}
