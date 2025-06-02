v = list(map(int, input().split()))
v.sort()
if v[0] - v[1] == v[1] - v[2]:
    print(v[2] + v[2] - v[1])
elif abs(v[0] - v[1]) > abs(v[1] - v[2]):
    print(v[0] + v[2] - v[1])
else:
    print(v[1] + v[1] - v[0])
