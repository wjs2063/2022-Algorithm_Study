n = int(input())
arr = list(map(int, input().split()))
order = [0] * n

for i in range(n):
    
    cnt = 0
    idx = 0
    while cnt != arr[i]:
        if order[idx] == 0: cnt += 1
        idx += 1

    while order[idx] != 0: idx += 1
    
    order[idx] = i + 1

print(" ".join(str(i) for i in order))
