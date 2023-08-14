#include <stdio.h>
#include <string.h>

int main( void )
{
    int testCase;
    int statesArr[9][2] = { {7, 1}, {2, 8}, {3, 8}, {3, 4}, {7, 5}, {6, 5}, {3, 0}, {8, 0}, {8, 8} };
    char givenBit[201];
    scanf( "%d", &testCase );

    int i, j, idx;
    for ( i = 0; i < testCase; i++ )
    {
        scanf( "%s", givenBit );

        idx = 0;

        for ( j = 0; j < strlen( givenBit ); j++ )
        {
            idx = statesArr[idx][givenBit[j] - '0'];
            // printf( "idx: %d, bit: %d\n", idx, givenBit[j] - '0' );
        }

        ((idx == 0) || (idx == 4) || (idx == 5)) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}