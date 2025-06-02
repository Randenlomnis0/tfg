T = int(input())
for tcase in range(1, T + 1):
    n, A, B, C, D, x, y, M = list(map(int, input().split()))
    trees = []
    for _ in range(n):
        trees.append((x, y))
        x = (A * x + B)%M
        y = (C * y + D)%M
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if (trees[i][0] + trees[j][0] + trees[k][0])%3 != 0 or (trees[i][1] + trees[j][1] + trees[k][1])%3 != 0:
                    continue
                ans += 1
    print(f'Case #{tcase}: {ans}')
