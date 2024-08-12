### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    ab, bc, cd = map( int, input().rstrip().split() )

    ad = ab*cd/bc
    print( '{:.6f}'.format( ad ) )

    return

### execution ###

init()