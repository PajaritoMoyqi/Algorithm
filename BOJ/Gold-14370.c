#include <stdio.h>
#include <string.h>

#define ALPHABET_MAX 26
#define MAX_LEN 2000
#define MAX_NUM 10

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
    {
        char STR[MAX_LEN+1];
        int CHECK[ALPHABET_MAX];
        int ANS[MAX_NUM];

        int j;
        for ( j = 0; j <= MAX_LEN; j++ )
            STR[j] = 0;
        for ( j = 0; j < ALPHABET_MAX; j++ )
            CHECK[j] = 0;
        for ( j = 0; j < ALPHABET_MAX; j++ )
            ANS[j] = 0;

        scanf( "%s", STR );
        int len = strlen( STR );

        int idx;
        for ( j = 0; j < len; j++ )
        {
            idx = STR[j] - 'A';
            CHECK[idx]++;
        }

        int idxZ = 'Z' - 'A';
        int idxE = 'E' - 'A';
        int idxR = 'R' - 'A';
        int idxO = 'O' - 'A';
        while ( CHECK[idxZ] )
        {
            CHECK[idxZ]--;
            CHECK[idxE]--;
            CHECK[idxR]--;
            CHECK[idxO]--;
            ANS[0]++;
        }
        int idxT = 'T' - 'A';
        int idxW = 'W' - 'A';
        while ( CHECK[idxW] )
        {
            CHECK[idxT]--;
            CHECK[idxW]--;
            CHECK[idxO]--;
            ANS[2]++;
        }
        int idxF = 'F' - 'A';
        int idxU = 'U' - 'A';
        while ( CHECK[idxU] )
        {
            CHECK[idxF]--;
            CHECK[idxO]--;
            CHECK[idxU]--;
            CHECK[idxR]--;
            ANS[4]++;
        }
        int idxS = 'S' - 'A';
        int idxI = 'I' - 'A';
        int idxX = 'X' - 'A';
        while ( CHECK[idxX] )
        {
            CHECK[idxS]--;
            CHECK[idxI]--;
            CHECK[idxX]--;
            ANS[6]++;
        }
        int idxG = 'G' - 'A';
        int idxH = 'H' - 'A';
        while ( CHECK[idxG] )
        {
            CHECK[idxE]--;
            CHECK[idxI]--;
            CHECK[idxG]--;
            CHECK[idxH]--;
            CHECK[idxT]--;
            ANS[8]++;
        }

        int idxN = 'N' - 'A';
        while ( CHECK[idxO] )
        {
            CHECK[idxO]--;
            CHECK[idxN]--;
            CHECK[idxE]--;
            ANS[1]++;
        }
        while ( CHECK[idxT] )
        {
            CHECK[idxT]--;
            CHECK[idxH]--;
            CHECK[idxR]--;
            CHECK[idxE]--;
            CHECK[idxE]--;
            ANS[3]++;
        }
        int idxV = 'V' - 'A';
        while ( CHECK[idxF] )
        {
            CHECK[idxF]--;
            CHECK[idxI]--;
            CHECK[idxV]--;
            CHECK[idxE]--;
            ANS[5]++;
        }
        while ( CHECK[idxS] )
        {
            CHECK[idxS]--;
            CHECK[idxE]--;
            CHECK[idxV]--;
            CHECK[idxE]--;
            CHECK[idxN]--;
            ANS[7]++;
        }

        while ( CHECK[idxN] )
        {
            CHECK[idxN]--;
            CHECK[idxI]--;
            CHECK[idxN]--;
            CHECK[idxE]--;
            ANS[9]++;
        }

        printf( "Case #%d: ", i );
        for ( j = 0; j <= MAX_NUM; j++ )
        {
            if ( ANS[j] )
            {
                int k;
                for ( k = 0; k < ANS[j]; k++ )
                    printf( "%d", j );
            }
        }
        puts( "" );
    }

    return 0;
}