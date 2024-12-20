#include <stdio.h>
#include <string.h>

#define MAX 30

char STR[MAX+1];

long long power2( long long number );

int main( void )
{
    scanf( "%s", STR );
    long long day;
    scanf( "%lld", &day );

    int len = strlen( STR );
    
    long long num = 0;
    int i;
    for ( i = len-1; i >= 0; i-- )
    {
        if ( STR[i] == 'B' )
            num += power2( i );
    }

    long long res = num + day;

    while ( len-- )
    {
        if ( res & 1 )
            printf( "B" );
        else
            printf( "A" );

        res /= 2;
    }

    return 0;
}

long long power2( long long number )
{
    long long result;
    if ( number == 0 ) return 1;
    else
        return 2 * power2( number - 1 );
}