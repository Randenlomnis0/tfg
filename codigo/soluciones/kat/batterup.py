n = int(input())
v = list(map(int, input().split()))
nom, denom = 0, 0
for x in v:
    if x == -1:
        continue
    nom += x
    denom += 1
print(f'{nom / denom:3f}')
