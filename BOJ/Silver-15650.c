#include <stdio.h>

int max, len;
char visited[1000];
char ans[1000];

int main( void )
{
    scanf( "%d%d", &max, &len );
    DFS( max, len, 0, 0 );

    return 0;
}

void DFS( int maxNum, int maxLen, int depth, int lastNum )
{
    if ( depth == maxLen )
    {
        int i;
        for ( i = 0; i < depth; i++ )
            printf( "%d ", ans[i] );
        puts( "" );
    }
    else
    {
        int i;
        for ( i = 0; i < maxNum; i++ )
        {
            if ( !visited[i] && lastNum < i + 1 )
            {
                visited[i] = 1;
                ans[depth] = i + 1;

                DFS( maxNum, maxLen, depth + 1, i + 1 );

                visited[i] = 0;
            }
        }
    }
}