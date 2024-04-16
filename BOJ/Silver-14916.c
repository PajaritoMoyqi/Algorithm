#include <stdio.h>

int main( void )
{
    int n, cnt = 0;
    scanf( "%d", &n );

    if ( n == 1 || n == 3 )
    {
        cnt = -1;
        goto end;
    }

    char flag = 0;
    while ( n )
    {
        if ( n >= 5 && !flag )
        {
            n -= 5;
            cnt++;
            if ( n < 5 && n & 1 )
            {
                flag = 1;
                n += 5;
                cnt--;
            }
        }
        else if ( n >= 2 )
        {
            n -= 2;
            cnt++;
        }
    }

end:
    printf( "%d", cnt );

    return 0;
}