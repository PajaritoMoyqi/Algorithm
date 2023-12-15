#include "HTChaining.h"

HT* CreateHT( int size )
{
    HT* HTable = (HT*)malloc( sizeof( HT ) );

    HTable->Table = (HTNode*)malloc( sizeof( HTNode ) * size );
    memset( HTable->Table, 0, sizeof( HTNode ) * size );
    HTable->Size = size;

    return HTable;
}
HTNode* CreateHTNode( KeyType key, ValueType value )
{
    HTNode* NewNode = (HTNode*)malloc( sizeof( HTNode ) );
    
    NewNode->Key = (char*)malloc( sizeof( char ) * (strlen( key ) + 1) );
    strcpy( NewNode->Key, key );
    NewNode->Value = (char*)malloc( sizeof( char ) * (strlen( value ) + 1) );
    strcpy( NewNode->Value, value );
    NewNode->Next = NULL;

    return NewNode;
}
void DestroyHTNode( HTNode* N )
{
    free( N->Key );
    free( N->Value );
    free( N );
}
void DestroyLinkedList( LinkedList L )
{
    if ( L == NULL ) return;

    if ( L->Next != NULL )
        DestroyLinkedList( L->Next );
    
    DestroyHTNode( L );
}
void DestroyHT( HT* HTable )
{
    int i;
    for ( i = 0; i < HTable->Size; i++ )
    {
        LinkedList L = HTable->Table[i];
        DestroyLinkedList( L );
    }
    free( HTable->Table );
    free( HTable );
}

int HashFn( KeyType key, int keyLen, int tableSize )
{
    int i, returnVal = 0;
    for ( i = 0; i < keyLen; i++ )
        returnVal = (returnVal << 3) + key[i];

    returnVal = returnVal % tableSize;
    
    return returnVal;
}

void Set( HT* HTable, KeyType key, ValueType value )
{
    int address = HashFn( key, strlen( key ), HTable->Size );
    HTNode* NewNode = CreateHTNode( key, value );

    if ( HTable->Table[address] == NULL )
        HTable->Table[address] = NewNode;
    else // collision
    {
        LinkedList L = HTable->Table[address];
        NewNode->Next = L;
        HTable->Table[address] = NewNode;
    }
}

ValueType Get( HT* HTable, KeyType key )
{
    int address = HashFn( key, strlen( key ), HTable->Size );
    
    LinkedList L = HTable->Table[address];
    LinkedList Target = NULL;

    if ( L == NULL ) return;

    while ( 1 )
    {
        if ( strcmp( L->Key, key ) == 0 )
        {
            Target = L;
            break;
        }

        if ( L->Next == NULL )
            break;
        else
            L = L->Next;
    }

    return Target->Value;
}