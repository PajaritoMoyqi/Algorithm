### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    Tree_dict = {}
    cnt = 0
    while True:
        string = input().rstrip()
        if string == '':
            break
        cnt += 1

        if string not in Tree_dict:
            Tree_dict[string] = 1
        else:
            Tree_dict[string] += 1

    Sorted_tree_dict = sorted( Tree_dict.items() )
    for key, value in Sorted_tree_dict:
        print( "%s %.4f" % ( key, value*100/cnt ) )

    return

### execution ###

init()