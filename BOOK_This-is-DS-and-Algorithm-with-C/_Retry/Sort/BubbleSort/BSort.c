#include <stdio.h>

void BubbleSort( int Set[], int length )
{
    int i, j, tmp;

    for ( i = 0; i < length - 1; i++ )
    {
        for ( j = 0; j < length - (i + 1); j++ )
        {
            if ( Set[j] > Set[j+1] )
            {
                tmp = Set[j+1];
                Set[j+1] = Set[j];
                Set[j] = tmp;
            }
        }
    }
}