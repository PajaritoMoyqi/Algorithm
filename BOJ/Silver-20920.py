### initialization ###

import sys

input = sys.stdin.readline
MAX_LEN = 10

### declaration ###

def len_filter( string, number ):
    return True if len( string ) == number else False

def init():
    n, limit = map( int, input().rstrip().split() )

    Dict_dict = {}
    for _ in range( n ):
        word = input().rstrip()
        
        if len( word ) < limit:
            continue

        if word not in Dict_dict:
            Dict_dict[word] = 1
        else:
            Dict_dict[word] += 1

    Sorted_dict = sorted( Dict_dict.items(), key = lambda x: (-x[1], -len(x[0]), x[0]) )
    for i in range( len( Sorted_dict ) ):
        print( Sorted_dict[i][0] )

    return

### execution ###

init()