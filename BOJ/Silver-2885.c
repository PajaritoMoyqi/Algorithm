#include <stdio.h>

int popCount( unsigned int n );
int getLSB( int x );
unsigned int getMSB( unsigned int n );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int num = 1;
    while ( num < n )
        num *= 2;

    int ans = 0;
    if ( num != n )
    {
        ans++;

        int lsb = getLSB( n );
        int msb = getMSB( n );
        while ( lsb < msb )
        {
            msb /= 2;
            ans++;
        }
    }

    printf( "%d %d", num, ans );

    return 0;
}

int getLSB( int x )
{
    return x & (-x);
}
unsigned int getMSB( unsigned int n )
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n = n + 1;

    return (n >> 1);
}

int popCount( unsigned int n )
{
	n = (n >>  1 & 0x55555555) + (n & 0x55555555);
	n = (n >>  2 & 0x33333333) + (n & 0x33333333);
	n = (n >>  4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >>  8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
	return n;
}