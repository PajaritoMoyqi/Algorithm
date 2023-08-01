#include <stdio.h>

int main( void )
{
    int price, friendMoney;
    scanf( "%d%d", &price, &friendMoney );

    if ( price <= 1023 )
        printf( "No thanks" );
    else if ( price > 2046 )
        printf( "Impossible" );
    else
    {
        price -= 1023;

        while ( price )
        {
            if ( price & 1 )
            {
                if ( !(friendMoney & 1) )
                {
                    printf( "Impossible" );
                    goto end;
                }
            }

            price >>= 1;
            friendMoney >>= 1;

            printf( "loop\n" );
        }

        printf( "Thanks" );
    }

    end:
        return 0;
}