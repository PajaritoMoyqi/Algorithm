#include <stdio.h>

int main( void )
{
    long long n, k;
    scanf( "%lld%lld", &n, &k );

    long long res = n*n*k;

    printf( "%lld", res );

    return 0;
}