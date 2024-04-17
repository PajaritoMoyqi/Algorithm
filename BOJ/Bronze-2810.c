#include <stdio.h>

char Seats[50];

int main( void )
{
    int n;
    scanf( "%d", &n );

    scanf( "%s", Seats );

    int i, cnt = 0, cntL = 0;
    for ( i = 0; i < n; i++ )
    {
        if ( Seats[i] == 'S' )
            cnt++;
        else
            cntL++;
    }

    if ( cntL )
    {
        cntL -= 2;
        cnt += 2;

        if ( cntL )
            cnt += (cntL / 2);
    }

    printf( "%d", cnt );

    return 0;
}