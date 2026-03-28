#include <stdio.h>

int main( void )
{
    int n;
    scanf( "%d", &n );

    if ( n < 6 ) {
      printf( "%s", "Oh My God!" );
    } else {
      printf( "%s", "Success!" );
    }

    return 0;
}