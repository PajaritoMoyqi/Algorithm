#include <stdio.h>
#include <math.h>

int main( void )
{
    int isPrime[1000+1];

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int k = 2; k <= 1000; k++)
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= sqrt(1000); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= 1000; mult++ )
            isPrime[i*mult] = 0;
    }

    int n, cnt = 0;
    scanf( "%d", &n );

    while( n-- )
    {
        int num;
        scanf( "%d", &num );

        if ( isPrime[num] ) cnt++;
    }

    printf( "%d", cnt );

    return 0;
}