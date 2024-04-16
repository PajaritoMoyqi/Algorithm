#include <stdio.h>

int score[100];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &score[i] );

    int prev = -1, cnt = 0;
    for ( i = n-1; i >= 0; i-- )
    {
        if ( ~prev )
        {
            while ( prev <= score[i] )
            {
                score[i]--;
                cnt++;
            }
        }

        prev = score[i];
    }

    printf( "%d", cnt );

    return 0;
}