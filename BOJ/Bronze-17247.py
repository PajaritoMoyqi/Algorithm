### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    height, width = map( int, input().rstrip().split() )

    startX = -1
    startY = -1
    for i in range( height ):
        Point_list = list( map( int, input().rstrip().split() ) )
        for j in range( width ):
            if Point_list[j] == 1:
                if startX == -1:
                    startX = i
                    startY = j
                else:
                    print( abs( startX - i ) + abs( startY - j ) )
                    return

    return

### execution ###

init()