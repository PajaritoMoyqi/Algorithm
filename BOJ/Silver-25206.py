### initialization ###

import sys

input = sys.stdin.readline
NUM = 20

### declaration ###

def init():
    totalWeight = 0
    totalScore = 0
    for _ in range( NUM ):
        _name, weight, score = map( str, input().rstrip().split() )
        
        if score == "P":
            continue
        
        weight = int( float( weight ) )
        totalWeight += weight
        
        if score == "A+":
            totalScore += 4.5 * weight
        elif score == "A0":
            totalScore += 4.0 * weight
        elif score == "B+":
            totalScore += 3.5 * weight
        elif score == "B0":
            totalScore += 3.0 * weight
        elif score == "C+":
            totalScore += 2.5 * weight
        elif score == "C0":
            totalScore += 2.0 * weight
        elif score == "D+":
            totalScore += 1.5 * weight
        elif score == "D0":
            totalScore += 1.0 * weight

    print( totalScore / totalWeight )

    return

### execution ###

init()