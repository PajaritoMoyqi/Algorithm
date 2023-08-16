#include <stdio.h>
 
int div( int num, int cycle, int c );

int main( void )
{
    int a, b, c;
    scanf( "%d%d%d", &a, &b, &c );

    printf("%d\n", div( a % c, b, c ));

    return 0;
}

int div( int num, int cycle, int c )
{
    if ( cycle > 1 )
    {
        long long result = div( num, cycle / 2, c );
        if ( cycle & 1 ) return ((result * result) % c * num) % c;
        else return (result * result) % c;
    }
    else
        return num;
}