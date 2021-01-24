#pragma once

#include <External/glm/glm.hpp>
#include <vector>

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

        void DeleteLayer( const unsigned int &index );

        void EnableLayer( const unsigned int &index );

        void DisableLayer( const unsigned int &index );

        void EnableUpdatingForLayer( const unsigned int &index );

        void DisableUpdatingForLayer( const unsigned int &index );

		void EnableDrawingForLayer( const unsigned int &index );

		void DisableDrawingForLayer( const unsigned int &index );

		void SetDirection( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction );

		void SetDirectionForAllLayers( const ScrollingBackground::DIRECTION &direction );

		void SetOrientation( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation );

		void SetOrientationForAllLayers( const ScrollingBackground::ORIENTATION &orientation );

        void SetScrollToManual( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation );

        void SetScrollToManualForAllLayers( const ScrollingBackground::ORIENTATION &orientation );

        void MoveLayer( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction, const float &speed );

        void MoveAllLayers( const ScrollingBackground::DIRECTION &direction, const float &speed );

		void SetOffset( const unsigned int &layerIndex, const float &offsetX, const float &offsetY );
		
        void SetOffsetForAllLayers( const float &offsetX, const float &offsetY );

        void SetSpeed( const unsigned int &layerIndex, const float &speed );

        void SetSpeedForAllLayers( const float &speed );

        void Reset( const unsigned int &layerIndex );

        void ResetAllLayers( );

    private:
        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Parallax layers, each being a set of scrolling backgrounds
        */
        std::vector<ScrollingBackground> _layers;

        /**
        * \brief Update and draw status, first is update and second is draw
        */
        std::vector<std::pair<bool, bool>> _layerStatus;
        
    };
}
