#include <stdio.h>
#include <string.h>

int main( void )
{
    long long llnum = 0LL;
    int t, n;
    char order[7] = { 0 };
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%s", order );
        scanf( "%d", &n );
        n -= 1;

        if ( strcmp( order, "add" ) == 0 )
        {
            llnum |= (1 << n);
        }
        else if ( strcmp( order, "remove" ) == 0 )
        {
            if ( llnum >> n & 1 ) llnum -= (1 << n);
        }
        else if ( strcmp( order, "check" ) == 0 )
        {
            printf( "%d\n", llnum >> n & 1 );
        }
        else if ( strcmp( order, "toggle" ) == 0 )
        {
            llnum ^= (1 << n);
        }
        else if ( strcmp( order, "all" ) == 0 )
        {
            llnum = (1 << 20) - 1;
        }
        else if ( strcmp( order, "empty" ) == 0 )
        {
            llnum = 0;
        }

        // printf( "order: %s, number: %d, result: %lld\n", order, n, llnum );
    }

    return 0;
}