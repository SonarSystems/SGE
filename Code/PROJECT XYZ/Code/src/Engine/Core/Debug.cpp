#include "pch.hpp"

#include <array>

namespace Sonar
{
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
			_sysInfo.LoadSystemInformation( );
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

	void Debug::DrawComputerStats( bool *pOpen, const glm::uvec2 &windowSize, const Verbosity verbosity, const float opacity )
	{
		static short int corner = COMPUTER_STATS_DEFAULT_CORNER;
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

		if ( verbosity > Verbosity::NONE )
		{
			ImGui::SetNextWindowBgAlpha( opacity ); // Transparent background

			if ( ImGui::Begin( "Computer Stats Overlay", pOpen, window_flags ) )
			{
				if ( _cpuLoadClock.GetElapsedTime( ).AsSeconds( ) > 0.25f )
				{
					_systemInformation = _sysInfo.GetSystemInformation( );
					_cpuLoadClock.Reset( );
				}

				if ( _frameData._FPS <= 5000.0f && _graphClock.GetElapsedTime( ).AsSeconds( ) > 0.0167f )
				{
					if ( _fpsGraphPoints.size( ) > 100 )
					{
						for ( unsigned int i = 1; i < _fpsGraphPoints.size( ); i++ )
						{ _fpsGraphPoints[i - 1] = _fpsGraphPoints[i]; }
						_fpsGraphPoints[_fpsGraphPoints.size( ) - 1] = _frameData._FPS;
					}
					else
					{ _fpsGraphPoints.push_back( _frameData._FPS ); }

					if ( _cpuGraphPoints.size( ) > 100 )
					{
						for ( unsigned int i = 1; i < _cpuGraphPoints.size( ); i++ )
						{ _cpuGraphPoints[i - 1] = _cpuGraphPoints[i]; }
						_cpuGraphPoints[_cpuGraphPoints.size( ) - 1] = _systemInformation._cpuLoadLast;
					}
					else
					{ _cpuGraphPoints.push_back( _systemInformation._cpuLoadLast ); }

					if ( _ramGraphPoints.size( ) > 100 )
					{
						for ( unsigned int i = 1; i < _ramGraphPoints.size( ); i++ )
						{ _ramGraphPoints[i - 1] = _ramGraphPoints[i]; }
						_ramGraphPoints[_ramGraphPoints.size( ) - 1] = _systemInformation._physicalTotalMemory - _systemInformation._physicalAvailableMemory;
					}
					else
					{ _ramGraphPoints.push_back( _systemInformation._cpuLoadLast ); }

					_graphClock.Reset( );
				}

				if ( verbosity >= Verbosity::MINIMAL )
				{
					ImGui::Text( "%i FPS", ( int )_frameData._FPS );
				}

				if ( verbosity >= Verbosity::MEDIUM )
				{
					ImGui::Text( "%.2fms", _frameData._frameTime );
					ImGui::Text( "Frame : %llu", _frameData._totalFrames );
				}

				if ( verbosity >= Verbosity::HIGH )
				{
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
			
					if ( !_fpsGraphPoints.empty( ) )
					{ ImGui::PlotHistogram( "FPS", &_fpsGraphPoints[0], _fpsGraphPoints.size( ), 0, 0, 0, 2000.0f ); }

					if ( !_cpuGraphPoints.empty( ) )
					{ ImGui::PlotHistogram( "CPU", &_cpuGraphPoints[0], _cpuGraphPoints.size( ), 0, 0, 0, 100.0f ); }

					if ( !_ramGraphPoints.empty( ) )
					{ ImGui::PlotHistogram( "RAM", &_ramGraphPoints[0], _ramGraphPoints.size( ), 0, 0, 0, _systemInformation._physicalTotalMemory ); }
				}

				if ( verbosity >= Verbosity::SUPER_HIGH )
				{
					ImGui::Separator( );

					ImGui::Text( "%ix%i", windowSize.x, windowSize.y );

					ImGui::Text( "SGE %s", ENGINE_VERSION );

					ImGui::Text( "%s", _systemInformation._gpus.at( 0 )._name.c_str( ) );
					ImGui::Text( "VRAM %s", _systemInformation._gpus.at( 0 )._ram.c_str( ) );

					ImGui::Text( "VRAM %s", _systemInformation._cpus.at( 0 )._name.c_str( ) );
				}

				if ( ImGui::BeginPopupContextWindow( ) )
				{
					if ( ImGui::MenuItem( "Custom", NULL, corner == -1 ) )
					{ corner = -1; }

					if ( ImGui::MenuItem( "Top-left", NULL, corner == 0 ) )
					{ corner = 0; }

					if ( ImGui::MenuItem( "Top-right", NULL, corner == 1 ) )
					{ corner = 1; }
				
					if ( ImGui::MenuItem( "Bottom-left", NULL, corner == 2 ) )
					{ corner = 2; }

					if ( ImGui::MenuItem( "Bottom-right", NULL, corner == 3 ) )
					{ corner = 3; }

					if ( pOpen && ImGui::MenuItem( "Close" ) )
					{ *pOpen = false; }

					ImGui::EndPopup( );
				}
			}

			ImGui::End( );
		}
	}

	void Debug::EnableGrid( )
	{ _isGridEnabled = true; }

	void Debug::DisableGrid( )
	{ _isGridEnabled = false; }

	void Debug::ToggleGrid( )
	{ _isGridEnabled = !_isGridEnabled; }

	const bool Debug::IsGridEnabled( ) const
	{ return ( _isGridEnabled && _isGridEnabled ); }

	void Debug::SetNumberOfGridSpacesX( const int &spaces )
	{ _grid.numOfSpacesX = spaces; }

	const int &Debug::GetNumberOfGridSpacesX( ) const
	{ return _grid.numOfSpacesX; }

	void Debug::SetNumberOfGridSpacesY( const int &spaces )
	{ _grid.numOfSpacesY = spaces; }

	const int &Debug::GetNumberOfGridSpacesY( ) const
	{ return _grid.numOfSpacesY; }

	void Debug::SetNumberOfGridSpaces( const int &spacesX, const int &spacesY )
	{
		_grid.numOfSpacesX = spacesX;
		_grid.numOfSpacesY = spacesY;
	}

	void Debug::SetNumberOfGridSpaces( const glm::uvec2 &spaces )
	{
		_grid.numOfSpacesX = spaces.x;
		_grid.numOfSpacesY = spaces.y;
	}

	const glm::uvec2 &Debug::GetNumberOfGridSpaces( ) const
	{ return glm::uvec2( _grid.numOfSpacesX, _grid.numOfSpacesY ); }

	void Debug::SetLineColor( const Color &color )
	{ _grid.color = color; }

	const Color &Debug::GetLineColor( ) const
	{ return _grid.color; }

	void Debug::SetLineWidth( const float &width )
	{ _grid.lineWidth = width; }

	const float &Debug::GetLineWidth( ) const
	{ return _grid.lineWidth; }

	void Debug::SetGridWidth( const float &width )
	{ _grid.gridWidth = width; }

	const float &Debug::GetGridWidth( ) const
	{ return _grid.gridWidth; }

	void Debug::EnableFixedWidth( )
	{ _grid.isFixedWidth = true; }

	void Debug::DisableFixedWidth( )
	{ _grid.isFixedWidth = false; }

	void Debug::ToggleFixedWidth( )
	{ _grid.isFixedWidth = !_grid.isFixedWidth; }

	const bool &Debug::IsFixedWidthEnabled( ) const
	{ return _grid.isFixedWidth; }

	void Debug::EnableBorder( )
	{ _grid.isBorderEnabled = true; }

	void Debug::DisableBorder( )
	{ _grid.isBorderEnabled = false; }

	void Debug::ToggleBorder( )
	{ _grid.isBorderEnabled = !_grid.isBorderEnabled; }

	const bool &Debug::IsBorderEnabled( ) const
	{ return _grid.isBorderEnabled; }
}
