#include <stdio.h>

long long int returnCnt( long long int initialVal );

int main()
{
    long long value1, value2;

    scanf( "%lld %lld", &value1, &value2 );

    printf( "%lld", returnCnt( value2 ) - returnCnt( value1 - 1 ) );
}

long long int returnCnt( long long int initialVal )
{
    long long int cnt = 0, num = initialVal, binaryDigit = 1;

    while( num ) // when there is number at 2^x digit
    {
        // printf( "number: %d, binaryDigit: %d\n", num, binaryDigit );

        // We should use "initialVal + 1", not just "initialVal",
        // because every 2^x digit number repeat its pattern with length 2^(x+1)
        // when we think 0 is a start number.
        // for example, 2^3 digit number repeat its pattern with length 16(2^4) from 0 to 15, not 1 to 16.

        // full pattern 2^x digit
        cnt += ( initialVal + 1 ) / ( binaryDigit << 1 ) * binaryDigit;

        // if it's not divided without remainder,
        // we should check 2^x digit number is 0 or 1
        if ( num & 1 ) // if 2^x digit number is 1, we need to count 1 "( initialVal + 1 ) % binaryDigit" times more
            cnt += ( initialVal + 1 ) % binaryDigit;

        num >>= 1;
        binaryDigit <<= 1;
    }

    return cnt;
}