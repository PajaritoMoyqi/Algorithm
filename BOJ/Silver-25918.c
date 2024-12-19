#include <stdio.h>
#include <math.h>

#define MAX 200000

char STR[MAX+1];

int main( void )
{
    int n;
    scanf( "%d", &n );
    scanf( "%s", STR );

    int i, rNum = 0, lNum = 0, max = 0, ans = 0;
    for ( i = 0; i < n; i++ )
    {
        if ( STR[i] == '(' )
        {
            lNum++;
            max++;
        }
        else if ( STR[i] == ')' )
        {
            rNum++;
            max--;
        }

        if ( abs( max ) > ans )
            ans = abs( max );
    }

    if ( rNum != lNum )
        printf( "-1" );
    else
        printf( "%d", ans );

    return 0;
}