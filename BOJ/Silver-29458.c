#include <stdio.h>

#define MAX 5

int ROOM[MAX];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &ROOM[i] );

    int sum = 0, orSum = 0;
    for ( i = 0; i < n; i++ )
    {
        sum += ROOM[i];
        orSum |= ROOM[i];
    }

    if ( sum == orSum )
    {
        if ( !sum )
        {
            printf( "Yes" );
            return 0;
        }

        while ( sum )
        {
            if ( sum & 1 )
                sum /= 2;
            else
            {
                printf( "No" );
                return 0;
            }
        }
        printf( "Yes" );
    }
    else
        printf( "No" );

    return 0;
}