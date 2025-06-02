def dfs(i, j, image, m, n):
    image[i][j] = '.'
    for di in [-1, 0, 1]:
        for dj in [-1, 0, 1]:
            if 0 <= i + di < m and 0 <= j + dj < n and image[i + di][j + dj] != '.':
                dfs(i + di, j + dj, image, m, n)
m, n = map(int, input().split())
image = [list(input().strip()) for _ in range(m)]
ans = 0
for i in range(m):
    for j in range(n):
        if image[i][j] == '.':
            continue
        ans += 1
        dfs(i, j, image, m, n)
print(ans)
