### initialization ###

import sys

input = sys.stdin.readline

MAX = 100000

Seq = [0] * MAX
Tmp = [0] * MAX

### declaration ###

def init():
    t = int( input().rstrip() )

    for _ in range( t ):
        N = int( input().rstrip() )

        Seq = list( map( int, input().split() ) )

        mex = -1
        ans = 0
        
        for i in range( 21 ):
            mask = (1 << i) - 1
            Cnt = [0] * (mask + 2)

            for k in range( N ):
                Tmp[k] = Seq[k] & mask
                Cnt[Tmp[k]] += 1

            for k in range( mask + 2 ):
                if Cnt[k] == 0:
                    if mex < k:
                        mex = k
                        ans = mask
                    break

        print(ans)

### execution ###

init()