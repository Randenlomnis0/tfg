n, m, a, c, x = list(map(int, input().split()))
X = [0 for _ in range(n)]
X[0] = (a * x + c)%m
for i in range(1, n):
    X[i] = (a * X[i - 1] + c)%m
ans = 0
for i in range(n):
    lb = 0
    hb = n - 1
    found = False
    while lb <= hb:
        nb = (hb + lb) // 2
        if X[nb] == X[i]:
            found = True
            break
        elif X[nb] < X[i]:
            lb = nb + 1
        else:
            hb = nb - 1
    if found:
        ans += 1
print(ans)
