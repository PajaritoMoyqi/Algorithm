#include <stdio.h>

int main( void )
{
    int testCase;
    long long givenNumber, x, y;
    scanf( "%d", &testCase );

    long long i;
    for ( i = 0; i < testCase; i++ )
    {
        scanf( "%lld", &givenNumber );
        long long num = givenNumber;
        long long testNum = givenNumber;
        long long length = 0;
        while ( testNum )
        {
            length++;
            testNum >>= 1;
        }

        x = y = -1;
        char bits[length];
        long long cnt, idx, bitCnt;
        cnt = idx = bitCnt = 0;

        while ( num )
        {
            if ( num & 1 )
            {
                cnt++;
                bits[idx] = 1;
            }
            else
                bits[idx] = 0;

            num >>= 1;
            idx++;
        }
        // printf( "given number: %d\n", givenNumber );
        // int j;
        // for ( j = length - 1; j >= 0; j-- )
        //     printf( "bits[%d]: %d\n", j, bits[j] );
        // printf( "1-bit count: %d\n", cnt );
        // printf( "bit length: %d\n", length );

        if ( givenNumber == 1 )
        {
            printf( "%d %d", 0, 0 );
            goto end;
        }
        else if ( givenNumber == 2 )
        {
            printf( "%d %d", 0, 0 );
            goto end;
        }
        else if ( givenNumber == 3 )
        {
            printf( "%d %d", 0, 1 );
            goto end;
        }
        else if ( givenNumber == 4 )
        {
            printf( "%d %d", 1, 1 );
            goto end;
        }

        if ( cnt == 2 )
        {
            for ( long long i = 0; i < length; i++ )
            {
                if ( bits[i] == 1 )
                {
                    printf( "%d ", i );
                    bitCnt++;
                }

                if ( bitCnt == 2 ) break;
            }
        }
        else if ( cnt == 1 )
        {
            for ( long long i = 0; i < length; i++ )
            {
                if ( bits[i] == 1 )
                {
                    printf( "%d %d", i - 1, i - 1 );
                    break;
                }
            }
        }
        else // cnt >= 3
        {
            for ( long long i = length - 1; i >= 0; i-- )
            {
                if ( (bits[i] == 1) && (y == -1) && (bitCnt != 2) )
                {
                    y = i;
                    bitCnt++;
                }
                else if ( (bits[i] == 1) && (x == -1) && (bitCnt != 2) )
                {
                    x = i;
                    bitCnt++;
                }
                // printf( "COUNTING-BIT: %d\n", bitCnt );

                if ( (bitCnt == 2) && (i != 0) )
                {
                    if ( bits[i-1] == 0 )
                    {
                        printf( "%d %d", x, y );
                    }
                    else if ( (bits[i-1] == 1) && (cnt == 3) )
                    {
                        printf( "%d %d", x, y );
                    }
                    else // bits[i-1] == 1 && cnt > 3
                    {
                        if ( (y - x) == 1 )
                        {
                            printf( "%d %d", y, y );
                        }
                        else
                        {
                            printf( "%d %d", x + 1, y );
                        }
                    }

                    break;
                }
            }
        }

        end:
            printf( "\n" );
    }

    return 0;
}