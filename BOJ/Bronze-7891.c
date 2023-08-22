#include <stdio.h>

int main( void )
{
    int t;
    long long a, b;
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%lld%lld", &a, &b );
        printf( "%lld\n", a + b );
    }

    return 0;
}