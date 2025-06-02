n, m = list(map(int, input().split()))
rules = dict()
for _ in range(n):
    l, _, r = input().split()
    rules[l] = r
S = input()
for _ in range(m):
    aux = list(S)
    S = ''
    for c in aux:
        if not c in rules:
            S += c
        else:
            S += rules[c]
print(S)
