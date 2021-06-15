#pragma once

#include <External/glm/glm.hpp>
#include <SFML/Graphics.hpp>

#include "Core/ENGINEDEFINITIONS.hpp"
#include "Input/Events.hpp"

namespace Sonar
{
	class Window
	{
	public:
		struct ContextSettings
		{
			////////////////////////////////////////////////////////////
			/// \brief Enumeration of the context attribute flags
			///
			////////////////////////////////////////////////////////////
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
        * \brief Class constructor - recommended to use overloaded version with parameters (width, height & title will be set by default properties in ENGINEDEFINITIONS.hpp)
        */
		Window( );

		/**
		* \brief Class constructor with width, height & title parameters (Recommended version of the constructor)
		*
		* \param width Width of the window
		* \param height Height of the window
		* \param title Title of the window
		*/
		Window( const unsigned int &width, const unsigned int &height, const std::string &title );

		/**
		* \brief Class constructor with width and height parameters (title will be set by default properties in ENGINEDEFINITIONS.hpp)
		*
		* \param width Width of the window
		* \param height Height of the window
		*/
		Window( const unsigned int &width, const unsigned int &height );

		/**
		* \brief Class constructor with title parameters (width and height will be set by default properties in ENGINEDEFINITIONS.hpp)
		* 
		* \param title Title of the window
		*/
		Window( const std::string &title );

		/**
		* \brief Class destructor
		*/
        ~Window( );

		void ShowWindow( );
		void CloseWindow( );
		bool IsOpen( ) const;
		const ContextSettings &GetSettings( );
		bool PollEvent( const Event &event );
		bool WaitEvent( const Event &event );
		glm::ivec2 GetPosition( ) const;
		void SetPosition( const glm::ivec2 &position );
		glm::uvec2 GetSize( ) const;
		void SetSize( const glm::uvec2 &size );
		void SetTitle( const std::string &title );
		void SetIcon( const unsigned int &width, const unsigned int &height, const unsigned char *pixels );
		void SetVisible( const bool &visible );
		void SetVerticalSyncEnabled( const bool &enabled );
		void SetMouseCursorVisible( const bool &visible );
		void SetMouseCursorGrabbed( const bool &grabbed );
		void SetKeyRepeatEnabled( const bool &enabled );
		void SetFramerateLimit( const unsigned int &limit );
		void SetJoystickThreshold( const float &threshold );
		bool SetActive( const bool &active = true ) const;
		void RequestFocus( );
		bool HasFocus( ) const;
		void DisplayWindowContent( );
                        
	private:
		/**
		* \brief Style of the window, to be OR'd with each other
		*/
		enum Style
		{
			None = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)
			Titlebar = 1 << 0, ///< Title bar + fixed border
			Resize = 1 << 1, ///< Title bar + resizable border + maximize button
			Close = 1 << 2, ///< Title bar + close button
			Fullscreen = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)

			Default = Titlebar | Resize | Close ///< Default window style
		};

		/**
		* \brief SFML Window object
		*/
        sf::Window _window;

		ContextSettings _contextSettings;

	};
}
