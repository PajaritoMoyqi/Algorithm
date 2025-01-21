### Initialization ###

import sys

input = sys.stdin.readline

### Declaration ###

def init():
    pokemon_n, problem_n = map( int, input().rstrip().split() )

    D_id = {}
    D_name = {}

    for i in range( 1, pokemon_n + 1 ):
        pokemon = input().rstrip()
        D_id[i] = pokemon
        D_name[pokemon] = i

    for _ in range(problem_n):
        p = input().rstrip()
        if p.isdigit():
            print(D_id[int( p )])
        else:
            print(D_name[p])

    return

### Execution ###

init()