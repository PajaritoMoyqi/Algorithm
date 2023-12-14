#include <stdio.h>

void Swap( int* a, int* b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int PartitionStep( int Set[], int left, int right )
{
    int first = left;
    int pivot = Set[first];

    ++left;

    while ( left <= right )
    {
        while ( Set[left] <= pivot && left < right )
            ++left;
        
        while ( Set[right] >= pivot && left <= right )
            --right;

        if ( left < right )
            Swap( &Set[left], &Set[right] );
        else
            break;
    }

    Swap( &Set[first], &Set[right] );

    return right;
}

void QuickSort( int Set[], int left, int right )
{
    if ( left < right )
    {
        int idx = PartitionStep( Set, left, right );

        QuickSort( Set, left, idx - 1 );
        QuickSort( Set, idx + 1, right );
    }
}