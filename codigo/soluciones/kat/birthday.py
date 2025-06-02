def dfs(i, AL, visited):
    visited[i] = True
    ans = 1
    for j in AL[i]:
        if visited[j]:
            continue
        ans += dfs(j, AL, visited)
    return ans
while True:
    p, c = map(int, input().split())
    if p == 0 and c == 0:
        break
    AL = [set() for _ in range(p)]
    EL = [list(map(int, input().split())) for _ in range(c)]
    for a, b in EL:
        AL[a].add(b)
        AL[b].add(a)
    ans = True
    for a, b in EL:
        AL[a].remove(b)
        AL[b].remove(a)
        visited = [False for _ in range(p)]
        if dfs(0, AL, visited) != p:
            ans = False
            break
        AL[a].add(b)
        AL[b].add(a)
    print("No" if ans else "Yes")
