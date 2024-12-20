### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def solve():
    n = int( input() )
    given_list = list( map( int, input().split() ) )

    ans = 0
    m = 0
    for i in range( 30+1 ):
        mask = (1 << i) - 1

        s = set()
        mex = -1
        for i in range( n ):
            s.add( given_list[i] & mask )

        for i in range( n ):
            if i not in s:
                mex = i
                break
        if mex == -1:
            mex = n

        if mex > m:
            ans = mask
            m = mex

    print( ans )

def init():
    t = int( input() )
    for _ in range( t ):
        solve()

### declaration ###

init()