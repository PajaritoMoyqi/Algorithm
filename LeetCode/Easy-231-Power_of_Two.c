#include <stdbool.h>

bool isPowerOfTwo( int n )
{
    if ( n <= 0 )
        return false;

    while ( 1 )
    {
        if ( n & 1 )
        {
            if ( n == 1 )
                return true;
            else
                return false;
        }
        n /= 2;
    }
}