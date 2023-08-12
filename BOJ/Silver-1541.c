#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 50

int main( void )
{
    char str[MAXLEN + 1] = { 0 };
    scanf( "%s", str );
    int len = strlen( str );

    int idx = 0, sign = 1, num = 0, sum = 0;
    while ( idx != len )
    {
        if ( str[idx] == '+' )
        {
            if ( sign == -1 )
                sum -= num;
            else
                sum += num;

            num = 0;
        }
        else if ( str[idx] == '-' )
        {
            if ( sign == -1 )
                sum -= num;
            else
                sum += num;

            if ( sign == 1 )
                sign = -sign;

            num = 0;
        }
        else
        {
            if ( !num )
                num = (int)(str[idx] - '0');
            else
                num = num*10 + (int)(str[idx] - '0');
        }

        if ( idx == len - 1 )
        {
            if ( sign == -1 )
                sum -= num;
            else
                sum += num;
        }
        // printf( "%d-th string, str[idx]: %c, num: %d, sum: %d\n", idx, str[idx], num, sum );

        idx++;
    }

    printf( "%d", sum );

    return 0;
}