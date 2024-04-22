#include <stdio.h>
#define LEN 6

int main( void )
{
    int n;
    scanf( "%d", &n );
    int changes = 1000 - n;

    int category[LEN] = { 500, 100, 50, 10, 5, 1 };

    int i, cnt = 0;
    for ( i = 0; i < LEN; i++ )
    {
        int bill = category[i];
        while ( changes >= bill )
        {
            changes -= bill;
            cnt++;
        }
    }

    printf( "%d", cnt );

    return 0;
}