def constant(v, n):
    if len(v) == 1:
        return True
    for i in range(n - 1):
        if v[i + 1] - v[i] != 0:
            return False
    return True
v = list(map(int, input().split()))
n = v[0]
v = [v[1:]]
while not constant(v[-1], n - len(v) + 1):
    v.append([])
    for i in range(n - len(v) + 1):
        v[-1].append(v[-2][i + 1] - v[-2][i])
for i in range(len(v) - 1, 0, -1):
    v[i - 1].append(v[i - 1][-1] + v[i][-1])
print(len(v) - 1, v[0][-1])
