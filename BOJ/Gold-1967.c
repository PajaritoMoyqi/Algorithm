#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int n, limit;
    int *wList, *vList, *ans;

    scanf( "%d%d", &n, &limit );

    wList = (int*)malloc( sizeof( int ) * n );
    vList = (int*)malloc( sizeof( int ) * n );
    ans = (int*)malloc( sizeof( int ) *(limit + 1) );

    int i, j;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d%d", &wList[i], &vList[i] );
        if ( vList[i] == 0 )
            wList[i] = 0;
    }
    for ( i = 0; i <= limit; i++ )
        ans[i] = 0;

    for ( i = 0; i < n; i++ )
    {
        for ( j = limit; j > 0; j-- )
        {
            if ( wList[i] <= j )
            {
                if ( ans[j] < ans[j - wList[i]] + vList[i] )
                    ans[j] = ans[j - wList[i]] + vList[i];
            }
        }

        // int check;
        // for ( check = 0; check <= limit; check++ )
        //     printf( "%d ", ans[check] );
        // puts( "" );
    }

    printf( "%d", ans[limit] );

    free(wList);
    free(vList);
    free(ans);

    return 0;
}