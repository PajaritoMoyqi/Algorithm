### initialization ###

import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

### declaration ###

def dijkstra( startNode, Graph, numV ):
    Distance = [INF] * (numV+1)
    Visited = [0] * (numV+1)

    queue = []
    heapq.heappush( queue, ( 0, startNode ) )
    Distance[startNode] = 0

    while queue:
        dist, curr = heapq.heappop( queue )

        if Visited[curr] == 1:
            continue
        Visited[curr] = 1

        if Distance[curr] < dist:
            continue

        for data in Graph[curr]:
            distCandidate = dist + data[1]
            vertex = data[0]

            if distCandidate < Distance[vertex] :
                Distance[vertex] = distCandidate
                heapq.heappush( queue, ( distCandidate, vertex ))

    return Distance

def init():
    numV, numE, targetDist, initNode = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]
    weight = 1

    for _ in range( numE ):
        start, target = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )
        # Graph[target].append( (start, weight) )

    Dist = dijkstra( initNode, Graph, numV )

    cnt = 0
    for i in range( 1, numV+1 ):
        if Dist[i] == targetDist:
            print( i )
            cnt += 1

    if cnt == 0:
        print( -1 )

    return

### execution ###

init()