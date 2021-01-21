#pragma once

#include <External/glm/glm.hpp>
#include <vector>

#include "Graphics/Sprite.hpp"
#include "Sonar.hpp"

namespace Sonar
{
    class Parallax
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
        Parallax( GameDataRef data );
        
        /**
        * \brief Class destructor
        */
        ~Parallax( );

        /**
        * \brief Set the backgrounds of the scroll
        *
        * \param backgrounds All the backgrounds to be set
        */
        void SetBackgrounds( const std::vector<Sprite *> &backgrounds );

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
        float GetSpeed( ) const;

        /**
        * \brief Set the direction of the scrolling backgrounds
        *
        * \param direction Direct of the scroll
        */
        void SetDirection( const Parallax::DIRECTION &direction );

        /**
        * \brief Get the direction of the scrolling backgrounds (the order is reverse for right/down, so last appears first)
        *
        * \return Output returns the direction of the background scroll
        */
        Parallax::DIRECTION GetDirection( ) const;

        /**
        * \brief Set the orientation of the scrolling backgrounds
        *
        * \param orientation Orientation of the scroll
        */
        void SetOrientation( const Parallax::ORIENTATION &orientation );

        /**
        * \brief Get the orientation of the scrolling backgrounds
        *
        * \return Output returns the orientation of the background scroll
        */
        Parallax::ORIENTATION GetOrientation( ) const;

        /**
        * \brief Set the scrolling to be triggered manually not time based (backgrounds are positioned with last first and going in the left/up direction)
        *
        * \param orientation Orientation of the manual scroll
        */
        void SetScrollToManual( const Parallax::ORIENTATION &orientation );

        /**
        * \brief Move the backgrounds manually
        *
		* \param direction Direction of the scrolling backgrounds
		* \param speed Movement speed of the backgrounds
        */
        void Move( const Parallax::DIRECTION &direction, const float &speed );

        // Set initial position
        // RESET

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
        Parallax::DIRECTION _direction;

        /**
        * \brief The orientation of the moving backgrounds
        */
        Parallax::ORIENTATION _orientation;

        /**
        * \brief Does the scrolling have to stop after a single update
        */
        bool _isSingleScroll;
        
    };
}
