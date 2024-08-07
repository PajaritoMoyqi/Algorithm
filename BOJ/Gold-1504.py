import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

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
    numV, numE = map( int, input().rstrip().split() )
    initNode = 1
    finalNode = numV
    Graph = [[] for _ in range( numV+1 )]

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )
        Graph[target].append( (start, weight) )

    stopover1, stopover2 = map( int, input().rstrip().split() )

    longestDist = 0
    InitDist = dijkstra( initNode, Graph, numV )
    FinalDist = dijkstra( finalNode, Graph, numV )
    st1Dist = dijkstra( stopover1, Graph, numV )
    st2Dist = dijkstra( stopover2, Graph, numV )

    dist1 = InitDist[stopover1] + st1Dist[stopover2] + st2Dist[finalNode]
    dist2 = InitDist[stopover2] + st2Dist[stopover1] + st1Dist[finalNode]
    longestDist = min( dist1, dist2 )

    if longestDist >= INF:
        print( -1 )
    else:
        print( longestDist )

    return

init()