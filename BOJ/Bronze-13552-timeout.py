### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    Point_list = []
    for _ in range( n ):
        Point = list( map( int, input().rstrip().split() ) )
        Point_list.append( Point )
    
    m = int( input() )
    for _ in range( m ):
        x, y, z, r = map( int, input().rstrip().split() )

        ans = 0
        for i in range( n ):
            x_len_sqr = (x-Point_list[i][0])*(x-Point_list[i][0])
            y_len_sqr = (y-Point_list[i][1])*(y-Point_list[i][1])
            z_len_sqr = (z-Point_list[i][2])*(z-Point_list[i][2])
            dist_sqr = x_len_sqr + y_len_sqr + z_len_sqr
            r_sqr = r*r
            if dist_sqr <= r_sqr:
                ans += 1

        print( ans )

    return

### execution ###

init()