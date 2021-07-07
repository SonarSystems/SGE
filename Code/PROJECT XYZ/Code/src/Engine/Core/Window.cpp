#include "Core/Window.hpp"
#include "Graphics/View.hpp"

namespace Sonar
{
	Window::Window( ) { }

	Window::~Window( ) { }

	void Window::Setup( )
	{ _window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), WINDOW_TITLE, Style::Close | Style::Titlebar ); }

	void Window::Setup( const unsigned int &width, const unsigned int &height, const std::string &title )
	{ _window.create( sf::VideoMode( width, height ), title, Style::Close | Style::Titlebar ); }

	void Window::Setup( const unsigned int &width, const unsigned int &height )
	{ _window.create( sf::VideoMode( width, height ), WINDOW_TITLE, Style::Close | Style::Titlebar ); }

	void Window::Setup( const std::string &title )
	{ _window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title, Style::Close | Style::Titlebar ); }

	sf::RenderWindow &Window::GetSFMLWindowObject( )
	{ return _window; }

	void Window::CloseWindow( )
	{ _window.close( ); }

	void Window::Display( )
	{ _window.display( ); }

	void Window::Clear( const Color &color )
	{ _window.clear( sf::Color( color.GetRed( ), color.GetGreen( ), color.GetBlue( ), color.GetAlpha( ) ) ); }

	bool Window::IsOpen( ) const
	{ return _window.isOpen( ); }

	const Sonar::Window::ContextSettings &Window::GetSettings( )
	{
		sf::ContextSettings sfmlContextSettings = _window.getSettings( );

		_contextSettings = ContextSettings::ContextSettings( sfmlContextSettings.depthBits, sfmlContextSettings.stencilBits, sfmlContextSettings.antialiasingLevel, sfmlContextSettings.majorVersion, sfmlContextSettings.minorVersion, sfmlContextSettings.attributeFlags, sfmlContextSettings.sRgbCapable );

		return _contextSettings;
	}

	bool Window::PollEvent( const Event &event )
	{ return _window.pollEvent( event.GetSFMLEventObject( ) ); }

	bool Window::WaitEvent( const Event &event )
	{ return _window.waitEvent( event.GetSFMLEventObject( ) ); }

	glm::ivec2 Window::GetPosition( ) const
	{
		auto position = _window.getPosition( );

		return glm::ivec2( position.x, position.y );
	}

	void Window::SetPosition( const glm::ivec2 &position )
	{ _window.setPosition( sf::Vector2i( position.x, position.y ) ); }

	glm::uvec2 Window::GetSize( ) const
	{
		auto size = _window.getSize( );

		return glm::uvec2( size.x, size.y );
	}

	void Window::SetSize( const glm::uvec2 &size )
	{ _window.setSize( sf::Vector2u( size.x, size.y ) ); }

	void Window::SetTitle( const std::string &title )
	{ _window.setTitle( title ); }

	void Window::SetIcon( const unsigned int &width, const unsigned int &height, const unsigned char *pixels )
	{ _window.setIcon( width, height, pixels ); }

	void Window::SetVisible( const bool &visible )
	{ _window.setVisible( visible ); }

	void Window::SetVerticalSyncEnabled( const bool &enabled )
	{ _window.setVerticalSyncEnabled( enabled ); }

	void Window::SetMouseCursorVisible( const bool &visible )
	{ _window.setMouseCursorVisible( visible ); }

	void Window::SetMouseCursorGrabbed( const bool &grabbed )
	{ _window.setMouseCursorGrabbed( grabbed ); }

	void Window::SetMouseCursor( const Mouse::Cursor &cursor )
	{
		sf::Cursor sfmlCursor;
		sfmlCursor.loadFromSystem( ( sf::Cursor::Type )cursor );

		_window.setMouseCursor( sfmlCursor );
	}

	void Window::SetKeyRepeatEnabled( const bool &enabled )
	{ _window.setKeyRepeatEnabled( enabled ); }

	void Window::SetFramerateLimit( const unsigned int &limit )
	{ _window.setFramerateLimit( limit ); }

	void Window::SetJoystickThreshold( const float &threshold )
	{ _window.setJoystickThreshold( threshold ); }

	void Window::SetActive( const bool &active )
	{ _window.setActive( active ); }

	void Window::RequestFocus( )
	{ _window.requestFocus( ); }

	bool Window::HasFocus( ) const
	{ return _window.hasFocus( ); }

	void Window::SetView( const View view )
	{ _window.setView( view.GetSFMLViewObject( ) ); }

	void Window::SetDefaultView( )
	{ _window.setView( _window.getDefaultView( ) ); }
}
