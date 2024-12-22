### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    while True:
        a = int( input() )
        if a == 0:
            break

        if a == 1:
            print( "{ }" )
            continue

        a -= 1
        print( "{ ", end="" )
        pow3 = 1
        flag = 0

        while a > 0:
            if a % 2 == 1:
                if flag == 1:
                    print( ", ", end="" )
                print( pow3, end="" )
                flag = 1

            pow3 *= 3
            a //= 2

        print( " }" )

    return

### execution ###

init()