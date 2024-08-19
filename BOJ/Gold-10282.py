### Initialization ###

import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

### Declaration ###

def dijkstra( startNode, Graph, numV ):
    Distance = [ [INF, 0] ] * (numV+1)
    Visited = [0] * (numV+1)

    queue = []
    heapq.heappush( queue, ( 0, startNode ) )
    Distance[startNode] = [0, startNode]

    while queue:
        dist, curr = heapq.heappop( queue )

        if Visited[curr] == 1:
            continue
        Visited[curr] = 1

        if Distance[curr][0] < dist:
            continue

        for data in Graph[curr]:
            distCandidate = dist + data[1]
            vertex = data[0]

            if distCandidate < Distance[vertex][0] :
                Distance[vertex] = [distCandidate, curr]
                heapq.heappush( queue, ( distCandidate, vertex ))

    return Distance

def init():
    n = int( input() )
    while ( n != 0 ):
        numV, numE, startNode = map( int, input().rstrip().split() )
        Graph = [[] for _ in range( numV+1 )]

        for _ in range( numE ):
            target, start, weight = map( int, input().rstrip().split() )
            Graph[start].append( (target, weight) )

        max = 0
        cnt = -1
        Dist_list = dijkstra( startNode, Graph, numV )
        for j in range( len( Dist_list ) ):
            if Dist_list[j][0] == INF:
                cnt += 1
                continue
            max = max if max > Dist_list[j][0] else Dist_list[j][0]

        print( numV - cnt, max )
        n -= 1

    return

### Execution ###

init()