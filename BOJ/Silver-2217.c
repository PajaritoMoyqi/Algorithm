#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    int RopeSet[n];

    for ( i = 0; i < n; i++ )
        scanf( "%d", &RopeSet[i] );

    qsort( RopeSet, n, sizeof( int ), cmp );

    int tmp, ans = 0;
    for ( i = 0; i < n; i++ )
    {
        tmp = (n - i) * RopeSet[i];
        if ( ans < tmp ) ans = tmp;
    }

    printf( "%d", ans );

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