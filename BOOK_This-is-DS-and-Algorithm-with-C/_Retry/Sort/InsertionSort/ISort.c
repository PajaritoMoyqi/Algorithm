#include <stdio.h>
#include <string.h>

void InsertionSort( int Set[], int length )
{
    int i, j, val;

    for ( i = 1; i < length; i++ )
    {
        if ( Set[i-1] <= Set[i] ) continue;

        val = Set[i];

        for ( j = 0; j < i; j++ )
        {
            if ( Set[j] > val )
            {
                memmove( &Set[j+1], &Set[j], sizeof( Set[0] ) * (i - j) );
                Set[j] = val;
                break;
            }
        }
    }
}