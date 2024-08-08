import sys

input = sys.stdin.readline

def init():
    num, _ = map( int, input().rstrip().split() )

    for _ in range( num ):
        string = input().rstrip()
        string_list = list( string )
        string_list.reverse()
        reversed_string = ''.join( string_list )
        print( reversed_string )

    return

init()