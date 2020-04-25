#include "Player.hpp"

namespace Sonar
{
    Player::Player( GameDataRef data ) : _data( data )
    {
        _player.SetSize( 75, 50 );
        _player.SetPosition( 300, 100 );
        _player.SetInsideColor( Color::Black );
    }

    void Player::HandleInput(float dt)
    {
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        {
            //player.move( -500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        {
            //player.move( 500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        {
            //player.move( 0, 500.0f * dt );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        {
            //player.move( 0, -500.0f * dt );
        }
    }

    void Player::Update( float dt )
    {
        /*if ( player.getPosition( ).x < -player.getSize( ).x )
        {
            player.setPosition( _data->window.getSize( ).x + player.getSize( ).x, player.getPosition( ).y );
        }
        else if ( player.getPosition( ).x - player.getSize( ).x > _data->window.getSize( ).x )
        {
            player.setPosition( -player.getSize( ).x, player.getPosition( ).y );
        }
        
        if ( player.getPosition( ).y < -player.getSize( ).y )
        {
            player.setPosition( player.getPosition( ).x, _data->window.getSize( ).y + player.getSize( ).y );
        }
        else if ( player.getPosition( ).y - player.getSize( ).y > _data->window.getSize( ).y )
        {
            player.setPosition( player.getPosition( ).x, -player.getSize( ).y );
        }*/
    }

    void Player::Draw( float dt )
    {
        _player.Draw( _data->window );
    }
}
