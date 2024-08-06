#include <stdio.h>

long long X[100000];
long long Y[100000];
long long numX[1+100000];
long long numY[1+100000];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%lld%lld", &X[i], &Y[i] );
        numX[X[i]]++;
        numY[Y[i]]++;
    }

    long long ans = 0;
    for ( i = 0; i < n; i++ )
        ans += ((numX[X[i]]-1)*(numY[Y[i]]-1));

    printf( "%lld", ans );

    return 0;
}