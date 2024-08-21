### initialization ###

import sys
import math

input = sys.stdin.readline

### declaration ###

def digit_length( n ):
    ans = 0

    while n:
        n //= 10
        ans += 1

    return ans

def init():
    Ans = [0] * 10

    limit = int( input() )
    digit_len = digit_length( limit )

    maximum = int( math.pow( 10, digit_len-1 ) )
    cnt = 0
    prevHistory = -1
    while maximum:
        # print( f'prevHistory: {prevHistory}, maximum: {maximum}' )

        if cnt == 0 and maximum == 1:
            for i in range( 1, limit+1 ):
                Ans[i] += 1
        elif cnt == 0 and maximum != 1:
            msb = limit // maximum
            rest = limit % maximum

            for i in range( 1, msb ):
                Ans[i] += maximum
        
            Ans[msb] += (rest+1)
        elif maximum != 1:
            msb = (limit // maximum) % 10
            rest = limit % maximum

            # print( f'msb: {msb}, rest: {rest}' )
            
            for i in range( 1, msb ):
                Ans[i] += (maximum*(prevHistory+1))
            
            Ans[msb] += (rest+1)

            for i in range( msb, 9+1 ):
                Ans[i] += (maximum*prevHistory)
            if msb != 0:
                Ans[0] += (maximum*prevHistory)
            else:
                Ans[0] -= (maximum*prevHistory)
                Ans[0] += (maximum*(prevHistory-1))
        else:
            msb = (limit // maximum) % 10

            for i in range( 1, msb+1 ):
                Ans[i] += (prevHistory+1)
            
            for i in range( msb+1, 9+1 ):
                Ans[i] += prevHistory
            Ans[0] += prevHistory

        prevHistory = limit // maximum
        maximum = maximum // 10
        cnt += 1

        # for i in range( 0, 9+1 ):
        #     print( Ans[i], end=" " )
        # print(  )

    for i in range( 0, 9+1 ):
        print( Ans[i], end=" " )

    return

### execution ###

init()