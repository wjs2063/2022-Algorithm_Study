import sys
input = sys.stdin.readline
t = int(input().rstrip())

for _ in range(t):
    n = int(input().rstrip())
    direction = input().rstrip()
    can_see = [0]*n
    origin_sum = 0
    dx = [0]*n
    for i, _dir in enumerate(direction):
        if _dir == 'L':
            can_see[i] = i
        else:
            can_see[i] = n - 1 -i
        origin_sum += can_see[i]
        dx[i] =  n - 1 - 2*can_see[i]
    # 변화량
    answer = [0]*n
    dx.sort(reverse = True )
    for i in range(n):
        if dx[i] > 0:
            origin_sum += dx[i]
        answer[i] = origin_sum
    print(*answer)