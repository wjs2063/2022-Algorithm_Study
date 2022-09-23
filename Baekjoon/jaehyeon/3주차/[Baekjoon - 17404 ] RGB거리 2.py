import sys
input = sys.stdin.readline

n = int(input())
color = []
INF = int(1e9)


for _ in range(n):
    color.append(list(map(int,input().split())))
# 첫번쨰 를 R G B : 로 색칠했을때
# 첫번쨰 R 이면 마지막은 두번쨰집은 G B or B G 여야한다
answer = INF
for c in range(3):
    dp = [[INF]*3 for _ in range(n)]
    for i in range(3):
        if c == i:
            dp[0][i] = color[0][i]

    for i in range(1,n):
        l , r = (i - 1) % n, (i + 1) % n
        dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) + color[i][0]
        dp[i][1] = min(dp[i - 1][0],dp[i - 1][2]) + color[i][1]
        dp[i][2] = min(dp[i - 1][0],dp[i - 1][1]) + color[i][2]
    for i in range(3):
        if c != i:
            answer = min(answer, dp[n - 1][i])
print(answer)
