#include <stdio.h>

#define NUM 5
#define MAX 4

int Sum[NUM+1];

int main( void )
{
    int num, ansIdx, max = 0;
    int i, j;
    for ( i = 1; i <= NUM; i++ )
    {
        for ( j = 0; j < MAX; j++ )
        {
            scanf( "%d", &num );
            Sum[i] += num;
        }

        if ( max < Sum[i] )
        {
            ansIdx = i;
            max = Sum[i];
        }
    }

    printf( "%d %d", ansIdx, max );

    return 0;
}