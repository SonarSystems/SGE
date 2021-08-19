#include "pch.hpp"

#include <array>

namespace Sonar
{
	std::vector<float> points;

    Debug *Debug::_instance = 0;

    Debug *Debug::getInstance( )
    {
        if ( 0 == _instance )
        { _instance = new Debug( ); }

        return _instance;
    }

    Debug::Debug( )
    {
        _isEnabled = START_STATE;

        _isPhysicsEnabled = PHYSICS_START_STATE;

		if ( _isEnabled )
		{
			//sysInfo.LoadSystemInformation( );
			_systemInformation = _sysInfo.GetSystemInformation( );
		}
    }

    void Debug::Enable( )
    { _isEnabled = true; }

    void Debug::Disable( )
    { _isEnabled = false; }

    void Debug::Toggle( )
    { _isEnabled = !_isEnabled; }

    bool Debug::IsEnabled( ) const
    { return _isEnabled; }

	void Debug::EnablePhysics( )
	{ _isPhysicsEnabled = true; }

	void Debug::DisablePhysics( )
	{ _isPhysicsEnabled = false; }

	void Debug::TogglePhysics( )
	{ _isPhysicsEnabled = !_isPhysicsEnabled; }

	bool Debug::IsPhysicsEnabled( ) const
	{
        if ( _isEnabled )
        { return _isPhysicsEnabled; }
        else
        { return false; }
    }

	void Debug::Log( const std::string &message, const std::string &category, const bool &newLine )
	{
		if ( _isEnabled )
		{
			if ( IsCategoryEnabled( category ) )
			{
				if ( newLine )
				{ spdlog::info( message + "\n" ); }
				else
				{ spdlog::info( message ); }
			}
			else
			{ AddCategory( category ); }
		}
	}

	void Debug::LogStatic( const std::string &message, const bool &newLine )
	{
		if ( newLine )
		{ spdlog::info( message + "\n" ); }
		else
		{ spdlog::info( message ); }
	}

	std::string Debug::ToLower( std::string string )
	{
		std::transform( string.begin( ), string.end( ), string.begin( ),
			[]( unsigned char c ) { return std::tolower( c ); }
		);

		return string;
	}

	void Debug::AddCategory( const std::string &category, const bool &isEnabled )
    {
        for ( const auto &element : _categories )
        {
            if ( ToLower( element.first ) == ToLower( category ) )
            { return; }
        }

        _categories.push_back( std::make_pair( category, isEnabled ) );
	}

	void Debug::RemoveCategory( const std::string &category )
	{
		for ( unsigned int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ _categories.erase( _categories.begin( ) + i ); }
		}
	}

	void Debug::UpdateCategory( const std::string &category, const bool &isEnabled )
	{
		for ( unsigned int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ _categories.at( i ).second = isEnabled; }
		}
	}

	bool Debug::IsCategoryEnabled( const std::string &category )
	{
		for ( unsigned int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ return _categories.at( i ).second; }
		}

        return false;
	}

	std::vector<std::pair<std::string, bool>> Debug::GetCategories( ) const
	{ return _categories; }

	void Debug::UpdateFrameData( const float frameTime )
	{
		_frameData._totalFrames++;

		if ( _clock.GetElapsedTime( ).AsSeconds( ) > 1.0f / DEBUG_FPS_UPDATE_FREQUENCY )
		{
			_frameData._FPS = 1.0f / frameTime;
			_frameData._frameTime = frameTime * 1000;

			_clock.Reset( );
		}
	}

	void Debug::ShowExampleAppSimpleOverlay( bool *p_open )
	{
		static int corner = 0;
		ImGuiIO &io = ImGui::GetIO( );
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
		if ( corner != -1 )
		{
			const float PAD = 10.0f;
			const ImGuiViewport *viewport = ImGui::GetMainViewport( );
			ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
			ImVec2 work_size = viewport->WorkSize;
			ImVec2 window_pos, window_pos_pivot;
			window_pos.x = ( corner & 1 ) ? ( work_pos.x + work_size.x - PAD ) : ( work_pos.x + PAD );
			window_pos.y = ( corner & 2 ) ? ( work_pos.y + work_size.y - PAD ) : ( work_pos.y + PAD );
			window_pos_pivot.x = ( corner & 1 ) ? 1.0f : 0.0f;
			window_pos_pivot.y = ( corner & 2 ) ? 1.0f : 0.0f;
			ImGui::SetNextWindowPos( window_pos, ImGuiCond_Always, window_pos_pivot );
			window_flags |= ImGuiWindowFlags_NoMove;
		}
		ImGui::SetNextWindowBgAlpha( 0.35f ); // Transparent background
		if ( ImGui::Begin( "Example: Simple overlay", p_open, window_flags ) )
		{
			if ( _cpuLoadClock.GetElapsedTime( ).AsSeconds( ) > 0.25f )
			{
				_systemInformation = _sysInfo.GetSystemInformation( );
				_cpuLoadClock.Reset( );
			}

			if ( _frameData._FPS <= 5000.0f && _fpsClock.GetElapsedTime( ).AsSeconds( ) > 0.0167f )
			{
				if ( points.size( ) > 100 )
				{
					for ( unsigned int i = 1; i < points.size( ); i++ )
					{ points[i - 1] = points[i]; }
					points[points.size( ) - 1] = _frameData._FPS;
				}
				else
				{ points.push_back( _frameData._FPS ); }

				_fpsClock.Reset( );
			}

			ImGui::Text( "%i FPS", ( int )_frameData._FPS );
			ImGui::Text( "%.2fms", _frameData._frameTime );
			ImGui::Text( "Frame : %llu", _frameData._totalFrames );
			if ( ImGui::BeginTable( "CPULoadTable", 5 ) )
			{
				ImGui::TableNextRow( );
				ImGui::TableSetColumnIndex( 1 );
				ImGui::Text( "avg" );
				ImGui::TableSetColumnIndex( 2 );
				ImGui::Text( "min" );
				ImGui::TableSetColumnIndex( 3 );
				ImGui::Text( "max" );
				ImGui::TableSetColumnIndex( 4 );
				ImGui::Text( "last" );

				ImGui::TableNextRow( );
				ImGui::TableSetColumnIndex( 0 );
				ImGui::Text( "CPU: " );
				ImGui::TableSetColumnIndex( 1 );
				ImGui::Text( "%hu", ( unsigned short )_systemInformation._cpuLoadAverage );
				ImGui::TableSetColumnIndex( 2 );
				ImGui::Text( "%hu", ( unsigned short )_systemInformation._cpuLoadMin );
				ImGui::TableSetColumnIndex( 3 );
				ImGui::Text( "%hu", ( unsigned short )_systemInformation._cpuLoadMax );
				ImGui::TableSetColumnIndex( 4 );
				ImGui::Text( "%hu", ( unsigned short )_systemInformation._cpuLoadLast );

				ImGui::EndTable( );
			}
			
			if ( !points.empty( ) )
			{ ImGui::PlotHistogram( "FPS", &points[0], points.size( ), 0, 0, 0, 5000.0f ); }
			//ImGui::PlotLines( "Frame Times", arr, IM_ARRAYSIZE( arr ) );

			ImGui::Separator( );
			if ( ImGui::IsMousePosValid( ) )
				ImGui::Text( "Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y );
			else
				ImGui::Text( "Mouse Position: <invalid>" );
			if ( ImGui::BeginPopupContextWindow( ) )
			{
				if ( ImGui::MenuItem( "Custom", NULL, corner == -1 ) ) corner = -1;
				if ( ImGui::MenuItem( "Top-left", NULL, corner == 0 ) ) corner = 0;
				if ( ImGui::MenuItem( "Top-right", NULL, corner == 1 ) ) corner = 1;
				if ( ImGui::MenuItem( "Bottom-left", NULL, corner == 2 ) ) corner = 2;
				if ( ImGui::MenuItem( "Bottom-right", NULL, corner == 3 ) ) corner = 3;
				if ( p_open && ImGui::MenuItem( "Close" ) ) *p_open = false;
				ImGui::EndPopup( );
			}
		}
		ImGui::End( );
	}
}
