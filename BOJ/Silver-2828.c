#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int length, posRight, num, posLeft = 1;
    scanf( "%d%d%d", &length, &posRight, &num );

    int next, i, ans = 0;
    for ( i = 0; i < num; i++ )
    {
        scanf( "%d", &next );

        if ( next >= posLeft && next <= posRight )
        {
            // printf( "%d-th ans: %d, posL: %d, posR: %d\n", i+1, ans, posLeft, posRight );
            continue;
        }
        else
        {
            int leftDist = abs( next - posLeft );
            int rightDist = abs( next - posRight );

            if ( leftDist < rightDist )
            {
                ans += leftDist;
                posLeft -= leftDist;
                posRight -= leftDist;
            }
            else if ( leftDist > rightDist )
            {
                ans += rightDist;
                posLeft += rightDist;
                posRight += rightDist;
            }
            else
            {
                if ( next > posRight )
                {
                    ans += rightDist;
                    posLeft += rightDist;
                    posRight += rightDist;
                }
                else
                {
                    ans += leftDist;
                    posLeft -= leftDist;
                    posRight -= leftDist;
                }
            }
        }
        // printf( "%d-th ans: %d, posL: %d, posR: %d\n", i+1, ans, posLeft, posRight );
    }

    printf( "%d", ans );

    return 0;
}