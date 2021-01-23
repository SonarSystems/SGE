#pragma once

#include <External/glm/glm.hpp>
#include <vector>

#include "Sonar.hpp"
#include "Graphics/ScrollingBackground.hpp"

namespace Sonar
{
    class Parallax
    {
    public:
        /**
        * \brief Default class constructor
        */
        Parallax( GameDataRef data );

        /**
        * \brief Class destructor
        */
        ~Parallax( );

        /**
        * \brief Update the Parallax
        *
        * \param dt Delta time between frames
        */
        void Update( const float &dt );

        /**
        * \brief Draw the layers
        */
        void Draw( );

        void AddLayer( const ScrollingBackground &layer );

		void AddLayer( const std::vector<Sprite *> &backgrounds );

		void AddLayer( const std::vector<std::string> &backgrounds );

        // delete layer
        // disable/hide layer
        // set direction
        // set orientation
        // set scroll to normal
        // move (specify the layer)
        // set offset for layer

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        std::vector<ScrollingBackground> _layers;
        
    };
}
