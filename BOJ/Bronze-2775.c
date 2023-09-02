#include <stdio.h>

apartment[1000+1][15];

int main( void )
{
    int t;
    int floor, nth;
    scanf( "%d", &t );

    int i;
    for ( i = 1; i < 15; i++ )
        apartment[0][i] = i;

    while ( t-- )
    {
        scanf( "%d%d", &floor, &nth );
        printf( "%d\n", DP( floor, nth ) );
    }
}

int DP( int floor, int nth )
{
    if ( apartment[floor][nth] )
        return apartment[floor][nth];
    else
    {
        int res = 0, i;
        for ( int i = 1; i <= nth; i++ )
            res += DP( floor - 1, i );
        
        return res;
    }
}