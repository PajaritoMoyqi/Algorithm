#include <stdio.h>
#include <math.h>

int main( void )
{
    int min, max;
    scanf( "%d", &min );
    scanf( "%d", &max );

    int isPrime[max+1];

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int k = 2; k <= max; k++)
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= sqrt(max); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= max; mult++ )
            isPrime[i*mult] = 0;
    }

    int sum = 0, minValue = -1;
    for ( i = min; i <= max; i++ )
    {
        if ( isPrime[i] == 1 )
        {
            sum += i;
            if ( minValue == -1 )
                minValue = i;
        }
    }

    if ( !(~minValue) ) printf( "%d", minValue );
    else
    {
        printf( "%d\n", sum );
        printf( "%d\n", minValue );
    }

    return 0;
}