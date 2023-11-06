#include <stdio.h>

int arr[6+1];
char visited[4+1];
int idx[6+1];

int main( void )
{
    int n, k, len;
    scanf( "%d", &n );

    int removedArea = 0, area = 0;
    int i;
    for ( i = 1; i <= 6; i++ )
    {
        scanf( "%d%d", &idx[i], &arr[i] );
        if ( visited[idx[i]] ) visited[idx[i]] = 0;
        else visited[idx[i]] = 1;
    }

    for ( i = 1; i <= 6; i++ )
    {
        // printf( "%d-th(visited: %d): %d\n", i, visited[idx[i]], arr[i] );
        if ( visited[idx[i]] )
        {
            if ( i != 1 && visited[idx[i-1]] == 0 )
            {
                arr[i-1] = 0;
            }
            else if ( i == 1 && visited[idx[6]] == 0 )
            {
                arr[6] = 0;
            }

            if ( i != 6 && visited[idx[i+1]] == 0 )
            {
                arr[i+1] = 0;
            }
            else if ( i == 6 && visited[idx[1]] == 0 )
            {
                arr[1] = 0;
            }
        }
    }

    for ( i = 1; i <= 6; i++ )
    {
        // printf( "%d-th(visited: %d): %d\n", i, visited[idx[i]], arr[i] );
        if ( visited[idx[i]] )
        {
            if ( !area ) area += arr[i];
            else area *= arr[i];
        }
        else
        {
            if ( !arr[i] ) continue;

            if ( !removedArea ) removedArea += arr[i];
            else removedArea *= arr[i];
        }
    }

    printf( "%d", n * (area - removedArea) );

    return 0;
}