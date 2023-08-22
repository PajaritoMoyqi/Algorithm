#include <stdio.h>

long long start, dest;
long long check( long long val, long long i, long long cnt );

int main( void )
{
    scanf( "%lld%lld", &start, &dest );

    long long res = check( start, dest, 1 );

    printf( "%d", res );
}

long long check( long long val, long long i, long long cnt )
{
    if ( i == val ) return cnt;
    if ( i < val ) return -1;

    if ( !(i & 1) )
    {
        return check( val, i / 2, cnt + 1 );
    }
    else if ( i % 10 == 1 )
    {
        return check( val, i / 10, cnt + 1 );
    }
    else return -1;
}