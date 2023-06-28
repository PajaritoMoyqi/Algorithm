#ifndef HUFFMAN_H
#define HUFFMAN_H

# include <stdio.h>
# include <stdlib.h>
# include "PriorityQueue.h"

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct tagSymbolInfo
{
    UCHAR Symbol;
    int Frequency;
} SymbolInfo;

typedef struct tagHuffmanNode
{
    SymbolInfo Data;
    struct tagHuffmanNode* Left;
    struct tagHuffmanNode* Right;
} HuffmanNode;

typedef struct tagBitBuffer
{
    UCHAR* Buffer;
    UINT Size;
} BitBuffer;

typedef struct tagHuffmanCode
{
    UCHAR Code[MAX_BIT];
    int Size;
} HuffmanCode;

HuffmanNode* Huffman_CreateNode( SymbolInfo NewData );
void Huffman_DestroyNode( HuffmanNode* N );
void Huffman_DestroyTree( HuffmanNode* N );

void Huffman_AddBit( BitBuffer* Buffer, char Bit );
void Huffman_BuildCodeTable( HuffmanNode* Tree, HuffmanCode CodeTable[MAX_CHAR], UCHAR Code[MAX_BIT], int Size );
void Huffman_BuildPrefixTree( HuffmanNode** Tree, SymbolInfo SymbolInfoTable[MAX_CHAR] );
void Huffman_Encode( HuffmanNode** Tree, UCHAR* Source, BitBuffer* Encoded, HuffmanCode CodeTable[MAX_CHAR] );
void Huffman_Decode( HuffmanNode* Tree, BitBuffer* Encoded, UCHAR* Decoded );

void Huffman_PrintBinary( BitBuffer* Buffer );

#endif