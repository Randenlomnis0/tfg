solved = set()
attempts = dict()
ans = 0
while True:
    tokens = input().split()
    if len(tokens) == 1:
        break
    t = int(tokens[0])
    c = tokens[1]
    s = tokens[2]
    if c in solved:
        continue
    if s == 'right':
        ans += t
        solved.add(c)
    else:
        if not c in attempts:
            attempts[c] = 0
        attempts[c] += 1
for c, x in attempts.items():
    if c not in solved:
        continue
    ans += x * 20
print(len(solved), ans)
