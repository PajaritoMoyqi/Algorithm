### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    while True:
        string = input().rstrip()
        if string == '*':
            break

        length = len( string )
        flag = 0

        for diff in range ( 1, length ):
            String_list = []
            for i in range( length ):
                if i+diff >= length:
                    break

                newStr = string[i] + string[i+diff]
                if newStr in String_list:
                    flag = 1
                    break
                else:
                    String_list.append( newStr )
            
            if flag == 1:
                break
        
        if flag == 1:
            print( f'{string} is NOT surprising.' )
        else:
            print( f'{string} is surprising.' )

    return

### execution ###

init()