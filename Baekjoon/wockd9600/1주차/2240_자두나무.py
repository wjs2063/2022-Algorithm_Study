import sys
input = sys.stdin.readline

t, w = map(int, input().split())
dp = [[0] * (w + 1) for _ in range(t)]

for i in range(t):
    tree = int(input()) - 1

    for j in range(w + 1):
        if j== 0: dp[i][j] = dp[i-1][j]
        else: dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])
        
        if j % 2 == tree: dp[i][j] += 1

print(max(dp[t-1]))
