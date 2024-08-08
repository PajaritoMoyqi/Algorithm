import sys

input = sys.stdin.readline

def init():
    num, _ = map( int, input().rstrip().split() )

    for _ in range( num ):
        print( input().rstrip()[::-1] )

    return

init()