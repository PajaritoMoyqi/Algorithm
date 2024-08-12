### initialization ###

import sys

input = sys.stdin.readline

### declaration ###

def init():
    Time_list = list( map( str, input().rstrip().split() ) )
    for i in range( len( Time_list ) ):
        Time_list[i] = Time_list[i].split( ':' )

    Attendance_limit_hour = int( Time_list[0][0] )
    Attendance_limit_minute = int( Time_list[0][1] )
    End_hour = int( Time_list[1][0] )
    End_minute = int( Time_list[1][1] )
    Stream_end_hour = int( Time_list[2][0] )
    Stream_end_minute = int( Time_list[2][1] )

    Attendance_set = set()
    cnt = 0
    while True:
        try:
            Chat_list = list( map( str, input().rstrip().split() ) )
            Chat_list[0] = Chat_list[0].split( ':' )

            name = Chat_list[1]
            hour = int( Chat_list[0][0] )
            minute = int( Chat_list[0][1] )

            if (Attendance_limit_hour > hour) or (Attendance_limit_hour == hour and Attendance_limit_minute >= minute):
                Attendance_set.add( name )

            if End_hour == Stream_end_hour:
                if (End_hour == hour and End_minute <= minute <= Stream_end_minute):
                    if name in Attendance_set:
                        Attendance_set.remove( name )
                        cnt += 1
            else:
                if ( End_hour == hour and End_minute <= minute ) or ( End_hour < hour < Stream_end_hour ) or ( End_hour < hour and hour == Stream_end_hour and minute <= Stream_end_minute ):
                    if name in Attendance_set:
                        Attendance_set.remove( name )
                        cnt += 1

        except:
            break

    print( cnt )
    
    return

### execution ###

init()