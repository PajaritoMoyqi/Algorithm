#include "Chaining.h"

int main( void )
{
    HashTable* HT = CHT_CreateHashTable( 12289 );

    CHT_Set( HT, "MSFT", "MicroSoft Corporation" );
    CHT_Set( HT, "JAVA", "Sun Microsystems" );
    CHT_Set( HT, "REDH", "Red Hat Linux" );
    CHT_Set( HT, "APAC", "Apache Org" );
    CHT_Set( HT, "ZYMZZ", "Unixyx Ops Check" );
    CHT_Set( HT, "IBM", "IBM Ltd." );
    CHT_Set( HT, "ORCL", "Oracle Corporation" );
    CHT_Set( HT, "CSCO", "Cisco Systems, Inc." );
    CHT_Set( HT, "GOOG", "Google Inc." );
    CHT_Set( HT, "YHOO", "Yahoo! Inc." );
    CHT_Set( HT, "NOVL", "Novell, Inc." );

    printf( "\n" );

    printf( "key: %s, value: %s\n", "MSFT", CHT_Get( HT, "MSFT" ) );
    printf( "key: %s, value: %s\n", "REDH", CHT_Get( HT, "REDH" ) );
    printf( "key: %s, value: %s\n", "APAC", CHT_Get( HT, "APAC" ) );
    printf( "key: %s, value: %s\n", "ZYMZZ", CHT_Get( HT, "ZYMZZ" ) );
    printf( "key: %s, value: %s\n", "JAVA", CHT_Get( HT, "JAVA" ) );
    printf( "key: %s, value: %s\n", "IBM", CHT_Get( HT, "IBM" ) );
    printf( "key: %s, value: %s\n", "ORCL", CHT_Get( HT, "ORCL" ) );
    printf( "key: %s, value: %s\n", "CSCO", CHT_Get( HT, "CSCO" ) );
    printf( "key: %s, value: %s\n", "GOOG", CHT_Get( HT, "GOOG" ) );
    printf( "key: %s, value: %s\n", "YHOO", CHT_Get( HT, "YHOO" ) );
    printf( "key: %s, value: %s\n", "NOVL", CHT_Get( HT, "NOVL" ) );

    CHT_DestroyHashTable( HT );

    return 0;
}