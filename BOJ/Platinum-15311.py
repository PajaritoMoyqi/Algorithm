### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    _n = int( input() )

    print( 2000 )
    for i in range( 1, 2000+1 ):
        if i <= 1000:
            print( 1, end=" " )
        else:
            print( 1001, end=" " )

    return

### execution ###

init()