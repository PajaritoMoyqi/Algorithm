#include <stdio.h>

#define MAX 200000
#define ALPHABET_MAX 26

char STR[MAX+1];
char CHECK[ALPHABET_MAX];

int main( void )
{
    int n;
    scanf( "%d", &n );
    scanf( "%s", STR );

    int idx;
    int i;
    for ( i = 0; i < n; i++ )
    {
        idx = STR[i] - 'a';
        CHECK[idx]++;
    }

    if ( n & 1 )
    {
        idx = STR[n/2] - 'a';
        CHECK[idx]--;
    }

    for ( i = 0; i < ALPHABET_MAX; i++ )
    {
        if ( CHECK[i] & 1 )
        {
            printf( "No" );
            return 0;
        }
    }
    
    printf( "Yes" );

    return 0;
}