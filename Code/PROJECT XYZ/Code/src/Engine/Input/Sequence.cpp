#include "Sequence.hpp"

namespace Sonar
{
    Sequence::Sequence( )
    {
        _count = 0;
        _min = 0;
        _max = 100;
    }

    void Sequence::TickUp( const float &amount, const bool &canGoOver )
    {
        _count += amount;
        
        if ( !canGoOver && _count > 100 )
        { _count = 100; }
    }

    void Sequence::TickDown( const float &amount, const bool &canGoUnder )
    {
        _count -= amount;
        
        if ( !canGoUnder && _count < 0 )
        { _count = 0; }
    }

    const float &Sequence::GetCount( ) const
    { return _count; }
    
    const float &Sequence::GetMin( ) const
    { return _min; }

    const float &Sequence::GetMax( ) const
    { return _max; }


    void Sequence::MousePress( const Mouse::Button &button, const float &amount )
    {
        if ( Mouse::IsPressed( button ) )
        { TickUp( amount ); }
    }

    void Sequence::SetCount( const float &count )
    { _count = count; }

    void Sequence::SetMin( const float &min )
    { _min = min; }

    void Sequence::SetMax( const float &max )
    { _max = max; }


    void Squence::Update( const float &dt )
    {
        // IMPLEMENT WITH A TIMER SYSTEM
        // PROBABLY BEST TO RENAME THE METHOD
    }
}
