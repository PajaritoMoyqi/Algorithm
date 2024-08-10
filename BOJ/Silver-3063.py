import sys

input = sys.stdin.readline

def init():
    num = int( input() )

    for _ in range( num ):
        x1, y1, x2, y2, x3, y3, x4, y4 = map( int, map( int, input().rstrip().split() ) )
        # print( f'({x1}, {y1}), ({x2}, {y2}), ({x3}, {y3}), ({x4}, {y4})' )
        if x2 > x3 and y2 > y3 and x1 < x4 and y1 < y4:
            if x1 > x3:
                if x2 > x4:
                    width = x4 - x1
                else:
                    width = x2 - x1
            else:
                if x2 > x4:
                    width = x4 - x3
                else:
                    width = x2 - x3
            
            if y1 > y3:
                if y2 > y4:
                    height = y4 - y1
                else:
                    height = y2 - y1
            else:
                if y2 > y4:
                    height = y4 - y3
                else:
                    height = y2 - y3

            area = (x2-x1)*(y2-y1) - height*width
            print( area )
        else:
            area = (x2-x1)*(y2-y1)
            print( area )

    return

init()