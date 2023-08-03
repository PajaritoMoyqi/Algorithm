#include <stdio.h>
int a;
int arr[(1<<20) + 1];

int main( void )
{
    int rest, idx;
    while ( scanf( "%d", &a ) != EOF )
    {
        idx = a / 32;
        rest = 1 << ( a % 32 );

        if ( !(arr[idx] & rest) )
        {
            arr[idx] += rest;
            printf( "%d ", a );  
        }
    }

    return 0;
}