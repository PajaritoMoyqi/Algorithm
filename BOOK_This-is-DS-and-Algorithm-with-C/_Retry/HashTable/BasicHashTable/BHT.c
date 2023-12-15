#include "BHT.h"

HT* CreateHT( int size )
{
    HT* HTable = (HT*)malloc( sizeof( HT ) );
    HTable->Table = (HTNode*)malloc( sizeof( HTNode ) * size );
    HTable->Size = size;

    return HTable;
}
void DestroyHT( HT* HTable )
{
    free( HTable->Table );
    free( HTable );
}

int HashFn( KeyType key, int size )
{
    return key % size;
}

void Set( HT* HTable, KeyType key, ValueType value )
{
    int address = HashFn( key, HTable->Size );

    HTable->Table[address].Key = key;
    HTable->Table[address].Value = value;
}

ValueType Get( HT* HTable, KeyType key )
{
    int address = HashFn( key, HTable->Size );

    return HTable->Table[address].Value;
}