#include <stdio.h>

int main( void )
{
    int NumberOfBooks;
    int NumberOfDummy;
    scanf( "%d", &NumberOfBooks );
    scanf( "%d", &NumberOfDummy );

    int i;
    int j;
    int answer = 0;

    for ( i = 0; i < NumberOfDummy; i++ )
    {
        int numberOfBooksInDummy;
        scanf( "%d", &numberOfBooksInDummy );

        int before;
        int now;

        for ( j = 0; j < numberOfBooksInDummy; j++ )
        {
            if ( j == 0 )
                scanf( "%d", &now );
            else
            {
                before = now;
                scanf( "%d", &now );

                if ( before < now )
                {
                    answer = 1;
                    goto exit;
                }
            }
        }
    }

    exit:
        if ( answer == 1 )
            printf( "No" );
        else
            printf( "Yes" );

    return 0;
}