#include <stdio.h>
#include <string.h>

char Record[2500];
int num[5];

int main( void )
{
    scanf( "%s", Record );
    int length = strlen( Record );

    int i, flag = 0, max = 0;
    for ( i = 0; i < length; i++ )
    {
        char s = Record[i];

        int idx = -1;
        if ( s == 'q' ) idx = 0;
        else if ( s == 'u' ) idx = 1;
        else if ( s == 'a' ) idx = 2;
        else if ( s == 'c' ) idx = 3;
        else if ( s == 'k' ) idx = 4;
        else
        {
            flag = 1;
            break;
        }

        if ( !idx || num[idx-1] > num[idx] )
        {
            if ( idx != 4 )
            {
                num[idx]++;
                if ( !idx )
                    max = max < num[idx] ? num[idx] : max;
            }
            else
            {
                int j;
                for ( j = 0; j < idx; j++ )
                    num[j]--;
            }
        }
        else
        {
            flag = 1;
            break;
        }

        int k;
        for ( k = 0; k < 5; k++ )
            printf( "%d ", num[k] );
        puts( " " );
    }

    if ( flag || ( num[0] || num[1] || num[2] || num[3] || num[4] ) )
        printf( "%d", -1 );
    else
        printf( "%d", max );

    return 0;
}