### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    a, b = map( int, input().rstrip().split() )

    ans = 0
    for i in range( a, b+1 ):
        if i == 1 or i == 2:
            continue
        if i % 2 == 0:
            ans += i

    print( ans )

    return

### execution ###

init()