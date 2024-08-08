import sys

input = sys.stdin.readline

def init():
    num = int( input() )

    for _ in range( num ):
        print( input().rstrip().lower() )

    return

init()