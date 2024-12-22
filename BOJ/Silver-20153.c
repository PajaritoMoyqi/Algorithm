#include <stdio.h>

#define MAX 2222222

int Seq[MAX];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int num;
    int flag = 0, min = 1000;
    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Seq[i] );

    int cmpN = 0;
    for ( i = 0; i < n; i++ )
        cmpN ^= Seq[i];
    // printf( "cmp: %d\n", cmpN );

    int ans = cmpN, tmp;
    for ( i = 0; i < n; i++ )
    {
        tmp = cmpN ^ Seq[i];
        // printf( "%d ", tmp );
        if ( ans < tmp )
            ans = tmp;
    }

    printf( "%d%d", ans, ans );

    return 0;
}