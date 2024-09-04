#include <stdio.h>
#include <math.h>

#ifndef MIN_NUM
#define MIN_NUM -1000000000
#endif

int BinarySearch( int Set[], int length, int target );
int MinPositiveNum( int a, int b, int c );

int main( void )
{
    int N;
    scanf( "%d", &N );

    int nums[N];
    int i;
    for ( i = 0; i < N; i++ )
        scanf( "%d", &nums[i] );

    int ans[N];
    for ( i = 0; i < N; i++ )
        ans[i] = MIN_NUM - 1;
    
    int idx = 0;
    ans[0] = nums[0];
    for ( i = 1; i < N; i++ )
    {
        if ( nums[i] > ans[idx] )
            ans[++idx] = nums[i];
        else if ( nums[i] < ans[idx] )
        {
            int targetIdx = BinarySearch( ans, idx+1, nums[i] );
            ans[targetIdx] = nums[i];
        }
    }

    printf( "%d\n", idx+1 );

    return 0;
}

int BinarySearch( int Set[], int length, int target )
{
    int left, right, middle;
    left = 0;
    right = length -1;

    int diffM, diffR, diffL;
    while ( left <= right )
    {
        middle = (left + right) / 2;

        diffL = Set[middle-1] - target;
        diffM = Set[middle] - target;
        diffR = Set[middle+1] - target;
        int min = MinPositiveNum( diffL, diffM, diffR );
        if ( min == diffR || min == -1 )
            left = middle + 1;
        else if ( min == diffL )
            right = middle - 1;
        else if ( min == diffM )
            return middle;
    }
}
int MinPositiveNum( int a, int b, int c )
{
    if ( a < 0 && b < 0 && c < 0 )
        return -1;
    else if ( a >= 0 && b < 0 && c < 0 )
        return a;
    else if ( a < 0 && b >= 0 && c < 0 )
        return b;
    else if ( a < 0 && b < 0 && c >= 0 )
        return c;
    else if ( a >= 0 && b < 0 && c >= 0 )
    {
        int min = a > c ? c : a;
        return min;
    }
    else if ( a >= 0 && b >= 0 && c < 0 )
    {
        int min = a > b ? b : a;
        return min;
    }
    else if ( a < 0 && b >= 0 && c >= 0 )
    {
        int min = b > c ? c : b;
        return min;
    }
    else if ( a >= 0 && b >= 0 && c >= 0 )
    {
        int min = b > c ? c : b;
        min = a > min ? min : a;
        return min;
    }
}