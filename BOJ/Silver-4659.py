### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    Vowel_list = [ 'a', 'e', 'i', 'o', 'u' ]

    while True:
        string = input().rstrip()
        if string == "end":
            break

        vowelStack = 0
        consonantStack = 0
        vowelFlag = 0
        flag = 0
        length = 0
        for spell in string:
            if spell in Vowel_list:
                vowelStack += 1
                consonantStack = 0

                if vowelFlag == 0:
                    vowelFlag = 1        
            else:
                consonantStack += 1
                vowelStack = 0
            
            if vowelStack >= 3 or consonantStack >= 3:
                flag = 1
                break

            if length == 0:
                prev = spell
                length += 1
                continue
            
            if prev == spell and spell != 'e' and spell != 'o':
                flag = 1
                break

            prev = spell
            length += 1

        if flag == 1 or vowelFlag == 0:
            print( "<" + string + "> is not acceptable." )
        else:
            print( "<" + string + "> is acceptable." )

    return

### execution ###

init()