#include "Core/Window.hpp"

namespace Sonar
{
	Window::Window( )
	{ _window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), WINDOW_TITLE, Style::Close | Style::Titlebar ); }

	Window::Window( const unsigned int &width, const unsigned int &height )
	{ _window.create( sf::VideoMode( width, height ), WINDOW_TITLE, Style::Close | Style::Titlebar ); }

	Window::Window( const unsigned int &width, const unsigned int &height, const std::string &title )
	{ _window.create( sf::VideoMode( width, height ), title, Style::Close | Style::Titlebar ); }

	Window::Window( const std::string &title )
	{ _window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title, Style::Close | Style::Titlebar ); }

	Window::~Window( ) { }

	void Window::ShowWindow( )
	{

	}

	void Window::CloseWindow( )
	{ _window.close( ); }

	bool Window::IsOpen( ) const
	{ return _window.isOpen( ); }

	const Sonar::Window::ContextSettings &Window::GetSettings( )
	{
		sf::ContextSettings sfmlContextSettings = _window.getSettings( );

		_contextSettings = ContextSettings::ContextSettings( sfmlContextSettings.depthBits, sfmlContextSettings.stencilBits, sfmlContextSettings.antialiasingLevel, sfmlContextSettings.majorVersion, sfmlContextSettings.minorVersion, sfmlContextSettings.attributeFlags, sfmlContextSettings.sRgbCapable );

		return _contextSettings;
	}

	bool Window::PollEvent( const Event &event )
	{

	}

	bool Window::WaitEvent( const Event &event )
	{

	}

	glm::ivec2 Window::GetPosition( ) const
	{

	}

	void Window::SetPosition( const glm::ivec2 &position )
	{

	}

	glm::uvec2 Window::GetSize( ) const
	{

	}

	void Window::SetSize( const glm::uvec2 &size )
	{

	}

	void Window::SetTitle( const std::string &title )
	{

	}

	void Window::SetIcon( const unsigned int &width, const unsigned int &height, const unsigned char *pixels )
	{

	}

	void Window::SetVisible( const bool &visible )
	{

	}

	void Window::SetVerticalSyncEnabled( const bool &enabled )
	{

	}

	void Window::SetMouseCursorVisible( const bool &visible )
	{

	}

	void Window::SetMouseCursorGrabbed( const bool &grabbed )
	{

	}

	void Window::SetKeyRepeatEnabled( const bool &enabled )
	{

	}

	void Window::SetFramerateLimit( const unsigned int &limit )
	{

	}

	void Window::SetJoystickThreshold( const float &threshold )
	{

	}

	bool Window::SetActive( const bool &active /*= true */ ) const
	{

	}

	void Window::RequestFocus( )
	{

	}

	bool Window::HasFocus( ) const
	{

	}

	void Window::DisplayWindowContent( )
	{

	}

}
