#include <stdio.h>

#define MAX_N 1000
#define MAX_CLASS 10000

long long Class[MAX_CLASS+1];
long long Student[MAX_N+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    long long rest;
    int i, j, num, h;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &num );

        for ( j = 1; j <= num; j++ )
        {
            scanf( "%d", &h );
            rest = 1LL << h;

            if ( !(Class[i] & rest) )
                Class[i] += rest;
        }
    }

    int m;
    scanf( "%d", &m );
    for ( i = 1; i <= m; i++ )
    {
        scanf( "%d", &num );

        for ( j = 1; j <= num; j++ )
        {
            scanf( "%d", &h );
            rest = 1LL << h;

            if ( !(Student[i] & rest) )
                Student[i] += rest;
        }
    }

    for ( i = 1; i <= m; i++ )
    {
        int cnt = 0;
        for ( j = 1; j <= n; j++ )
        {
            if ( (Student[i] & Class[j]) == Class[j] )
                cnt++;
        }

        printf( "%d\n", cnt );
    }

    return 0;
}