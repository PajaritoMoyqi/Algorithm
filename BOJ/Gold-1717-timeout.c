#include <stdio.h>
#include <stdlib.h>

int Parent[1000000+1];

int FindParent( int i )
{
    if ( Parent[i] == i ) return i;
    else return FindParent( Parent[i] );
}

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int i;
    for ( i = 0; i <= n; i++ )
        Parent[i] = i;

    while ( m-- )
    {
        int order, target1, target2;
        scanf( "%d", &order );
        scanf( "%d%d", &target1, &target2 );

        if ( !order )
        {
            if ( target1 == target2 ) continue;
            
            int parent1, parent2;
            parent1 = FindParent( target1 );
            parent2 = FindParent( target2 );

            if ( parent1 == parent2 ) continue;
            else
                Parent[parent1] = parent2;
        }
        else
        {
            if ( FindParent( target1 ) == FindParent( target2 ) )
                printf( "YES\n" );
            else
                printf( "NO\n" );
        }
    }

    return 0;
}