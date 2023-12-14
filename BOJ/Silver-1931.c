#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

typedef struct Meeting {
	int x;
	int y;
} Meeting;

int GetMeetingNum( Meeting Set[], int idx, int num );

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    Meeting* TimeSet = (Meeting*)malloc( sizeof( Meeting ) * n );;

    for ( i = 0; i < n; i++ )
        scanf( "%d%d", &TimeSet[i].x, &TimeSet[i].y );

    qsort( TimeSet, n, sizeof( TimeSet[0] ), cmp );

    int j = 0, ans = 0, tmp;
    ans = GetMeetingNum( TimeSet, 1, n );

    // for ( i = 0; i < n; i++ )
    //     printf( "%d %d\n", TimeSet[i].x, TimeSet[i].y );

    printf( "%d", ans );

    return 0;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    Meeting* elem1 = (Meeting*)_elem1;
    Meeting* elem2 = (Meeting*)_elem2;

    if ( elem1->y == elem2->y )
    {
        if ( elem1->x > elem2->x )
            return 1;
        else if ( elem1->x < elem2->x )
            return -1;
        else
            return 0;
    }
    else
    {
        if ( elem1->y > elem2->y )
            return 1;
        else if ( elem1->y < elem2->y )
            return -1;
        else
            return 0;
    }
}

int GetMeetingNum( Meeting Set[], int idx, int num )
{
    int i, j = 0, cnt = 1;
    for ( i = idx; i < num; i++ )
    {
        if ( Set[j].y <= Set[i].x )
        {
            cnt++;
            j = i;
        }
    }
    return cnt;
}