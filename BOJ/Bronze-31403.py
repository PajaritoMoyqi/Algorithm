import sys

input = sys.stdin.readline

def init():
    num1 = int( input() )
    num2 = int( input() )
    num3 = int( input() )

    print( num1 + num2 - num3 )
    changed_str = str( num1 ) + str( num2 )
    changed_num = int( changed_str )
    print( changed_num - num3 )

    return

init()