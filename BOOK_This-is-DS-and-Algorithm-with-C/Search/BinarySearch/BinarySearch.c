#include <stdlib.h>
#include <stdio.h>
#include "Point.h"

Point* BinarySearch( Point PointList[], int Size, double Target );
int ComparePoint( const void* _elem1, const void* _elem2 );

int main( void )
{
    int Length = sizeof DataSet / sizeof DataSet[0];
    Point* found = NULL;

    qsort( (void*)DataSet, Length, sizeof( Point ), ComparePoint );

    found = BinarySearch( DataSet, Length, 671.78 );

    printf( "found... ID: %d, Point: %f \n", found->id, found->point );

    return 0;
}

Point* BinarySearch( Point PointList[], int Size, double Target )
{
    int Left, Right, Mid;

    Left = 0;
    Right = Size - 1;

    while ( Left <= Right )
    {
        Mid = ( Left + Right ) / 2;

        if ( Target == PointList[Mid].point )
            return &( PointList[Mid] );
        else if ( Target > PointList[Mid].point )
            Left = Mid + 1;
        else
            Right = Mid - 1;
    }

    return NULL;
}

int ComparePoint( const void* _elem1, const void* _elem2 )
{
    Point* elem1 = (Point*)_elem1;
    Point* elem2 = (Point*)_elem2;

    if ( elem1->point > elem2->point )
        return 1;
    else if ( elem1->point < elem2->point )
        return -1;
    else
        return 0;
}