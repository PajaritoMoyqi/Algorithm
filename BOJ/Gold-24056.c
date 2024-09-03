#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 500000

int Arr[MAX_LEN];
int Cmp_Arr[MAX_LEN];

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n;
    scanf( "%d", &n );
    int totalN = n;

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Arr[i] );

    for ( i = 0; i < n; i++ )
        scanf( "%d", &Cmp_Arr[i] );

    while ( n > 0 && Arr[n-1] == Cmp_Arr[n-1] )
        n--;

    int idx = 0;
    while ( idx + 1 < n && Cmp_Arr[idx] <= Cmp_Arr[idx+1] )
        idx++;

    if ( !memcmp( Arr, Cmp_Arr, sizeof( int ) * totalN ) )
    {
        printf( "%d", 1 );
        return 0;
    }

    qsort( Arr, idx, sizeof( int ), cmp );

    if ( !memcmp( Arr, Cmp_Arr, sizeof( int ) * totalN ) )
    {
        printf( "%d", 1 );
        return 0;
    }

    int target = -1;
    for ( i = 0; i < n-1; i++ )
    {
        if ( Cmp_Arr[i] == Cmp_Arr[i+1] )
        {
            target = i+1;
            break;
        }
    }

    if ( !~target )
    {
        qsort( Arr, idx+1, sizeof( int ), cmp );
        printf( "%d", !memcmp( Arr, Cmp_Arr, sizeof( int ) * totalN ) );
        return 0;
    }

    int tmp = Arr[idx];
    while ( 0 < idx && target <= idx && tmp < Arr[idx-1] )
    {
        Arr[idx] = Arr[idx-1];
        idx--;
    }

    printf( "%d", !memcmp( Arr, Cmp_Arr, sizeof( int ) * totalN ) );

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