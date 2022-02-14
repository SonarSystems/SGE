#pragma once

#include "Input/Mouse.hpp"

namespace Sonar
{
	class Event;
	class View;

	class Window
	{
	public:
		/**
		* \brief Style of the window
		*/
		struct Style
		{
			bool titlebar = true;
			bool resize = false;
			bool close = true;
			bool fullscreen = false;
		};

		/**
		* \brief Window's context settings
		*/
		struct ContextSettings
		{
			/**
			* \brief Enumeration of the context attribute flags
			*/
			enum Attribute
			{
				Default = 0,      ///< Non-debug, compatibility context (this and the core attribute are mutually exclusive)
				Core = 1 << 0, ///< Core attribute
				Debug = 1 << 2  ///< Debug attribute
			};

			////////////////////////////////////////////////////////////
			/// \brief Default constructor
			///
			/// \param depth        Depth buffer bits
			/// \param stencil      Stencil buffer bits
			/// \param antialiasing Antialiasing level
			/// \param major        Major number of the context version
			/// \param minor        Minor number of the context version
			/// \param attributes   Attribute flags of the context
			/// \param sRgb         sRGB capable framebuffer
			///
			////////////////////////////////////////////////////////////
			explicit ContextSettings( unsigned int depth = 0, unsigned int stencil = 0, unsigned int antialiasing = 0, unsigned int major = 1, unsigned int minor = 1, unsigned int attributes = Default, bool sRgb = false ) :
				depthBits( depth ),
				stencilBits( stencil ),
				antialiasingLevel( antialiasing ),
				majorVersion( major ),
				minorVersion( minor ),
				attributeFlags( attributes ),
				sRgbCapable( sRgb )
			{
			}

			////////////////////////////////////////////////////////////
			// Member data
			////////////////////////////////////////////////////////////
			unsigned int depthBits;         ///< Bits of the depth buffer
			unsigned int stencilBits;       ///< Bits of the stencil buffer
			unsigned int antialiasingLevel; ///< Level of antialiasing
			unsigned int majorVersion;      ///< Major number of the context version to create
			unsigned int minorVersion;      ///< Minor number of the context version to create
			unsigned int attributeFlags;    ///< The attribute flags to create the context with
			bool         sRgbCapable;       ///< Whether the context framebuffer is sRGB capable
		};

		/**
		* \brief Points on the screen/window
		*/
		enum POINTS
		{
			CENTER = 0,
			TOP_LEFT,
			TOP_RIGHT,
			BOTTOM_RIGHT,
			BOTTOM_LEFT
		};

        /**
        * \brief Class constructor
        */
		Window( );

		/**
		* \brief Class destructor
		*/
        ~Window( );

		/**
		* \brief Setup function - recommended to use overloaded version with parameters (width, height & title will be set by default properties in ENGINEDEFINITIONS.hpp)
		* 
		* \param contextSettings Context settings of the window
		*/
		void Setup( const ContextSettings &contextSettings = ContextSettings( ) );

		/**
		* \brief Setup function with width, height & title parameters (Recommended version of the constructor)
		*
		* \param width Width of the window
		* \param height Height of the window
		* \param title Title of the window
		* \param style Style of the window
		* \param contextSettings Context settings of the window
		*/
		void Setup( const unsigned int &width, const unsigned int &height, const std::string &title, const Style &style, const ContextSettings &contextSettings = ContextSettings( ) );

		/**
		* \brief Setup function with width and height parameters (title will be set by default properties in ENGINEDEFINITIONS.hpp)
		*
		* \param width Width of the window
		* \param height Height of the window
		* \param style Style of the window
		* \param contextSettings Context settings of the window
		*/
		void Setup( const unsigned int &width, const unsigned int &height, const Style &style, const ContextSettings &contextSettings = ContextSettings( ) );

		/**
		* \brief Setup function with title parameters (width and height will be set by default properties in ENGINEDEFINITIONS.hpp)
		* 
		* \param title Title of the window
		* \param style Style of the window
		* \param contextSettings Context settings of the window
		*/
		void Setup( const std::string &title, const Style &style, const ContextSettings &contextSettings = ContextSettings( ) );

		/**
		* \brief Get the underlying SFML Window object
		*
		* \return Output returns the SFML Window object
		*/
		[[nodiscard]] sf::RenderWindow &GetSFMLWindowObject( );

		/**
		* \brief Close the window and destroy all the attached resources
		*/
		void CloseWindow( );

		/**
		* \brief Display on screen what has been rendered to the window so far
		*/
		void Display( );

		/**
		* \brief Clear the screen
		*
		* \param color Color of the screen background, black by default
		*/
		void Clear( const Color &color = Color( 0, 0, 0, 255 ) );

		/**
		* \brief Tell whether or not the window is open
		*
		* \return Output returns true if the window is open and false if it has been closed
		*/
		[[nodiscard]] bool IsOpen( ) const;

		/**
		* \brief Get the settings of the OpenGL context of the window
		*
		* \return Output returns the OpenGL settings
		*/
		[[nodiscard]] const ContextSettings &GetSettings( );

		/**
		* \brief Pop the event on top of the event queue, if any, and return it
		*
		* \param event Event object to poll
		*
		* \return Output returns true if an event was detected and false if not events were detected
		*/
		[[nodiscard]] bool PollEvent( Event &event );

		/**
		* \brief Wait for an event and return it
		*
		* \param event Event object to wait on
		*
		* \return Output returns false if any error occured and true if it did not
		*/
		[[nodiscard]] bool WaitEvent( Event &event );

		/**
		* \brief Get the position of the window
		*
		* \return Output returns window's position
		*/
		[[nodiscard]] glm::ivec2 GetPosition( ) const;

		/**
		* \brief Change the position of the window on screen
		*
		* \param position Window's new position
		*/
		void SetPosition( const glm::ivec2 &position );

		/**
		* \brief Get the size of the rendering region of the window
		*
		* \return Output returns the window size
		*/
		[[nodiscard]] glm::uvec2 GetSize( ) const;

		/**
		* \brief Change the size of the rendering region of the window
		*
		* \param size Window's new size
		*/
		void SetSize( const glm::uvec2 &size );

		/**
		* \brief Change the title of the window
		*
		* \param title Window's title
		*/
		void SetTitle( const std::string &title );

		/**
		* \brief Change the window's icon
		*
		* \param width Width of the icon
		* \param height Height of the icon
		* \param pixels Pointer to the array of pixels in memory
		*/
		void SetIcon( const unsigned int &width, const unsigned int &height, const unsigned char *pixels );

		/**
		* \brief Show or hide the window
		*
		* \param visible True shows the window and false hides it
		*/
		void SetVisible( const bool &visible );

		/**
		* \brief Enable or disable vertical synchronization
		*
		* \param enabled True enables v-sync and false disables v-sync
		*/
		void SetVerticalSyncEnabled( const bool &enabled );

		/**
		* \brief Show or hide the mouse cursor
		*
		* \param visible rue to show the mouse cursor, false to hide it
		*/
		void SetMouseCursorVisible( const bool &visible );

		/**
		* \brief Grab or release the mouse cursor
		*
		* \param grabbed True to enable, false to disable
		*/
		void SetMouseCursorGrabbed( const bool &grabbed );

		/**
		* \brief Set the displayed cursor to a native system cursor
		*
		* \param cursor Native system cursor type to display
		*/
		void SetMouseCursor( const Mouse::Cursor &cursor );

		/**
		* \brief Enable or disable automatic key-repeat
		*
		* \param enabled True to enable, false to disable
		*/
		void SetKeyRepeatEnabled( const bool &enabled );

		/**
		* \brief Limit the framerate to a maximum fixed frequency
		*
		* \param limit Framerate limit, in frames per seconds (use 0 to disable limit)
		*/
		void SetFramerateLimit( const unsigned int &limit );

		/**
		* \brief Change the joystick threshold
		*
		* \param threshold New threshold, in the range [0, 100]
		*/
		void SetJoystickThreshold( const float &threshold );

		/**
		* \brief Activate or deactivate the window as the current target for OpenGL rendering
		*
		* \param active True if operation was successful, false otherwise
		*/
		void SetActive( const bool &active = true );

		/**
		* \brief Request the current window to be made the active foreground window
		*/
		void RequestFocus( );

		/**
		* \brief Check whether the window has the input focus
		*
		* \return Output return true if window has focus, false otherwise
		*/
		[[nodiscard]] bool HasFocus( ) const;

		/**
		* \brief Set the Window's current view to display
		*
		* \param view View to display
		*/
		void SetView( const View view );

		/**
		* \brief Get the Window's default view
		*/
		void SetDefaultView( );

		/**
		* \brief Description
		*
		* \param isWindow True gets the point of the window, false gets the point of the screen
		* \param point Which point's coordinates to get
		*
		* \return Output returns the window/screen points
		*/
		const glm::vec2 &GetPointOnScreen( const bool isWindow, const POINTS &point );
                        
	private:
		/**
		* \brief Style of the window, to be OR'd with each other
		*/
		enum StyleEnum
		{
			None = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)
			Titlebar = 1 << 0, ///< Title bar + fixed border
			Resize = 1 << 1, ///< Title bar + resizable border + maximize button
			Close = 1 << 2, ///< Title bar + close button
			Fullscreen = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)

			Default = Titlebar | Resize | Close ///< Default window style
		};

		/**
		* \brief Calculate the style of the window
		*
		* \param style Window style properties
		*
		* \return Output returns the style as an enum
		*/
		const StyleEnum CalculateStyle( const Style &style );

		/**
		* \brief Convert SGE context settings to SFML objecty
		*
		* \param contextSettings Context settings object to be converted
		*
		* \return Output returns the SFML version of the context settings
		*/
		const sf::ContextSettings ConvertContextSettingsToSFMLObject( const ContextSettings &contextSettings );

		/**
		* \brief SFML Window object
		*/
        sf::RenderWindow _window;

		/**
		* \brief OpenGL settings
		*/
		ContextSettings _contextSettings;

	};
}
