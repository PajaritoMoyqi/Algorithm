#include <stdio.h>

int arr[10000+1];
int x;

void postPrint( int start, int end );

int main( void )
{
    int x, i = 0;
    
    while( scanf( "%d", &x ) != EOF )
        arr[i++] = x;
    
    postPrint( 0, i );
    
    return 0;
}

void postPrint( int sIdx, int eIdx )
{
    if ( sIdx >= eIdx ) return;
    
    int i;
    for ( i = sIdx+1; i < eIdx; i++ )
        if ( arr[sIdx] < arr[i] ) break;
    
    postPrint( sIdx + 1, i );
    postPrint( i, eIdx );
    printf( "%d\n", arr[sIdx] );
    
    return;
}