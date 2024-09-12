#include <stdio.h>

#define MAX_N 2187

int Video[MAX_N+1][MAX_N+1];
int cnt[3];

void Compression( int(* Video)[MAX_N+1], int x, int y, int len, int cnt[3] );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, j;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
            scanf( "%d", &Video[i][j] );

    Compression( Video, 1, 1, n, cnt );

    printf( "%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2] );

    return 0;
}

void Compression( int(* Video)[MAX_N+1], int x, int y, int len, int cnt[3] )
{
    int num, flag = 0;
    int i, j;
    for ( i = y; i < y + len; i++ )
        for ( j = x; j < x + len; j++ )
        {
            if ( i == y && j == x )
            {
                num = Video[i][j];
                continue;
            }

            if ( num != Video[i][j] )
            {
                int L = len/3;
                flag = 1;
                Compression( Video, x, y, L, cnt );
                Compression( Video, x+L, y, L, cnt );
                Compression( Video, x+2*L, y, L, cnt );
                Compression( Video, x, y+L, L, cnt );
                Compression( Video, x+L, y+L, L, cnt );
                Compression( Video, x+2*L, y+L, L, cnt );
                Compression( Video, x, y+2*L, L, cnt );
                Compression( Video, x+L, y+2*L, L, cnt );
                Compression( Video, x+2*L, y+2*L, L, cnt );
                
                return;
            }
        }

    if ( !flag )
        cnt[num+1]++;
}