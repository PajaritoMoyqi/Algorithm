#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long PosX[100000];
long long PosY[100000];

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    long long num;
    scanf( "%lld", &num );

    long long i;
    for ( i = 0; i < num; i++ )
        scanf( "%lld%lld", &PosX[i], &PosY[i] );

    qsort( PosX, num, sizeof( long long ), cmp );
    qsort( PosY, num, sizeof( long long ), cmp );

    long long x = PosX[num/2];
    long long y = PosY[num/2];

    long long sumX = 0;
    for ( i = 0; i < num; i++ )
        sumX += llabs( x - PosX[i] );
    
    long long sumY = 0;
    for ( i = 0; i < num; i++ )
        sumY += llabs( y - PosY[i] );

    printf( "%lld", sumX + sumY );

    return 0;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    long long* elem1 = (long long*)_elem1;
    long long* elem2 = (long long*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}