### initialization ###

import sys
import math

input = sys.stdin.readline

### declaration ###

def init():
    top, bottom, height = map( int, input().rstrip().split() )

    if top == bottom:
        print( -1 )
        return
    
    if top > bottom:
        tmp = top
        top = bottom
        bottom = tmp

    total_height = height * bottom/(bottom-top)
    total_area = (total_height*total_height + bottom*bottom)*math.pi
    removed_height = height * top/(bottom-top)
    removed_area = (removed_height*removed_height + top*top)*math.pi

    print( '{:.6f}'.format( total_area - removed_area ) )
    
    return

### execution ###

init()