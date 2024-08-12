### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    string = input().rstrip()
    length = len( string )
    String_list = list( string )

    i = 0
    while i < length:
        if i == 0:
            i += 1
            continue

        if String_list[i] == ')' and String_list[i-1] == '(':
            del String_list[i]
            del String_list[i-1]
            length -= 2
            i -= 2

        i += 1

    # print( String_list )
    print( length )

    return

### execution ###

init()