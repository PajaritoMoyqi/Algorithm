### Initialization ###

import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

### Declaration ###

def dijkstra( startNode, Graph, numV, Sign_list ):
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

            if distCandidate < Distance[vertex][0] and Sign_list[vertex] != 1:
                Distance[vertex] = [distCandidate, curr]
                heapq.heappush( queue, ( distCandidate, vertex ))

    return Distance

def init():
    numV, numE = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]

    Sign_list = list( map( int, input().rstrip().split() ) )
    Sign_list[-1] = 0

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )
        Graph[target].append( (start, weight) )

    Dist_list = dijkstra( 0, Graph, numV, Sign_list )
    if Dist_list[numV-1][0] == INF:
        print( "-1" )
    else:
        print( Dist_list[numV-1][0] )

    return

### Execution ###

init()