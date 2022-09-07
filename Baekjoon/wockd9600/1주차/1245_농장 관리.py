from collections import deque

def bfs():
    queue = deque([])
    cnt = 0
    
    for i in range(n):
        for j in range(m):
            if not mountain[i][j]: check[i][j] = 1
            if check[i][j]: continue

            queue.append((i, j))
            check[i][j] = 1

            top = 1

            while queue:
                x, y = queue.popleft()
                

                for dx, dy in dmove:
                    tx, ty = x + dx, y + dy

                    if 0 > tx or tx >= n or 0 > ty or ty >= m: continue

                    if mountain[x][y] < mountain[tx][ty]:
                        top = 0
                        break
                    if check[tx][ty]: continue
                    
                    if mountain[x][y] == mountain[tx][ty]:
                        queue.append((tx, ty))
                        check[tx][ty] = 1

            if top: cnt += 1

    return cnt

dmove = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

n, m = map(int, input().split())
mountain = [list(map(int, input().split())) for _ in range(n)]
check = [[0] * m for _ in range(n)]

print(bfs())
