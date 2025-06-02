l = set()
r = set()
for _ in range(3):
    a, b = list(map(int, input().split()))
    if a in l:
        l.remove(a)
    else:
        l.add(a)
    if b in r:
        r.remove(b)
    else:
        r.add(b)
print(l.pop(), r.pop())
