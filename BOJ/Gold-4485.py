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
    cnt = 0
    while 1:
        cnt += 1 
        v = int( input() )
        if v == 0:
            break

        numV = v*v
        initNode = 1
        finalNode = numV
        Graph = [[] for _ in range( numV+1 )]
        basic_weight = 0

        for i in range( v ):
            Tmp_list = list( map( int, input().rstrip().split() ) )
            if i == 0:
                basic_weight = Tmp_list[0]
            Tmp_list.insert( 0, 0 )
            
            for j in range( 1, v+1 ):
                k = i*v + j
                weight = Tmp_list[j]
                # print( f'num: {k}, weight: {weight}' )
                if i != 0:
                    # print( f'top -> {k-v} to {k}: {weight}' )
                    Graph[k-v].append( (k, weight) )
                if i != v-1:
                    # print( f'bottom -> {k+v} to {k}: {weight}' )
                    Graph[k+v].append( (k, weight) )
                if j != 1:
                    # print( f'left -> {k-1} to {k}: {weight}' )
                    Graph[k-1].append( (k, weight) )
                if j != v:
                    # print( f'right -> {k+1} to {k}: {weight}' )
                    Graph[k+1].append( (k, weight) )

        Dist_list = dijkstra( initNode, Graph, numV )
        print( f'Problem {cnt}: {Dist_list[finalNode] + basic_weight}' )

    return

init()