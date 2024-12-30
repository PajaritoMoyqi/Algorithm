#include <stdbool.h>

bool isPowerOfThree( int n )
{
    if ( n <= 0 )
        return false;

    while ( 1 )
    {
        if ( n % 3 == 1 || n % 3 == 2 )
        {
            if ( n == 1 )
                return true;
            else
                return false;
        }
        n /= 3;
    }
}