#include <stdio.h>

int Drinks[10000];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, max = 0;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &Drinks[i] );
        if ( max < Drinks[i] )
            max = Drinks[i];
    }

    int flag = 1;
    double ans = .0f;
    for ( i = 0; i < n; i++ )
    {
        if ( Drinks[i] == max && flag )
        {
            ans += (double)Drinks[i];
            flag = 0;
        }
        else
            ans += (double)Drinks[i] / 2;
    }

    printf( "%.5f", ans );

    return 0;
}