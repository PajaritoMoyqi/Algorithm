#include <stdio.h>

#define MAX 2000

int M[MAX+1];

int main( void )
{
    int l, r, x;
    scanf( "%d%d%d", &l, &r, &x );

    int tmp;
    int i;
    for ( i = l; i <= r; i++ )
    {
        tmp = i | x;
        M[tmp]++;
    }

    for ( i = 0; i <= 2000; i++ )
    {
        if ( !M[i] )
        {
            printf( "%d", i );
            break;
        }
    }

    return 0;
}