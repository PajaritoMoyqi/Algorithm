#ifndef BASIC_HT_H
#define BASIC_HT_H

# include <stdio.h>
# include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct HTNode
{
    KeyType Key;
    ValueType Value;
} HTNode;
typedef struct HT
{
    int Size;
    HTNode* Table;
} HT;

// declarations
HT* CreateHT( int size );
void DestroyHT( HT* HTable );
int HashFn( KeyType key, int size );
void Set( HT* HTable, KeyType key, ValueType value );
ValueType Get( HT* HTable, KeyType key );

#endif