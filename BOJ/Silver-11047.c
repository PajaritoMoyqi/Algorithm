#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int n, cash;
    scanf( "%d%d", &n, &cash );

    int* arr = (int*)calloc( n, sizeof( int ) );

    int i;
    for ( i = n-1; i >= 0; i-- )
        scanf( "%d", &arr[i] );

    int cnt = 0;
    for ( i = 0; i < n; i++ )
    {
        if ( !cash )
            break;

        while ( arr[i] <= cash )
        {
            cash -= arr[i];
            cnt++;
        }
    }

    printf( "%d", cnt );

    free( arr );
    return 0;
}