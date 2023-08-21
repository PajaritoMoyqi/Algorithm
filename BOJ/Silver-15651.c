#include <stdio.h>

int max, len;
char visited[1000];
char ans[1000];

int main( void )
{
    scanf( "%d%d", &max, &len );
    DFS( max, len, 0 );

    return 0;
}

void DFS( int maxNum, int maxLen, int depth )
{
    int i;
    
    if ( depth == maxLen )
    {
        for ( i = 0; i < maxLen; i++ )
            printf( "%d ", ans[i] );
        puts( "" );
    }
    else
    {
        for ( i = 0; i < maxNum; i++ )
        {
            ans[depth] = i + 1;
            DFS( maxNum, maxLen, depth + 1 );
        }
    }
}