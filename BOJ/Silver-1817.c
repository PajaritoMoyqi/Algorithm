#include <stdio.h>

#define MAX_NUM 50

int Box[MAX_NUM];

int main( void )
{
    int bookNum, boxWeight, bookWeight;
    scanf( "%d%d", &bookNum, &boxWeight );

    if ( !bookNum )
    {
        printf( "0" );
        return 0;
    }
    
    int ans = 1, currentBox = boxWeight;
    while ( bookNum-- )
    {
        scanf( "%d", &bookWeight );
        // printf( "%d\n", currentBox );
        if ( currentBox < bookWeight )
        {
            ans++;
            currentBox = boxWeight;
        }

        currentBox -= bookWeight;
    }

    printf( "%d", ans );

    return 0;
}