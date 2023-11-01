#include <stdio.h>

int getResult( int sausage, int person );

int main( void )
{
	int n, m;
	scanf( "%d%d", &n, &m );
    n %= m;
	printf( "%d", getResult( n, m ) );

	return 0;
}

int getResult( int sausage, int person )
{
	if ( sausage == 0 ) return 0;
    else
    	return person - getGCD( sausage, person );
}
int getGCD( int a, int b )
{
    int big = (a >= b) ? a : b;
    int small = (a >= b) ? b : a; 
    int mod = big % small;

    if ( mod == 0 )
        return small;
    else
        return getGCD( small, mod );
}