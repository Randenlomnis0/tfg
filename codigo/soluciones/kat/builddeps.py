import sys
sys.setrecursionlimit(10**6)
def dfs(changed, AL, ts, visited):
    visited.add(changed)
    if changed in AL:
        for s in AL[changed]:
            if s in visited:
                continue
            dfs(s, AL, ts, visited)
    ts.append(changed)
n = int(input())
AL = dict()
for _ in range(n):
    tokens = input().split()
    tokens[0] = tokens[0][0:-1]
    for token in tokens:
        if token in AL:
            continue
        AL[token] = set()
    for token in tokens[1:]:
        AL[token].add(tokens[0])
changed = input()
ts = []
visited = set()
dfs(changed, AL, ts, visited)
ts.reverse()
for s in ts:
    print(s)
