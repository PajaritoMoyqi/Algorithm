#include <stdbool.h>

bool isUgly( int n )
{
    if ( n <= 0 )
        return false;

    while ( !(n & 1) )
        n /= 2;

    while ( !(n % 3) )
    {
        n /= 3;
    }

    while ( !(n % 5) )
    {
        n /= 5;
    }

    if ( n == 1 )
        return true;
    else
        return false;
}