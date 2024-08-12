### initialization ###

import sys
import math

input = sys.stdin.readline

### declaration ###

def init():
    r, s, h, m, d = map( int, input().rstrip().split() )

    a = (r-s)/h
    b = s
    drank_coffee = math.pi*(a*a*(h-d)*(h-d)*(h-d)/3+a*b*(h-d)*(h-d)+b*b*(h-d))
    speed_per_min = drank_coffee/m
    total_coffee = math.pi*(a*a*h*h*h/3+a*b*h*h+b*b*h)
    ramaining_coffee = total_coffee - math.pi*(a*a*(h-d)*(h-d)*(h-d)/3+a*b*(h-d)*(h-d)+b*b*(h-d))
    print( '{:.6f}'.format( ramaining_coffee/speed_per_min ) )
    
    return

### execution ###

init()