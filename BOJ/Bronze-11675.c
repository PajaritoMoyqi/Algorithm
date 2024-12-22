#include <stdio.h>

#define MAX 255

unsigned char Ans[MAX+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    unsigned char pwd;
    int i;
    for ( i = 0; i <= MAX; i++ )
    {
        pwd = (unsigned char)(i ^ (i << 1));
        Ans[pwd] = i;
        // printf( "pwd - %d: %d\n", i, pwd );
    }

    for ( i = 0; i < n; i++ )
    {
        scanf( "%hhu", &pwd );
        printf( "%d ", Ans[pwd] );
    }

    return 0;
}