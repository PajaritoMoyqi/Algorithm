#include "OpenAddressing.h"

int main( void )
{
    HashTable* HT = OAHT_CreateHashTable( 11 );

    OAHT_Set( &HT, "MSFT", "MicroSoft Corporation" );
    OAHT_Set( &HT, "JAVA", "Sun Microsystems" );
    OAHT_Set( &HT, "REDH", "Red Hat Linux" );
    OAHT_Set( &HT, "APAC", "Apache Org" );
    OAHT_Set( &HT, "ZYMZZ", "Unixyx Ops Check" );
    OAHT_Set( &HT, "IBM", "IBM Ltd." );
    OAHT_Set( &HT, "ORCL", "Oracle Corporation" );
    OAHT_Set( &HT, "CSCO", "Cisco Systems, Inc." );
    OAHT_Set( &HT, "GOOG", "Google Inc." );
    OAHT_Set( &HT, "YHOO", "Yahoo! Inc." );
    OAHT_Set( &HT, "NOVL", "Novell, Inc." );

    printf( "\n" );

    printf( "key: %s, value: %s\n", "MSFT", OAHT_Get( HT, "MSFT" ) );
    printf( "key: %s, value: %s\n", "REDH", OAHT_Get( HT, "REDH" ) );
    printf( "key: %s, value: %s\n", "APAC", OAHT_Get( HT, "APAC" ) );
    printf( "key: %s, value: %s\n", "ZYMZZ", OAHT_Get( HT, "ZYMZZ" ) );
    printf( "key: %s, value: %s\n", "JAVA", OAHT_Get( HT, "JAVA" ) );
    printf( "key: %s, value: %s\n", "IBM", OAHT_Get( HT, "IBM" ) );
    printf( "key: %s, value: %s\n", "ORCL", OAHT_Get( HT, "ORCL" ) );
    printf( "key: %s, value: %s\n", "CSCO", OAHT_Get( HT, "CSCO" ) );
    printf( "key: %s, value: %s\n", "GOOG", OAHT_Get( HT, "GOOG" ) );
    printf( "key: %s, value: %s\n", "YHOO", OAHT_Get( HT, "YHOO" ) );
    printf( "key: %s, value: %s\n", "NOVL", OAHT_Get( HT, "NOVL" ) );

    OAHT_DestroyHashTable( HT );

    return 0;
}