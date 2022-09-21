import sys
import heapq
input = sys.stdin.readline

n = int(input())
card = []
for _ in range(n):
    card.append(int(input()))
heapq.heapify(card)
ans = 0
for _ in range(n - 1):
    a = heapq.heappop(card)
    b = heapq.heappop(card)
    ans += a + b
    heapq.heappush(card,a + b)
print(ans)