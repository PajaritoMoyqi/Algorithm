#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char K[100];

int main( void )
{
    int n;
    scanf( "%d", &n );
    scanf( "%s", K );
    int len = strlen( K );

    int i, cntW = 0, cntM = 0, diff;
    for ( i = 0; i < len; i++ )
    {
        if ( K[i] == 'W' )
            cntW++;
        else
            cntM++;

        diff = abs( cntW - cntM );
        if ( diff > n )
        {
            if ( K[i+1] )
            {
                if ( K[i] != K[i+1] )
                {
                    if ( K[i+1] == 'W' )
                        cntW++;
                    else
                        cntM++;
                    
                    i++;
                }
                else
                    break;
            }
            else
                break;
        }
    }

    printf( "%d", i );

    return 0;
}