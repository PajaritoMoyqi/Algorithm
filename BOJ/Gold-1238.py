import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

def init():
    numV, numE, initNode = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]
    Distance = [INF] * (numV+1)
    ReturnDistance = [INF] * (numV+1)
    Visited = [0] * (numV+1)

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )

    def dijkstra( startNode ):
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

    def dijkstraReturn( startNode ):
        queue = []
        heapq.heappush( queue, ( 0, startNode ) )
        ReturnDistance[startNode] = 0

        while queue:
            dist, curr = heapq.heappop( queue )

            if Visited[curr] == 1:
                continue
            Visited[curr] = 1

            if ReturnDistance[curr] < dist:
                continue

            for data in Graph[curr]:
                distCandidate = dist + data[1]
                vertex = data[0]

                if distCandidate < ReturnDistance[vertex]:
                    ReturnDistance[vertex] = distCandidate
                    heapq.heappush( queue, ( distCandidate, vertex ))

    dijkstra( initNode )

    for i in range( 1, numV+1 ):
        if i != initNode:
            ReturnDistance = [INF] * (numV+1)
            Visited = [0] * (numV+1)
            dijkstraReturn( i )
            Distance[i] += ReturnDistance[initNode]

    longestDist = 0
    for i in range( 1, numV+1 ):
        if longestDist < Distance[i]:
            longestDist = Distance[i]

    print( longestDist )

    return

init()