#include <stdio.h>

#define MAX 1000000

int Seq[MAX];
int Visited[MAX];
int Ans[MAX];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Seq[i] );

    int max = 0;
    while ( 1 )
    {
        int flag = 0;
        for ( i = 0; i < n; i++ )
        {
            if ( Seq[i] )
            {
                flag = 1;
                break;
            }
        }

        if ( !flag )
            break;

        int cnt = 0;
        for ( i = 0; i < n; i++ )
        {
            if ( Seq[i] & 1 )
                cnt++;
        }

        if ( cnt > max )
            max = cnt;

        for ( i = 0; i < n; i++ )
            Seq[i] /= 2;
    }

    printf( "%d", max );

    return 0;
}