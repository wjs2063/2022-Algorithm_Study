import sys
from collections import defaultdict,deque
input = sys.stdin.readline
k = int(input())

def bfs(start,graph):
    q = deque([(start,1)])
    color[start] = 1
    while q :
        vertex, vertex_color = q.popleft()
        for node in graph[vertex]:
            if color[node] == vertex_color:
                return False
            if not color[node]:
                color[node] = - vertex_color
                q.append((node,-vertex_color))
    return True

for _ in range(k):
    graph = defaultdict(list)
    v,e = map(int,input().split())
    color = [0]*(v + 1)
    for _ in range(e):
        a,b = map(int,input().split())
        # 양방향이므로 둘다추가
        graph[a].append(b)
        graph[b].append(a)
    state = True
    for i in range(1,v + 1):
        if not color[i]:
            state = bfs(i,graph)
        if not state or v <= 2:
            state = False
            break
    if state:
        print("YES")
    else:
        print("NO")



'''
50% 에서 틀린코드

import sys
from collections import defaultdict,deque
input = sys.stdin.readline
k = int(input())

def bfs(graph,v):
    q = deque([(1,1)])
    color = [0]*(v + 1)
    color[1] = 1
    while q :
        vertex, vertex_color = q.popleft()
        for node in graph[vertex]:
            if color[node] == vertex_color:
                return False
            if not color[node]:
                color[node] = - vertex_color
                q.append((node,-vertex_color))
    return True

for _ in range(k):
    graph = defaultdict(list)
    v,e = map(int,input().split())
    for _ in range(e):
        a,b = map(int,input().split())
        # 양방향이므로 둘다추가
        graph[a].append(b)
        graph[b].append(a)
    if bfs(graph,v):
        print("YES")
    else:
        print("NO")


'''

# test case

'''
1
3 3
1 2
1 3
2 3
-> No

1
2 2
1 2
2 1
-> No 

1
4 3
1 2
2 4
4 3
-> YES 

'''