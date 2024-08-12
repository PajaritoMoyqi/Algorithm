### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    for _ in range( n ):
        length = int( input() )
        String_list = list( map( str, input().rstrip().split() ) )

        Final_string_list = []
        for i in range( length ):
            if i == 0:
                Final_string_list.append( String_list[i] )
            else:
                if Final_string_list[0] >= String_list[i]:
                    Final_string_list.insert( 0, String_list[i] )
                else:
                    Final_string_list.append( String_list[i] )

        print( ''.join( Final_string_list ) )

    return

### execution ###

init()