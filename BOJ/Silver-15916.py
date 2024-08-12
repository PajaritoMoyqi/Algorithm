### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    Y_list = list( map( int, input().rstrip().split() ) )
    k = int( input() )

    if Y_list[0] - 1*k < 0:
        flag = -1
    elif Y_list[0] - 1*k > 0:
        flag = 1
    else:
        flag = 0

    for i in range( n ):
        pointY = (i+1)*k
        if (Y_list[i] - pointY) * flag <= 0:
            flag = 0
            break

    if flag == 0:
        print( "T" )
    else:
        print( "F" )

    return

### execution ###

init()