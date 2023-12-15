#include "HTOA.h"

HashTable* CreateHT( int size )
{
    HashTable* HT = (HashTable*)malloc( sizeof( HashTable ) );

    HT->Table = (ElementType*)malloc( sizeof( ElementType ) );
    memset( HT->Table, 0, sizeof( ElementType ) * size );
    HT->Size = size;
    HT->OccupiedCount = 0;

    return HT;
}
void ClearElement( ElementType* Element )
{
    if ( Element->Status == EMPTY )
        return;

    free( Element->Key );
    free( Element->Value );
}
void DestoryHT( HashTable* HT )
{
    int i;
    for ( i = 0; i < HT->Size; i++ )
        ClearElement( &(HT->Table[i]) );
    
    free( HT->Table );
    free( HT );
}

int Hash( KeyType key, int keyLen, int size )
{
    int i, hashValue;
    for ( i = 0; i < keyLen; i++ )
        hashValue = (hashValue << 3) + key[i];

    hashValue = hashValue % size;
    return hashValue;
}
int CollisionHash( KeyType key, int keyLen, int size )
{
    int i, hashValue;
    for ( i = 0; i < keyLen; i++ )
        hashValue = (hashValue << 2) + key[i];

    hashValue = hashValue % (size - 3) + 1;
    return hashValue;
}

void ReHash( HashTable** HT )
{
    ElementType* PrevTable = (*HT)->Table;

    HashTable* NewHT = CreateHT( (*HT)->Size * 2 );

    int i;
    for ( i = 0; i < (*HT)->Size; i++ )
    {
        if ( PrevTable[i].Status == OCCUPIED )
            Set( &NewHT, PrevTable[i].Key, PrevTable[i].Value );
    }

    DestoryHT( (*HT) );

    (*HT) = NewHT;
}
void Set( HashTable** HT, KeyType key, ValueType value )
{
    int keyLen, address, stepSize;

    double usage = (double)(*HT)->OccupiedCount / (*HT)->Size;
    if ( usage > 0.66 )
    {
        ReHash( HT );
    }

    keyLen = strlen( key );
    address = Hash( key, keyLen, (*HT)->Size );
    stepSize = CollisionHash( key, keyLen, (*HT)->Size );

    while ( (*HT)->Table[address].Status != EMPTY && strcmp( (*HT)->Table[address].Key, key ) != 0 ) // collision
    {
        address = (address + stepSize) % (*HT)->Size;
    }

    (*HT)->Table[address].Key = (char*)malloc( sizeof( char ) * (keyLen + 1) );
    strcpy( (*HT)->Table[address].Key, key );
    (*HT)->Table[address].Value = (char*)malloc( sizeof( char ) * (strlen( value ) + 1) );
    strcpy( (*HT)->Table[address].Value, value );
    (*HT)->Table[address].Status = OCCUPIED;

    (*HT)->OccupiedCount++;
}
ValueType Get( HashTable* HT, KeyType key )
{
    int keyLen = strlen( key );
    int address = Hash( key, keyLen, HT->Size );
    int stepSize = CollisionHash( key, keyLen, HT->Size );

    while ( (*HT)->Table[address].Status != EMPTY && strcmp( (*HT)->Table[address].Key, key ) != 0 ) // collision
    {
        address = (address + stepSize) % (*HT)->Size;
    }

    return HT->Table[address].Value;
}