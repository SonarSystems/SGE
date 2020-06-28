#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <glm/glm.hpp>
#include "Color.hpp"
#include "Game.hpp"
#include "Mouse.hpp"

namespace Sonar
{
    class Drawable
    {
    public:
        /**
         * \brief Draw object to application window
        */
        void Draw( );
        
        /**
         * \brief Set x and y position
         *
         * \param x X position
         * \param y Y position
        */
        void SetPosition( const float &x, const float &y );
        
        /**
         * \brief Set x position
         *
         * \param x X position
        */
        void SetPositionX( const float &x );
        
        /**
         * \brief Set y position
         *
         * \param y Y position
        */
        void SetPositionY( const float &y );
        
        /**
         * \brief Get the x position
         *
         * \return Output returns the x position
        */
        const float &GetPositionX( ) const;
        
        /**
         * \brief Get the y position
         *
         * \return Output returns the y position
        */
        const float &GetPositionY( ) const;
        
        /**
         * \brief Get the position vector
         *
         * \return Output returns the position vector
        */
        const glm::vec2 &GetPosition( ) const;
        
        /**
         * \brief Set width and height
         *
         * \param width Width of the drawable object
         * \param height Height of the drawable object
        */
        void SetSize( const float &width, const float &height );
        
        /**
         * \brief Set width
         *
         * \param width Width of the drawable object
        */
        void SetWidth( const float &width );
        
        /**
         * \brief Set height
         *
         * \param height Height of the drawable object
        */
        void SetHeight( const float &height );
        
        /**
         * \brief Get the width
         *
         * \return Output returns the width
        */
        const float &GetWidth( ) const;
        
        /**
         * \brief Get the height
         *
         * \return Output returns the height
        */
        const float &GetHeight( ) const;
        
        /**
         * \brief Get the size vector
         *
         * \return Output returns the size vector
        */
        const glm::vec2 &GetSize( ) const;
        
        /**
         * \brief Set the inside color (fill color)
         *
         * \param color Color object
        */
        void SetInsideColor( const Color &color );
        
        /**
         * \brief Set the border color
         *
         * \param color Color object
         *
         * SetBorderThickness method required aswell
        */
        void SetBorderColor( const Color &color );
        
        /**
         * \brief Set the border thickness
         *
         * \param thickness Thickness of the border
         *
         * Required for border, otherwise border is to set 0 thickness and cannot be seen
        */
        void SetBorderThickness( const float &thickness );
        
        /**
         * \brief Get the inside color (fill color)
         *
         * \return Output returns the inside color
        */
        const Color &GetInsideColor( ) const;
        
        /**
         * \brief Get the border color
         *
         * \return Output returns the border color
        */
        const Color &GetBorderColor( ) const;
        
        /**
         * \brief Get the border thickness
         *
         * \return Output returns the border thickness
        */
        const float &GetBorderThickness( ) const;
        
        /**
         * \brief Move the object relative to it's current position in the x and y axis
         *
         * \param x Offset in x axis
         * \param y Offset in y axis
        */
        void Move( const float &x, const float &y );
        
        /**
         * \brief Move the object relative to it's current position in the x axis
         *
         * \param x Offset in x axis
        */
        void MoveX( const float &x );
        
        /**
         * \brief Move the object relative to it's current position in the y axis
         *
         * \param y Offset in y axis
        */
        void MoveY( const float &y );
        
        /**
         * \brief Check if the object is clicked by the mouse
         *
         * \param button The mouse button to check
         *
         * \return Output returns true if the mouse is being clicked over the object and false otherwise
        */
        const bool &IsClicked( const Mouse::Button &button ) const;
		
		/**
		 * \brief Check if the object has collided with another using bounding box
		 *
		 * \param object The other object to check collision with
		 *
		 * \return Output returns true if the objects have collided, false otherwise
		 */
		const bool &BoundingBoxCollision( const Drawable &object ) const;
    
    protected:
        /**
         * \brief Class constructor
         *
         * \param data game engine object
        */
        Drawable( GameDataRef data );
        
        /**
         * \brief Class destructor
        */
         ~Drawable( ) ;
        
        /**
         * \brief Object to be drawn to the screen, assigned the address of the object from a child class
        */
        sf::Drawable *object;
        
        /**
         * \brief Game data object
        */
        GameDataRef _data;

    private:
        /**
         * \brief Object position vector (x and y)
        */
        glm::vec2 _position;
        
        /**
         * \brief Object size vector (width and height)
        */
        glm::vec2 _size;
        
        /**
         * \brief Inside color object
        */
        Color _color;
        
        /**
         * \brief Border color object
        */
        Color _borderColor;
        
        /**
         * \brief Border thickness
        */
        float _borderThickness;
        
    };
}
