#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <External/glm/glm.hpp>
#include "Core/ENGINEDEFINITIONS.hpp"
#include "Core/Game.hpp"
#include "Graphics/Shapes/Circle.hpp"

namespace Sonar
{
    class View
    {
    public:
        /**
        * \brief Default class constructor (creates a default view of 0, 0, 1000, 1000)
		* 
		* \param data Game data object
        */
        View( GameDataRef data );
        
		/**
		* \brief Explicit class constructor
		*
		* \param data Game data object
		* \param rectangle View's new rectangle to set to
		*/
		explicit View( GameDataRef data, const glm::vec4 &rectangle );

		/**
		* \brief Class constructor with center and size parameters
		*
		* \param data Game data object
		* \param center Center of the view
		* \param size Size of the view
		*/
		View( GameDataRef data, const glm::vec2 &center, const glm::vec2 &size );

        /**
         * \brief Class destructor
        */
        ~View( );

		/**
		* \brief Draw the classes objects
		*/
		void Draw( );

		/**
		* \brief Update the classes objects
		*
		* \param dt Delta time (difference between frames)
		*/
		void Update( const float &dt );

		/**
		* \brief Set the center of the view
		*
		* \param x X position
		* \param y Y position
		*/
		void SetCenter( const float &x, const float &y );

		/**
		* \brief Set the center of the view
		*
		* \param center Center of the view
		*/
		void SetCenter( const glm::vec2 &center );

		/**
		* \brief Set the size of the view
		*
		* \param width Width of the view
		* \param height Height of the view
		*/
		void SetSize( const float &width, const float &height );

		/**
		* \brief Set the size of the view
		*
		* \param size Size of the view
		*/
		void SetSize( const glm::vec2 &size );

		/**
		* \brief Set the rotation of the view
		*
		* \param angle New rotation angle of the view
		*/
		void SetRotation( const float &angle );

		/**
		* \brief Set the viewport of the view
		*
		* \param viewport View's new viewport
		*/
		void SetViewport( const glm::vec4 &viewport );

		/**
		* \brief Reset the view
		*
		* \param rectangle View's new rectangle to reset to
		*/
		void Reset( const glm::vec4 &rectangle );

		/**
		* \brief Get the view's center
		*
		* \return Output returns the view's center vector
		*/
		const glm::vec2 GetCenter( ) const;

		/**
		* \brief Get the view's size
		*
		* \return Output returns the view's size vector
		*/
		const glm::vec2 GetSize( ) const;

		/**
		* \brief Get the view's rotation angle
		*
		* \return Output returns the view's rotation angle
		*/
		const float GetRotation( ) const;

		/**
		* \brief Get the view's viewport
		*
		* \return Output returns the view's viewport vector
		*/
		const glm::vec4 GetViewport( ) const;

		/**
		* \brief Move the view
		*
		* \param offsetX Offset in x axis
		* \param offsetY Offset in y axis
		*/
		void Move( const float &offsetX, const float &offsetY );

		/**
		* \brief Move the view
		*
		* \param offset Offset in x and y axis
		*/
		void Move( const glm::vec2 &offset );

		/**
		* \brief Rotate the view
		*
		* \param angle Angle to rotate by (relative to current rotation angle)
		*/
		void Rotate( const float &angle );

		/**
		* \brief Zoom into the view
		*
		* \param factor Zoom factor (relative to current zoom factor)
		*/
		void Zoom( const float &factor );

		/**
		* \brief Get the view's SFML Transform object (COULD ABTRAST LATER INTO Sonar::Transform)
		*
		* \return Output returns the view's transform
		*/
		const sf::Transform &GetTransform( ) const;

		/**
		* \brief Get the view's SFML Inverse Transform object (COULD ABTRAST LATER INTO Sonar::Transform)
		*
		* \return Output returns the view's inverse transform
		*/
		const sf::Transform &GetInverseTransform( ) const;
        
    private:
		/**
		* \brief Game data object
		*/
		GameDataRef _data;

		/**
		* \brief Local SFML View object
		*/
        sf::View *_view;

    };
}
