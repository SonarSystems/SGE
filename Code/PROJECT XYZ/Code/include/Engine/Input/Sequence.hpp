#pragma once

#include "Joystick.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace Sonar
{
    class Sequence
    {
    public:
        Sequence( );
        ~Sequence( ) { };
        
        void TickUp( const float &amount = 1, const bool &canGoOver = false );
        
        void TickDown( const float &amount = 1, const bool &canGoUnder = false );
        
        void MousePress( const Mouse::Button &button, const float &amount = 1 );
        
        void SetCount( const float &count );
        
        void SetMin( const float &min );
        
        void SetMax( const float &max );
        
        const float &GetCount( ) const;
        
        const float &GetMin( ) const;
        
        const float &GetMax( ) const;
        
        void Update( const float &dt );

    private:
        float _count;
        
        float _min;
        
        float _max;
        
    };
}
