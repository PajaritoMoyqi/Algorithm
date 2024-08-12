### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    Height_list = list( map( int, input().rstrip().split() ) )

    ans = 0
    for i in range( n ):
        if i != n-1:
            ans += ((Height_list[i] + Height_list[i+1])*(Height_list[i] + Height_list[i+1]) + (Height_list[i] - Height_list[i+1])*(Height_list[i] - Height_list[i+1]))

    print( ans )

    return

### execution ###

init()