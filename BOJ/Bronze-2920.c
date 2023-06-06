#include <stdio.h>
#include <string.h>

#define MAX_SIZE 16

int main()
{
    char str_read[MAX_SIZE];
    fgets( str_read, MAX_SIZE, stdin );

    // printf ( "%s\n", str_read );
    if ( strcmp( str_read, "1 2 3 4 5 6 7 8" ) == 0 )
        printf ( "ascending" );
    else if ( strcmp( str_read, "8 7 6 5 4 3 2 1" ) == 0 )
        printf ( "descending" );
    else
        printf ( "mixed" );

    return 0;
}