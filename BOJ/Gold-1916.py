import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

def init():
    numV = int( input() )
    numE = int( input() )
    Graph = [[] for _ in range( numV+1 )]
    Distance = [INF] * (numV+1)
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

    initNode, targetNode = map( int, input().rstrip().split() )
    dijkstra( initNode )

    print( Distance[targetNode] )

    return

init()