#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000

void Swap( int* a, int* b );
int PartitionStep( int Set[], int left, int right, int len );
void QuickSort( int Set[], int left, int right, int len );
void IsEqual( int len );

int Arr[MAX_LEN];
int Cmp_Arr[MAX_LEN];

int flag = 0;

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Arr[i] );
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Cmp_Arr[i] );

    IsEqual( n );

    QuickSort( Arr, 0, n-1, n );

    printf( "%d", flag );

    return 0;
}

void Swap( int* a, int* b )
{
    if ( *a == *b )
        return;

    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int PartitionStep( int Set[], int left, int right, int len )
{
    int first = right;
    int pivot = Set[first];

    left--;

    for ( right = left+1; right < first; right++ )
    {
        if ( Arr[right] <= pivot )
        {
            Swap( &Set[++left], &Set[right] );
            if ( left != right
                && Arr[left] == Cmp_Arr[left]
                && Arr[right] == Cmp_Arr[right] )
            {
                IsEqual( len );
            }
        }
    }

    if ( ++left != first )
    {
        Swap( &Set[left], &Set[first] );
        if ( left != right
            && Arr[left] == Cmp_Arr[left]
            && Arr[first] == Cmp_Arr[first] )
        {
            IsEqual( len );
        }
    }

    return left;
}

void QuickSort( int Set[], int left, int right, int len )
{
    if ( left < right )
    {
        int idx = PartitionStep( Set, left, right, len );
        if ( !~idx )
            return;

        QuickSort( Set, left, idx - 1, len );
        QuickSort( Set, idx + 1, right, len );
    }
}
void IsEqual( int len )
{
    int i;
    for ( i = 0; i < len; i++ )
    {
        if ( Arr[i] != Cmp_Arr[i] )
            return;
    }

    printf( "1" );
    exit( 0 );
}