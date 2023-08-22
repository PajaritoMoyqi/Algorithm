#include <stdio.h>

int size, t;
int nums[1024][1024];

int main( void )
{
    scanf( "%d%d", &size, &t );

    int i, j, tmp;
    for ( i = 0; i < size; i++ )
    {
        for ( j = 0; j < size; j++ )
        {
            scanf( "%d", &tmp );
            if ( !j ) nums[i][j] = tmp;
            else nums[i][j] = nums[i][j-1] + tmp;
        }
    }

    // for ( i = 0; i < size; i++ )
    // {
    //     for ( j = 0; j < size; j++ )
    //         printf( "%d ", nums[i][j] );
    //     puts( "" );
    // }

    int startRow, startCol, endRow, endCol, sum;
    while ( t-- )
    {
        sum = 0;

        scanf( "%d%d%d%d", &startRow, &startCol, &endRow, &endCol );
        startRow -= 1;
        startCol -= 1;
        endRow -= 1;
        endCol -= 1;

        for ( i = startRow; i <= endRow; i++ )
        {
            if ( !startCol ) sum += nums[i][endCol];
            else sum += nums[i][endCol] - nums[i][startCol-1];
        }

        printf( "%d\n", sum );
    }
    
    return 0;
}