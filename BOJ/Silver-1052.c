#include <stdio.h>
#include <math.h>

int main( void )
{
    int givenNumber, testNum, testNum2, cnt;
    scanf( "%d%d", &givenNumber, &cnt );
    testNum = testNum2 = givenNumber;

    int totalBit = 0;
    int length = 0;
    while ( testNum )
    {
        if ( testNum % 2 ) totalBit++;

        length++;
        testNum >>= 1;
    }
    // printf( "givenNumber: %d, length: %d\n", givenNumber, length );

    char bits[length];
    int i;
    for ( i = 0; i < length; i++ )
    {
        bits[i] = testNum2 % 2;

        testNum2 >>= 1;
    }

    if ( totalBit <= cnt )
    {
        printf( "%d", 0 );
        goto end;
    }

    int bitCnt = 0;
    int sum = 0;
    for ( i = length - 1; i >= 0; i-- )
    {
        if ( bits[i] == 1 )
        {
            bitCnt++;
            sum += pow( 2, i );
        }
        // printf( "bit[%d]: %d, sum: %d, pow: %d\n", i, bits[i], sum, (int)pow( 2, i ) );

        if ( bitCnt == cnt )
        {
            printf( "%d", sum + (int)pow( 2, i ) - givenNumber );
            break;
        }
    }

    end:
        return 0;
}