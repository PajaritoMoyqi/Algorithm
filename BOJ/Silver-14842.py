### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    _width, height, n = map( int, input().rstrip().split() )
    
    ans = 0
    if n & 1:
        basic_len = height/n

        n -= 1
        n /= 2
        for i in range( int( n ) ):
            ans += (2*i+1)*basic_len
        ans *= 2
    else:
        n -= 2
        n /= 2

        average_len = height/2
        ans += average_len*n
        ans *= 2

    print( '{:.6f}'.format( ans ) )
    
    return

### execution ###

init()