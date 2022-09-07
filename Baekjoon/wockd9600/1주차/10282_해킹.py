import heapq
import sys
input = sys.stdin.readline

INF = int(2e14)

def dijkstra():
    q = []
    dp = [0] + [INF] * n
    dp[c] = 0
    
    heapq.heappush(q, (0, c))
    
    while q:
        dist, now = heapq.heappop(q)
    
        for next_node, l in graph[now]:
            cost = dist + l
            
            if dp[next_node] > cost:
                dp[next_node] = cost
                heapq.heappush(q, (cost, next_node))

    return dp

for _ in range(int(input())):
    n, d, c = map(int, input().split())
    
    graph = [[] for _ in range(n + 1)]
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    
    dp = dijkstra()
    
    cnt = 0
    for i in range(1, n + 1):
        if dp[i] == INF:
            cnt += 1
            dp[i] = 0
    
    print(n - cnt, max(dp))
