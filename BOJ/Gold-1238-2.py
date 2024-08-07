import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

def init():
    numV, numE, initNode = map( int, input().rstrip().split() )
    Graph = [[] for _ in range( numV+1 )]

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )

    def dijkstra( startNode ):
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

    ComebackRoute = dijkstra( initNode )

    longestDist = 0
    for i in range( 1, numV+1 ):
        GoRoute = dijkstra( i )
        longestDist = max( longestDist, ComebackRoute[i] + GoRoute[initNode] )

    print( longestDist )

    return

init()