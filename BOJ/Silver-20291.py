### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )

    Type_dict = {}
    for _ in range( n ):
        string = input().rstrip()
        Tmp_list = string.split( '.' )
        
        if Tmp_list[1] not in Type_dict:
            Type_dict[Tmp_list[1]] = 1
        else:
            Type_dict[Tmp_list[1]] += 1

    Sorted_type_dict = sorted( Type_dict.items() )
    for key, value in Sorted_type_dict:
        print( "%s %d" % ( key, value ) )

    return

### execution ###

init()