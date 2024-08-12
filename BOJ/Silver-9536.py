### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    for _ in range( n ):
        i = 0
        while True:
            if i == 0:
                Sound_list = list( map( str, input().rstrip().split() ) )
                i += 1
                continue

            hint = input().rstrip()
            length = len( hint )
            if length == 0:
                break
            
            if 'goes' in hint:
                another_sound = hint.split( 'goes', maxsplit=1 )[1].strip()
                while another_sound in Sound_list:
                    Sound_list.remove( another_sound )
            else:
                break

        print( ' '.join( Sound_list ).strip() )

    return

### execution ###

init()