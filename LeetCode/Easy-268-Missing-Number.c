#include <stdlib.h>

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}

int missingNumber( int* nums, int numsSize )
{
    qsort( nums, numsSize, sizeof( int ), cmp );

    int i;
    for ( i = 0; i < numsSize; i++ )
    {
        if ( i != nums[i] )
            return i;
    }

    return numsSize;
}