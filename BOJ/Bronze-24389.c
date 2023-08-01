#include <stdio.h>

int main( void )
{
    long long givenNumber;
    scanf( "%d", &givenNumber );
    long long difNumber = -givenNumber;

    int loopCnt, cnt = 0;
    for ( loopCnt = 0; loopCnt < 32; loopCnt++ )
    {
        if ( (givenNumber & 1) != (difNumber & 1) ) cnt++;

        givenNumber >>= 1;
        difNumber >>= 1;
    }

    printf( "%d", cnt );
}