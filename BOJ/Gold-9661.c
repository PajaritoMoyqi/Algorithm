#include <stdio.h>

int main( void )
{
    long long v;
    scanf( "%lld", &v );

    char* s = ((v % 5 == 2) || (v % 5 == 0)) ? "CY" : "SK";
    printf( "%s", s );

    return 0;
}