import heapq
import sys
from _collections import defaultdict
v,e = map(int,input().split())
def dijkstra(start,end):
    INF = float('inf')
    distance = [INF]*(v + 1)
    distance[start] = 0
    h = []
    heapq.heappush(h,(0,start))
    while h :
        cost,node = heapq.heappop(h)
        for next_cost,next_node in graph[node]:
            if distance[next_node] < cost + next_cost:
                continue
            distance[next_node] = cost + next_cost
            heapq.heappush(h,(distance[next_node],next_node))
    return distance[end]
graph = defaultdict(list)
for _ in range(e):
    a,b,cost = map(int,input().split())
    graph[a].append((cost,b))
    graph[b].append((cost,a))
v1,v2 = map(int,input().split())


answer = min(dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,v),dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,v))

print(-1) if answer == float('inf') else print(answer)

