#include <stdio.h>

# ifndef max
# define max(a,b)  (((a) > (b)) ? (a) : (b))
# endif

int nums[501][501];

int main( void )
{
	int t;
	scanf( "%d", &t );

	int i, j;
	for ( i = 0; i < t; i++ )
		for ( j = 0; j < i+1; j++ )
			scanf( "%d", &nums[i][j] );
	
	for ( i = t-1; i > 0; i-- )
		for ( j = 0; j < i; j++ )
			nums[i-1][j] += max( nums[i][j], nums[i][j+1] );
	
	printf( "%d", nums[0][0] );
	
	return 0;
}