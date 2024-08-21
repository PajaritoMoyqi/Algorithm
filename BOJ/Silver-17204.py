### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n, k = map( int, input().rstrip().split() )
    Visited = [0] * n
    Target = [0] * n

    for i in range( n ):
        Target[i] = int( input() )

    start = 0
    Visited[start] = 1
    cnt = 0
    while True:

        if cnt == 0:
            t = Target[start]
        else:
            t = Target[t]
        cnt += 1
        if t == k:
            print( cnt )
            break

        if Visited[t] == 1:
            print( -1 )
            break

        Visited[t] = 1

    return

### execution ###

init()