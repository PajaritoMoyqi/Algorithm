#include <stdio.h>
#define LEN 4

int main( void )
{
    int n;
    scanf( "%d", &n );

    int category[LEN] = { 25, 10, 5, 1 };

    int i;
    for ( i = 0; i < n; i++ )
    {
        int changes;
        scanf( "%d", &changes );

        int j;
        for ( j = 0; j < LEN; j++ )
        {
            int cnt = 0;

            int bill = category[j];
            while ( changes >= bill )
            {
                changes -= bill;
                cnt++;
            }

            printf( "%d ", cnt );
        }

        puts( "" );
    }

    return 0;
}