import sys
import heapq

input = sys.stdin.readline
INF = int( 1e9 )

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
    numV = int( input() )
    numE = int( input() )
    Graph = [[] for _ in range( numV+1 )]

    for _ in range( numE ):
        start, target, weight = map( int, input().rstrip().split() )
        Graph[start].append( (target, weight) )

    startNode, finalNode = map( int, input().rstrip().split() )

    Dist_list = dijkstra( startNode, Graph, numV )
    print( Dist_list[finalNode][0] )

    Route_list = []
    curr_node = finalNode
    while 1:
        Route_list.append( str( curr_node ) )
        if curr_node == startNode:
            break
        curr_node = Dist_list[curr_node][1]
    
    print( len( Route_list ) )
    print( ' '.join( list( reversed( Route_list ) ) ) )

    return

init()