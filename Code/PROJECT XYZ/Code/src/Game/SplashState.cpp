#include "SplashState.hpp"

namespace Sonar
{
	SplashState::SplashState( GameDataRef data ) : _data( data )
	{
        player = new Player( _data );
        physicsWorld = new PhysicsWorld( _data );

		_data->debug->AddCategory( "Hello" );
		_data->debug->AddCategory( "Batman", false );

		auto cat = _data->debug->GetCategories( );

		for ( auto element : cat )
		{
			std::cout << element.first << " : " << element.second << std::endl;
		}
	}

	void SplashState::Init( )
	{
        
	}

	void SplashState::PollInput( const float &dt, const Event &event )
	{
        player->HandleInput( dt );
	}

	void SplashState::Update( const float &dt )
	{
        player->Update( dt );
        
        physicsWorld->Update( dt );

		_data->debug->UpdateCategory( "BatmAN", true );

		_data->debug->Log( "1", "HEllo" );

		_data->debug->Log( "2", "BATMAN" );
	}

	void SplashState::Draw( const float &dt )
	{
        player->Draw( dt );
        
		physicsWorld->Draw( dt );
	}
}
