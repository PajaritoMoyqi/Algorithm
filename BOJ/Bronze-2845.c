#include <stdio.h>

int main( void )
{
    int n, num;
    scanf( "%d%d", &n, &num );
    int pNum = n * num;

    int i;
    for ( i = 0; i < 5; i++ )
    {
        int estimate;
        scanf( "%d", &estimate );
        printf( "%d ", estimate - pNum );
    }

    return 0;
}