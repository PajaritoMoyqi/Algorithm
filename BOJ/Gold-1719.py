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
    numV, numE = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )
        Graph[target].append( (start, weight) )

    for i in range( 1, numV+1 ):
        Dist_list = dijkstra( i, Graph, numV )

        First_visit = []
        for j in range( 1, numV+1 ):
            if Dist_list[j][0] != 0 and Dist_list[j][1] == i:
                First_visit.append( j )
        for j in range( 1, numV+1 ):
            curr = j
            while True:
                if curr == i:
                    print( "-", end=" " )
                    break
                if curr in First_visit:
                    print( curr, end=" " )
                    break
                prev = curr
                curr = Dist_list[prev][1]
        print()

    return

### Execution ###

init()