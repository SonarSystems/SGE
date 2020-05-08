#include "Player.hpp"

namespace Sonar
{
    Player::Player( GameDataRef data ) : _data( data )
    {
        _player = new Rectangle( data );
        _player->SetSize( 75, 50 );
        _player->SetPosition( 300, 100 );
        _player->SetInsideColor( Color::Black );
    }

    void Player::HandleInput( float dt )
    {
        if ( Keyboard::IsPressed( Keyboard::Key::Left ) )
        {
            _player->Move( -500.0f * dt, 0 );
        }
        
        if ( Keyboard::IsPressed( Keyboard::Key::Right ) )
        {
            _player->Move( 500.0f * dt, 0 );
        }
        
        if ( Keyboard::IsPressed( Keyboard::Key::Down ) )
        {
            _player->Move( 0, 500.0f * dt );
        }
        
        if ( Keyboard::IsPressed( Keyboard::Key::Up ) )
        {
            _player->Move( 0, -500.0f * dt );
        }
    }

    void Player::Update( float dt )
    {
        if ( _player->GetPositionX( ) < -_player->GetWidth( ) )
        {
            _player->SetPositionX( _data->window.getSize( ).x + _player->GetWidth( ) );
        }
        else if ( _player->GetPositionX( ) -_player->GetWidth( ) > _data->window.getSize( ).x )
        {
            _player->SetPositionX( -_player->GetWidth( ) );
        }

        if ( _player->GetPositionY( ) < -_player->GetHeight( ) )
        {
            _player->SetPositionY( _data->window.getSize( ).y + _player->GetHeight( ) );
        }
        else if ( _player->GetPositionY( ) - _player->GetHeight( ) > _data->window.getSize( ).y )
        {
            _player->SetPositionY( -_player->GetHeight( ) );
        }
    }

    void Player::Draw( float dt )
    {
        _player->Draw( );
    }
}
