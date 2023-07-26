#include <stdio.h>
#include <math.h>

int main( void )
{
    int max, cnt, notPrimeCnt = 0;
    scanf( "%d", &max );
    scanf( "%d", &cnt );

    int isPrime[max+1];

    isPrime[0] = 0;
    isPrime[1] = 0;
    
    int k;
    for ( int k = 2; k <= max; k++ )
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= max; i++ )
    {
        if ( isPrime[i] == 0 ) continue;

        int mult;
        for ( mult = 1; i*mult <= max; mult++ )
        {
            if ( isPrime[i*mult] == 0 ) continue;

            isPrime[i*mult] = 0;
            notPrimeCnt++;

            if ( notPrimeCnt == cnt )
            {
                printf( "%d", i*mult );
                goto end;
            } 
        }
    }

    end:
        return 0;
}