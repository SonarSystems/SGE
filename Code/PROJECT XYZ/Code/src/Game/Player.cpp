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

    void Player::HandleInput(float dt)
    {
        if ( _player->IsClicked( sf::Mouse::Button::Left ) )
        {
            Debug::Print( "Clicked" );
        }
        else
        {
            //Debug::Print( "NOT CLICKED" );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        {
            _player->Move( -500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        {
            _player->Move( 500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        {
            _player->Move( 0, 500.0f * dt );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
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
