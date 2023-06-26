#include "SimpleHashTable.h"

int main( void )
{
    HashTable* HT = SHT_CreateHashTable( 193 );

    SHT_Set( HT, 418, 32114 );
    SHT_Set( HT, 9, 514 );
    SHT_Set( HT, 27, 8917 );
    SHT_Set( HT, 1031, 286 );

    printf( "key: %d, value: %d\n", 418, SHT_Get( HT, 418 ) );
    printf( "key: %d, value: %d\n", 9, SHT_Get( HT, 9 ) );
    printf( "key: %d, value: %d\n", 27, SHT_Get( HT, 27 ) );
    printf( "key: %d, value: %d\n", 1031, SHT_Get( HT, 1031 ) );

    SHT_DestroyHashTable( HT );

    return 0;
}