#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 10000

int Arr[MAX_LEN];
int Cmp_Arr[MAX_LEN];

int InsertionSort( int Set[], int length );
int CompareArray( int Set[], int Set2[], int length );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Arr[i] );

    for ( i = 0; i < n; i++ )
        scanf( "%d", &Cmp_Arr[i] );

    if ( CompareArray( Arr, Cmp_Arr, n ) )
    {
        printf( "%d", 1 );
        return 0;
    }

    int ans = InsertionSort( Arr, n );

    printf( "%d", ans );

    return 0;
}

int InsertionSort( int Set[], int length )
{
    int i, j, k, val;

    for ( i = 1; i < length; i++ )
    {
        if ( Set[i-1] <= Set[i] )
            continue;

        val = Set[i];

        for ( j = 0; j < i; j++ )
        {
            if ( Set[j] > val )
            {
                for ( k = i; k > j; k-- )
                {
                    Set[k] = Set[k-1];
                    if ( CompareArray( Arr, Cmp_Arr, length ) )
                    {
                        // int l;
                        // for ( l = 0; l < length; l++ )
                        //     printf( "%d ", Set[l] );
                        // puts( "" );
                        return 1;
                    }
                }
                Set[j] = val;
                if ( CompareArray( Arr, Cmp_Arr, length ) )
                {
                    // int l;
                    // for ( l = 0; l < length; l++ )
                    //     printf( "%d ", Set[l] );
                    // puts( "" );
                    return 1;
                }
                break;
            }
        }
    }

    return 0;
}
int CompareArray( int Set[], int Set2[], int length )
{
    int i, flag = 1;

    for ( i = 1; i < length; i++ )
    {
        if ( Set[i] != Set2[i] )
        {
            flag = 0;
            break;
        }
    }

    return flag;
}