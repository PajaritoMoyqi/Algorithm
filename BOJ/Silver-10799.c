#include <stdio.h>

int main( void )
{
    char c, prev;
    int cnt = 0, num = 0;

    while ( (c = getchar()) != '\n' )
    {
        if ( c == '(' )
        {
            num++;
        }
        else if ( c == ')' )
        {
            if ( prev == '(' )
            {
                num--;
                cnt += num;
            }
            else
            {
                num--;
                cnt += 1;
            }
        }

        prev = c;
        // printf( "num: %d, cnt: %d\n", num, cnt );
    }

    printf( "%d", cnt );

    return 0;
}