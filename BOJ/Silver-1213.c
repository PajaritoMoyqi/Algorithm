#include <stdio.h>

#define NUMBER_OF_ALPHABET 26
int cnt[NUMBER_OF_ALPHABET];

int main( void )
{
    char c;
    while ( ( c = getchar() ) != '\n' )
    {
        int idx = c - 'A';
        cnt[idx]++;
    }

    int i, chance = 1;
    for ( i = 0; i < NUMBER_OF_ALPHABET; i++ )
    {
        if ( cnt[i] & 1 )
            chance--;
    }

    char later, flag = 0;
    if ( chance < 0 )
        printf( "I'm Sorry Hansoo" );
    else
    {
        for ( i = 0; i < NUMBER_OF_ALPHABET; i++ )
        {
            char c = i + 'A';
            if ( cnt[i] & 1 )
            {
                later = c;
                flag = 1;
                cnt[i]--;
            }

            int num = cnt[i] / 2;
            int j;
            for ( j = 0; j < num; j++ )
            {
                printf( "%c", c );
                cnt[i]--;
            }
        }

        if ( flag )
            printf( "%c", later );

        for ( i = NUMBER_OF_ALPHABET - 1; i >= 0; i-- )
        {
            char c = i + 'A';
            int num = cnt[i];
            int j;
            for ( j = 0; j < num; j++ )
            {
                printf( "%c", c );
                cnt[i]--;
            }
        }
    }

    return 0;
}