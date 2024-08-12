### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    Height_list = list( map( int, input().rstrip().split() ) )

    area = 0
    if n == 1:
        area += 2
        area += Height_list[0]*4
    else:
        for i in range( n ):
            area += 2
            if i == 0:
                area += Height_list[i]*3
                inside_area = Height_list[i] - Height_list[i+1]
                if inside_area > 0:
                    area += inside_area
            elif i == n-1:
                area += Height_list[i]*3
                inside_area = Height_list[i] - Height_list[i-1]
                if inside_area > 0:
                    area += inside_area
            else:
                area += Height_list[i]*2
                left_side_area = Height_list[i] - Height_list[i-1]
                right_side_area = Height_list[i] - Height_list[i+1]
                if left_side_area > 0:
                    area += left_side_area
                if right_side_area > 0:
                    area += right_side_area
    
    print( area )

    return

### execution ###

init()