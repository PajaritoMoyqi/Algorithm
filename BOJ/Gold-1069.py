### initialization ###

import sys
import math

input = sys.stdin.readline

### declaration ###

def init():
    x, y, d, t = map( int, input().rstrip().split() )

    total_dist = math.sqrt( math.pow( x, 2 ) + math.pow( y, 2 ) )
    time = 0
    if d <= t:
        print( total_dist )
    else:
        if total_dist <= t:
            print( total_dist )
        else:
            while total_dist > 2*d:
                total_dist = math.fabs( total_dist - d )
                time = time + t

            if total_dist == 2*d:
                time = time + 2*t
                print( time )
                
            else:
                if total_dist > d:
                    left_dist = math.fabs( total_dist - d )
                    time = time + t
                    if left_dist > t:
                        time = time + t
                    else:
                        time = time + left_dist
                    print( time )
                else:
                    if total_dist == d:
                        time = time + t
                        print( time )
                    else:
                        left_dist = math.fabs( total_dist - d )
                        fastest_time = min( [left_dist + t, total_dist, 2*t ] )
                        time = time + fastest_time
                        print( time )

    return

### execution ###

init()