l, d, n = list(map(int, input().split()))
birds = [int(input()) for _ in range(n)]
birds.append(6 - d)
birds.append(l - 6 + d)
n += 2
birds.sort()
ans = 0
for i in range(1, n):
    ans += max(0, (birds[i] - birds[i - 1]) // d - 1)
print(ans)
