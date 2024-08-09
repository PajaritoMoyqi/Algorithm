### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    n = int( input() )
    Sold_dict = {}
    for _ in range( n ):
        book_title = input()
        if book_title in Sold_dict:
            Sold_dict[book_title] += 1
        else:
            Sold_dict[book_title] = 1

    max_quantity = max( Sold_dict.values() )

    Best_seller_list = []
    for key, value in Sold_dict.items():
        if value == max_quantity:
            Best_seller_list.append(key)

    Best_seller_list.sort()
    print( Best_seller_list[0] )

    return

### execution ###

init()