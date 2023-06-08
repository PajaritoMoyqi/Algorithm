#include <stdio.h>
#include <stdlib.h>

int cmp (void* first, void* second);
int cmpNeg (void* first, void* second);

int main( void )
{
    int length;
    int i = 0;
    scanf( "%d", &length );

    int arr1[length], arr2[length];

    int result = 0;

    for ( i = 0; i < length*2; i++ )
    {
        if ( i < length )
            scanf( "%d", &arr1[i] );
        else
            scanf( "%d", &arr2[i%length] );
    }

    qsort( arr1, length, sizeof( int ), cmp );
    qsort( arr2, length, sizeof( int ), cmpNeg );

    for ( i = 0; i < length; i++ )
        result += arr1[i]*arr2[i];

    printf( "%d", result );

    // for ( i = 0; i < length*2; i++ )
    // {
    //     if ( i < length )
    //         printf( "%d\n", arr1[i] );
    //     else
    //         printf( "%d\n", arr2[i%length] );
    // }

    return 0;
}

int cmp (void* first, void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}
int cmpNeg (void* first, void* second)
{
    if (*(int*)first > *(int*)second)
        return -1;
    else if (*(int*)first < *(int*)second)
        return 1;
    else 
        return 0;
}