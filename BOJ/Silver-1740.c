#include <stdio.h>

long long power3( long long number );

int main( void )
{
    long long givenNumber;
    scanf( "%lld", &givenNumber );

    long long sum = 0, cnt = 0;
    while ( givenNumber )
    {
        if ( givenNumber & 1 )
        {
            sum += power3( cnt );
        }

        cnt++;
        givenNumber >>= 1;
    }

    printf( "%lld", sum );

    return 0;
}

long long power3( long long number )
{
    long long result;
    if ( number == 0 ) return 1;
    else
        return 3 * power3( number - 1 );
}