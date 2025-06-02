while True:
    n = int(input())
    if n == 0:
        break
    v = [tuple(map(int, input().split())) for _ in range(n)]
    p = v[n // 2][0]
    q = v[n // 2][1]
    a = 0
    b = 0
    for i in range(n):
        if (v[i][0] - p) * (v[i][1] - q) > 0:
            a += 1
        if (v[i][0] - p) * (v[i][1] - q) < 0:
            b += 1
    print(a, b)
