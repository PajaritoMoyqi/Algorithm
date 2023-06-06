#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int bookNum = 0, capacity = 0;
    int bookPosition[50];
    int positiveArr[50], negativeArr[50];
    int negIdx = 0, posIdx = 0;
    int answer = 0;
    
    scanf( "%d", &bookNum );

    scanf( "%d", &capacity );


    for ( int i = 0; i < bookNum; i++ )
        scanf( "%d", &bookPosition[i] );

    for ( int i = 0; i < bookNum; i++ )
    {
        if ( bookPosition[i] < 0 )
            negativeArr[negIdx++] = abs(bookPosition[i]);
        else
            positiveArr[posIdx++] = bookPosition[i];

        bookPosition[i] = abs(bookPosition[i]);

        // printf( "%d ", bookPosition[i] );
    }

    qsort( negativeArr, negIdx, sizeof( int ), cmp );
    qsort( positiveArr, posIdx, sizeof( int ), cmp );

    // for ( int i = 0; i < posIdx; i++ )
    // {
    //     printf( "\npositive Array\n" );
    //     printf( "%d ", positiveArr[i] );
    // }

    // for ( int i = 0; i < negIdx; i++ )
    // {
    //     printf( "\nnegative Array\n" );
    //     printf( "%d ", negativeArr[i] );
    // }


    while ( negIdx > 0 )
    {
        // printf( "\n" );
        int loopCapacity = capacity;

        int temp[loopCapacity];
        int diffSign = 0;
        
        for ( int i = 0; i < loopCapacity; i++ )
        {
            if ( negIdx < 0 ) break;

            if (negativeArr[negIdx-1] == 0)
            {
                loopCapacity--;
                continue;
            }

            temp[i] = negativeArr[negIdx-1];
            negIdx--;
            // printf( "temp[i]: %d, i: %d\n", temp[i], i );
        }

        answer += temp[0]*2;
    }

    while ( posIdx > 0 )
    {
        // printf( "\n" );
        int loopCapacity = capacity;

        int temp[loopCapacity];
        int diffSign = 0;
        
        for ( int i = 0; i < loopCapacity; i++ )
        {
            if ( posIdx < 0 ) break;

            if (positiveArr[posIdx-1] == 0)
            {
                loopCapacity--;
                continue;
            }

            temp[i] = positiveArr[posIdx-1];
            posIdx--;
            // printf( "temp[i]: %d, i: %d\n", temp[i], i );
        }

        answer += temp[0]*2;
    }

    qsort( bookPosition, bookNum, sizeof( int ), cmp );

    answer -= bookPosition[bookNum-1];

    printf( "%d", answer );

    return 0;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}