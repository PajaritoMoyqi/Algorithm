### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n, m = map( int, input().rstrip().split() )
    Student_dict = {}

    for _ in range( m ):
        std_id = input().rstrip()

        if std_id in Student_dict:
            Student_dict.pop( std_id )
        Student_dict[std_id] = 1

    Student_list = list( Student_dict.keys() )
    for i in range( n ):
        if i >= len( Student_list ):
            break
        print( Student_list[i] )

    return

### execution ###

init()