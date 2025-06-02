def bfs(i, j, m, ids, r, c, id):
    if ids[i][j] != 0:
        return
    q = []
    q.append((i, j))
    ids[i][j] = id
    while q:
        i, j = q.pop()
        for d in [-1, 1]:
            if 0 <= i + d < r and m[i + d][j] == m[i][j] and ids[i + d][j] == 0:
                q.append((i + d, j))
                ids[i + d][j] = id
            if 0 <= j + d < c and m[i][j + d] == m[i][j] and ids[i][j + d] == 0:
                q.append((i, j + d))
                ids[i][j + d] = id
r, c = map(int, input().split())
m = [input().strip() for _ in range(r)]
ids = [[0 for _ in range(c)] for _ in range(r)]
id = 0
for i in range(r):
    for j in range(c):
        if ids[i][j] != 0:
            continue
        id += 1
        bfs(i, j, m, ids, r, c, id)
n = int(input())
for _ in range(n):
    r1, c1, r2, c2 = map(int, input().split())
    r1 -= 1
    c1 -= 1
    r2 -= 1
    c2 -= 1
    if (ids[r1][c1] == ids[r2][c2]):
        print("binary" if m[r1][c1] == '0' else "decimal")
    else:
        print("neither")
