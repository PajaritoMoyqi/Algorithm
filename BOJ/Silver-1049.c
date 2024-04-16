#include <stdio.h>

int main( void )
{
    int need, n;
    scanf( "%d%d", &need, &n );

    int minPack = 1001, minSingle = 1001;
    while ( n-- )
    {
        int candidatePack, candidateSingle;
        scanf( "%d%d", &candidatePack, &candidateSingle );

        if ( minPack > candidatePack )
            minPack = candidatePack;
        if ( minSingle > candidateSingle )
            minSingle = candidateSingle;
    }

    if ( minPack >= minSingle*6 )
        printf( "%d", minSingle * need );
    else
    {
        int ans = 0;
        while ( need )
        {
            if ( need < 6 )
            {
                if ( minPack >= minSingle*need )
                    ans += (minSingle*need);
                else
                    ans += minPack;

                need -= need;
            }
            else
            {
                ans += minPack;
                need -= 6;
            }
        }

        printf( "%d", ans );
    }

    return 0;
}