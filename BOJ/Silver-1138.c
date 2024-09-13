#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10

int List[MAX_N+1];
int Ans[MAX_N+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
        scanf( "%d", &List[i] );

    int j;
    for ( i = 1; i <= n; i++ )
    {
        int cnt = 0;
        for ( j = 1; j <= n; j++ )
        {
            if ( List[i] == cnt && !Ans[j] )
            {
                Ans[j] = i;
                // printf( "Ans[%d] = %d\n", j, i );
                break;
            }

            if ( !Ans[j] )
                cnt++;
        }
    }

    for ( i = 1; i <= n; i++ )
        printf( "%d ", Ans[i] );

    return 0;
}