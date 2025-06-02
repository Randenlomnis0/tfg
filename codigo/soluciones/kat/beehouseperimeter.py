import sys
sys.setrecursionlimit(1000000)
def dfs(grid, i, j, N):
    grid[i][j] = -1
    ans = 0
    for d in [-1, 1]:
        if 0 <= i + d < N:
            if grid[i + d][j] == 0:
                ans += dfs(grid, i + d, j, N)
            elif grid[i + d][j] == 1:
                ans += 1
        if 0 <= j + d < N:
            if grid[i][j + d] == 0:
                ans += dfs(grid, i, j + d, N)
            elif grid[i][j + d] == 1:
                ans += 1
        if 0 <= i + d < N and 0 <= j + d < N:
            if grid[i + d][j + d] == 0:
                ans += dfs(grid, i + d, j + d, N)
            elif grid[i + d][j + d] == 1:
                ans += 1
    return ans
R, K = list(map(int, input().split()))
grid = [[0 for _ in range(2 * R + 1)] for _ in range(2 * R + 1)]
pos = [0 for _ in range(R**3 - (R - 1)**3)]
aux = 0
for i in range(R):
    for j in range(R + i):
        pos[aux] = (i + 1, j + 1)
        aux += 1
for i in range(R, 2 * R - 1):
    for j in range(i - R + 1, 2 * R - 1):
        pos[aux] = (i + 1, j + 1)
        aux += 1
idxs = list(map(int, input().split()))
for idx in idxs:
    idx -= 1
    grid[pos[idx][0]][pos[idx][1]] = 1
print(dfs(grid, 0, 0, 2 * R + 1))