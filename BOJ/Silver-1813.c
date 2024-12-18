#include <stdio.h>

#define MAX 50

int Cnt[MAX+1];

int main( void )
{
    int n, num;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );
        Cnt[num]++;
    }

    int ans = -1;
    for ( i = 0; i <= MAX; i++ )
    {
        if ( i == Cnt[i] )
            ans = i;
    }

    printf( "%d", ans );

    return 0;
}