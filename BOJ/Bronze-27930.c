#include <stdio.h>
#define MAX_LEN 500000

char str[MAX_LEN+1];

int main( void )
{
    scanf( "%s", str );

    char* Y = "YONSEI";
    char* K = "KOREA";

    int i, idxY = 0, idxK = 0;
    for ( i = 0; i < MAX_LEN; i++ )
    {
        // printf( "%c: %d, %d\n", str[i], idxY, idxK );
        if ( Y[idxY] == str[i] )
            idxY++;
        if ( K[idxK] == str[i] )
            idxK++;

        if ( idxY == 6 )
        {
            printf( "%s", Y );
            break;
        }
        if ( idxK == 5 )
        {
            printf( "%s", K );
            break;
        }
    }

    return 0;
}