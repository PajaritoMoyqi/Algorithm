import sys

input = sys.stdin.readline

def init():
    for i in range( 1, int( input() ) + 1 ):
        print( str( i ) + ". " + input().rstrip() )

    return

init()