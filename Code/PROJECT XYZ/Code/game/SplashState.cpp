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
		//this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		//_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        player = sf::RectangleShape( sf::Vector2f( 100, 100 ) );
        player.setFillColor( sf::Color::Black );
        
        boundaryPlayer = sf::RectangleShape( sf::Vector2f( 100, 100 ) );
        boundaryPlayer.setFillColor( sf::Color::Red );
        
        boundaryPlayer.setPosition( -1000, -1000 );
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
        bool swapPlayers = false;
        
        if ( boundaryPlayer.getPosition( ).x < _data->window.getSize( ).x - boundaryPlayer.getSize( ).x
            && boundaryPlayer.getPosition( ).x > 0 )
        {
            //swapPlayers = true;
        }
        
        else if ( boundaryPlayer.getPosition( ).y < _data->window.getSize( ).y - boundaryPlayer.getSize( ).y
            && boundaryPlayer.getPosition( ).y > 0 )
        {
            //swapPlayers = true;
        }
        
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
        
        if ( swapPlayers )
        {
            sf::Vector2f tempPos = boundaryPlayer.getPosition( );
            
            boundaryPlayer.setPosition( player.getPosition( ) );
            player.setPosition( tempPos );
        }
        
        /*if ( player.getPosition( ).x < 0 )
        {
            sf::Vector2f posDiff = player.getPosition( );
            
            boundaryPlayer.setPosition( _data->window.getSize( ).x + posDiff.x, posDiff.y );
        }
        else if ( player.getPosition( ).x + player.getSize( ).x > _data->window.getSize( ).x )
        {
            sf::Vector2f posDiff = player.getPosition( );
            
            boundaryPlayer.setPosition( posDiff.x - _data->window.getSize( ).x, posDiff.y );
        }
        else if ( player.getPosition( ).y < 0 )
        {
            sf::Vector2f posDiff = player.getPosition( );
            
            boundaryPlayer.setPosition( posDiff.x, _data->window.getSize( ).y + posDiff.y );
        }
        else if ( player.getPosition( ).y + player.getSize( ).y > _data->window.getSize( ).y )
        {
            sf::Vector2f posDiff = player.getPosition( );
            
            boundaryPlayer.setPosition( posDiff.x, posDiff.y - _data->window.getSize( ).y );
        }*/
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::White);

        this->_data->window.draw( this->player );
        this->_data->window.draw( this->boundaryPlayer );

		this->_data->window.display();
	}
}
