#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 500000
#define MAX_NUM 4000

int Seq[MAX];
int Cnt[MAX_NUM+MAX_NUM+1];

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int max = -MAX_NUM; int min = MAX_NUM; int sum = 0;
    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &Seq[i] );
        Cnt[Seq[i]+MAX_NUM]++;

        if ( max < Seq[i] )
            max = Seq[i];
        if ( min > Seq[i] )
            min = Seq[i];

        sum += Seq[i];
    }

    int mostFreq = 0, MFidx = -MAX_NUM;
    for ( i = 0; i <= MAX_NUM+MAX_NUM; i++ )
    {
        if ( Cnt[i] > mostFreq )
        {
            mostFreq = Cnt[i];
            MFidx = i - MAX_NUM;
        }
    }
    int flag = 0;
    for ( i = 0; i <= MAX_NUM+MAX_NUM; i++ )
    {
        if ( Cnt[i] == mostFreq )
        {
            if ( !flag )
                flag = 1;
            else
            {
                MFidx = i - MAX_NUM;
                break;
            }
        }
    }

    qsort( Seq, n, sizeof( int ), cmp );
    int mid = Seq[n/2];

    double avg = (double)(sum) / n;
    int roundedAvg = (int)round( avg );

    printf( "%d\n%d\n%d\n%d", roundedAvg, mid, MFidx, max - min );

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