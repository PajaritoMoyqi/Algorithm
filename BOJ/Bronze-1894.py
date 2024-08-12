### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    while True:
        try:
            x1, y1, x2, y2, x3, y3, x4, y4 = map( float, input().rstrip().split() )
            if (x1 == x3 and y1 == y3):
                x = x1
                y = y1
                diff_x1 = x2 - x1
                diff_y1 = y2 - y1
                diff_x2 = x4 - x3
                diff_y2 = y4 - y3
            elif (x1 == x4 and y1 == y4):
                x = x1
                y = y1
                diff_x1 = x2 - x1
                diff_y1 = y2 - y1
                diff_x2 = x3 - x4
                diff_y2 = y3 - y4
            elif (x2 == x3 and y2 == y3):
                x = x2
                y = y2
                diff_x1 = x1 - x2
                diff_y1 = y1 - y2
                diff_x2 = x4 - x3
                diff_y2 = y4 - y3
            elif (x2 == x4 and y2 == y4):
                x = x2
                y = y2
                diff_x1 = x1 - x2 
                diff_y1 = y1 - y2
                diff_x2 = x3 - x4
                diff_y2 = y3 - y4

            # print( diff_x1, diff_y1, diff_x2, diff_y2 )
            print( '{:.3f} {:.3f}'.format( x + diff_x1 + diff_x2, y + diff_y1 + diff_y2 ) )

        except:
            break

    return

### execution ###

init()