#include <stdio.h>
#include <stdlib.h>

int max, len;
char visited[10001];
int ans[1000];
char checkNums[10001];
int givenNums[1000];

void DFS( int maxNum, int maxLen, int depth, int lastNum );
int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    scanf( "%d%d", &max, &len );
    int i;
    for ( i = 0; i < max; i++ )
        scanf( "%d", &givenNums[i] );

    int cnt = 0;
    for ( i = 0; i < max; i++ )
    {
        if ( checkNums[givenNums[i]] )
        {
            givenNums[i] = 0;
            cnt--;
        }
        else checkNums[givenNums[i]] = 1;
    }
    max += cnt;

    qsort( givenNums, sizeof( givenNums ) / sizeof( givenNums[0] ), sizeof( givenNums[0] ), cmp );

    DFS( max, len, 0, 0 );

    return 0;
}

void DFS( int maxNum, int maxLen, int depth, int lastNum )
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
                ans[depth] = givenNums[i];
                DFS( maxNum, maxLen, depth + 1, givenNums[i] );
        }
    }
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 == 0 ) return 1;
    else if ( *elem2 == 0 ) return 0;
    else if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}