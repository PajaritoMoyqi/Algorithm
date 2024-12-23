#include <stdio.h>
#include <math.h>

#define MAX 1000

char isPrime[MAX+1];
char isVisited[MAX+1];

int main( void )
{
    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int k = 2; k <= MAX; k++)
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            isPrime[i*mult] = 0;
    }

    int tMin, tMax, jMin, jMax;
    scanf( "%d%d%d%d", &tMin, &tMax, &jMin, &jMax );

    int ytCnt = 0, yjCnt = 0, commonCnt = 0;
    for ( i = tMin; i <= tMax; i++ )
    {
        if ( isPrime[i] )
        {
            ytCnt++;
            isVisited[i] = 1;
        }
    }
    for ( i = jMin; i <= jMax; i++ )
    {
        if ( isPrime[i] )
        {
            if ( isVisited[i] )
            {
                ytCnt--;
                commonCnt++;
            }
            else
                yjCnt++;
        }
    }

    if ( commonCnt & 1 )
        ytCnt++;

    if ( ytCnt > yjCnt ) printf( "yt" );
    else printf( "yj" );

    return 0;
}