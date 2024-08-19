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
    numV, limit, numE = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]

    Item_list = list( map( int, input().rstrip().split() ) )

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )
        Graph[target].append( (start, weight) )

    max = 0
    for i in range( 1, numV+1 ):
        cnt = 0
        Dist_list = dijkstra( i, Graph, numV )
        for j in range( len( Dist_list ) ):
            if Dist_list[j][0] <= limit:
                cnt += Item_list[j-1]
        max = max if max > cnt else cnt

    print( max )

    return

### Execution ###

init()