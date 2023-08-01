#include <stdio.h>
char bits[1000001];

int main( void )
{
    int num;
    scanf( "%d", &num );

    int cnt = 0;
    int i;
    int bit;
    for ( i = 0; i <= num; i++ )
    {
        scanf( "%c", &bits[i] );
        if ( bits[i] == 49 ) cnt++;
    }

    printf( "%d", cnt );

    return 0;
}