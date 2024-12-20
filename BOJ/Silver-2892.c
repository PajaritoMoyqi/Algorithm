#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 2

int Seq[MAX];
char STR[LEN+2];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%s", STR );
        Seq[i] = (int)strtol( STR, NULL, 16 );
    }
    

    for ( i = 0; i < n; i++ )
        if ( Seq[i] >= 64 )
            printf( "-" );
        else
            printf( "." );

    return 0;
}