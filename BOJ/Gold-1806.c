#include <stdio.h>
#include <math.h>

#define MAX 100000
int Arr[MAX+1];

int main( void )
{
    int i;
    int n, val, ans = 0, len;
    scanf( "%d%d", &n, &val );

    int start, end = 1, sum = 0;

    for ( i = 1; i <= n; i++ )
        scanf( "%d", &Arr[i] );

    for ( start = 1; start <= n; start++ )
    {
        while ( sum < val && end <= n )
        {
            sum += Arr[end];
            // printf( "sum: %d, start: %d, end: %d, ans: %d\n", sum, start, end, ans );
            end++;
        }

        len = end - start;
        // printf( "sum: %d, start: %d, end: %d, ans: %d, len: %d\n", sum, start, end, ans, len );

        if ( sum >= val && n >= len )
        {
            if ( ans ) ans = (ans > len) ? len : ans;
            else ans = len;
        }

        sum -= Arr[start];
    }

    printf( "%d", ans );

    return 0;
}