#pragma once

#include "Core/Game.hpp"

namespace Sonar
{
    class Sprite;

    class ScrollingBackground
    {
    public:
        /**
        * \brief Direction of the moving backgrounds
        */
        enum DIRECTION
        {
            LEFT = 0,
            RIGHT,
            UP,
            DOWN
        };

        /**
        * \brief Orientation of the moving backgrounds
        */
        enum ORIENTATION
        {
            HORIZONTAL = 0,
            VERTICAL
        };

        /**
        * \brief Default class constructor
        */
        ScrollingBackground( GameDataRef data );
        
        /**
        * \brief Class destructor
        */
        ~ScrollingBackground( );

        /**
        * \brief Set the backgrounds
        *
        * \param backgrounds All the backgrounds to be set
        */
        void SetBackgrounds( const std::vector<Sprite *> &backgrounds );

        /**
        * \brief Set the backgrounds
        *
        * \param backgrounds All the backgrounds to be using file paths
        */
        void SetBackgrounds( const std::vector<std::string> &backgrounds );

        /**
        * \brief Update the scrolling backgrounds
        *
        * \param dt Delta time between frames
        */
        void Update( const float &dt );

        /**
        * \brief Draw the backgrounds
        */
        void Draw( );

        /**
        * \brief Set the background scrolling speed
        *
        * \param speed Speed at which the backgrounds move
        */
        void SetSpeed( const float &speed );

        /**
        * \brief Get the speed at which the backgrounds scroll
        *
        * \return Output returns the background speed
        */
        [[nodiscard]] float GetSpeed( ) const;

        /**
        * \brief Set the direction of the scrolling backgrounds
        *
        * \param direction Direct of the scroll
        */
        void SetDirection( const ScrollingBackground::DIRECTION &direction );

        /**
        * \brief Get the direction of the scrolling backgrounds (the order is reverse for right/down, so last appears first)
        *
        * \return Output returns the direction of the background scroll
        */
        [[nodiscard]] ScrollingBackground::DIRECTION GetDirection( ) const;

        /**
        * \brief Set the orientation of the scrolling backgrounds
        *
        * \param orientation Orientation of the scroll
        */
        void SetOrientation( const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Get the orientation of the scrolling backgrounds
        *
        * \return Output returns the orientation of the background scroll
        */
        [[nodiscard]] ScrollingBackground::ORIENTATION GetOrientation( ) const;

        /**
        * \brief Set the scrolling to be triggered manually not time based (backgrounds are positioned with last first and going in the left/up direction)
        *
        * \param orientation Orientation of the manual scroll
        */
        void SetScrollToManual( const ScrollingBackground::ORIENTATION &orientation );

        /**
        * \brief Move the backgrounds manually
        *
		* \param direction Direction of the scrolling backgrounds
		* \param speed Movement speed of the backgrounds
        */
        void Move( const ScrollingBackground::DIRECTION &direction, const float &speed );

        /**
        * \brief Resets the backgrounds
        */
        void Reset( );

        /**
        * \brief Set the background offset
        *
		* \param offsetX Offset between backgrounds in the x axis
		* \param offsetY Offset between backgrounds in the y axis
        */
        void SetOffset( const float &offsetX, const float &offsetY );

    private:
        /**
        * \brief Set background position
        */
        void SetBackgroundPositions( );

        /**
        * \brief Game data object
        */
        GameDataRef _data;

        /**
        * \brief Backgrounds to scroll next to each other
        */
        std::vector<Sprite *> _backgrounds;

        /**
        * \brief Speed at which the background moves (negative moves it left/up and positive moves it right/down)
        */
        float _speed;

        /**
        * \brief The direction of the moving backgrounds
        */
        ScrollingBackground::DIRECTION _direction, _originalDirection;

        /**
        * \brief The orientation of the moving backgrounds
        */
        ScrollingBackground::ORIENTATION _orientation;

        /**
        * \brief Does the scrolling have to stop after a single update
        */
        bool _isSingleScroll;

        /**
        * \brief Offsets for the backgrounds
        */
        float _offsetX, _offsetY;
        
    };
}
