#include <stdio.h>

long long power2( long long number );

int main( void )
{
    unsigned long long x, k;

    scanf( "%lld %lld", &x, &k );
    unsigned long long givenX = x;
    unsigned long long givenK = k;

    int length = 0;
    int lengthK = 0;
    while ( givenX )
    {
        length++;
        givenX >>= 1;
    }
    while ( givenK )
    {
        lengthK++;
        givenK >>= 1;
    }

    char bits[length];
    char bitsK[lengthK];
    int i;
    unsigned long long testX = x;
    unsigned long long testK = k;
    for ( i = 0; i < length; i++ )
    {
        if ( testX & 1 ) bits[i] = 1;
        else bits[i] = 0;

        testX >>= 1;
    }
    for ( i = 0; i < lengthK; i++ )
    {
        if ( testK & 1 ) bitsK[i] = 1;
        else bitsK[i] = 0;

        testK >>= 1;
    }
    // for ( i = 0; i < length; i++ )
    //     printf( "bits[%d]: %d\n", i, bits[i] );
    // for ( i = 0; i < lengthK; i++ )
    //     printf( "bitsK[%d]: %d\n", i, bitsK[i] );

    char bitsY[length+lengthK];
    int idx = 0;
    int idxK = 0;
    while ( idxK != lengthK )
    {
        if ( bits[idx] == 1 )
        {
            bitsY[idx] = 0;
        }
        else
        {
            bitsY[idx] = bitsK[idxK];
            idxK++;
        }

        idx++;
    }
    // for ( i = 0; i < length + lengthK; i++ )
    //     printf( "bitsY[%d]: %d\n", i, bitsY[i] );

    unsigned long long sum = 0;
    for ( i = 0; i < length + lengthK; i++ )
    {
        if ( bitsY[i] ) sum += power2( i );
    }

    printf( "%lld", sum );

    return 0;
}

long long power2( long long number )
{
    if ( number == 0 ) return 1;
    else
        return 2 * power2( number - 1 );
}