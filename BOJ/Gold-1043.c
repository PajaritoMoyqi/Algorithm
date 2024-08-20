#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSON 50

int Parent[MAX_PERSON+1];
int Party[MAX_PERSON+1][MAX_PERSON+1];

int FindParent( int idx );
void Union( int x, int y );

int main( void )
{
    int num, partyNum;
    scanf( "%d%d", &num, &partyNum );

    int i;
    for ( i = 1; i <= num; i++ )
        Parent[i] = i;

    int knownPersonNum;
    scanf( "%d", &knownPersonNum );

    int person, parent = -1;
    for ( i = 0; i < knownPersonNum; i++ )
    {
        scanf( "%d", &person );
        if ( i == 0 )
        {
            parent = FindParent( person );
        }
        else
            Parent[person] = parent;
    }

    int j;
    for ( i = 1; i <= partyNum; i++ )
    {
        scanf( "%d", &Party[i][0] );

        for ( j = 1; j <= Party[i][0]; j++ )
        {
            scanf( "%d", &Party[i][j] );
        }
    }
    for ( i = 1; i <= partyNum; i++ )
    {
        for ( j = 2; j <= Party[i][0]; j++ )
        {
            Union( Party[i][1], Party[i][j] );
        }
    }

    int cnt = 0;
    parent = FindParent( parent );
    for ( i = 1; i <= partyNum; i++ )
    {
        for ( j = 1; j <= Party[i][0]; j++ )
        {
            if ( FindParent( Party[i][j] ) == parent )
                break;

            if ( j == Party[i][0] )
                cnt++;
        }
    }

    printf( "%d", cnt );

    // for ( i = 1; i <= num; i++ )
    //     printf( "%d ", Parent[i] );

    return 0;
}

int FindParent( int idx )
{
    if ( Parent[idx] == idx ) return idx;
    else return Parent[idx] = FindParent( Parent[idx] );
}
void Union( int x, int y )
{
    int xParent = FindParent(x);
    int yParent = FindParent(y);

    if ( xParent != yParent )
    {
        if ( xParent < yParent )
            Parent[yParent] = xParent;
        else
            Parent[xParent] = yParent;
    }
}