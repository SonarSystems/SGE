#include "Core/Debug.hpp"

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
		for ( int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ _categories.erase( _categories.begin( ) + i ); }
		}
	}

	void Debug::UpdateCategory( const std::string &category, const bool &isEnabled )
	{
		for ( int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ _categories.at( i ).second = isEnabled; }
		}
	}

	bool Debug::IsCategoryEnabled( const std::string &category )
	{
		for ( int i = 0; i < _categories.size( ); i++ )
		{
			if ( ToLower( _categories.at( i ).first ) == ToLower( category ) )
			{ return _categories.at( i ).second; }
		}

        return false;
	}

	std::vector<std::pair<std::string, bool>> Debug::GetCategories( ) const
	{ return _categories; }
}
