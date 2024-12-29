#include <stdlib.h>

#define MAX 30000

int singleNumber( int* nums, int numsSize )
{
    char* Visited = (char*)calloc( MAX*2+1, sizeof( char ) );

    int i;
    for ( i = 0; i < numsSize; i++ )
    {
        int n = nums[i] + MAX;
        if ( Visited[n] )
        {
            Visited[n]--;
        }
        else
        {
            Visited[n]++;
        }
    }

    int ans;
    for ( i = 0; i <= MAX*2; i++ )
    {
        if ( Visited[i] )
        {
            ans = i - MAX;
            break;
        }
    }

    free( Visited );
    return ans;
}