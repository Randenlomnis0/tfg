n = int(input())
ans = n
prev = dict()
V = list(map(int, input().split()))
for i, x in enumerate(V):
    if x in prev:
        ans = min(ans, i - prev[x])
    prev[x] = i
print(ans)
