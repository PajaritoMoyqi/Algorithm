### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    pool_num, min_pool_num = map( int, input().rstrip().split() )

    Dist_list = []
    for _ in range( pool_num ):
        point_num = int( input() )
        Point_list = list( map( int, input().rstrip().split() ) )

        max_dist = 0
        for i in range( point_num ):
            dist = Point_list[2*i]*Point_list[2*i] + Point_list[2*i+1]*Point_list[2*i+1]
            max_dist = max_dist if max_dist > dist else dist
        
        Dist_list.append( max_dist )

    Dist_list.sort()
    print( '{:.2f}'.format( Dist_list[min_pool_num-1] ) )

    return

### execution ###

init()