#include <stdio.h>

int Drinks[10000];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, max = 0, curr;
    double ans = .0f;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &curr );
        if ( max < curr )
        {
            ans += (double)max / 2;
            max = curr;
        }
        else
            ans += (double)curr / 2;
    }

    ans += (double)max;

    printf( "%.5f", ans );

    return 0;
}