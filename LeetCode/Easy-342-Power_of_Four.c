#include <stdbool.h>

bool isPowerOfFour( int n )
{
    if ( n <= 0 )
        return false;

    while ( 1 )
    {
        if ( n & 3 )
        {
            if ( n == 1 )
                return true;
            else
                return false;
        }
        n /= 4;
    }
}