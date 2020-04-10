#pragma once

#include <sstream>
#include "SplashState.hpp"

#include <iostream>

namespace Sonar
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
        player = sf::RectangleShape( sf::Vector2f( 100, 100 ) );
        player.setFillColor( sf::Color::Black );
	}

	void SplashState::HandleInput(float dt)
	{
		sf::Event event;
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        {
            player.move( -500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        {
            player.move( 500.0f * dt, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        {
            player.move( 0, 500.0f * dt );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        {
            player.move( 0, -500.0f * dt );
        }

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
        if ( player.getPosition( ).x < -player.getSize( ).x )
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
        }
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::White);

        this->_data->window.draw( this->player );

		this->_data->window.display();
	}
}
