#include <stdio.h>

int main( void )
{
    int n;
    scanf( "%d", &n );

    int a, b;
    scanf( "%d%d", &a, &b );

    int remove;
    int ans = 0;
    if ( a + b >= n )
        remove = a + b - n;
    else
        remove = n - (a + b);

    int pow2 = 1;
    int i;
    for ( i = 0; i < remove; i++ )
        pow2 *= 2;

    for ( i = remove; i < n; i++ )
    {
        ans += pow2;
        pow2 *= 2;
    }

    printf( "%d", ans );

    return 0;
}