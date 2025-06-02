def find(v, x):
    lb = -1
    hb = len(v)
    while lb != hb - 1:
        nb = (lb + hb) // 2
        if v[nb] >= x:
            hb = nb
        else:
            lb = nb
    return hb
N, H = list(map(int, input().split()))
heights = [[], []]
for i in range(N):
    heights[i%2].append(int(input()))
for x in heights:
    x.sort()
ans = 1000000000
cnt = 0
for i in range(H):
    aux = len(heights[0]) - find(heights[0], i + 1) + len(heights[1]) - find(heights[1], H - i)
    if aux < ans:
        ans = aux
        cnt = 1
    elif aux == ans:
        cnt += 1
print(ans, cnt)
