### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    while n != 0:
        N, M = map( int, input().rstrip().split() )
        for _ in range( M ):
            _a, _b = map( int, input().rstrip().split() )

        print( N-1 )

        n -= 1

    return

### execution ###

init()