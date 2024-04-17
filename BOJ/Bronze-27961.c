#include <stdio.h>

int main( void )
{
    long long n;
    scanf( "%lld", &n );

    long long cnt = 0;
    long long cmpNum = 1;
    while ( n )
    {
        if ( n <= cmpNum )
            break;
        
        cmpNum *= 2;
        if ( !cnt )
            cnt += 2;
        else
            cnt++;
    }

    if ( !cnt )
        printf( "%lld", n );
    else
        printf( "%lld", cnt );

    return 0;
}
