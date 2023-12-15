#ifndef CHAINING_HT_H
#define CHAINING_HT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct HTNode
{
    KeyType Key;
    ValueType Value;

    struct HTNode* Next;
} HTNode;
typedef HTNode* LinkedList;
typedef struct HT
{
    int Size;
    LinkedList* Table;
} HT;

// declarations
HT* CreateHT( int size );
HTNode* CreateHTNode( KeyType key, ValueType value );
void DestroyHTNode( HTNode* N );
void DestroyHT( HT* HTable );

int HashFn( KeyType key, int keyLen, int tableSize );
void Set( HT* HTable, KeyType key, ValueType value );
ValueType Get( HT* HTable, KeyType key );

#endif