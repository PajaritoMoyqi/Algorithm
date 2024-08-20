#include <stdio.h>
#include <stdlib.h>

#define MAX_CITY 200

int Parent[MAX_CITY+1];

int FindParent( int i )
{
    if ( Parent[i] == i ) return i;
    else return Parent[i] = FindParent( Parent[i] );
}

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int i;
    for ( i = 0; i <= n; i++ )
        Parent[i] = i;

    int j, relation;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            scanf( "%d", &relation );

            if ( i == j )
                continue;
            
            if ( relation )
            {
                int parentI, parentJ;
                parentI = FindParent( i );
                parentJ = FindParent( j );

                if ( parentI == parentJ )
                    continue;
                else
                    Parent[parentI] = parentJ;
            }
        }
    }

    int parent = -1, prevParent = -1, cityNum, flag = 0;
    while ( m-- )
    {
        scanf( "%d", &cityNum );
        if ( !~prevParent )
        {
            prevParent = FindParent( cityNum );
            continue;
        }

        parent = FindParent( cityNum );

        if ( parent != prevParent )
            flag = 1;
    }

    if ( flag )
        printf( "NO" );
    else
        printf( "YES" );

    return 0;
}