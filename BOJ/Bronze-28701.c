#include <stdio.h>

int main( void )
{
    long long limit;
    scanf( "%lld", &limit );

    long long sum = 0, i, tripleSum = 0;
    for ( i = 1; i <= limit; i++ )
    {
        sum += i;

        tripleSum += (i*i*i);
    }

    printf( "%d\n", sum );
    printf( "%d\n", sum * sum );
    printf( "%d\n", tripleSum );

    return 0;
}