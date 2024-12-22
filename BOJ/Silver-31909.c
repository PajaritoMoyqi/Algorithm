#include <stdio.h>

#define MAX 200000
#define KEY_MAX 8

int Order[MAX];
int Key[KEY_MAX] = {0, 1, 2, 3, 4, 5, 6, 7};
int KeyNum[KEY_MAX] = {1, 2, 4, 8, 16, 32, 64, 128};

int popCount( unsigned int n );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int cnt;
    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &Order[i] );
        cnt = popCount( Order[i] );

        if ( cnt == 2 )
        {
            int a = -1, b = -1;
            int j;
            for ( j = 0; j < KEY_MAX; j++ )
            {
                if ( ~a && ~b )
                    break;

                if ( (KeyNum[j] & Order[i]) && !~a )
                    a = j;
                else if ( (KeyNum[j] & Order[i]) && ~a )
                    b = j;
            }

            int idxA = -1, idxB = -1;
            for ( j = 0; j < KEY_MAX; j++ )
            {
                if ( ~idxA && ~idxB )
                    break;

                if ( Key[j] == a )
                    idxA = j;
                if ( Key[j] == b )
                    idxB = j;
            }

            int tmp = Key[idxA];
            Key[idxA] = Key[idxB];
            Key[idxB] = tmp;
        }
    }
    // for ( i = 0; i < KEY_MAX; i++ )
    //     printf( "%d ", Key[i] );

    int m;
    scanf( "%d", &m );
    for ( i = 0; i < KEY_MAX; i++ )
    {
        if ( Key[i] == m )
        {
            printf( "%d", i );
            break;
        }
    }

    return 0;
}

int popCount( unsigned int n )
{
	n = (n >>  1 & 0x55555555) + (n & 0x55555555);
	n = (n >>  2 & 0x33333333) + (n & 0x33333333);
	n = (n >>  4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >>  8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
	return n;
}