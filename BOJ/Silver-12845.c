#include <stdio.h>
#include <stdlib.h>

int Level[1000];

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Level[i] );

    qsort( Level, n, sizeof( int ), cmp );

    int lev, ans = 0;
    for ( i = 0; i < n; i++ )
    {
        lev = Level[i];
        if ( !i )
            if ( n == 1 )
                ans += lev;
            else
                ans += (lev*(n-1));
        else
            ans += lev;
    }

    printf( "%d", ans );

    return 0;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return -1;
    else if ( *elem1 < *elem2 )
        return 1;
    else
        return 0;
}