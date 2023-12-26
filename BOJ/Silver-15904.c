#include <stdio.h>

int main( void )
{
    int flag = 0;
    char c;
    while ( scanf( "%c", &c ) != EOF )
    {
        if ( flag == 0 )
        {
            if ( c == 'U' )
                flag++;
        }
        else if ( flag == 1 )
        {
            if ( c == 'C' )
                flag++;
        }
        else if ( flag == 2 )
        {
            if ( c == 'P' )
                flag++;
        }
        else if ( flag == 3 )
        {
            if ( c == 'C' )
            {
                flag++;
                break;
            }
        }
    }

    if ( flag == 4 ) printf( "I love UCPC" );
    else printf( "I hate UCPC" );

    return 0;
}
