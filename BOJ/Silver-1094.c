#include <stdio.h>

int main( void )
{
    int givenNumber, cnt = 0;
    scanf( "%d", &givenNumber );

    while ( givenNumber > 0 )
    {
        if ( givenNumber % 2 )
            cnt++;
        
        givenNumber >>= 1;
    }

    printf( "%d", cnt );

    return 0;
}