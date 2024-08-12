### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    key_num, post_num = map( int, input().rstrip().split() )
    keyword_set = set()

    for _ in range( key_num ):
        string = input().rstrip()
        keyword_set.add( string )

    for _ in range( post_num ):
        Keyword_list = list( map( str, input().rstrip().split(',') ) )
        for i in range( len( Keyword_list ) ):
            if Keyword_list[i] in keyword_set:
                keyword_set.remove( Keyword_list[i] )
        print( len( keyword_set ) )

    return

### execution ###

init()