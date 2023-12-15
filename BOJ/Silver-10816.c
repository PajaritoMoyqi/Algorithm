#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n, m, num, i;
    scanf( "%d", &n );
    
    int NumberSet[n];
    for ( i = 0; i < n; i++ )
        scanf( "%d", &NumberSet[i] );

    qsort( NumberSet, n, sizeof( int ), cmp );
    // for ( i = 0; i < n; i++ )
    //     printf( "%d ", NumberSet[i] );

    int* find;
    scanf( "%d", &m );
    while ( m-- )
    {
        int cnt = 0;
        scanf( "%d", &num );

        printf( "%d ", BSearch( NumberSet, n, num ) );
    }

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
int BSearch( int Set[], int len, int target )
{
    int leftIdx = 0, rightIdx = len, middle;
    while ( rightIdx > leftIdx )
    {
        middle = (leftIdx + rightIdx) / 2;
        Set[middle] > target ? rightIdx = middle : (leftIdx = middle + 1);
    }
    
    int tmp = rightIdx;
    leftIdx = 0, rightIdx = len;
    while ( rightIdx > leftIdx )
    {
        middle = (leftIdx + rightIdx) / 2;
        Set[middle] >= target ? rightIdx = middle : (leftIdx = middle + 1);
    }
    return tmp - rightIdx;
}