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

        /**
        * \brief Add a layer to the parallax using a ScrollingBackground object
        *
        * \param layer Layer to be added
        */
        void AddLayer( const ScrollingBackground &layer );

        /**
        * \brief Add a layer to the parallax using a set of sprite objects
        *
        * \param backgrounds Backgrounds to create a layer to be added to the parallax
        */
		void AddLayer( const std::vector<Sprite *> &backgrounds );

        /**
        * \brief Add a layer to the parallax using a set of string
        *
        * \param backgrounds Backgrounds to create a layer to be added to the parallax
        */
		void AddLayer( const std::vector<std::string> &backgrounds );

        /**
        * \brief Delete a layer
        *
        * \param index Index of the layer to be deleted
        */
        void DeleteLayer( const unsigned int &index );

        /**
        * \brief Enable a layer (enables the update and draw functionality)
        *
        * \param index Index of the layer to be enabled
        */
        void EnableLayer( const unsigned int &index );

        /**
        * \brief Disable a layer (disables the update and draw functionality)
        *
        * \param index Index of the layer to be disabled
        */
        void DisableLayer( const unsigned int &index );

        /**
        * \brief Enable a layers updating functionality
        *
        * \param index Index of the layer to be enabled
        */
        void EnableUpdatingForLayer( const unsigned int &index );

        /**
        * \brief Disable a layers updating functionality
        *
        * \param index Index of the layer to be disabled
        */
        void DisableUpdatingForLayer( const unsigned int &index );

        /**
        * \brief Enable a layers drawing functionality
        *
        * \param index Index of the layer to be enabled
        */
		void EnableDrawingForLayer( const unsigned int &index );

        /**
        * \brief Disable a layers drawing functionality
        *
        * \param index Index of the layer to be disabled
        */
		void DisableDrawingForLayer( const unsigned int &index );

        /**
        * \brief Set the direction of a particular layer
        *
		* \param layerIndex Index of the layer to be modified
		* \param direction Direction the layer is to move
        */
		void SetDirection( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction );

        /**
        * \brief Set the direction of all layers
        *
        * \param direction Direction the layer is to move
        */
		void SetDirectionForAllLayers( const ScrollingBackground::DIRECTION &direction );

        /**
        * \brief Set the orientation of a particular layer
        *
        * \param layerIndex Index of the layer to be modified
        * \param orientation Orientation the layer is to have
        */
		void SetOrientation( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Set the orientation of all layers
        *
        * \param orientation Orientation the layer is to have
        */
		void SetOrientationForAllLayers( const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Set a layer to scroll manually
        *
        * \param layerIndex Index of the layer to be modified
        * \param orientation Orientation the layer is to have
        */
        void SetScrollToManual( const unsigned int &layerIndex, const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Set all layers to scroll manually
        *
        * \param orientation Orientation the layer is to have
        */
        void SetScrollToManualForAllLayers( const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Move a layer
        *
        * \param layerIndex Index of the layer to be modified
		* \param direction Direction the layer is to move
		* \param speed How much the layer should move (speed for the update, single use)
        */
        void MoveLayer( const unsigned int &layerIndex, const ScrollingBackground::DIRECTION &direction, const float &speed );

        /**
        * \brief Move all layers
        *
        * \param direction Direction the layer is to move
        * \param speed How much the layer should move (speed for the update, single use)
        */
        void MoveAllLayers( const ScrollingBackground::DIRECTION &direction, const float &speed );

        /**
        * \brief Set a layer's offset
        *
        * \param layerIndex Index of the layer to be modified
        * \param offsetX Offset for the x axis
		* \param offsetY Offset for the y axis
        */
		void SetOffset( const unsigned int &layerIndex, const float &offsetX, const float &offsetY );
		
        /**
        * \brief Set all layers offset
        *
        * \param offsetX Offset for the x axis
        * \param offsetY Offset for the y axis
        */
        void SetOffsetForAllLayers( const float &offsetX, const float &offsetY );

        /**
        * \brief Set a layer's speed
        *
        * \param layerIndex Index of the layer to be modified
        * \param speed Speed the layer should move
        */
        void SetSpeed( const unsigned int &layerIndex, const float &speed );

        /**
        * \brief Set all layers speed
        *
        * \param speed Speed the layer should move
        */
        void SetSpeedForAllLayers( const float &speed );

        /**
        * \brief Reset a layer
        *
        * \param layerIndex Index of the layer to be modified
        */
        void Reset( const unsigned int &layerIndex );

        /**
        * \brief Reset all layers
        *
        * \param layerIndex Index of the layer to be modified
        */
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
