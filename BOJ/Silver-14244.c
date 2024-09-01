#include <stdio.h>

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int plus = n - m;

    int i;
    int node = 0;
    for ( i = 0; i < plus; i++ )
        printf( "%d %d\n", node++, node );

    for ( i = node+1; i < n; i++ )
        printf( "%d %d\n", node, i );

    return 0;
}