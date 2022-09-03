import sys
from collections import deque
input = sys.stdin.readline

t = int(input())


# 우령님이 피드백해주신 풀이
# 최악의 경우에는 path 에 다 저장해야하는 경우가 나옴
def bfs(sx,sy,ex,ey):
    # 출발지점 좌표 + 최단거리
    path = set()
    path.add((sx,sy))
    q = deque([(sx,sy,0)])
    while q :
        x,y,cnt = q.popleft()
        # 도착지점이라면
        if (x,y) == (ex,ey):
            return cnt
        for dx,dy in zip([-2,-1,1,2,2,1,-1,-2],[-1,-2,-2,-1,1,2,2,1]):
            nx = x + dx
            ny = y + dy
            if 0 <= nx < l and 0 <= ny < l and (nx,ny) not in path:
                q.append((nx,ny,cnt + 1))
                path.add((nx,ny))
    return -1



for _ in range(t):
    l = int(input())
    # 출발점
    sx,sy = map(int,input().split())
    # 도착점
    ex,ey = map(int,input().split())
    print(bfs(sx,sy,ex,ey))

# T : O( l^2 ) , S : O( l^2 )


'''
내가 풀이한 공간복잡도 O ( l^2) 코드

import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
def bfs(sx,sy,ex,ey):
    global graph
    # 출발지점 좌표 + 최단거리
    q = deque([(sx,sy)])
    while q :
        x,y = q.popleft()
        for dx,dy in zip([-2,-1,1,2,2,1,-1,-2],[-1,-2,-2,-1,1,2,2,1]):
            nx = x + dx
            ny = y + dy
            if 0 <= nx < l and 0 <= ny < l and not graph[nx][ny]:
                graph[nx][ny]  += graph[x][y] + 1
                q.append((nx,ny))



for _ in range(t):
    l = int(input())
    # 출발점
    sx,sy = map(int,input().split())
    # 도착점
    ex,ey = map(int,input().split())

    graph = [[0]*l for _ in range(l)]
    # 시작지점은 그냥 1로 처리해주고 ex ,ey 가 sx ,sy 랑같으면 그냥 0 리턴해주자, 최종결괏값에서 -1 뺴기
    graph[sx][sy] = 1

    if (sx,sy) == (ex,ey):
        print(0)
    else:
        bfs(sx,sy,ex,ey)
        print(graph[ex][ey] - 1)

# T : O( l^2 ) , S : O( l^2 )


'''