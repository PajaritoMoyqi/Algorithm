#include <stdio.h>
#include <string.h>

char str[100000+1];
char stack[100000+1];
char ans[100000+1];

int main( void )
{
    scanf( "%[^\n]", &str );
    int len = strlen( str );
    
    int i, top = -1, flag = 0;
    for ( i = 0; i < len; i++ )
    {
        if ( str[i] == '<' )
        {
            while ( top >= 0 )
            {
                ans[i-top-1] = stack[top];
                top--;
            }

            while ( str[i] != '>' )
            {
                ans[i] = str[i];
                i++;
            }
            ans[i] = str[i];
        }
        else if ( str[i] == ' ' )
        {
            while ( top >= 0 )
            {
                ans[i-top-1] = stack[top];
                top--;
            }
            ans[i] = str[i];
        }
        else
        {
            stack[++top] = str[i];
        }
        
        // printf( "idx: %d, top: %d, char: %c\n", i, top, str[i] );
    }
    
    while ( top >= 0 )
    {
        ans[i-top-1] = stack[top];
        top--;
    }

    for ( i = 0; i < len; i++ )
        printf( "%c", ans[i] );

    return 0;
}