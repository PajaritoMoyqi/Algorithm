### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    a, b, c = map( int, input().rstrip().split() )
    x1, x2, y1, y2 = map( int, input().rstrip().split() )

    if a != 0 and b != 0:
        crossline_y1 = -(a*x1 + c)/b
        crossline_y2 = -(a*x2 + c)/b
        crossline_x1 = -(b*y1 + c)/a
        crossline_x2 = -(b*y2 + c)/a
        if y1 < crossline_y1 < y2 or y1 < crossline_y2 < y2 or x1 < crossline_x1 < x2 or x1 < crossline_x2 < x2 :
            print( "Poor" )
        else:
            print( "Lucky" )
    elif a == 0:
        crossline_y = -c/b
        if y1 < crossline_y < y2:
            print( "Poor" )
        else:
            print( "Lucky" )
    elif b == 0:
        crossline_x = -c/a
        if x1 < crossline_x < x2:
            print( "Poor" )
        else:
            print( "Lucky" )

    return

### execution ###

init()