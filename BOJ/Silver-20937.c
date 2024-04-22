#include <stdio.h>
#define MAX_SIZE 50000

int Size[MAX_SIZE+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        int idx;
        scanf( "%d", &idx );
        Size[idx]++;
    }

    int max = 0;
    for ( i = 1; i <= MAX_SIZE; i++ )
        max = max > Size[i] ? max : Size[i];

    printf( "%d", max );

    return 0;
}