from collections import defaultdict
import sys
sys.setrecursionlimit(10**4)
n = 9
path = [[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]]
order = [[8,5],[6,7],[4,1]]
from collections import deque,defaultdict

def solution(n,path,order):
    graph = defaultdict(list)
    visited = [False]*(n + 1)
    before = defaultdict(int)
    for x,y in path:
        graph[x].append(y)
        graph[y].append(x)
    # y 를 방문하려면 먼저 x를 방문해야함
    for x,y in order:
        before[y] = x
    # before[x] := x 전에 방문해야할 곳은 before[x] 이다
    q = deque([0])
    waited_queue = dict()
    cnt = 0
    while q :
        node = q.popleft()
        # 이전에 방문해야할 곳 && 방문하지않았던 곳이라면 waited_queue 에 넣어줌
        if before[node] and not visited[before[node]]:
            waited_queue[before[node]] = node
            continue
        # 방문 체크
        cnt += 1
        visited[node] = True
        for next_node in graph[node]:
            if not visited[next_node]:
                q.append(next_node)
        # 현재 노드가 waited_queue 에있다면
        if node in waited_queue:
            # 변경표시
            q.append(waited_queue[node])
    return cnt == n
print(solution(n,path,order))




