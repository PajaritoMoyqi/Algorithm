#ifndef OPENADDRESSING_HT_H
#define OPENADDRESSING_HT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus
{
    EMPTY = 0,
    OCCUPIED = 1
};

typedef struct ElementType
{
    KeyType Key;
    ValueType Value;

    enum ElementStatus Status;
} ElementType;
typedef struct HashTable
{
    int OccupiedCount;
    int Size;

    ElementType* Table;
} HashTable;

// declarations
HashTable* CreateHT( int size );
void ClearElement( ElementType* Element );
void DestoryHT( HashTable* HT );

int Hash( KeyType key, int keyLen, int size );
int CollisionHash( KeyType key, int keyLen, int size );
void ReHash( HashTable** HT );

void Set( HashTable** HT, KeyType key, ValueType value );
ValueType Get( HashTable* HT, KeyType key );

#endif