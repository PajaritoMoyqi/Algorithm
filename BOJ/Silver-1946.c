#include <stdio.h>
#include <stdlib.h> // qsort

int cmpX( const void* _elem1, const void* _elem2 );
int cmpY( const void* _elem1, const void* _elem2 );

typedef struct Score {
    int x;
    int y;
} Score;

int GetScoreNum( Score Set[], int idx, int num );

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    while ( n-- )
    {
        int m;
        scanf( "%d", &m );
        Score* ScoreSet = (Score*)malloc( sizeof( Score ) * m );

        for ( i = 0; i < m; i++ )
            scanf( "%d%d", &ScoreSet[i].x, &ScoreSet[i].y );
        
        int ans = 0;
        qsort( ScoreSet, m, sizeof( ScoreSet[0] ), cmpX );
        ans++;
        int idx = ScoreSet[0].y - 1;

        if ( m != 1 )
        {
            qsort( ScoreSet, m, sizeof( ScoreSet[0] ), cmpY );
            int tmp = ScoreSet[0].x;

            if ( tmp != 1 )
            ans++;
            {
                for ( i = 1; i < idx; i++ )
                {
                    if ( tmp > ScoreSet[i].x )
                    {
                        if ( ScoreSet[i].x != 1 )
                            ans++;

                        tmp = ScoreSet[i].x;
                    }

                    if ( tmp == 1 ) break;
                }
            }
        }

        printf( "%d\n", ans );
    }

    return 0;
}

int cmpX( const void* _elem1, const void* _elem2 )
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;

    if ( elem1->x > elem2->x )
        return 1;
    else if ( elem1->x < elem2->x )
        return -1;
    else
        return 0;
}
int cmpY( const void* _elem1, const void* _elem2 )
{
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;

    if ( elem1->y > elem2->y )
        return 1;
    else if ( elem1->y < elem2->y )
        return -1;
    else
        return 0;
}

int GetScoreNum( Score Set[], int idx, int num )
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