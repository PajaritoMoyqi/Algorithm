#include <stdio.h>

int main( void )
{
    long long ans = 1;
    long long givenNum;
    scanf( "%lld", &givenNum );

    while ( givenNum )
    {
        ans *= givenNum--;
    }

    printf( "%lld", ans );

    return 0;
}