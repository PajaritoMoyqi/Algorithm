#include <stdio.h>
int Points[300000];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d%d%d", &Points[i*3], &Points[i*3+1], &Points[i*3+2] );

    int m;
    scanf( "%d", &m );
    for ( i = 0; i < m; i++ )
    {
        int x, y, z, r;
        scanf( "%d%d%d%d", &x, &y, &z, &r );

        int ans = 0;
        int j;
        for ( j = 0; j < n; j++ )
        {
            long long lenSqr = 1LL*(x - Points[j*3])*(x - Points[j*3]) + 1LL*(y - Points[j*3+1])*(y - Points[j*3+1]) + 1LL*(z - Points[j*3+2])*(z - Points[j*3+2]);
            long long rSqr = 1LL*r*r;
            if ( lenSqr <= rSqr )
                ans++;
        }

        printf( "%d\n", ans );
    }

    return 0;
}