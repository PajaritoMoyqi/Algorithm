#include "MakingChange.h"
#include <stdio.h>
#include <stdlib.h>

int Compare( const void* a, const void* b );

int main( void )
{
    int i = 0;
    int Pay = 0;
    int Price = 0;
    int UnitCount = 0;
    int* CoinUnits = NULL;
    int* Change = NULL;

    printf( "Let us know the number of types of coin: " );
    scanf( "%d", &UnitCount );

    CoinUnits = (int*)malloc( sizeof( int ) * UnitCount );
    Change = (int*)malloc( sizeof( int ) * UnitCount );

    for ( i = 0; i < UnitCount; i++ )
    {
        printf( "Let us know unit of [%d]th type of coin: ", i );
        scanf( "%d", &CoinUnits[i] );
    }

    qsort( CoinUnits, UnitCount, sizeof( int ), Compare );

    printf( "What's the price? : " );
    scanf( "%d", &Price );

    printf( "what's the payment of customer? : " );
    scanf( "%d", &Pay );

    GetChange( Price, Pay, CoinUnits, Change, UnitCount );
    PrintChange( CoinUnits, Change, UnitCount );

    return 0;
}

int Compare( const void* a, const void* b )
{
    int _a = *(int*)a;
    int _b = *(int*)b;

    if ( _a < _b )
        return 1;
    else
        return -1;
}