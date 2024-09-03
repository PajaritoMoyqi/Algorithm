#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 500000

int Arr[MAX_LEN];
int Sorted_Arr[MAX_LEN];

int cmp( const void* _elem1, const void* _elem2 );
int BinarySearch( int Set[], int length, int target );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, num;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );
        Arr[i] = num;
        Sorted_Arr[i] = num;
    }

    qsort( Sorted_Arr, n, sizeof( int ), cmp );

    int j, sortedIdx, maxDiff = 0;
    for ( i = 0; i < n; i++ )
    {
        sortedIdx = BinarySearch( Sorted_Arr, n, Arr[i] );
        int ans = abs( n - sortedIdx ) > abs( sortedIdx - i ) ? abs( sortedIdx - i ) : abs( n - sortedIdx );
        if ( ans > maxDiff )
            maxDiff = ans;
    }

    printf( "%d", maxDiff );

    return 0;
}

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
int BinarySearch( int Set[], int length, int target )
{
    int left, right, middle;
    left = 0;
    right = length -1;
    
    while ( left <= right )
    {
        middle = (left + right) / 2;

        if ( target > Set[middle] )
            left = middle + 1;
        else if ( target < Set[middle] )
            right = middle - 1;
        else 
            return middle;
    }
}